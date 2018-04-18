/*
Reverse words in a given string
Example: Let the input string be .i like this program very much.. The function should change the string to .much very program this like i.
*/

#include<iostream>
#include<string.h>
using namespace std;

/*
Algorithm.

1. Reverse The entire string.
2. Reverse each words
*/

void reverse(char *str)
{
    int len = strlen(str)-1;
    int i=0;
    while( i <= len/2)
    {
        char temp = str[i];
        str[i] = str[len-i];
        str[len-i] = temp;
        i++;
    }
}

// Ravi Giri
void reverseWordsInSentence(char *str)
{
    reverse(str);
    int index=0;
    for(int i=0;str[i] != '\0';++i)
    {
        if(str[i] == ' ')
        {
            str[i]='\0';
            reverse(&str[index]);
            str[i]=' ';
            index=i+1;
        }
    }
    // Reverse the last word
    reverse(&str[index]);
}

int main()
{
    char str[]="Ravi Giri";
    cout<<"Original String : "<<str<<endl;
    //reverse(str);
    reverseWordsInSentence(str);
    cout<<"Reversed String : "<<str<<endl;
}
