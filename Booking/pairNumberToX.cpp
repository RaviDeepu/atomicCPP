#include<iostream>
#include<unordered_map>

using namespace std;

void printArray(int *a, int size)
{
    for(int i=0 ; i<size ; ++i)
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


int findPivot(int *a, int start, int end)
{
    int pivot = a[end];
    int partitionIndex = start;

    for(int i=start ; i<end ; ++i)
    {
//        cout<<"a[i] : "<<a[i]<<" , pivot - "<<pivot<<endl;
        if(a[i] <= pivot)
        {
            swap(&a[i],&a[partitionIndex]);
            partitionIndex++;
        }
    }

    swap(&a[end],&a[partitionIndex]);
    return partitionIndex;
}


void quickSort(int *a, int start, int end)
{
    if(start <= end)
    {
        int pivot = findPivot(a,start,end);
        quickSort(a,start,pivot-1);
        quickSort(a,pivot+1,end);
    }
}

void printPairToX(int* a, int size, int sum)
{
    int start = 0;
    int end = size-1;


    quickSort(a,start,end);
    printArray(a,size);


    int i=0,j=size-1;

    while(i < j)
    {
        int tSum = a[i] + a[j];
        if(tSum == sum)
        {
            cout<<a[i]<<" + "<<a[j]<<endl;
        }

        if(tSum < sum)
            i++;
        else
            j--;
    }

}



// Pair Number to x using hash set.

void pairNumberToXHashing(int *a, int size, int sum)
{
    unordered_map<int, int> map;
    for(int i=0 ; i<size; ++i)
    {
        cout<<sum-a[i]<<endl;

        if(map[sum-a[i]] == 1)
        {
            cout<<sum-a[i]<<" + "<<a[i]<<endl;
        }
        else
        {
            map[a[i]]=1;
        }
    }
}

int main()
{
    int a[]={7,1,5,9,3,6,2,4};

    int size = sizeof(a)/sizeof(a[0]);

    printArray(a,size);

    int sum = 8;
    pairNumberToXHashing(a,size,sum);

}
