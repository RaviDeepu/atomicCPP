#include<iostream>

using namespace std;

// int a[] = {1,2,3,4,5};
void productArray(int a[], int n)
{
    int leftArraySum[n],rightArraySum[n];
    int prod[n];

    leftArraySum[0] = 1;
    rightArraySum[n-1] = 1;

    for(int i=1;i<n;++i)
    {
        leftArraySum[i] = leftArraySum[i-1] * a[i-1];
    }

    for(int i=n-2;i>=0;i--)
    {
        rightArraySum[i] = rightArraySum[i+1] * a[i+1];
    }


}
