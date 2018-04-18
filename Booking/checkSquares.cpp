#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int  main()
{
    vector<int> vec = {3,1,4,5,6};
    vector<int> squareVec = {1,9,16,2};


    unordered_map<int,int> map;

    for(auto a : squareVec)
    {
        map[a]=1;
    }
    

    for(auto a: vec)
    {
        if(map[a*a] == 1)
        {
            cout<<a<<endl;
        }
    }
}
