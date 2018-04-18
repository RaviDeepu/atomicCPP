#include<iostream>
#include<string.h>


using namespace std;

/*

(Count characters)
This method assumes that the set of possible characters in both strings is small. In the following implementation, it is assumed that the characters are stored using 8 bit and there can be 256 possible characters.
1) Create count arrays of size 256 for both strings. Initialize all values in count arrays as 0.
2) Iterate through every character of both strings and increment the count of character in the corresponding count arrays.
3) Compare count arrays. If both count arrays are same, then return true.


Time Complexity - O(n)



*/


bool areAnagram(string mainList, string patList)
{
    int count[256] = {0};

    // Get hashvalues of Pattern List
    int i=0;
    while(patList[i])
    {
        count[patList[i]]++;
        i++;
    }   

    // Get Hashvalues of MainList
    i=0;
    while(mainList[i])
    {
        if(count[mainList[i]])
            count[mainList[i]]--;

        i++;
    }


    for(int i=0;i<256;++i)
    {
        if(count[i])
        {
            cout<<"Not Anagram\n";
            return false;
        }
    }

    cout<<"Anagram\n";
    return true;
    
 
    for(auto a : count)
    {
        //cout<<a<<endl;
    }
}


int main()
{
    while(1)
    {
        string mainList;//="ABDEFC";
        string patList;//="ABC";

        cout<<"Main String\n";
        getline(cin,mainList);

        cout<<"Pattern String\n";
        getline(cin,patList);

        areAnagram(mainList,patList); 
    }
}
