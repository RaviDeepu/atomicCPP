#include<iostream>
#include"quickSort.cpp"

using namespace std;



void reverseArray(int a[], int n)
{
    int i=0;
    int j=n-1;
    int temp;

    while(i < j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}


// Reverse Array - Recursive;

void reverseArray_Recursive(int a[], int start, int end)
{
    int temp;
    if(start >= end)
        return;
    temp = a[start];
    a[start] = a[end];
    a[end] = temp;
    
    reverseArray_Recursive(a, start+1, end-1);
}

int main()
{
    int a[]={1,2,3,4,5,6};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<"Before : ";
    printArray(a,size);

    reverseArray_Recursive(a,0,size-1);

    cout<<"After Reverse : ";
    printArray(a,size);
}
