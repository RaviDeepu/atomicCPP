#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

void printArray(int *a, int n)
{
    for(int i=0 ; i<n ; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int findPivot(int a[], int start, int end)
{
    int partitionIndex=start;
    int pivot = a[end];

    for(int i=start ; i<end ; ++i)//while(start < end)
    {
        if(a[i] <= pivot)
        {
            swap(&a[i], &a[partitionIndex]);

            //start++;
            partitionIndex++;
        }
        //start++;
    }

    swap(&a[end],&a[partitionIndex]);

    return partitionIndex;

}

void quickSort(int a[], int start, int end)
{
    if(start < end)
    {
        int pivot = findPivot(a,start,end);

        cout<<"Pivot - "<<pivot<<endl;

        quickSort(a,start,pivot-1);
        quickSort(a,pivot+1,end);
    }
}

// Using Sorting method
void checkPairsWithSum(int a[], int n, int sum)
{
    quickSort(a,0,n-1);

    printArray(a,n);


    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";

    cout<<endl;

    int l=0,r=n-1;
    while(l<r)
    {   
        int tSum = a[l]+a[r];

        if(tSum == sum)
        {
            cout<<a[l]<<" "<<a[r]<<" = "<<sum<<endl;
            return;
        }

        if(tSum > sum)
            r--;
        else if(tSum < sum)
            l++;
    }
}

int main()
{
    int a[20] = {2,6,3,5,9,4,1,15,12,16};
    int n = 10;
    int sum = 5;


    checkPairsWithSum(a,n,sum);

    /*
    while(1)
    {
        cout<<"Enter Number of elements in an Array\n";
        cin>>n;


        cout<<"Enter Array Elements\n";
        for(int i=0;i<n;++i)
            cin>>a[i];

        cout<<"Enter the sum to be searched in array\n";
        cin>>sum;

        checkPairsWithSum(a,n,sum);
    }
    */
}
