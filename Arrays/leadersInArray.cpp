#include<iostream>

using namespace std;

void printLeadersInArray(int a[], int n)
{
    int maxTillNow = a[n-1];
    cout<<a[n-1]<<" ";
    for(int i=n-2;i>=0;i--)
    {
        if(a[i] > maxTillNow)
        {
            cout<<a[i]<<" ";
            maxTillNow = a[i];
        }
    }

}

int main()
{
    int a[]={20,16,17,4,3,5,2};
    int size = sizeof(a)/sizeof(a[0]);

    printLeadersInArray(a,size);

}
