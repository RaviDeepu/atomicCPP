#include<iostream>

using namespace std;


int getMax(int a, int b)
{
    cout<<"MAX : "<<a<<","<<b<<endl;
    return a>b?a:b;
}

int knapsack(int wt[], int val[], int maxWeight, int n)
{
    int k[n+1][maxWeight+1];
    for(int i=0 ; i<=n ; i++)
    {
        for(int w=0 ; w<=maxWeight ; w++)
        {
            if(i == 0 || w == 0)
                k[i][w]=0;            
            else if(wt[i-1] <= w)
                k[i][w] = getMax(k[i-1][w-wt[i-1]] + val[i-1], k[i-1][w]);
            else
                k[i][w] = k[i-1][w];
        }
    }


    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=maxWeight;w++)
        {
            cout<<k[i][w]<<",";
        }
        cout<<endl;
    }
    return k[n][maxWeight];
}

int main()
{
    int weight[]={1,3,5};
    int value[]={8,6,5};

    int maxWeight = 5;
    int noOfItems = 3;

    cout<<"Max Value to be stolen is "<<knapsack(weight,value,maxWeight,noOfItems);
    cout<<"Hello\n";
}
