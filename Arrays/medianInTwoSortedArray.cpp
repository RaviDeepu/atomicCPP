#include<iostream>
#include"quickSort.cpp"

using namespace std;


/*
Following are the steps to be followed to get median in two sorted arrays

1. Get the median of Two sorted arrays, say m1 & m2.
2. If m1 == m2, then return either m1 or m2
3. if m1 > m2, then the median will be between a1[....m1] to a2[m2.....]
4. If m1 < m2, then a1[m1......] to a2[......m2].
5. if n ==2 then, return (max(a1[0],a2[0]) + min(a1[1],a2[1])) / 2
*/

int median(int a[], int n)
{
    if(n%2 == 0)
        return (a[n/2]+a[n/2-1])/2;
    else
        return a[n/2];
}

int getMedian(int a1[], int a2[], int n)
{
    if(n <= 0)
        return -1;
    if(n == 1)
        return (a1[0]+a2[0])/2;

    cout<<"Array 1 "<<endl;
    printArray(a1,n);
    
    cout<<"Array 2 "<<endl;
    printArray(a2,n);

    if(n == 2)
        return (max(a1[0],a2[0]) + min(a1[1],a2[1]))/2;
    
    
    int m1 = median(a1,n);
    int m2 = median(a2,n);

    cout<<"Median 1 - "<<m1<<", Median 2 - "<<m2<<endl;    

    if(m1 == m2)
        return m1;

    // If m1 < m2 then the median will be between a1[m1.....] and a2[......m2];
    if(m1 < m2)
    {
        if(n%2 == 0)
            return getMedian(a1+n/2-1,a2,n-n/2+1);
        
        return getMedian(a1+n/2,a2,n-n/2);
    }

    /*
        If m1 > m2 then the median of two sorted arrays will be between a1[....m1] and a2[m2.....]
    */
    if(n%2 == 0)
        return getMedian(a2+n/2-1,a1,n-n/2+1);
    
    return getMedian(a2+n/2,a1,n-n/2);
}


int main()
{
    int a1[] = {1,2,3,6};
    int a2[] = {4,6,8,10};

    int n = 4;

    cout<<"Median of Two Sorted arrays - "<<getMedian(a1,a2,n)<<endl;
}
