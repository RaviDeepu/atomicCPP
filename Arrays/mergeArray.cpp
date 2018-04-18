#include<iostream>
#define NA -1

using namespace std;

// Merge Array of Size N into another array of size mPlusN.
// Logic.
// Move all the elements of mPlusN into end.
// Now compare the elements from N and mPlusN and push into mPlusN at appropriate place.

/*
* mPlusN[] = 2,3,-1,5,-1,9,-1
* N[] = 5,7,8,10
*
*/

void moveToEnd(int mPlusN[], int size)
{
    int j=size-1;
    for(int i=size-1;i>=0;i--)
    {
        if(mPlusN[i] != NA)
        {
            mPlusN[j] = mPlusN[i];
            j--;
        }
    }
}

void merge(int mPlusN[], int m, int N[], int n)
{
    int k=0;
    int i=n;
    int j=0;

    while( k < (m+n) )
    {
        if( (i<(m+n) && mPlusN[i] <= N[j]) || (j==n) )
        {
            mPlusN[k] = mPlusN[i];
            k++;
            i++;
        }
        else
        {
            mPlusN[k] = N[j];
            k++;
            j++;
        }
    }
}


void mergeIntoArray(int mPlusN[], int m, int N[], int n)
{
    moveToEnd(mPlusN,m);
    merge(mPlusN,m,N,n);

    cout<<"Merged Array : "<<endl;
    for(int i=0;i<m;++i)
    {
        cout<<mPlusN[i]<<endl;
    }
}

int main()
{
    int mPlusN[]={2,NA,3,5,7,NA,9,NA};
    int N[]={4,6,8};

    int m = sizeof(mPlusN)/sizeof(mPlusN[0]);
    int n = sizeof(N)/sizeof(N[0]);

    mergeIntoArray(mPlusN,m,N,n);

}
