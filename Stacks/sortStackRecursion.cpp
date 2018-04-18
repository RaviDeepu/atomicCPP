#include<iostream>
#include<stack>


using namespace std;


void printStack(stack<int> s)
{
    while(s.size() > 0)
    {   
        cout<<s.top()<<" ";
        s.pop();
    }
}


void sortStack(stack<int> &s)
{
    if(s.empty())
        return;

    int x = s.top();
    s.pop();
    sortStack(s);

    sortedInsert

    
}


int main()
{
    stack<int> s;
    
    s.push(1);
    s.push(2);
    s.push(5);
    s.push(4);
    s.push(3);

    printStack(s);
    
}
