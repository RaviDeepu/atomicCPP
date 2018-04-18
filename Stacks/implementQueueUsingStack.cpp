#include<iostream>
#include<stack>
#include<stdlib.h>

using namespace std;

/*
    Implement Queue Using Stack.
    1. By Making Dequeue operation costly.
    a. Push Everything to s1.
    b. Pop
        a. If both the stacks are empty then return error.
        a. If Stack2 is empty
            while Stack1 is empty
                Push everything from Stack1 to Stack2.
            Pop element from Stack2 and return.
*/

void enqueue(stack<int> &s, int item)
{
    s.push(item);
}

void dequeue(stack<int> &s1, stack<int> &s2)
{
    if(s1.empty() && s2.empty())
    {
        cout<<"Stack Empty\n";
        return;
    }

    if(s2.empty())
    {
        while(!s1.empty())
        {
            int temp = s1.top();
            s1.pop();
            enqueue(s2,temp);
        }
    }

    cout<<"Deleted item : "<<s2.top()<<endl;
    s2.pop();
}


int dequeue_UsingOneStack(stack<int> &s)
{
    if(s.empty())
    {
        cout<<"Stack Empty\n";
        return -1;
    }
    else if(s.size() == 1)
    {
        int tt = s.top();
        s.pop();
        //cout<<"Deleted Item : "<<tt<<" ";
        return tt;
    }
    else
    {
        int x = s.top();
        s.pop();

        int res = dequeue_UsingOneStack(s);

        s.push(x);

        return res;
    }
}


int main()
{
    stack<int> s1,s2;
    
    while(1)
    {
        int ch;
        cout<<"1. Push\t2. Pop\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                int item;
                cout<<"Enter item to be inserted into Stack\n";
                cin>>item;
                //int item;
                enqueue(s1,item);
            }
                break;
            case 2:
            {
                cout<<"Deleted Item : "<<dequeue_UsingOneStack(s1)<<endl;
                //dequeue(s1,s2);
                break;
            }
            default:
                exit(0);
        }
    }
}
