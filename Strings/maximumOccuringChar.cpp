#include<iostream>
#define NO_OF_CHARS 256
#include<string.h>
#include<stdlib.h>

using namespace std;

void returnMaxOccuringChar(char *str)
{
    int countArray[NO_OF_CHARS]={0};

    int len = strlen(str);
    int max = -1;
    char result;

    for(int i=0;i<len;++i)
    {
        countArray[str[i]]++;
        if(max < countArray[str[i]])
        {
            max = countArray[str[i]];
            result = str[i];
        }
    
    }
    cout<<result<<" has occured "<<max<<" times"<<endl;
}

int main()
{
    char str[]="geksforgeks";
    cout<<"Max Occuring Char in : "<<str<<endl;
    returnMaxOccuringChar(str);
}
