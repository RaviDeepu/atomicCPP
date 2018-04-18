#include<iostream>
#include<map>
#include<vector>
#include<list>

using namespace std;



int main()
{
    vector<string> names = {"Luis","Hector","Selena","Emmanuel","Amish"};

    map<char,string> mapFirstChar;
    map<char,string> mapLastChar;

    list<string> result;

    for(auto s : names)
    {
        cout<<s<<endl;
        mapFirstChar.insert(pair<char,string>(tolower(s[0]),s));
        mapLastChar.insert(pair<char,string>(s[s.length()-1],s));
    }

    for(auto s : names)
    {
        if(result.empty())
        {
            result.push_back(s);
        }

        string front = result.front();
        string back = result.back();

        char begin = tolower(front[0]);
        char end = back[back.length()-1];

        map<char,string>::iterator iter;
        if((iter = mapLastChar.find(begin)) != mapLastChar.end())
        {
            result.push_front(iter->second);
            mapLastChar.erase(iter);
        }
        
        if((iter = mapFirstChar.find(end)) != mapFirstChar.end())
        {
            result.push_back(iter->second);
            mapFirstChar.erase(iter);
        }
    }

    cout<<"===================================\n";
    for(auto s: result)
    {
        cout<<s<<endl;
    }
}
