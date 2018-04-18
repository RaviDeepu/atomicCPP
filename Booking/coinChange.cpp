#include<iostream>
#include<vector>

using namespace std;


/*

m - Size of Array
V - Sum 

Time complexity of the above solution is O(mV).

*/

int minCoinRequired(vector<int> coins, int sum)
{
    vector<int> table (sum+1,100000);
    vector<int> denoms (sum+1);


    table[0] = 0;

    for(int i=1; i<=sum ; ++i)
    {
        //cout<<"i : "<<i<<endl;
        // Loop for all the coins less than i.
        for(int j=0 ; j<coins.size() ; ++j)
        {
            if(coins[j] <= i && (table[i-coins[j]] + 1 < table[i]))
            {
                table[i] = table[i-coins[j]]+1;
                cout<<"i : "<<i<<"table[i] : "<<table[i]<<endl;
                denoms[i] = j;
                cout<<"denoms[i] : "<<denoms[i]<<endl;
            }
        }
    }

    cout<<"Coins : "<<endl;
    int j=sum;
    while(j)
    {
        cout<<coins[denoms[j]]<<" ";
        j = j-coins[denoms[j]];
    }
    cout<<endl;
    return table[sum];

}


int main()
{
    int n;
    vector<int> coins;
    int sum,num;

    cout<<"Enter The number of Elements : "<<endl;
    cin>>n;

    cout<<"Enter the coins\n";
    for(int i=0 ; i<n ; ++i)
    {
        cin>>num;
        coins.push_back(num);
    }   

    cout<<"Enter the Sum\n";
    cin>>sum;

    cout<<"Minumum Coin Required : "<<minCoinRequired(coins,sum)<<endl;    

    

}
