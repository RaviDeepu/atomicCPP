/*
Remove characters from the first string which are present in the second string
Write an efficient C function that takes two strings as arguments and removes the characters from first string which are present in second string (mask string).

Algorithm: Let first input string be.test string. and the string which has characters to be removed from first string be .mask.
1: Initialize:
res_ind = 0 /* index to keep track of processing of each character in i/p string */
//ip_ind = 0 /* index to keep track of processing of each character in the resultant string */

/*
2: Construct count array from mask_str. Count array would be:
(We can use Boolean array here instead of int count array because we don.t need count, we need to know only if character is present in mask string)
count[.a.] = 1
count[.k.] = 1
count[.m.] = 1
count[.s.] = 1

3: Process each character of the input string and if count of that character is 0 then only add the character to the resultant string.
str = .tet tringng. // .s. has been removed because .s. was present in mask_str but we we have got two extra characters .ng.
ip_ind = 11
res_ind = 9

4: Put a .\0. at the end of the string?
*/

#include<iostream>
#include<string.h>
using namespace std;

void removeCharsFromSecString(char *str, char *mask_str)
{
    int countArray[256]={0};
    int len = strlen(mask_str);
    for(int i=0;i<len;++i)
    {
        countArray[mask_str[i]]++;
    }

    int ipIndex=0,resIndex=0;
    char temp;
    while(*(str+ipIndex))
    {
        temp = *(str+ipIndex);
        if(countArray[temp] == 0)
        {
            *(str+resIndex) = *(str+ipIndex);
            resIndex++;
        }
        ipIndex++;
    }

    *(str+resIndex)='\0';
}

int main()
{
    char str[]="test string";
    char mask[]="testn";

    cout<<"Original String : "<<str<<", Mask String : "<<mask<<endl;
    removeCharsFromSecString(str,mask);
    cout<<"Original String : "<<str<<", Mask String : "<<mask<<endl;
}
