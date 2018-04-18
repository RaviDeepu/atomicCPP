#include<iostream>
#include "quickSort.cpp"



/*
void checkPair(int a[], int size, int x)
{
    quickSort(a,0,size);
    printArray(a,size);    

    int left=0,right=size;
    while(left < right)
    {
        int sum = a[left]+a[right];
        if(sum == x)
            cout<<a[left]<<" "<<a[right]<<endl;
        if(x > sum)
            left++;
        else
            right--;
    }
}
*/

void checkPair(int a[], int size, int x)
{
    int hashMap[1000]={0};
    
    for(int i=0;i<size;++i)
    {
        if(hashMap[x-a[i]])
            cout<<x-a[i]<<" "<<a[i]<<endl;
        else
            hashMap[a[i]] = 1;
    }
}


int main()
{
    int a[]={3,2,1,5,7,9,6};
    checkPair(a,6,7);
}

