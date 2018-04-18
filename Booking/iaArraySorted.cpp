#include<iostream>



using namespace std;

bool isSorted(int a[], int n)
{
    bool sorted=true;

    int diff = a[1] - a[0];
    bool ascending=false,descending=false;

    if(diff > 0)
        ascending = true;
    else
        descending = true;

    if(ascending)
    {
        for(int i=0 ; i<n-1 ; ++i)
        {
            if(a[i] > a[i+1] )
            {
                sorted = false;
                break;
            }
        }
    }
    else if(descending)
    {
        for(int i=0 ; i<n-1 ; ++i)
        {
            if(a[i] < a[i+1] )
            {
                sorted = false;
                break;
            }
        }

    }

    return sorted;
    
}


int main()
{
    int n;
    int a[100];

    while(1)
    {
        cout<<"Enter n\n";
        cin>>n;

        cout<<"Enter Array Elements\n";
        for(int i=0 ; i<n ; ++i)
        {
            cin>>a[i];
        }

        if(isSorted(a,n))
            cout<<"Yesssssssssssss\n";
        else
            cout<<"NoooooOOOOOoooooo\n";
    }
}
