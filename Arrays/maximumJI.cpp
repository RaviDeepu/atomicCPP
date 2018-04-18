//Given an array arr[], find the maximum j . i such that arr[j] > arr[i]
/*
  Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
  Output: 6  (j = 7, i = 1)
*/
#include<iostream>


using namespace std;

/*
    Initialize maxDiff variable
    Use Two loops.
    In outer loop traverse from left and pick leftElement.
    In Inner loop traverse from right say rightElement till leftElement.
    If rightElement is greater than leftElement and maxDiff is smaller, update maxDiff.
*/
int maxDiff_UsingLoop(int a[], int size)
{
    int maxDiff = -1;
    for(int i=0;i<size;++i)
    {
        for(int j=size-1;j>i;j--)
        {
            if(a[j] > a[i] && maxDiff < (j-i))
            {
                maxDiff = j-i;
            }
        }
    }
    return maxDiff;
}


/*
    Tricky
    Use Two Arrays, leftMin will hold all elements smaller than a[i] in the left
    rightMax will hold all elements greater than a[i] towards right.
    
    If leftMin[i] > rightMax[j], we need to ignore , move i+1. Because leftMin must freater than rightMax.

*/

int getMin(int i, int j)
{
    return i < j ? i:j;
}

int getMax(int i, int j)
{
    return i > j ? i:j;
}

int maxDiff_Tricky(int a[], int n)
{
    int maxDiff = -1;
    int LMin[n], RMax[n];

    LMin[0] = a[0];
    for(int i=1;i<n;++i)
        LMin[i] = getMin(a[i],LMin[i-1]);

    RMax[n-1] = a[n-1];
    for(int j=n-2;j>=0;j--)
        RMax[j] = getMax(a[j],RMax[j+1]);

    int i=0,j=0;
    while(i<n && j<n)
    {
        if(LMin[i] < RMax[j])
        {
            maxDiff = getMax(maxDiff,(j-i));
            j = j+1;
        }
        else
            i = i+1;
    }
    return maxDiff;
}


int main()
{
    int a[]={34,8,10,3,2,80,30,33,1};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"Maximum j-1 Diff : "<<maxDiff_UsingLoop(a,n)<<endl;

    cout<<"Maximum j-1 Diff : "<<maxDiff_Tricky(a,n)<<endl;

}
