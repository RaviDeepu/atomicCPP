#include<iostream>
#include<unordered_map>
#include<vector>


/*

What you would need is
1 - build your hash for given word(O(n))
2 - check if the word is present in every other hash with same quantity, since you will need to compare with all previous words everytime the complexity is O(nk) where k is the number of distinct words

so overal complexity O(nk)

*/
using namespace std;

vector<unordered_map<char,int> > myVector;

void print1IfPermutation(string str)
{
    unordered_map<char, int> newStrMap;
    cout<<"Strig : "<<str<<endl;

    int i=0;

    // Store the hash value of new string into a map.
    while( i < str.length() )
    {
        if(str[i] != ' ')
        {
            newStrMap[str[i]]++;
        }
        i++;
    }

    // If the vector is empty, push the string anf return from function.
    if(myVector.empty())
    {   
        myVector.push_back(newStrMap);
        return;
    }
    int j=0;

    bool Found = false;
    // Iterate over all the previous words.

    for(auto a : myVector)
    {
        j=0;
        unordered_map<char, int> tMap = a;
        if(tMap.size() != newStrMap.size())
        {
            // Ignore if the size does not match
        }
        else
        {
            while(j<str.length())
            {
                if(tMap[str[j]] != newStrMap[str[j]])
                {
                    //cout<<"Not Same\n";
                    break;
                }
                j++;
            }
        }
        if(j==str.length())
        {
            cout<<"Found\n";
            break;
        }
    }
}

int main()
{
    print1IfPermutation("ravi");
    print1IfPermutation("giri");
    print1IfPermutation("ivar");
    print1IfPermutation("iva");
}
