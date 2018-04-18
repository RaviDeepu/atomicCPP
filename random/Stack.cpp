#include<iostream>
#include<stdlib.h>

using namespace std;


class MyStack
{
    private:
        int *p;
        int top,length;
    public:
        MyStack(int size = 0)
        {
            top = -1;
            length = size;
            if(size == 0)
                p = 0;
            else
                p = new int[size];
        }

        ~MyStack()
        {
            if(p != 0)
                delete []p;
        }


        void push(int item);

        int pop();

        void display();

        void reverse();

        bool isEmpty();

        void insertAtBottom(int );
};


bool MyStack::isEmpty()
{
    if(top < 0)
        return true;
    return false;
}

void MyStack::push(int item)
{
    if(p == 0)
    {
        cout<<"Empty Stack\n";
        cout<<"Enter the Size of Stack ?\n";
        cin>>length;
        p = new int[length];
    }

    if(top >= length-1)
    {
        cout<<"Stack Full..!! Cannot Push "<<item<<endl;
        return;
    }
    else
    {
        top++;
        p[top]=item;
    }
}

int MyStack::pop()
{
    if(top < 0)
    {
        cout<<"Stack Empty..!!"<<endl;
        return -1;
    }

    return p[top--];
}


void MyStack::display()
{
    cout<<"Stack Elements are : "<<endl;

    for(int i=top;i>=0;i--)
    {
        cout<<p[i]<<endl;
    }
}

void MyStack::insertAtBottom(int item)
{

    if(isEmpty())
    {
        push(item);
    }
    else
    {
        int val = pop();
        insertAtBottom(item);

        push(val);
    }
}

void MyStack::reverse()
{
    if(!isEmpty())
    {
        int val = pop();
        reverse();

        insertAtBottom(val);
    }
}

int main()
{
    int ch;
    MyStack s(10);
    for(;;)
    {
        cout<<"----------------------------------------------"<<endl;
        cout<<"1. Push, 2. Pop, 3. Display, 4. Reverse"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                    {
                        int item;
                        //cout<<"Enter item to be pushed"<<endl;
                        //cin>>item;

                        s.push(8);
                        s.push(7);
                        s.push(6);
                        s.push(5);
                        s.push(4);
                        s.push(3);
                        s.push(2);
                        s.push(1);
                    }
                    break;
           case 2:
                    cout<<"The Deleted item is : "<<s.pop()<<endl;
                    break;
           case 3:
                    s.display();
                    break;
           case 4:
                    {
                        s.reverse();

                    }
                    break;
           default:
                    exit(0);
        }
    }
}
