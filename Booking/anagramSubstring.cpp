/*#include<iostream>
#include<string.h>


using namespace std;



(Count characters)
This method assumes that the set of possible characters in both strings is small. In the following implementation, it is assumed that the characters are stored using 8 bit and there can be 256 possible characters.
1) Create count arrays of size 256 for both strings. Initialize all values in count arrays as 0.
2) Iterate through every character of both strings and increment the count of character in the corresponding count arrays.
3) Compare count arrays. If both count arrays are same, then return true.


Time Complexity - O(n)






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
*/

// C++ program to search all anagrams of a pattern in a text
#include<iostream>
#include<cstring>
#define MAX 256
#include<string>
using namespace std;
 

// This function returns true if counts of PatCountArray and MainStrCOunt are same
// otherwise false.
bool isSubStringFound(int patCount[], int mainStrCount[])
{
    for (int i=0; i<MAX; i++)
    {
        if (patCount[i] != mainStrCount[i])
        {
            return false;
        }
    }   
    return true;
}
 
// This function search if first word contains an anagram of the second word as a substring
bool containsAnagramSubstring(string mainString, string subString)
{
    int mainStringLen = mainString.length();
    int patStringLen = subString.length();
    
 
    // countMainStr[]: Store count of current window of text
    int countPattern[MAX]; //  Store count of all characters of pattern
    int countMainStr[MAX]; // Store count of current window of text
    
    for(int i=0 ; i<MAX ; ++i)
    {
        countPattern[i] = 0;
        countMainStr[i] = 0;
    }
    
    for (int i = 0; i < patStringLen; i++)
    {
        (countPattern[subString[i]])++;
        (countMainStr[mainString[i]])++;
        
    }
 
    // Traverse through remaining characters of pattern
    for (int index = patStringLen; index < mainStringLen; index++)
    {
        /* Check if SubString found by comparing counts of Pattern and MainStr.  */
        if (isSubStringFound(countPattern, countMainStr))
            return true;
 
        /* Update character to current string window */
        (countMainStr[mainString[index]])++;
 
        // Update the window by removing the first character.
        countMainStr[mainString[index-patStringLen]]--;
    }
 
    // Check for the last window in text
    if (isSubStringFound(countPattern, countMainStr))
        return true;


    return false;
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

        if(containsAnagramSubstring(mainList,patList))
            cout<<"Anagram : \n";
        else
            cout<<"Not Anagram : \n";
    }
}
