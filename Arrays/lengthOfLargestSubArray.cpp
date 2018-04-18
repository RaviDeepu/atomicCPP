/*
Length of the largest subarray with contiguous elements | Set 1
Given an array of distinct integers, find length of the longest subarray which contains numbers that can be arranged in a continuous sequence.

Input:  arr[] = {14, 12, 11, 20};
Output: Length of the longest contiguous subarray is 2

*/

#include<iostream>

using namespace std;

int getMin(int a, int b)
{
    return a < b ? a:b;
}

int getMax(int a, int b)
{
    return a > b ? a:b;
}

/*
    The below algorithm works fine for distinct integers.
*/
int lengthOfLargestSubArray(int *a, int n)
{
    int min,max,maxLength=0;
    for(int i=0;i<n;++i)
    {
        min = a[i];
        max = a[i];
        cout<<"Max : "<<max<<", Min : "<<min<<endl;
        for(int j=i+1;j<n;++j)
        {
            min = getMin(min, a[j]);
            max = getMax(max, a[j]);
            cout<<"     Max : "<<max<<", Min : "<<min<<endl;
            if((max-min) == (j-i))
            {
                maxLength = getMax(maxLength,j-i+1);
                cout<<"Max Length : "<<maxLength<<endl;
            }
        }
    }
    return maxLength;
}

/*
    For duplicate elements we must use a Set to ignore the duplicate elements and use the same above algorithm.
*/
int main()
{
    int a[]={14, 12, 11, 20};
    int size = sizeof(a)/sizeof(a[0]);

    cout<<"Length of the largest SubArray : "<<lengthOfLargestSubArray(a,size)<<endl;
    return 0;
}
