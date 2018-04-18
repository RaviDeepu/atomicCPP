#include<iostream>

using namespace std;


// a[]={1,2,4,6,7};
// b[]={1,2,3,5,6};

void UnionOfArray(int a[], int an, int b[], int bn)
{
    cout<<"UNIO OF TWO ARRAYS : "<<endl;
    int i=0, j=0;
    while(i<an && j<bn)
    {
        if(a[i] < b[j])
        {
            cout<<a[i]<<endl;
            i++;
        }
        else if(a[i] > b[j])
        {
            cout<<b[j]<<endl;
            j++;
        }
        else
        {
            cout<<a[i]<<endl;
            i++;
            j++;
        }
    }

    while(i < an)
    {
        cout<<a[i]<<endl;
        i++;
    }

    while(j < bn)
    {
        cout<<b[j]<<endl;
        j++;
    }
}


void interSectionOfArray(int a[], int an, int b[], int bn)
{
    cout<<"Intersection Of Two Arrays : "<<endl;
    int i=0,j=0;
    while(i<an && j<bn)
    {
        if(a[i] < b[j])
            i++;
        else if(a[i] > b[j])
            j++;
        else
        {
            cout<<a[i]<<endl;
            i++;
            j++;
        }

    }
}


int main()
{
    int a[]={1,2,3,5,7};
    int b[]={1,2,3,4,5,6,7,8};

    int an = sizeof(a)/sizeof(a[0]);
    int bn = sizeof(b)/sizeof(b[0]);

    UnionOfArray(a,an,b,bn);
    interSectionOfArray(a,an,b,bn);
}
