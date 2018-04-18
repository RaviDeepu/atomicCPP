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

void insertAtBottom(stack<int> &s, int item)
{
    if(s.empty())
    {
        s.push(item);
    }
    else
    {
        int temp = s.top();

        s.pop();
        insertAtBottom(s,item);
        
        s.push(temp);
    }
}



void reverse(stack<int> &s)
{
    if(s.empty())
        return;
    
    int x = s.top();
    s.pop();

    reverse(s);

    insertAtBottom(s,x);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<"Before Reverse\n";
    printStack(s);
    
    
    reverse(s);
    cout<<"\n After Reverse\n";
    printStack(s);
}
