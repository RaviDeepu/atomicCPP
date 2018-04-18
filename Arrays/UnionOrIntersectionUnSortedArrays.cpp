/*
Find Union and Intersection of two unsorted arrays
Given two unsorted arrays that represent two sets (elements in every array are distinct), find union and intersection of two arrays.

For example, if the input arrays are:
arr1[] = {7, 1, 5, 2, 3, 6}
arr2[] = {3, 8, 6, 20, 7}
Then your program should print Union as {1, 2, 3, 5, 6, 7, 8, 20} and Intersection as {3, 6}. Note that the elements of union and intersection can be printed in any order.
*/

// -- UNION
// Copy First Array into a temp union array, 
// Iterate second array, for every element x in second array. Search if x does not exists in first array then copy x into union array

#include<iostream>

using namespace std;

int searchArray(int a[], int n, int item)
{
    for(int i=0;i<n;++i)
    {
        if(a[i] == item)
            return 1;
    }
    return 0;
}

void printArray(int a[], int n)
{
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


void printUnion(int a[], int b[], int an, int bn)
{
    cout<<"- - - -Union- - - - \n";
    int tempUnion[an+bn];
    int index;
    for(int i=0;i<an;++i)
    {
        tempUnion[i]=a[i];
    }
    index=an;

    for(int i=0;i<bn;++i)
    {
        // Search for every element from second array in first array.
        // If item does not exist
        int itemExists=searchArray(a,an,b[i]);
        if(!itemExists)
            tempUnion[index++] = b[i];
    }

    printArray(tempUnion,index);
}

// -- INTERSECTION
// Initialize a temp intersect array.
// Iterate first array, for every element x in first array. seach if the element present is second array then copy x into intersect array

void printIntersection(int a[], int b[], int an, int bn)
{
    cout<<"- - - - INTERSECTION - - - -\n";
    int tempIntersect[an+bn];
    int index=0;
    for(int i=0;i<an;++i)
    {
        int itemExists = searchArray(b,bn,a[i]);
        if(itemExists)
            tempIntersect[index++] = a[i];
    }
        
    printArray(tempIntersect,index);
}

void unionAndIntersection(int a[], int b[], int an, int bn)
{
    printUnion(a,b,an,bn);


    printIntersection(a,b,an,bn);
}



/*

Use Searching and Sorting.
// compare the sizes m and n. Sort the smaller array.
// From the bigger array, pick element one by one and do a binary search in the larger array.
UNION - If item not presnt them print.
Intersection - If Item present then print.
*/


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
    
    for(int i=start; i<end; ++i)
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
    if(start <= end)
    {
        int pivot = partition(a,start, end);
        quickSort(a,start,pivot-1);
        quickSort(a,pivot+1,end);
    }
}

int binarySearch(int a[], int left,int right, int item)
{
    if(left <= right)
    {
        int mid = (left+right)/2;

        if(a[mid] == item)
            return a[mid];

        if(a[mid] > item)
            return binarySearch(a,left,mid-1,item);

        return binarySearch(a,mid+1,right,item);
    }
    return -1;

}


void printUnionSort(int a[], int b[], int an, int bn)
{
    cout<<"<printUnionSort"<<endl;
    // For every element in Second array, Search in First array
    for(int i=0;i<bn;++i)
    {
        if(binarySearch(a,0,an,b[i]) == -1)
            cout<<b[i]<<"\n";
    }
}


void unionAndIntersection_SearchAndSort(int a[], int b[], int an, int bn)
{
    // Make Sure the First array is smaller.
    if(an > bn)
    {
        int *tempp = a;
        a = b;
        b = tempp;

        int temp = an;
        an = bn;
        bn = temp;
    }


    /*
    cout<<"Array 1"<<endl;
    printArray(a,an);
    cout<<"Array 2"<<endl;
    printArray(b,bn);
    */

    quickSort(a,0,an);

    cout<< "- - - -UNION - - - -\n";
    printArray(a,an);
    printUnionSort(a,b,an,bn);
}

int main()
{
    int arr1[] = {7, 1, 5, 2, 3, 6};
    int arr2[] = {3, 8, 6, 20, 7};

    int an = sizeof(arr1)/sizeof(arr1[0]);
    int bn = sizeof(arr2)/sizeof(arr2[0]);

    //unionAndIntersection(arr1,arr2,an,bn);

    /*
    cout<<"Array 1"<<endl;
    printArray(arr1,an);
    cout<<"Array 2"<<endl;
    printArray(arr2,bn);
    */

    unionAndIntersection_SearchAndSort(arr1,arr2,an,bn);
}
