/*
Find a sorted subsequence of size 3 in linear time
Given an array of n integers, find the 3 elements such that a[i] < a[j] < a[k] and i < j < k in 0(n) time. If there are multiple such triplets, then print any one of them.

Examples:

Input:  arr[] = {12, 11, 10, 5, 6, 2, 30}
Output: 5, 6, 30

Input:  arr[] = {1, 2, 3, 4}
Output: 1, 2, 3 OR 1, 2, 4 OR 2, 3, 4

Input:  arr[] = {4, 3, 2, 1}
Output: No such triplet
Source: Amazon Interview Question

Hint: Use Auxiliary Space

Solution:
1) Create an auxiliary array smaller[0..n-1]. smaller[i] should store the index of a number which is smaller than arr[i] and is on left side of arr[i]. smaller[i] should contain -1 if there is no such element.
2) Create another auxiliary array greater[0..n-1]. greater[i] should store the index of a number which is greater than arr[i] and is on right side of arr[i]. greater[i] should contain -1 if there is no such element.
3) Finally traverse both smaller[] and greater[] and find the index i for which both smaller[i] and greater[i] are not -1.

*/

#include<iostream>

using namespace std;


void find3Numbers(int a[], int n)
{
    int smaller[n],greater[n];
    int max=n-1,min=0;

    smaller[0]=-1;
    // Create Smaller arrray. It stores the index of smaller element in the left side of a[i].
    for(int i=1;i<n;++i)
    {
        if(a[min] <= a[i])
        {
            smaller[i] = min;
        }
        else
        {
            min = i;
            smaller[i]=-1;
        }
    }

    greater[n-1]=-1;
    // Create a greater array. It stores the index of greater element in the right side of a[i]
    for(int i=n-2;i>=0;i--)
    {
        if(a[max] >= a[i])
        {
            greater[i]=max;
        }
        else
        {
            max=i;
            greater[i]=-1;
        }
    }

    for(int i=0;i<n;++i)
    {
        if(smaller[i] != -1 && greater[i] != -1)
        {
            cout<<a[smaller[i]]<<" , "<<a[i]<<" , "<<a[greater[i]]<<endl;
        }
    }
}


int main()
{
    int arr[] = {12, 11, 10, 5, 6, 2, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    find3Numbers(arr, n);

    return 0;
}
