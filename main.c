//#include "INC/dynamic_memory/DynamicMemoryV2.h"
#include "INC/trainingFunctions/excQuest.h"

void PrintArray(char* pArray, uint8_t n)
{
  uint8_t i;
  printf("LIST: \n");
  
  for(i=0; i<n; i++)
  {
    printf("| %x = %x | ", i, pArray[i]);
  }
  printf("\n");
}

int main()
{
    uint8_t retval, n;
    char myarray1[] = {0x11, 0x22, 0x33, 0x44, 0x11, 0x22, 0x33, 0x44, 0x11, 0x22, 0x33, 0x44, 0x11, 0x55, 0x33, 0x55};
    char myarray2[] = {0x11, 0x11, 0x22, 0x22, 0x33, 0x33, 0x44, 0x44};
    char* p;
    p = myarray2;
    n = 16;

    PrintArray(p, n);
    retval = RemoveDuplicatesInArray(p, n);
    PrintArray(p, retval);

    return 0;
}