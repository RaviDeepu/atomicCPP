#include<iostream>

using namespace std;

void quickSort(int a[], int left, int right)
{
        int i = left, j = right;
        int pivot = a[(left+right)/2];
        while( i <= j )
        {
           while( a[i] < pivot )
               i++;
           while(a[j] > pivot)
               j--;
            if( i<=j )
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        }

        if(left < j)
            quickSort(a,left,j);
        if(i < right)
            quickSort(a,i,right);
}


int main()
{
    int ar[]={5,6,2,3,7,8,9};

    quickSort(ar,0,6);

    for(int i=0;i<7;++i)
    {
        cout<<ar[i]<<endl;
    }
}

