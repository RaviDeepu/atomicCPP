#include<iostream>

using namespace std;

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int partitionIndex = start;

    for(int i=start;i<end;++i)
    {
        if(a[i] <= pivot)
        {
            swap(&a[i],&a[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&a[partitionIndex],&a[end]);
    return partitionIndex;
    
}

void quickSort(int a[], int start, int end)
{
   if(start < end)
    {
        int pivot = partition(a,start,end);
        //cout<<"Pivot - "<<pivot<<endl;
        quickSort(a,start,pivot-1);
        quickSort(a,pivot+1,end);
    } 
}

void printArray(int a[],int size)
{
    for(int i=0;i<size;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

/*
int main()
{
    int a[]={8,5,4,9,6,3,7};
    printArray(a,7);
    cout<<"After\n";
    quickSort(a,0,6);
    
    printArray(a,7);
}
*/
