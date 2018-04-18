#include<iostream>

using namespace std;

// a[] = {1,2,3,3,3,3,4};
// Check for majority element using Linear Search. 
// An item is majority if it is present in i and i+n/2 position. 


void majorityElement_LinearSearch(int a[], int size, int item)
{
    int midIndex = (size%2)?((size/2)+1):size/2;
    
    for(int i=0 ; i<midIndex ; ++i)
    {
        if(a[i] == item && a[i+(size/2)] == item)
        {
            cout<<"Majority Element : "<<a[i]<<endl;
        }
    }
}


// Using Binary Search.

// Function to return the first index of item.
int _binarySearch(int a[], int low, int high, int item)
{
    if(low <= high)
    {
        int mid = (low+high)/2;
        
        if(((mid == 0) || item > a[mid-1]) && (a[mid] == item))
            return mid;
        else if(item > a[mid])
            return _binarySearch(a,mid+1,high,item);
        else
            return _binarySearch(a,low,mid-1,item);
    }
    return -1;
}


void isMajority(int a[], int size, int item)
{
    // Find first occurence of item in a[].
    int index = _binarySearch(a,0,size-1,item);

    if(index == -1)
    {

        cout<<"No Majority Elelement : "<<endl;
        return;
    }

    // We have the first index of item.
    // We need to chec k if the item exists in index+n/2 position.
    if(((index+(size/2)) <= (size-1)) && a[index+(size/2)] == item)
    {
        cout<<"Majority Element : "<<a[index]<<endl;
    }
    else
    {
        cout<<"No Majority Elelement : "<<endl;
    }
}


int main()
{
    int a[]={1,2,3,3,3,3,4};

    int size = sizeof(a)/sizeof(a[0]);

    cout<<"Using Linear Search : "<<endl;
    majorityElement_LinearSearch(a,size,4);


    cout<<"Using Binary Search : "<<endl;
    isMajority(a,size,4);
}
