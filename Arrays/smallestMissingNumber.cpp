/*
Find the smallest missing number
Given a sorted array of n integers where each integer is in the range from 0 to m-1 and m > n. Find the smallest number that is missing from the array.

Examples
Input: {0, 1, 2, 6, 9}, n = 5, m = 10
Output: 3

Input: {4, 5, 10, 11}, n = 4, m = 12
Output: 0

Input: {0, 1, 2, 3}, n = 4, m = 5
Output: 4

Input: {0, 1, 2, 3, 4, 5, 6, 7, 10}, n = 9, m = 11
Output: 8
*/

#include<iostream>

using namespace std;

// Use Linear Search.
// If a[0] is not 0, return 0 as missing Number.
// for i=0 to n, if a[i+1] - a[i] > 1. return i+1
void smallestMissingNumber(int a[], int n)
{
    if(a[0] != 0)
    {
        cout<<"Smallest Missing Number : 0"<<endl;
        return;
    }

    for(int i=0;i<n-1;++i)
    {
        if(a[i+1] - a[i] > 1)
        {
            cout<<"Smallest Missing Number : "<<i+1<<endl;
            return;

        }
    }
}


// Use Binary Search.
// If First element is not the same as its index, then return the first index.
// If a[mid] > mid then the element lies in left helf.
// Else the element lies in right half.
int smallestMissingNumberBinaySearch(int a[], int start, int end)
{
    if(start > end)
        return end+1;

    if(a[start] != start)
        return start;

    int mid = (start+end)/2;

    if(a[mid] > mid)
        return smallestMissingNumberBinaySearch(a,start,mid);
    else
        return smallestMissingNumberBinaySearch(a,mid+1,end);
}

int main()
{
    int a[]={0, 1, 2, 3, 4, 5, 6, 7, 10};
    int size = sizeof(a)/sizeof(a[0]);  
    //smallestMissingNumber(a,size);

    cout<<"Smallest Missing Number : "<<smallestMissingNumberBinaySearch(a,0,size-1)<<endl;
}
