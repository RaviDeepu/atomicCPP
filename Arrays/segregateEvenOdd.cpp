//  Segregate Even and Odd numbers

#include<iostream>
//#include "printArray.hpp"
using namespace std;

void displayArrayValues(int a[],int size);


void segregateEvenOdd(int a[], int n)
{
    int i=0,j=n-1;

    while( i < j )
    {
        while((a[i]%2 == 0) && i < j)
            i++;
        while((a[j]%2 == 1) && i < j)
            j--;

        if(i<j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
}

void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }

}

int main()
{
    int a[]={1,2,3,4,5,6,7,8};
    int size = sizeof(a)/sizeof(a[0]);
    segregateEvenOdd(a,size);

    displayArrayValues(a,size);
}
