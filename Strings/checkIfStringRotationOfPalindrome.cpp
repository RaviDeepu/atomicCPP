/*

Check if a given string is a rotation of a palindrome
Given a string, check if it is a rotation of a palindrome. For example your function should return true for .aab. as it is a rotation of .aba..

Examples:

Input:  str = "aaaad"
Output: 1  
// "aaaad" is a rotation of a palindrome "aadaa"

Input:  str = "abcd"
Output: 0
// "abcd" is not a rotation of any palindrome.


*/


#include<iostream>
#include<string.h>

using namespace std;

// aaaad - aadaa

bool checkIfStringRotationOfPalindrome(char *str)
{
    char tempStr[100]="";
    
    strcat(tempStr,str);
    strcat(tempStr,str);

    int len = strlen(tempStr);
    bool found = false;
    int start=0,maxLength=0;
    cout<<"Concatenated String : "<<tempStr<<endl;
    for(int i=1 ; i<len ; ++i)
    {
        int low = i-1;
        int high = i+1;
        while(low >= 0 && high < len && tempStr[low] == tempStr[high] && maxLength <= strlen(str))
        {
            if((high-low+1) > maxLength && maxLength <= strlen(str))
            {
                maxLength = high-low+1;
                start = low;
            }
            low--;
            high++;
            //return true;
        }
    }
    
    for(int i=start ; i<(start+maxLength-1);++i)
    {
        cout<<tempStr[i];
    }
    cout<<endl;
}


int main()
{
    checkIfStringRotationOfPalindrome("aaaab");
}

