#include<iostream>
#include"quickSort.cpp"
using namespace std;


int searchInSortedPivotedArray(int a[], int low,int high,int key)
{

    if(low > high)
        return -1;
    
   int mid = (low+high)/2;
       
   cout<<"Low - "<<a[low]<<", Mid - "<<a[mid]<<", High - "<<a[high]<<endl;

   if(a[mid] == key)
      return a[mid];

    // If Array[low....mid] is sorted
    if(a[low] <= a[mid])
    {
        if(key > a[low] && key < a[mid])
            return searchInSortedPivotedArray(a,low,mid-1,key);

        return searchInSortedPivotedArray(a,mid+1,high,key);
    }

    // Array[low....mid] is not sorted.
    // So, the Array[mid+1......high] must be sorted.
    if(key > a[mid] && key < a[high])
        return searchInSortedPivotedArray(a,mid+1,high,key); 

    return searchInSortedPivotedArray(a,low,mid-1,key);
}
int main()
{
    int a[]={3,4,5,6,1,2};
    int size = sizeof(a)/sizeof(a[0]);

    int item;

    while(1)
    {
        printArray(a,size);
        cout<<"Enter the Item To be searched : "<<endl;
        cin>>item;
        cout<<"Got : "<<searchInSortedPivotedArray(a,0,size-1,item)<<endl;
    }
}
