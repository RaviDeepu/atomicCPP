#include<iostream>


using namespace std;


void numberOccurOddTimes(int a[], int size)
{
    int res = 0;

    for(int i=0;i<size;++i)
    {
        res = res ^ a[i];
    }
    cout<<"Number Occuring Odd Times : "<<res<<endl;
}


int main()
{
    int a[]={1,2,3,2,3};
    int n = sizeof(a)/sizeof(a[0]);

    numberOccurOddTimes(a,n);
}


