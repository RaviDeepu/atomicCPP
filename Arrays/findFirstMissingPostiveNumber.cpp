#include<iostream>
#include<stdlib.h>

using namespace std;

// To find the first missing positive number. 
// If the element is x, then change the value of x to negative.
// Search for the first positive number and return the index.

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}



int segregate(int a[], int n)
{
    int positiveStartIndex=0;
    for(int i=0;i<n;++i)
    {
        if(a[i] <= 0)
        {
            swap(&a[i],&a[positiveStartIndex]);
            positiveStartIndex++;
        }
    }
    return positiveStartIndex;
}


void findMissingPositiveNumber(int *a, int n)
{
    for(int i=0;i<n;++i)
    {
        // First Condition is to check for the value not more than size.
        // Second condition is to check for the positive number.
        if(abs(a[i]) - 1 < n && a[abs(a[i]) - 1] > 0)
        {
            // Pick the element as index and change the value of that index.
            a[abs(a[i])-1] = -a[abs(a[i])-1];
        }

    }

    // First Positive index is the missing number.
    for(int i=0;i<n;++i)
    {
        if(a[i] > 0)
        {
            cout<<"Missing Positive Number is : "<<i+1<<endl;
        }
    }

    cout<<"Missing Positive Number is : "<<n+1<<endl;
}


/*
    Linear Search for numbers form 1 to n
*/

bool search(int a[], int size, int n)
{
    int i;
    cout<<"Search : "<<n<<endl;
    for(i=0;i<size;++i)
    {
        cout<<"Array : "<<a[i]<<endl;
        if(a[i] > 0 && n == a[i])
            return true;
    }
    //cout<<"Returning False : "<<a[i]<<endl;
    return false;
}


void findMissingNumber(int *a, int n)
{
    bool found;
    int count=1;
    for(int i=0;i<n;++i)
    {        
        if(!search(a,n,count++))
            cout<<"Missing Element : "<<count-1<<endl;
    }
}


int main()
{
    int a[]={2,3,6,8,1};
    int size = sizeof(a)/sizeof(a[0]);

    //int positiveStartIndex = segregate(a,size);
    
    //findMissingPositiveNumber(a+positiveStartIndex,size-positiveStartIndex);
    findMissingNumber(a,size);

}
