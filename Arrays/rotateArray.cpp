#include<iostream>
#include"quickSort.cpp"

using namespace std;

void rotateArrayRight(int a[], int size)
{
    int last = a[size-1];
    //int next;
    for(int i=size-1;i>0;--i)
    {
        a[i] = a[i-1];
    }
    a[0] = last; 
}

void rotateArrayLeft(int a[], int size)
{
    int first = a[0];
    for(int i=0;i<size-1;i++)
        a[i] = a[i+1];

    a[size-1] = first;
}


void rotateArrayUtil(int a[], int size, int d)
{
    for(int i=0;i<d;++i)
        rotateArrayLeft(a,size);
}

/*
    Reverse (a,0,d)
    Reverse (a,d+1,n)
    Reverse (a,0,n)
*/

void reverse(int a[], int start, int end)
{
    if(start >= end)
        return;

    int temp;
    while(start < end)
    {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

void rotateArrayReversal(int a[], int size, int d)
{
    reverse(a,0,d);
    reverse()
}

int main()
{
    int a[] = {3,4,5,6,1,2};
    int size = sizeof(a)/sizeof(a[0]);
    int d;
    cout<<"Enter Rotation Index : "<<endl;
    cin>>d;
    printArray(a,size);
    rotateArrayUtil(a,size,d);
    printArray(a,size);
}
