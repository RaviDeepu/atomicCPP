/*
Given an array arr[], find the maximum j . i such that arr[j] > arr[i]
Given an array arr[], find the maximum j . i such that arr[j] > arr[i].

Examples:

Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output: 6  (j = 7, i = 1)

Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
Output: 8 ( j = 8, i = 0)

Input:  {1, 2, 3, 4, 5, 6}
Output: 5  (j = 5, i = 0)

Input:  {6, 5, 4, 3, 2, 1}
Output: -1 
*/


#include<iostream>


using namespace std;

// Use Two loops.
// In the Outer Loop, traverse from left to right. i
// In the Inner loop, traverse from right to left, j . If a[j] > a[i] then calculate the maximumDiffIndex and update.

int maxDiffIndex(int a[], int n)
{
    int maxDiff = -1;
    for(int i=0;i<n;++i)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(a[j] > a[i] && maxDiff > (j-i))
                maxDiff = j-i;
        }
    }
    return maxDiff;
}

int main()
{
    int a[]={34, 8, 10, 3, 2, 80, 30, 33, 1};
    int size = sizeof(a)/sizeof(a[0]);

    cout<<"Max Diff : "<<maxDiffIndex(a,size)<<endl;
}
