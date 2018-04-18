#include<iostream>
#include<string.h>

using namespace std;


void removeSpaces(char *str)
{
    int count=0;

    for(int i=0;str[i] != '\0';++i)
    {
        if(str[i] != ' ')
        {
            str[count] = str[i];
            count++;
        }
    }
    str[count]='\0';
}


int main()
{
    char str[]="Ravi Prakash Giri";
    removeSpaces(str);
    cout<<str<<endl;
}
