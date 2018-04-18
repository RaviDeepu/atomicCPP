/*
String matching where one string contains wildcard characters
Given two strings where first string may contain wild card characters and second string is a normal string. Write a function that returns true if the two strings match. The following are allowed wild card characters in first string.

* --> Matches with 0 or more instances of any character or set of characters.
? --> Matches with any one character.
For example, .g*ks. matches with .geeks. match. And string .ge?ks*. matches with .geeksforgeeks. (note .*. at the end of first string). But .g*k. doesn.t match with .gee. as character .k. is not present in second string.
*/

// g*ks and geeks

#include<iostream>

using namespace std;

bool stringMatching(char* first, char *second)
{
    // If we reach at the end of strings
    if(*first == '\0' && *second == '\0')
        return true;

    // Make sure the characters after * are present in
    // in the second string.
    if(*first == '*' && *(first+1) != '\0' && *second == '\0')
        return false;

    // If the character is ? or the character matches in both first and second string.
    if(*first == '?' || *first == *second )
        return stringMatching(first+1,second+1);

    // If the character is *, then there are two possibilities.
    // Consider the current character of second string.
    // Ignore the current chatacter of second string.
    if(*first == '*')
        return stringMatching(first+1,second) || stringMatching(first,second+1);

    return false;
    
    // 
}



int main()
{
    cout<<"*pqrst, apqrst\n";
    if(stringMatching("*pqrst", "apqrst"))
        cout<<"Matching \n";
    else
        cout<<"Not Matching \n";
}
