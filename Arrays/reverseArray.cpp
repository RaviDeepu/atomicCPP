#include<iostream>


using namespace std;


void reverseArraySwap(int a[], int n)
{

    int start=0, end=n-1;

    while(start < end)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        ++start;
        --end;
    }
}

void reverseArrayRecursive(int a[], int start, int end)
{
    if(start >= end)
        return;
    reverseArrayRecursive(a,start+1,end-1);

    int temp = a[start];
    a[start] = a[end];
    a[end] = temp;

}

int main()
{
    int a[]={1,2,3,4,5,6,7};
    int n = sizeof(a)/sizeof(a[0]);

    reverseArraySwap(a,n);

    cout<<"Reversed Array : "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<endl;
    }

    reverseArrayRecursive(a,0,n-1);


    cout<<"Reversed Array : "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<endl;
    }

}
