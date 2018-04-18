#include<iostream>
#define MAX_COUNT 1000

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

    for(int i=start ; i<end ; ++i)
    {
        if(a[i] <= pivot)
        {
            // Swap partitionIndex and i
            swap(&a[i], &a[partitionIndex]);
            partitionIndex++;
        }
    }

    // Swap partitionIndex and end.
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


void printPairsSorting(int a[], int size, int sum)
{
    cout<<"Array : "<<endl;
    for(int k=0;k<size;k++)
    {
        cout<<a[k]<<endl;
    }
    int i=0, j=size-1;
    while(i < j)
    {
        //cout<<"i,j : "<<i<<","<<j<<endl;
        //cout<<"a[i],a[j] : "<<a[i]<<","<<a[j]<<endl;
        if(a[i] + a[j] == sum)
        {
            cout<<"Pairs Found : "<<a[i]<<","<<a[j]<<" = "<<sum<<endl;
            i++;
            //break;
        }
        else if(a[i] + a[j] < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

void printPairHash(int a[], int size, int sum)
{
    int binMap[MAX_COUNT]={0};
    for(int i=0;i<size;++i)
    {
        int temp = sum - a[i];
        if(temp > 0 && binMap[temp] == 1)
        {
            cout<<"Pair : "<<a[i]<<","<<temp<<endl;
        }
        binMap[a[i]]=1;
    }
}


int main()
{
    int a[]={1,4,45,6,10,12};
    int sum = 16;
    int arr_size = sizeof(a)/sizeof(a[0]);
    cout<<"Array SIze : "<<arr_size<<endl;
    quickSort(a,0,arr_size-1);
    cout<<"Sorted Array\n";
    for(int i=0;i<arr_size;i++)
    {
        cout<<a[i]<<endl;
    }

    cout<<"Array SIze : "<<arr_size<<endl;
    printPairsSorting(a,arr_size,sum);

    int ai[]={1,4,45,6,10,12};
    printPairHash(ai,arr_size,sum);
}

