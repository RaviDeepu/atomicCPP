# include <stdio.h>
#include<iostream>

 

// List all permutations of a String.

using namespace std;

/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
	//cout<<*x<<","<<*y<<endl;
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n)
{
   int j;
   if (i == n)
   {
	cout<<"==============================\n";
     printf("%s\n", a);
	cout<<"==============================\n";
   }
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
}
 
/* Driver program to test above functions */
int main()
{
   char a[] = "ABC"; 
   permute(a, 0, 2);
   getchar();
   return 0;
}

/*
Output:

ABC
ACB
BAC
BCA
CBA
CAB
*/
