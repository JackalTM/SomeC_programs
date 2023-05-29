#include "jobIntervievQuestions.h"

int Question39_DuplicatesInArray(void)
{
  int n, a[100], b[100], calc = 0, i, j,count;
  printf("Enter no. of elements in array: ");
  scanf("%d", &n);
  printf("Enter %d integers: ", n);
  for (i = 0; i < n; i++)
  {
      scanf("%d", &a[i]);
  }
        
  for (i = 0; i<n; i++) 
  {
      for (j = 0; j<calc; j++) 
      {
          if(a[i] == b[j])
          break;  
      }
      if (j== calc) 
      {
            b[calc] = a[i];
            calc++; 
      }
    }
    
    printf("Array obtained after removing duplicate elements: ");
    for (i = 0; i<calc; i++) 
    { 
          printf("%d ", b[i]);
    }
    return 0;   
}

/***********************************************************************************************
 * 41. Write a program to get the higher and lower nibble of a byte without using shift operator?
*/
int Question41_lowernibble(void)
{
  Q_41_union_t  tData;

  tData.data = 0xAB;

  printf("BYTE = %x \n", tData.data);
  printf("LOW BYTE = %x HIGH BYTE = %x \n", tData.dataSlise.data1, tData.dataSlise.data2);

  return 0;
}
//=============================================================================================

/***********************************************************************************************
 * 43. Write a C program to check if it is a palindrome number or not using a recursive method.
*/
int Question43_palindrome_number_isPalindrome(int num)
{
  if(num == Question43_palindrome_number_reverse(num)) 
  { return 1;}
  else { return 0;}
}
int Question43_palindrome_number_reverse(int num)
{
  int rem;
  static int sum=0;
  if(num!=0)
  {
    rem=num%10;
    sum=sum*10+rem;
    Question43_palindrome_number_reverse(num/10);
  }
  else  
  { return sum;}
  return sum;
}
int Question43_palindrome_number(int Num)
{
  printf("========================================== \n");
  printf("Is the given numbe a palindrome??? %d \n", Num);
  if(Question43_palindrome_number_isPalindrome(Num) == 1)
  { printf("TRUE \n");}
  else
  { printf("FALSE \n");}
  printf("========================================== \n");
  return 0;
}
//==============================================================================================

/***********************************************************************************************
 * 44. C program to check the given number format is in binary or not.
*/
int Question44_binary_or_not(int Num)
{
	int j;
  printf("========================================== \n");
	printf("Does number %d is binary?? \n", Num);
  while(Num > 0x00)
  {
      j = Num % 10;
      if((j != 0) && (j != 1 ))
      {
          printf("FALSE \n");
          break;
      }

      Num = Num / 10;
      if(Num == 0x00)
      { printf("TRUE \n");}
  }
  printf("========================================== \n");

  return 0;
}
//==============================================================================================

/***********************************************************************************************
 * 45. C Program to find a sum of digits of a number using recursion.
*/
int Question45_find_SUM_recursion_sumOfDigits(int num, int* pCallsAmount)
{
  static int sum = 0;
  int rem;

  if(*(pCallsAmount) > 10)  { return -1;}
  else                      { *(pCallsAmount) = *(pCallsAmount) + 1;}

  sum = sum + (num % 10);
  rem = num / 10;

  if(rem > 0x00)  { Question45_find_SUM_recursion_sumOfDigits(rem, pCallsAmount);}
  else            { return sum;}
}
int Question45_find_SUM_recursion(int Num)
{
  int tCallsAmount = 0;
  printf("========================================== \n");
	printf("Sum of digits from a number %d \n", Num);

  Num = Question45_find_SUM_recursion_sumOfDigits(Num, &tCallsAmount);
  printf("Sum of digits = %d \n", Num);
  printf("Recursion number = %d \n", tCallsAmount);

  printf("========================================== \n");
}
//==============================================================================================

/***********************************************************************************************
 * 52. When is the "void" keyword used in a function
*/
void Question52_MyMemCopy(void* pDst, const void* pSrc, int numBytes) 
{ 
  int i;
	char* pDst_c;
	char* pSrc_c;

	pDst_c       = (char*)(pDst); 
	pSrc_c = (char*)(pSrc);

	for (i = 0; i < numBytes; ++i) 
  {
    *(pDst_c + i) = *(pSrc_c + i);
  }
}
//==============================================================================================

/***********************************************************************************************
 * 54. Add Two Numbers Without Using the Addition Operator
*/
int Question54_addTwoNUmbers(int num1, int num2)
{
  int x, y;
  printf("========================================== \n");
  printf("Two numbers add  %d + %d \n", num1, num2);
  x = num1;
  y = num2;

  // method 1
  printf("%d\n", x - (-y));

  // method 2
  printf("%d\n", -(-x -y));

  // method 3
  printf("%d\n", abs(-x -y));

  // method 4
  printf("%d", x - (~y) - 1);
  printf("========================================== \n");

  return 0;
}
//==============================================================================================

/***********************************************************************************************
 * 55. Subtract Two Number Without Using Subtraction Operator
*/
int Question55_subTwoNUmbers(int num1, int num2)
{
  printf("========================================== \n");
  printf("Two numbers sub  %d + %d \n", num1, num2);

  printf("%d", num1 + (~num1) + 1);
  printf("========================================== \n");

  return 0;
}
//==============================================================================================

/***********************************************************************************************
 * 56. Multiply an Integer Number by 2 Without Using Multiplication Operator
*/
int Question56_multiplyNumber(int num)
{
  int x;
  printf("========================================== \n");
  printf("Number %d to multiply by 2 \n");

  x = num << 1;
  printf("%d", x<<1);
  printf("========================================== \n");
  return 0;
}
//==============================================================================================

