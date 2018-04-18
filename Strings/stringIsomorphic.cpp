#include<iostream>
#include<string.h>

using namespace std;

/*

Check if two given strings are isomorphic to each other
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2. And all occurrences of every character in .str1. map to same character in .str2.

Examples:

Input:  str1 = "aab", str2 = "xxy"
Output: True
'a' is mapped to 'x' and 'b' is mapped to 'y'.

Input:  str1 = "aab", str2 = "xyz"
Output: False
One occurrence of 'a' in str1 has 'x' in str2 and 
other occurrence of 'a' has 'y'.

*/


/*

Algorithm

1. If the length of both strings are not same then return False.
2. If the character from FirstString is seen first time.
   a. Then the character fron SecondString must not have appeared before, else return false.
   b. Store the mapping
3. If the character from FirstString is seen second time
   b. The mapping must be equal to the SecondString character.


*/



bool isIsomorphic(char *mainStr, char *mappedStr)
{
    bool seen[256]={false};
    int mapping[256]={0};

    if(strlen(mainStr) != strlen(mappedStr))
        return false;

    cout<<"Mapping value\n";
    for(int i=0;i<256;++i)
        cout<<mapping[i]<<endl;

    for(int i=0 ; mainStr[i] != '\0' ; ++i)
    {
        cout<<i+1<<" iteration\n";
        // mainStr[i] is seen first time
        if(mapping[mainStr[i]] == 0)
        {
            // If current character of mappedString is already seen
            if(seen[mappedStr[i]] == true)
            {
                // The 
                cout<<mappedStr[i]<<", MappedStr is seen second time\n";
                return false;
            }

            seen[mappedStr[i]] = true;
            mapping[mainStr[i]]=mappedStr[i];
        }
        else
        {
            if(mapping[mainStr[i]] != mappedStr[i])
            {
             cout<<mapping[mainStr[i]]<<" and "<<mappedStr[i]<<", not matching\n";
             return false;
            }
        }

    }

}


int main()
{
    char mainStr[]="aab";
    char mapStr[]="xcy";

    if(isIsomorphic(mainStr,mapStr))
        cout<<mainStr<<" and "<<mapStr<<" are isomorphic \n";
    else
        cout<<mainStr<<" and "<<mapStr<<" are NOT isomorphic \n";
//    DCS_LOG_DEBUG("")
}









