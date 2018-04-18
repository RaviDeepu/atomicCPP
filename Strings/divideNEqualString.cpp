/*
Divide a string in N equal parts
Difficulty Level: Rookie

Question:
Write a program to print N equal parts of a given string.

length od string is 28
    char *str = "a_simple_divide_string_quest";

a_simpl
e_divid
e_strin
g_quest


*/


#include<iostream>
#include<string.h>


using namespace std;


void divideString(char *str, int n)
{
    int len = strlen(str);
    int divideLen;

    if(len%n != 0)
    {
        cout<<"Cannot Divide String by "<<n<<endl;
        return;
    }

    divideLen = len/n;

    for(int i=0;i<len;++i)
    {
        if(i%divideLen == 0)
            cout<<endl;
        cout<<str[i];
    }
    cout<<endl;
}


int main()
{
    char str[]="ravigiriabcd";
    int n;
    while(1)
    {
        cout<<"String : "<<str<<endl;
        cout<<"Enter n to be divided : "<<endl;
        cin>>n;
        divideString(str,n);
    }
}
