#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

/*
There can be 2 solutions-

1- Sorting and comparing
a- SOrt any two array- O(nlogn)
b- find common of two sorted arrays and insert into the Set O(n)
c- Check for remaing arrays , whther elements of that array is present in the set or not. if yes then it is common element. O(n) for each new array

*set will not be modified after step b.

Time complexity O(nlogn) + O(n) ~= O(nlogn)


2- It can also be dome in O(n) time, by using hashmap and set-
a- Create an hash map of one array and aray element as key of the hashmap - O(n)
b- Traverse second array and check in hashmap for every element, if the key is present in hashmap then insert to the set. O(n)
Now you have set of common elements in 2 arrays. 
c- Check for remaing arrays , whther elements of that array is present in the set or not. if yes then it is common element. - O(n) for each new array

*set will not be modified after step b.

Time complexity O(n) or O(k*n) ~= O(n) , where k is number of the arrays



a. Read an array and store the value into an unordered_map (HashTable) - Constant lookup time
b. Read the second array and check if the element is already present in HashTable, If present then it is common and store it in a set.
c. Check Remaining Arrays - If the element is presetn in Set, then it is a common element.
*/

void getCommonHotelIDS(vector<vector<int>> v)
{
    unordered_map<int,int> mm;
    set<int> listOfUniqueIDs;

    auto firstVec = v[0];
    
    for(auto a : firstVec)
    {
        mm[a] = 1;        
    }

    auto secondVec = v[1];
    for(auto a : secondVec)
    {
        if(mm.find(a) != mm.end())
        {
            listOfUniqueIDs.insert(a);
        }
    }

    cout<<"Set Contains : "<<endl;
    for(auto a : listOfUniqueIDs)
    {
        cout<<a<<endl;
    }


    for(int i=2 ; i < v.size() ; ++i)
    {
        vector<int> tempVec = v[i];
        for(auto a : tempVec)
        {
            //cout<<"Checking : "<<a<<endl;
            if(listOfUniqueIDs.find(a) != listOfUniqueIDs.end())
            {
                cout<<"Unique : "<<a<<endl;
                //listOfUniqueIDs.insert(a);                    
            }
        }
    }

    for(auto a : listOfUniqueIDs)
    {
        //cout<<"Unique : "<<a<<endl;
    }

}

int main()
{
    vector<int> userA = {2,3,1};
    vector<int> userB = {2,5,3};
    vector<int> userC = {7,3,1};

    vector<vector<int>> hotelVector;
    
    hotelVector.push_back(userA);
    hotelVector.push_back(userB);
    hotelVector.push_back(userC);


    getCommonHotelIDS(hotelVector);


}
