#include "DynamicMemoryV2.h"

/*******************************************************************************************************************
 * @name    CheckForErros
 * @brief   Check data in terms of worng content
 * @param[in] pContrldata Pointer to control stucture
 * @return State of error if present
 * @note This is static private function
*/
static uint8_t CheckStackState(MallocControlData_t* pControlData)
{
    if(pControlData->init != TRUE)          
        return DYNAMIC_ARRAY_NO_INIT;
    else if(pControlData->n == 0x00)        
        return DYNAMIC_ARRAY_NOELEMENT;
    else if(pControlData->pHead == NULL)    
        return DYNAMIC_ARRAY_HEADPTR_NULL;
    else if(pControlData->pTail == NULL)    
        return DYNAMIC_ARRAY_TAILPTR_NULL;
    else                                    
        return DYNAMIC_ARRAY_DATA_OK;
}
//==================================================================================================================

/*******************************************************************************************************************
 *@name     AddFirstItem
 *@brief    Return last element from dynamic array to given pointer
 *@param    pContrldata     Pointer to control data
 *@param    pEle            Start addr for data to put inside
 *@return   Status of the operation
*/
uint8_t AddFirstItem(MallocControlData_t* pControlData, uint8_t* pEle)
{
    MemoryMember_t* pFirstElement;
    pFirstElement = ((MemoryMember_t*)malloc(sizeof(MemoryMember_t)));

    #ifdef DEBUG_ON
        printf("Aloc ADDR:= 0x%08x \n", pFirstElement);
    #endif

    pFirstElement->pPrev = NULL;
    pFirstElement->pNext = NULL;

    pControlData->pTail = pFirstElement;
    pControlData->pHead = pFirstElement;
    pControlData->n     = 0x01;
    pControlData->init  = TRUE;

    uint8_t i;
    for(i=0; i<DATA_LEN; i++)
    {
        pFirstElement->mydata[i] = *(pEle + i);
    }
    return 0x00;
}
//================================================================================================================

/*****************************************************************************************************************
 *@name     AddHeadElement
 *@brief    Add element on the HEAD of array

 *@param    pContrldata     Pointer to control data
 *@param    pEle            Start addr for data to put inside

 *@return   Status of the operation
*/
uint8_t AddHeadElement(MallocControlData_t* pControlData, uint8_t* pEle)
{
    uint8_t temp;
    temp = CheckStackState(pControlData);
    if(temp) return temp;

    MemoryMember_t* pNewHead; 
    MemoryMember_t* pOldHead;
    
    //1. New alocated memory.
    pNewHead = ((MemoryMember_t*)malloc(sizeof(MemoryMember_t)));
    pOldHead = pControlData->pHead;

    #ifdef DEBUG_ON
        printf("Aloc ADDR:= 0x%08x \n", pNewHead);
    #endif
    
    pOldHead->pNext = pNewHead;
    pNewHead->pPrev = pOldHead;
    pNewHead->pNext = NULL;

    pControlData->pHead = pNewHead;
    pControlData->n++;

    // 
    uint8_t i, j;
    for (i=0; i<DATA_LEN; i++)
    {
        pNewHead->mydata[i] = *(pEle + i);
    }
    return 0x00;
}
//================================================================================================================

/*****************************************************************************************************************
 *@name     AddTaillElement
 *@brief    Add element on the TAILL of array

 *@param    pContrldata     Pointer to control data
 *@param    pEle            Start addr for data to put inside

 *@return   Status of the operation
*/
uint8_t AddTaillElement(MallocControlData_t* pControlData, uint8_t* pEle)
{
    uint8_t temp;
    temp = CheckStackState(pControlData);
    if(temp) return temp;

    MemoryMember_t* pNewTail;
    MemoryMember_t* pOldTail;

    pNewTail = ((MemoryMember_t*)malloc(sizeof(MemoryMember_t)));
    pOldTail = pControlData->pTail; 

    #ifdef DEBUG_ON
        printf("Aloc ADDR:= 0x%08x \n", pNewTail);
    #endif

    pOldTail->pPrev = pNewTail;
    pNewTail->pNext = pOldTail;
    pNewTail->pPrev = NULL;

    pControlData->pTail = pNewTail;
    pControlData->n++;

    uint8_t i,j;
    for(i=0; i<DATA_LEN; i++)
    {
        pNewTail->mydata[i] = *(pEle + i);
    }
    return 0x00;
}
//================================================================================================================

