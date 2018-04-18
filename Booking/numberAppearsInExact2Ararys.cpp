#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

/*

Given any number of arrays containing numbers, write a  function which finds the numbers that appear in exactly two arrays. arrays = [ [6, 2, 2, 0, 4], [5, 0, 2, 6, 7, 1], [6, 7, 9, 9], ] find_in_two(arrays) should return [2, 0, 7] 
*/

void returnNumberAppearsInExactTwoArrays(vector<vector<int>> ivec)
{
    unordered_map<int,int> myMap;
    unordered_set<int> mySet;

    for(vector<int> vv : ivec)
    {
        mySet.clear();
        for(vector<int>::iterator ii=vv.begin(); ii != vv.end(); ++ii)
        {
            if(mySet.find(*ii) == mySet.end())
            {
                //cout<<"Insert : "<<*ii<<endl;
                myMap[*ii]++;
                mySet.insert(*ii);

            }
        }
    }

    for(auto a : myMap)
    {
        if(a.second == 2)
            cout<<a.first<<" "<<a.second<<endl;
    }

}


int main()
{
    vector<int> a {6,2,2,0,4};
    vector<int> b {5,0,2,6,7,1};
    vector<int> c {6,7,9,9};
    
    vector<vector<int>> myVec;
    myVec.push_back(a);
    myVec.push_back(b);
    myVec.push_back(c);

    returnNumberAppearsInExactTwoArrays(myVec);


}
