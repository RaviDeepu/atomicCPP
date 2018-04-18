#include<iostream>

using namespace std;


int myStringLength(char *str)
{
    int len = 0;
    while(*str)
    {
        str++;
        len++;
    }
    return len;
}

void myStringReverseRecursive(char *str)
{
    if(*str)
    {
        myStringReverseRecursive(str+1);
        cout<<*str;
    }
}


void myStringReverse(char *str)
{
    int len = myStringLength(str) - 1;
    cout<<"Lenght : "<<len<<endl;

    int i=0;
    while(i <= (len/2))
    {
        char temp = str[i];
        str[i] = str[len-i];
        str[len-i] = temp;
        i++;
        cout<<"i : "<<i<<", Temp : "<<temp<<endl;
    }
}

int main()
{
    char str[]="RaviGiri";
    myStringReverse(str);
    cout<<"Reversed String : "<<str<<endl;
    cout<<endl;
}
