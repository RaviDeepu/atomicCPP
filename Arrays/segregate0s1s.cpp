#include<iostream>
#include"quickSort.cpp"

using namespace std;

void segreate0s1s(int a[], int size)
{
    int start = 0, last = size-1;
    int temp;

    while(start < last)
    {
        while(a[start] == 0)
            start++;

        while(a[last] == 1)
            last--;

        if(start < last)
        {   
            temp = a[start];
            a[start] = a[last];
            a[last] = temp;
            start++;
            last--;
                        
        }
    }
}   


int main()
{
    int a[] = {1,0,0,1,0,1,1,1,1,0};
    int size = sizeof(a)/sizeof(a[0]);

    printArray(a,size);
    segreate0s1s(a,size);
    printArray(a,size);
}
