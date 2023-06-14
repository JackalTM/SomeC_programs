#include "sortfunctions.h"

static uint8_t _CheckIfSorted(uint8_t* pArray, uint8_t inEleN, uint8_t inAscDsc)
{
    uint8_t i, j; j = 0;
    if(inAscDsc = 0x01)
    {
        for(i=1; i<inEleN; i++)
        {
            if(*(pArray + i - 1) >= *(pArray + i))  { j++; }
        }
    }
    else if(inAscDsc = 0x01)
    {
        for(i=1; i<inEleN; i++)
        {
            if(*(pArray + i - 1) <= *(pArray + i))  { j++; }
        }
    }
    if(j == inEleN) return 0xFF;
    else            return 0x00;
}
uint8_t SortBubleBYTE(uint8_t* pArray, uint8_t inEleN, uint8_t inAscDsc)
{
    uint8_t i,j, nmax, tByte;
    nmax = 0x00;

    if(inAscDsc == 0x01)
    {   do
        {   j = 0x00; nmax++;
            for(i=1; i<inEleN; i++)
            {
                if(*(pArray + i - 1) < *(pArray + i))
                {   j++;
                    tByte = *(pArray + i);
                    *(pArray + i) = *(pArray + i - 1);
                    *(pArray + i - 1) = tByte;
                }
            }
        } while ((j > 0x00) && (nmax < 0xF0));
    }
    else if(inAscDsc == 0xFF)
    {   do
        {   j = 0x00; nmax++;
            for(i=1; i<inEleN; i++)
            {
                if(*(pArray + i - 1) > *(pArray + i))
                {   j++;
                    tByte = *(pArray + i);
                    *(pArray + i) = *(pArray + i - 1);
                    *(pArray + i - 1) = tByte;
                }
            }
        } while ((j > 0x00) && (nmax < 0xF0));
    }
    else
        return 0x00;

    return nmax;
}

static uint8_t _CompareElementStr(uint8_t* pA, uint8_t* pB, uint8_t oneEleSize)
{
    uint8_t i, cmpResoult; 

    for(i=0; i<oneEleSize; i++)
    {
        if(*(pA + i) > *(pB + i))   
        {   cmpResoult = COMPARE_MORE; break;}
        else if(*(pA + i) < *(pB + i)) 
        {   cmpResoult = COMPARE_LESS; break;}
        else
            cmpResoult = COMPARE_EQUAL;
    }
    return cmpResoult;
}
static uint8_t _CompareElementINT(uint8_t* pA, uint8_t* pB, uint8_t oneEleSize)
{
    uint8_t i, cmpResoult; 
    i = 0;
    pA = pA + oneEleSize - 1;
    pB = pB + oneEleSize - 1;
    while(i < oneEleSize)
    {
        if(*(pA - i) > *(pB - i))   
        {   cmpResoult = COMPARE_MORE; break;}
        else if(*(pA - i) < *(pB - i)) 
        {   cmpResoult = COMPARE_LESS; break;}
        else
            cmpResoult = COMPARE_EQUAL; 
        i++; 
    }
    return cmpResoult;
}
uint8_t SortBubleForAllTypes(uint8_t* pBasePtr, uint8_t inNumOfEle, uint8_t inSizeOfEle, pCompareFunType pFun)
{
    uint8_t i;

    return 0;
}

void CallSortBouble1(void)
{
    char tChar;
    uint8_t i,n;
    uint8_t byteArray[] = { 56,9,8,74,6,59,4,31,2,1,1,21,14 };

    printf("Before sort: ");
    for(i=0; i< sizeof(byteArray); i++)
    {
        printf(" %2x ", byteArray[i]);
    }

    printf("\n After sort: ");
    n = SortBubleBYTE(byteArray, sizeof(byteArray), 0xFF);
    for(i=0; i< sizeof(byteArray); i++)
    {
        printf(" %2x ", byteArray[i]);
    }
    printf("NUmber of loops %x \n", n);

    printf("\n After sort: ");
    n = SortBubleBYTE(byteArray, sizeof(byteArray), 0x01);
    for(i=0; i< sizeof(byteArray); i++)
    {
        printf(" %2x ", byteArray[i]);
    }
    printf("NUmber of loops %x \n", n);
}
void CallSortBouble2(void)
{
    uint64_t num1;
    num1 = -1;
    uint64_t num2;
    num2 = -3;
    uint8_t cmpRes;

    cmpRes = _CompareElementINT(&num1, &num2, sizeof(uint64_t));

    printf("CMP of uint64_t resoult = %x \n", cmpRes);
}