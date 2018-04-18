/*
Find the minimum distance between two numbers
Given an unsorted array arr[] and two numbers x and y, find the minimum distance between x and y in arr[]. The array might also contain duplicates. You may assume that both x and y are different and present in arr[].
*/


#include<iostream>
#include <stdlib.h> // for abs()
#include <limits.h> // for INT_MAX
using namespace std;

/*
    Use Two Loops.
    In the outer loop, pick one element i
    In the inner loop traverse from i+1, compare if both the element matches and i-j < minDistance.
*/
int minimumDistance_UsingTwoLoops(int a[], int n, int x, int y)
{
    int minDistance=INT_MAX;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if((a[i] == x && a[j] == y || a[i] == y && a[j] == x) && abs(i-j) < minDistance)
            {
                minDistance = abs(i-j);
            }
        }
    }
    return minDistance;
}

/*
    Tricky Solution.
    Traverse an array and search for x or y, If found mark the index as prev.
    Now search for other element from prev index.
    If found then compute the minimum distance.
*/

int minDistance_Tricky(int a[], int n, int x, int y)
{
    int minDistance = INT_MAX;
    int prev=0;
    int i;
    for(i=0;i<n;++i)
    {
        if(a[i] == x || a[i] == y)
        {
            prev = i;
            break;
        }
    }

    for(;i<n;++i)
    {
        if(a[i] == x || a[i] == y)
        {
            if(a[i] != a[prev] && (i-prev) < minDistance)
            {
                minDistance = i - prev;
                prev = i;
            }
        }
    }

    return minDistance;
}


/* Driver program to test above fnction */
int main() 
{
    int arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int y = 6;
                     
    cout<<"Minimum distance between "<<x<<" and "<<y<<" = "<<minimumDistance_UsingTwoLoops(arr, n, x, y)<<endl;

    cout<<"Minimum distance between "<<x<<" and "<<y<<" = "<<minDistance_Tricky(arr, n, x, y)<<endl;
    return 0;
}











