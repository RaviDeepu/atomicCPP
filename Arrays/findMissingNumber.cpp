#include<iostream>


using namespace std;


void findMissingNumber(int a[], int n)
{
    int total = (n+1)*(n+2)/2;
    for(int x=0;x<n;++x)
    {
        total = total-a[x];
    }
    cout<<"Missing Number - "<<total<<endl;
}


int main()
{
    int a[] = {1,2,3,5,6};
    int size = sizeof(a)/sizeof(a[0]);
    
    findMissingNumber(a,size);
}
