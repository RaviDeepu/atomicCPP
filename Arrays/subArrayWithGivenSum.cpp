/*
Find subarray with given sum
Given an unsorted array of nonnegative integers, find a continous subarray which adds to a given number.


Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Ouptut: Sum found between indexes 2 and 4

*/

#include<iostream>

using namespace std;

/*
    Use two loops, pick an element in the first loop.
    the outer loop picks a starting point i and the inner loop tries all subarrays starting from i.
*/
void subArray_TwoLoops(int a[], int n, int sum)
{
    int cur_sum=0;
    for(int i=0;i<n;++i)
    {
        cur_sum = a[i];
        for(int j=i+1;j<n;++j)
        {
            if(cur_sum == sum)
            {
                cout<<"SubArray is present between index : "<<i<<" and "<<j-1<<endl;
                return;
            }
    
            if(cur_sum > sum)
                break;
            cur_sum = cur_sum + a[j];
        }
    }
    cout<<"Sub Array Not Found "<<endl;
}

void subArray_TwoIndex(int a[], int n, int sum)
{
    int start=0;
    int curSum=a[0];
    for(int i=1;i<n;++i)
    {
        while(curSum > sum && start < i-1)
        {
            curSum = curSum-a[start];
            start++;
        }

        if(curSum == sum)
        {
            cout<<"SubArray is present between index : "<<start<<" and "<<i-1<<endl;
            return;
        }

        curSum = curSum + a[i];
    }
    cout<<"Sub Array Not Found "<<endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int start, int end)
{
    int partitionIndex = start;
    int i,j;

    int pivot = a[end];

    for(int i=start; i<=end; ++i)
    {
        if(a[i] < pivot)
        {
            swap(&a[i],&a[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&a[partitionIndex], &a[end]);
    return partitionIndex;
}


void quickSort(int a[], int start, int end)
{
    if(start <= end)
    {
        int pivot = partition(a,start,end);
        quickSort(a,start,pivot-1);
        quickSort(a,pivot+1,end);
    }
}


// Driver program to test above function
int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 23;
    
    subArray_TwoLoops(arr, n, sum);
    subArray_TwoIndex(arr,n,sum);

    quickSort(arr,0,n-1);

    cout<<"Array Elements : "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}

