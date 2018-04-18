/*


Given an array A[] and a number x, check for pair in A[] with sum as x

Write a C program that, given an array A[] of n numbers and another number x, determines whether or not there exist two elements in S whose sum is exactly x. 

1) Initialize Binary Hash Map M[] = {0, 0, …}
2) Do following for each element A[i] in A[]
   (a)	If M[x  - A[i]] is set then print the pair (A[i], x – A[i])
   (b)	Set M[A[i]]

*/

#include <stdio.h>
#define MAX 100000
 
void printPairs(int arr[], int arr_size, int sum)
{
  int i, temp;
  bool binMap[MAX] = {0}; /*initialize hash map as 0*/
 
  for(i = 0; i < arr_size; i++)
  {
    temp = sum - arr[i];
    if(temp >= 0 && binMap[temp] == 1)
    {
      printf("Pair with given sum %d is (%d, %d) \n", sum, arr[i], temp);
    }
    binMap[arr[i]] = 1;
  }
}
 
/* Driver program to test above function */
int main()
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int n = 14;
    int arr_size = 6;
 
    printPairs(A, arr_size, n);
 
    getchar();
    return 0;
}
