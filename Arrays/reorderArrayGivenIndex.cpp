
/*
Reorder an array according to given indexes
Given two integer arrays of same size, .arr[]. and .index[]., reorder elements in .arr[]. according to given index array. It is not allowed to given array arr.s length.

Example:

Input:  arr[]   = [10, 11, 12];
        index[] = [1, 0, 2];
        Output: arr[]   = [11, 10, 12]
                index[] = [0,  1,  2] 

                Input:  arr[]   = [50, 40, 70, 60, 90]
                        index[] = [3,  0,  4,  1,  2]
                        Output: arr[]   = [40, 60, 90, 50, 70]
                                index[] = [0,  1,  2,  3,   4] 
                                Expected time complexity O(n) and auxiliary space O(1)
*/



#include<iostream>

using namespace std;


/*
    index[i] = a[i].
    a[i] must store the value from index[i]
    Take a temp array.
    Values in the temp array will be correct values at correct positions
    Take index from index array and respective item from a store it in temp.
    temp[index[i]] = a[i]
    
    Copy from temp array and put it in a.

*/


void printArray(int a[], int n)
{
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}



void reorderArray(int a[], int index[], int n)
{
    int temp[n];

    for(int i=0;i<n;++i)
    {
        temp[index[i]] = a[i];
    }

    for(int i=0;i<n;++i)
    {
        a[i] = temp[i];
        index[i]=i;
    }
}

/*
*/
void reorderArray()

int main()
{
    int a[]={50,40,70,60,90};
    int index[]={3,0,4,1,2};

    int size = sizeof(a)/sizeof(a[0]);

    cout<<"Original Array : "<<endl;
    printArray(a,size);
    cout<<"Index Array : "<<endl;
    printArray(index,size);
    reorderArray(a,index,size);

    
    cout<<"Modified Array "<<endl;
    printArray(a,size);
    cout<<"Index Array : "<<endl;
    printArray(index,size);
}