/*****************************************************************************************************************
 *@name     RemoveHeadElement
 *@brief    Return last element from dynamic array to given pointer
 *@param    pContrldata to control data
 *@param    pRet start addr to place data
 *@param    inRemove remove or not last element
 *@return   Status of the operation
*/
uint8_t RemoveHeadElement(MallocControlData_t* pControlData, uint8_t* pRet, uint8_t inRemove)
{
    uint8_t temp;
    temp = CheckStackState(pControlData);
    if(temp) return temp;

    MemoryMember_t* pOldHead;
    MemoryMember_t* pNewHead;
    uint8_t i;

    // 1. Return head element
    pOldHead = pControlData->pHead;
    pNewHead = pOldHead->pPrev;
    for (i=0; i<DATA_LEN; i++)
    {
        *(pRet + i) = pOldHead->mydata[i];
    }

    // 2. If not remove element then return
    if(inRemove == FALSE)
        return FALSE;

    // 3. Removing element from memry
    if((pControlData->pTail == pControlData->pHead) || (pControlData->n == 0x1))
    {// Last element is present
        pControlData->pTail = NULL;
        pControlData->pHead = NULL;
        pControlData->n     = 0x00;
        pControlData->init  = 0x00;
    }
    else if(pControlData->n > 0x1)
    {// More than 1 element is present
        pNewHead->pNext = NULL;
        pControlData->pHead = pNewHead;
        if(pControlData->n > 0x00)
            pControlData->n--;
    }
    else // Other cases
    {   return FALSE;}

    #ifdef DEBUG_ON
        printf("free ADDR:= 0x%08x \n", pOldHead);
    #endif

    // 4. Return ocupieted memory
    free((MemoryMember_t*)pOldHead);
    return TRUE;
}
//================================================================================================================

/*****************************************************************************************************************
 *@name     RemoveTaillElement
 *@brief    Return last element from dynamic array to given pointer
 *@param    pContrldata to control data
 *@param    pRet start addr to place data
 *@param    inRemove remove or not last element
 *@return   Status of the operation
*/
uint8_t RemoveTaillElement(MallocControlData_t* pControlData, uint8_t* pRet, uint8_t inRemove)
{
    uint8_t temp = CheckStackState(pControlData);
    if(temp) return temp;

    MemoryMember_t* pNewTail;
    MemoryMember_t* pOldTail;

    pOldTail = pControlData->pTail;
    pNewTail = pOldTail->pNext;
    uint8_t i;
    for(i=0; i<DATA_LEN; i++)
    {
        *(pRet + i) = pOldTail->mydata[i];
    }

    if(inRemove == FALSE)
        return FALSE;

    if((pControlData->pTail == pControlData->pHead) || (pControlData->n == 0x1))
    {
        pControlData->pTail = NULL;
        pControlData->pHead = NULL;
        pControlData->n     = 0x00;
        pControlData->init  = 0x00;
    }
    else if(pControlData->n > 0x1)
    {
        pNewTail->pPrev = NULL;
        pControlData->pTail = pNewTail;
        if(pControlData->n > 0x00)
            pControlData->n--;
    }
    else
    {   return FALSE;}

    #ifdef DEBUG_ON
        printf("free ADDR:= 0x%08x \n", pOldTail);
    #endif

    free((MemoryMember_t*)pOldTail);
    return TRUE;
}
//================================================================================================================

/*****************************************************************************************************************
 *@name     PrintAllElements
 *@brief    Print on screen all elements in pointer stack.
 *@param    pContrldata Pointer to structure with control data
 *@return   Void
*/
void PrintAllElements(MallocControlData_t* pControlData)
{
    uint8_t stackstate = CheckStackState(pControlData);
    if(stackstate)
    {
        printf("EMPTY \n");
        return;
    }

    MemoryMember_t* pTemp;

    uint8_t i;
    pTemp = pControlData->pTail;
    for (i=0; i < pControlData->n; i++)
    {
        printf("[%x] | ", i);
        printf("ADDR:= 0x%08x | ", pTemp);
        printf("DATA:= 0x%x \n", pTemp->mydata[0]);
        pTemp = pTemp->pNext;
    }
    printf("\n --- \n");
}
//================================================================================================================

void CallMyDynamicStackTest3(void)
{
    MallocControlData_t mallControl;
    uint64_t tdata;
    uint8_t retval;

    printf("Alocating memory \n");

    tdata = 0x11;
    retval = AddFirstItem(&mallControl, (uint8_t*)&tdata);
    PrintAllElements(&mallControl);
    
    tdata = 0x22;
    //retval= AddTaillElement(&mallControl, (uint8_t*)&tdata);
    retval= AddHeadElement(&mallControl, (uint8_t*)&tdata);
    PrintAllElements(&mallControl);

    tdata = 0x33;
    retval= AddHeadElement(&mallControl, (uint8_t*)&tdata);
    PrintAllElements(&mallControl);

    printf("Releasing memory \n \n");

    do
    {
        PrintAllElements(&mallControl);
        printf("Next call \n");
        retval = RemoveHeadElement(&mallControl, (uint8_t*)&tdata, TRUE);
        //retval = RemoveTaillElement(&mallControl, (uint8_t*)&tdata, TRUE);
    } 
    while (retval == TRUE);
}
//================================================================================================================