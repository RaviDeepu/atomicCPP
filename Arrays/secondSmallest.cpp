#include<iostream>
#include<limits.h>

using namespace std;

void secondSmallest(int a[], int n)
{
    int small,secondSmall;
    small = secondSmall = INT_MAX;

    for(int i=0;i<n;++i)
    {
        if(a[i] < small)
        {
            secondSmall = small;
            small = a[i];
        }
        else if(a[i] < secondSmall && a[i] != small)
        {
            secondSmall = a[i];
        }
    }

    cout<<"Small - "<<small<<" ---- SecondSmall - "<<secondSmall<<endl;

}

int main()
{
    int a[]={1,16,17,4,3,5,2};
    int size = sizeof(a)/sizeof(a[0]);

    secondSmallest(a,size);
}
