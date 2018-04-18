//Maximum difference between two elements such that larger element appears after the smaller number

#include<iostream>
//#include "printArray.hpp"

using namespace std;


// a[]={2, 3, 10, 6, 4, 8, 1}


// Using two loops.
int maxDiffFunc(int a[], int n)
{
    int maxDiff = a[1] - a[0];

    for(int i=0 ; i<n ; ++i)
    {
        for(int j=i+1 ; j<n ; ++j)
        {
            if(a[j] - a[i] > maxDiff)
                maxDiff = a[j] - a[i];
        }
    }
    return maxDiff;
}


int maxDifference_UsingOneLoop(int a[], int n)
{
    int maxDiff = a[1] - a[0];
    int minValue = a[0];

    for(int i=1;i<n;i++)
    {
        if(a[i] - minValue > maxDiff)
            maxDiff = a[i]-minValue;

        if(a[i] < minValue)
            minValue = a[i];
    }
    return maxDiff;
}

int main()
{
    int a[]={2,3,10,6,4,8,11};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<"Max Diff : "<<maxDiffFunc(a,size)<<endl;


    cout<<"Max Diff One Loop : "<<maxDifference_UsingOneLoop(a,size)<<endl;
}
