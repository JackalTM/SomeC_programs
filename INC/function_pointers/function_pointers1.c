#include "function_pointers1.h"

pFunType_oneArg FunctionPointerInAndOutTest1(pFunType_oneArg inPfun)
{
    pFunType_oneArg pFunNOT;
    pFunNOT = inPfun;

    return pFunNOT;
}
pFunType_twoArg FunctionPointerInAndOutTest2(pFunType_twoArg pFunIN[], uint8_t maxn,uint8_t n)
{
    pFunType_twoArg pFun; 
    if(n > maxn) 
        n = 0;
    else
        pFun = *(pFunIN + n);


    return pFun;
}
void CallTest1(void)
{
    uint8_t retval, i;
    pFunType_twoArg pFunTwoArgs;
    quasiClassTestBasic_t myquasiClassTestBasic;
    myquasiClassTestBasic.pFunAND = (pFunType_twoArg)&LogicalAND;
    myquasiClassTestBasic.pFunOR  = (pFunType_twoArg)&LogicalOR;
    myquasiClassTestBasic.pFunXOR = (pFunType_twoArg)&LogicalXOR;
    myquasiClassTestBasic.pFunNOT = FunctionPointerInAndOutTest1((pFunType_oneArg)&LogicalNOT);

    myquasiClassTestBasic.pFunArr[0] = (pFunType_twoArg)&LogicalAND;
    myquasiClassTestBasic.pFunArr[1] = (pFunType_twoArg)&LogicalOR;
    myquasiClassTestBasic.pFunArr[2] = (pFunType_twoArg)&LogicalXOR;    

    retval = (*myquasiClassTestBasic.pFunAND)(0x1F, 0xF1);
    printf("Return value: %x \n", retval);

    retval = (*myquasiClassTestBasic.pFunOR)(0x1F, 0xF1);
    printf("Return value: %x \n", retval);

    for(i=0; i<3; i++)
    {
        retval = (*myquasiClassTestBasic.pFunArr[i])(0x1F, 0xF1);
        printf("Arr Return value: %x \n", retval); 
    }

    printf("Function pointer in and out test: \n");
    retval = (*myquasiClassTestBasic.pFunNOT)(0x77);
    printf("Return value: %x \n", retval);

    printf("Array of function pointer and return function pointer: \n");
    for(i=0; i<3; i++)
    {
        pFunTwoArgs = FunctionPointerInAndOutTest2(myquasiClassTestBasic.pFunArr, 2, i);
        retval = (*pFunTwoArgs)(0x00, 0xFF); 
        printf("i= %x Function return pointer to function: %x \n", i,retval); 
    }
}