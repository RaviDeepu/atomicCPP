#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string.h>
using namespace std;


int main()
{   
    unordered_map<string,vector<int>> hotels;

    int n;
    cout<<"Enter the numbe rof Hotel Lists\n";
    cin>>n;

    for(int i=0 ; i<n ; ++i)
    {
        string hotelId;
        int score;

        cout<<"Enter Hotel id\n";
        cin>>hotelId;

        cout<<"Enter Score\n";
        cin>>score;

        hotels[hotelId].push_back(score);
    }


    for(auto a:hotels)
    {
        cout<<a.first<<" ";

        for(auto ab : a.second)
            cout<<ab<<":";

        cout<<endl;
    }

    while(1)
    {
        int minAvgScore;
        cout<<"Enter Min Average Score\n";
        cin>>minAvgScore;

        int tAvgScore=0,noOfScore=0;

        for(auto a:hotels)
        {
            //cout<<a.first<<" ";

            tAvgScore=0,noOfScore=0;
            for(auto ab : a.second)
            {
                //cout<<ab<<":";
                tAvgScore+=ab;
                noOfScore++;
            }

            cout<<"tAvgScore : "<<tAvgScore<<" , noOfScore : "<<noOfScore<<" , "<<"minAvgScore : "<<minAvgScore<<endl;
            cout<<"tAvgScore/noOfScore : "<<(tAvgScore/noOfScore)<<endl;

            if((tAvgScore/noOfScore) >= minAvgScore)
                cout<<a.first<<endl;
        }

    }

}
