#include<iostream>
#define MAX 256
#include<unordered_map>

using namespace std;


void anagram(string mainList, string patList)
{
    int count[MAX] = {0};
    unordered_map<char,int> map;
    
    cout<<"Map Size - "<<map.size()<<endl;

    // Hash the pattern.
    int i=0;
    while(patList[i])
    {
        cout<<"Inserting : "<<patList[i]<<endl;
        map[patList[i]]++;
        i++;
    }

    
    cout<<"Map Size - "<<map.size()<<endl;
    // Iterate over the main List and deerment the count.
    i=0;

    while(mainList[i])
    {
        if(map[mainList[i]])
        {
            cout<<"Decrementing : "<<mainList[i]<<endl;
            map[mainList[i]]--;
        }
        i++;  
    }

    cout<<"Map Size - "<<map.size()<<endl;

    for(auto a : map)
    {
        if(a.second == 1)
            cout<<a.first<<" , Not Anagram\n";
    }    

}


int main()
{
    string mainList;
    string patList;


    while(1)
    {
        cout<<"Enter Main String\n";
        cin>>mainList;


        cout<<"Enter Pattern String\n";
        cin>>patList;


        anagram(mainList,patList);
    }
}

