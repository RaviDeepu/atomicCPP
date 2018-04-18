/*
Find common elements in three sorted arrays
Given three arrays sorted in non-decreasing order, print all common elements in these arrays.

Examples:

ar1[] = {1, 5, 10, 20, 40, 80}
ar2[] = {6, 7, 20, 80, 100}
ar3[] = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20, 80

ar1[] = {1, 5, 5}
ar2[] = {3, 4, 5, 5, 10}
ar3[] = {5, 5, 10, 20}
Outptu: 5, 5
*/


#include<iostream>


using namespace std;

void findCommonIn3Array(int a1[], int n1, int a2[], int n2, int a3[], int n3)
{
    int i=0,j=0,k=0;

    // x,y and z are three indexes of three respective arrays.
    // The logic is to find the smallest number and increment the index.
    while(i<n1 && j<n2 && k<n3)
    {
        if(a1[i] == a2[j] && a2[j] == a3[k])
        {
            cout<<"Common Elements : "<<a1[i]<<endl;
            i++;
            j++;
            k++;
        }
        else if(a1[i] < a2[j]) // If x < y 
            i++;
        else if(a2[j] < a3[k]) // If y < z
            j++;
        else // z is the smallest number
            k++;
    }

}

int main()
{
    int a[]={1,3,5,7,9};
    int b[]={4,5,6,7,9};
    int c[]={2,3,4,5,6,7,8};

    int an = sizeof(a)/sizeof(a[0]);
    int bn = sizeof(b)/sizeof(b[0]);
    int cn = sizeof(c)/sizeof(c[0]);

    findCommonIn3Array(a,an,b,bn,c,cn);
}
