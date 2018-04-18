#include<iostream>

using namespace std;
void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

// Pick Last element as Pivot.
// Check if any other element is less than Pivot, then swap it with pivot.
int partition(int a[], int start, int end)
{
    cout<<"Start : "<<start<<", End : "<<end<<endl;
    int pivot = a[end];
    int partitionIndex = start;
    for(int i=start; i<	end ; ++i)
    {
        if(a[i] <= pivot)
        {
            // Swap i and partitionIndex
            swap(&a[i],&a[partitionIndex]);
            partitionIndex++;
        }
    }
    // Swap partitionIndex and end
    swap(&a[partitionIndex],&a[end]);

    return partitionIndex;
}

int quicksort(int a[], int start, int end)
{
    if(start <= end)
    {
        int pivot = partition(a,start,end);
        cout<<"Pivot : "<<pivot<<endl;
        quicksort(a,start,pivot-1);
        quicksort(a,pivot+1,end);
    }
}


int main()
{
    int a[]={7,6,5,4,3,2,1,0};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<"Size : "<<size<<endl;
    quicksort(a,0,size-1);
    cout<<"Done\n";
    for(int i=0 ; i<size;i++)
    {
        cout<<a[i]<<endl;
    }
}
