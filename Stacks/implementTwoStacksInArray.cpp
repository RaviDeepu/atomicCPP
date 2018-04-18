#include<iostream>
#include<stack>

using namespace std;


class twoStack
{
    int top1, top2;
    int size;
    int *a;

    public:
        twoStack(int n)
        {
            a = new int[n];
            top1 = -1;
            top2 = n;
            size = n;
        }

        void push1(int item)
        {
            if(top1 < top2-1)
            {
                top1++;
                a[top1] = item;
            }
            else
            {
                cout<<"Stack 1 Overflow\n";
            }
        }

        void push2(int item)
        {
            if(top1 < top2-1)
            {
                top2--;
                a[top2] = item;
            }
            else
            {
                cout<<"Stack 2 Overflow\n";
            }
        }

        int pop1()
        {
            if(top1 >= 0)
            {
                int x = a[top1];
                top1--;
                return x;
            }
            else
            {
                cout<<"Stack 1 Empty\n";
            }
        }

        int pop2()
        {
            if(top2 < size)
            {
                int x = a[top2];
                top2++;
                return x;
            }
            else
            {
                cout<<"Stack 2 Empty\n";
            }
        }

};


int main()
{
    twoStack t(6);

    t.push1(1);
    t.push1(2);
    t.push1(3);

    t.push2(4);
    t.push2(5);
    t.push2(6);

    cout<<"Popped item from Stack 1: "<<t.pop1()<<endl;
    cout<<"Popped Item from Stack 2: "<<t.pop2()<<endl;
    
    t.push1(7);

    cout<<"Popped Item from Stack 2: "<<t.pop2()<<endl;
}
