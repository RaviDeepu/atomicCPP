#include<iostream>
#include<stack>

using namespace std;

bool isDigitOrAlphabet(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))    
        return true;


    return false;
}

bool isMatchingPair(char c1, char c2)
{
    if(c1 == ')' && c2 == '(')
        return true;
    else if(c1 == '}' && c2 == '{')
        return true;
    else if(c1 == ']' && c2 == '[');
        return true;

    return false;
}

void checkStringParanthesis(string s)
{
    stack<char> myStack;

    int i=0;
    while(s[i])
    {
        char item = s[i];
        
        if(isDigitOrAlphabet(item))
        {
            i++;
            cout<<"Digit or Alphabet : "<<item<<endl;
        }
        else if(item == '(' || item == '{' || item == '[')
        {
            myStack.push(item);
            i++;
        }
        else if(item == ')' || item == '}' || item == ']')
        {
            if(myStack.empty())
            {
                cout<<"Stack Empty - Without opening brace\n";
                return;
            }

            if( !isMatchingPair(myStack.top(), item) )
            {
                cout<<"Not Matching Pair\n";
                return;
            }
        
            myStack.pop();
            i++;
        }    
    }

    if( !myStack.empty() )
    {
        cout<<"Not balanced - Not Empty at last\n";
        return;
    }
    cout<<"Yessss - Balanced Paranthesis\n";
}

int main()
{
    while(1)
    {
        cout<<"Enter Paranthesised String\n";
        string s;
        getline(cin,s);

        checkStringParanthesis(s);
    }
}
