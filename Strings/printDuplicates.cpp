#include<iostream>
#include<string.h>
#include<stdlib.h>
/*
    Print all the duplicates in the input string
    Write an efficient C program to print all the duplicates and their counts in the input string

    Algorithm: Let input string be .geeksforgeeks.
    1: Construct character count array from the input string.

    count[.e.] = 4
    count[.g.] = 2
    count[.k.] = 2
    ..

    2: Print all the indexes from the constructed array which have value greater than 0.
*/

using namespace std;

void printDuplicates(char *str)
{
    int count[256]={0};

    int len = strlen(str);
    for(int i=0;i<len;++i)
    {
        count[str[i]]++;
    }

    for(int i=0;i<len;++i)
    {
//        cout<<str[i]<<" = "<<count[str[i]]<<endl;
    }

    for(int i=0;i<256;++i)
    {
        if(count[i])
          cout<<_itoa(i)<<" - "<<count[i]<<endl;
    }

}


int main()
{
    char str[]="geeksforgeeks";
    cout<<"Original String : "<<str<<endl;
    printDuplicates(str);
//    cout<<"Print Duplicates : "
}
