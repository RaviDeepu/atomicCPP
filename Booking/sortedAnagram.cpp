#include <vector>
#include <unordered_map>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> sort_string_anagram(vector<string> array)
{
    unordered_map<string, set<string>> anagram;

    for(string word : array)
    {
        string sorted_word(word);

        sort(sorted_word.begin(),sorted_word.end());
    
        cout<<"Sorted Word : "<<sorted_word<<" , Word : "<<word<<endl;
        anagram[sorted_word].insert(word);
    }

    
    cout<<"Before Sorting\n";

    for(string s:array)
    {
        cout<<s<<endl;
    }    


    sort(array.begin(), array.end());

    cout<<"After Sorting\n";

    for(string s:array)
    {
        cout<<s<<endl;
    }
    

    vector<string> result;

    for(string word : array)
    {
        unordered_map<string,set<string>>::iterator iter;

        string sorted_word(word);

        sort(sorted_word.begin(), sorted_word.end());

        if( (iter = anagram.find(sorted_word)) != anagram.end() )
        {
           for(set<string>::iterator it = (iter->second).begin(); it!= (iter->second).end();++it)
           {
              result.push_back(*it);
           }
           anagram.erase(iter);
        }
    }
    return result;
}


int main()
{
    vector<string> v;

    v.push_back("god");
    v.push_back("dog");
    v.push_back("abc");
    v.push_back("cab");
    v.push_back("man");

        //v.push_back("god");
    
    vector<string> res = sort_string_anagram(v);

    cout<<"Result \n";
    for(string s:res)
    {
        cout<<s<<endl;
    }
}
