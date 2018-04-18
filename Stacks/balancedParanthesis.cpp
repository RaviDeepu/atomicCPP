#include<iostream>
#include<stack>

using namespace std;

bool isMatchedPair(char first, char second)
{
    if(first == '(' && second == ')')
        return true;
    else if(first == '{' && second == '}')
        return true;
    else if(first == '[' && second == ']')
        return true;

    return false;
}

bool checkMatchedParanthesis(char* str)
{
    stack<char> s;

    int i=0;
    while(str[i])
    {
        if(str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else if(isMatchedPair(s.top(), str[i]))
        {
            s.pop();
        }
        else
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    char s[100];//="{()}[]";
    cout<<"Enter the String\n";
    cin>>s;
    if(checkMatchedParanthesis(s))
        cout<<"Yessss : Balanced\n";
    else
        cout<<"Oooops : Not-Balanced\n";
}