/***********************************************************************************************
 * 57. Check whether the number is EVEN or ODD, without using any arithmetic or relational operators
*/
int Question57_number_EvenOrOdd(int num)
{
  int x;
  x = num;
  printf("========================================== \n");
  printf("NUmber to check %d \n", num);

  (x&1)?printf("ODD \n"):printf("EVEN \n");

  printf("========================================== \n");
  return 0;
}
//==============================================================================================

/***********************************************************************************************
 * 58. Reverse the Linked List. Input: 1->2->3->4->5->NULL Output: 5->4->3->2->1->NULL
*/
void Question56_reverseObjectsList(MallocControlData_t* pMallocControlData)
{ 
  if(pMallocControlData->init != 0xFF)  return;
  if(pMallocControlData->n == 0x00)     return;

  MemoryMember_t* pCurrent  = pMallocControlData->pHead;
  MemoryMember_t* pPrev     = NULL; 
  MemoryMember_t* pNext     = NULL;

// Input: 1-> 2-> 3-> 4-> 5-> NULL Output: 5->4->3->2->1->NULL

// (pPrev)=[ curr ]=(pNext) ; (pPrev)=[ curr ]=(pNext) ; (pPrev)=[ curr ]=(pNext) ; (pPrev)=[ curr ]=(pNext) ;
// (NULL )=[ obj1 ]=(&obj2) ; (obj1 )=[ obj2 ]=(&obj3) ; (obj2 )=[ obj3 ]=(&obj4) ; (obj3 )=[ obj4 ]=(NULL )

  uint8_t i;
  for(i=0; i<(pMallocControlData->n); i++)
  {
    pNext = pCurrent->pNext;
    pPrev = pCurrent->pPrev;

    pCurrent->pNext = pPrev;
    pCurrent->pPrev = pNext;

    if(pNext == NULL) break;
    else   pCurrent = pNext;
  }
}
//==============================================================================================

/***********************************************************************************************
 * 59. Check for Balanced Parentheses using Stack
*/
int Question59_check(char exp[] )
{
  /*
  int i;
  char temp;
  for(i=0; i<strlen(exp); i++)
  {
    if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') { push(exp[i]);}

    if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
    {
      if(top == -1)    //stack empty
      {
        printf("Right parentheses are more than left parentheses\n");
        return 0;
      }
      else
      {
        temp=pop();
        if(!match(temp, exp[i]))
        {
          printf("Mismatched parentheses are : ");
          printf("%c and %c\n",temp,exp[i]);
          return 0;
        }
      }
    }
  }

  if(top==-1) //stack empty
  {
    printf("Balanced Parentheses\n");
    return 1;
  }
  else
  {
    printf("Left parentheses more than right parentheses\n");
    return 0;
  }
  */
}
//==============================================================================================

/***********************************************************************************************
 * 60. Program to find n’th Fibonacci number
*/
int Question60_fib(int n)
{
  if (n <= 1) 
  { return n;}

  return Question60_fib(n - 1) + Question60_fib(n - 2);
}
 
int Question60_fibcall(int n)
{
  printf("nth Fibonacci number is %d", Question60_fib(n));

  return 0;
}
//==============================================================================================

/***********************************************************************************************
 * 61. Write a program to find the node at which the intersection of two singly linked lists begins.
*/ 
int Question61_getIntersectionNode(MallocControlData_t pMallocControlData1, MallocControlData_t pMallocControlData2) 
{ 
  uint8_t i,j;
  MemoryMember_t* pOBJ11 = pMallocControlData1.pHead;
  MemoryMember_t* pOBJ22 = pMallocControlData2.pHead;
  MemoryMember_t* pCURR;

  for(i=0; pMallocControlData1.n; i++)
  {
    pCURR = pOBJ11->pNext;
  }
  for(j=0; pMallocControlData2.n; j++)
  {

  }
}
//==============================================================================================

/***********************************************************************************************
 * 62. Merge Two sorted Linked List
*/
void Question62_merge_sorted(MallocControlData_t pMallocControlData1, MallocControlData_t pMallocControlData2)
{  
  // if both lists are empty then merged list is also empty
  // if one of the lists is empty then other is the merged list
  if((pMallocControlData1.pHead == NULL) && (pMallocControlData1.pTail == NULL))
  {
    ;
  }
  if((pMallocControlData2.pHead == NULL) && (pMallocControlData2.pTail == NULL))
  {
    ;
  }

  

  /*
  if (head1 == void*0) 
  {
    return head2;
  } 
  else if (head2 == nullptr) 
  {
    return head1;
  }


  Node_t mergedHead = nullptr;
  if (head1->data <= head2->data) 
  {
    mergedHead = head1;
    head1 = head1->next;
  } 
  else 
  {
    mergedHead = head2;
    head2 = head2->next;
  }

  NodePtr mergedTail = mergedHead;
  
  while (head1 != nullptr && head2 != nullptr) 
  {
    NodePtr temp = nullptr;
    if (head1->data <= head2->data) 
    {
      temp = head1;
      head1 = head1->next;
    } 
    else 
    {
      temp = head2;
      head2 = head2->next;
    }

    mergedTail->next = temp;
    mergedTail = temp;
  }

  if (head1 != nullptr) 
  {
    mergedTail->next = head1;
  } 
  else if (head2 != nullptr) 
  {
    mergedTail->next = head2;
  }

  return mergedHead;
  */
}
//==============================================================================================