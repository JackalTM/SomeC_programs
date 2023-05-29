#include <stdio.h>      /* printf, scanf, NULL */
#include <stdint.h>
#include <stdlib.h>     /* malloc, free, rand */

#define PRINT_TYPE_01   0x11
#define PRINT_TYPE_02   0x22
#define PRINT_TYPE_03   0x33
#define PRINT_TYPE_04   0x44

#define DYNAMIC_ARRAY_REMOVE        0xFF
#define DYNAMIC_ARRAY_DATA_OK       0x00
#define DYNAMIC_ARRAY_NO_INIT       0x11
#define DYNAMIC_ARRAY_NOELEMENT     0x22
#define DYNAMIC_ARRAY_HEADPTR_NULL  0x33
#define DYNAMIC_ARRAY_TAILPTR_NULL  0x44
#define DYNAMIC_ARRAY_DATA_PRESENT  0x55

#define TRUE    0xFF
#define FALSE   0x00

//#define DEBUG_ON    

#define DATA_LEN    8
typedef struct MemoryMember_t
{
    struct MemoryMember_t *pPrev;
    struct MemoryMember_t *pNext;
    uint8_t mydata[DATA_LEN];
}MemoryMember_t;

typedef struct
{
    struct MemoryMember_t *pTail;
    struct MemoryMember_t *pHead; 
    uint8_t n;
    uint8_t init;
}MallocControlData_t;

uint8_t AddFirstItem(MallocControlData_t* pControlData, uint8_t* pEle);

uint8_t AddHeadElement(MallocControlData_t* pControlData, uint8_t* pEle);
uint8_t AddTaillElement(MallocControlData_t* pControlData, uint8_t* pEle);

uint8_t RemoveHeadElement(MallocControlData_t* pControlData, uint8_t* pRet, uint8_t inRemove);
uint8_t RemoveTailElement(MallocControlData_t* pControlData, uint8_t* pRet, uint8_t inRemove);

uint8_t GetRandomElement(MallocControlData_t* pControlData, uint8_t* pEle, uint8_t inIntex);

void PrintAllElements(MallocControlData_t* pControlData);

void CallMyDynamicStackTest3(void);
