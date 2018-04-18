#include<iostream>


#include<string.h>


using namespace std;


void longestValidParanthesis(char *str)
{
    int start=0,pair=0;
    for(int i=0 ; str[i] != '\0' ; ++i)
    {
        if(str[i] == '(')
            start++;
        else if(str[i] == ')')
        {
            if(start > 0)
            {
                start--;
                pair = pair+2;
            }
        }
    }

    cout<<"Longest Paranthesis Substirng is : "<<pair<<endl;
}


int main()
{
    char str[]=")()())";
    longestValidParanthesis(str);
}
