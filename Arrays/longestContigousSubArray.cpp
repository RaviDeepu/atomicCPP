#include<iostream>
#include<climits>
using namespace std;

int longestContiguousSubArray(int a[], int size)
{
    int sumSoFar=0;
    int sumTillNow=0;

    for(int i=0;i<size;++i)
    {
        sumTillNow = sumTillNow + a[i];
        if(sumSoFar < sumTillNow)
        {
            sumSoFar = sumTillNow;
            cout<<"sumSoFar ; "<<sumSoFar<<endl;
        }
        else if(sumTillNow < 0)
            sumTillNow = 0;
    }
    return sumSoFar;
}

int main()
{
    int a[]={-2,-3,4,-1,-2,1,5,-3};
    cout<<longestContiguousSubArray(a,8)<<endl;

        
    
    
}
