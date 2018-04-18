#include<iostream>


using namespace std;


int getMaxProfit(int a[], int n)
{
    int maxDiff = 0;
    int minElement = a[0];
    int buy,sell;
    for(int i=1;i<n;++i)
    {
        if((a[i] - minElement) > maxDiff)
        {
            maxDiff = a[i] - minElement;
            sell = a[i];
        }
        
        if(a[i] < minElement)
        {
            minElement = a[i];
            buy = a[i];
        }
    }
    cout<<"Buy @ "<<buy<<", Sell @ "<<sell<<endl;
    return maxDiff;
}

int main()
{
    int a[]={2,4,6,8,1,9};
    int size = sizeof(a)/sizeof(a[0]);

    cout<<"Max Profit : "<<getMaxProfit(a,size)<<endl;
}
