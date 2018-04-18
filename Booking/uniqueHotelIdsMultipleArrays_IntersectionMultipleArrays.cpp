#include<unordered_map>
#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

/*
    1. Use hashMap and set.
    2. Iterate the first array and populate a map and increment the value of it.
    3. Iterate the second array and check if the value presents in the map. If the value is present then populate the set(which will have unique elements from 1 and 2 array)
    4. iterate the remmaining array and if any of the the elemnts present in set then it is a common Id's

*/
void findCommonIds(vector<vector<int>> &v)
{
    unordered_map<int,int> map;
    unordered_set<int> set;

    vector<int> tVec = v.at(0);

    for(auto a : tVec)
    {
        map[a]++;
    } 

    tVec = v.at(1);
    
    for(auto a : tVec)
    {
        if(map[a])
            set.insert(a);
    }

    for(int i=2 ; i<v.size() ; ++i)
    {
        tVec = v.at(i);
        for(auto a : tVec)
        {
            if(set.find(a) != set.end())
            {
                cout<<a<<endl;
            }
        }
    }
        
} 

int main()
{

    vector<int> a = {2,3,1,4};
    vector<int> b = {2,5,3,4};
    vector<int> c = {7,4,3,1};


    vector< vector<int> > hotelIdVector;
    hotelIdVector.push_back(a);
    hotelIdVector.push_back(b);
    hotelIdVector.push_back(c);
    
    findCommonIds(hotelIdVector);
 
}

