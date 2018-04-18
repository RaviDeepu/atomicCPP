#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

/*
Given any number of arrays containing numbers, write a  function which finds the numbers that appear in exactly two arrays. arrays = [ [6, 2, 2, 0, 4], [5, 0, 2, 6, 7, 1], [6, 7, 9, 9], ] find_in_two(arrays) should return [2, 0, 7] 
*/

void printNumberInExact2Arrays(vector<vector<int> >& v)
{

    unordered_set<int> set;
    unordered_map<int,int> map;

    for(vector<int> vv : v)
    {
        set.clear();
        for(auto a : vv)
        {
            if(set.find(a) == set.end())
            {
                set.insert(a);
                map[a]++;
                
            }
            
        }
    }

    for(auto a : map)
    {
        if(map[a.first] == 2)
        {
            cout<<a.first<<endl;
        }
    }


}

int main()
{
    vector< vector<int> > v;
    vector<int> a = {6,2,2,0,4};
    vector<int> b = {5,0,2,6,7,1};
    vector<int> c = {6,7,9,9};

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    printNumberInExact2Arrays(v);

    
}
