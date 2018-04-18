/*
Find a triplet that sum to a given value
Given an array and a value, find if there is a triplet in array whose sum is equal to the given value. If there is such a triplet present in array, then print the triplet and return true. Else return false. For example, if the given array is {12, 3, 4, 1, 6, 9} and given sum is 24, then there is a triplet (12, 3 and 9) present in array whose sum is 24.

*/



#include<iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int start, int end)
{
    int partitionIndex = start;
    int pivot = a[end];

    for(int i=start;i<end;++i)
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


int quickSort(int a[], int start, int end)
{
    if(start < end)
    {
        int pivot = partition(a,start,end);
        quickSort(a,start,pivot-1);
        quickSort(a,pivot+1,end);
    }
}

void tripletsInArray(int a[], int n, int sum)
{
    int l=0,r=n-1;
    int curSum=0;
    for(int i=0;i<n-2;++i)
    {
        l=i+1;
        r=n-1;
        while(l < r)
        {
            if(a[i] + a[l] + a[r] == sum)
            {
                cout<<"Triplets are : "<<a[i]<<" , "<<a[l]<<" , "<<a[r]<<endl;
                return;
            }
            else if(a[i]+a[l]+a[r] < sum)
            {
                l++;
            }
            else
                r--;
        }
    }
}

int main()
{
    int a[]={9,1,3,7,4,5,8,6};
    int size = sizeof(a)/sizeof(a[0]);

    quickSort(a,0,size-1);

    for(int i=0;i<size;++i)
    {
        cout<<a[i]<<endl;
    }

    tripletsInArray(a,size,14);
}
