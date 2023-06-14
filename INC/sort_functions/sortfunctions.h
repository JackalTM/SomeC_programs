#include <stdint.h>
#include <stdio.h>

#define COMPARE_EQUAL   0x00
#define COMPARE_MORE    0x01
#define COMPARE_LESS    0xFF
uint8_t SortBubleBYTE(uint8_t* pArray, uint8_t inEleN, uint8_t inAscDsc);

typedef uint8_t (*pCompareFunType)(uint8_t* pA, uint8_t* pB, uint8_t oneEleSize);
uint8_t SortBubleForAllTypes(uint8_t* pBasePtr, uint8_t inNumOfEle, uint8_t inSizeOfEle, pCompareFunType pFun);
void CallSortBouble1(void);
void CallSortBouble2(void);