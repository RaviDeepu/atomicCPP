#include<iostream>
#include<map>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<unordered_map>
#include<vector>


using namespace std;


bool compare(const pair<int, int>&p1, const pair<int,int>&p2)
{
    if(p1.second == p2.second)
    {
//        cout<<"p1.first : "<<p1.first<<" , p2.second : "<<p2.second<<endl;
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}



int main()
{
    int n=1000000;

    unordered_map<int, int> myMap;
    int i=0;
    const clock_t begin_time = clock();

    vector<pair<int, int>> myPair;
    
    while(i < n)
    {
        int num = rand() % n;
        myMap[num]++;
        i++;
    }

    myPair.reserve(myMap.size());
    int iii=0;
    //copy(myMap.begin(), myMap.end(), back_inserter(myPair));
    for(unordered_map<int,int>::iterator iter = myMap.begin() ; iter != myMap.end() ; ++iter)
    {
        myPair[iii] = *iter;
        //myPair.push_back(*iter);
        ++iii;
    }


    sort(myPair.begin(), myPair.end(), compare);


    cout<<float(clock() - begin_time)/CLOCKS_PER_SEC<<endl;;
}
