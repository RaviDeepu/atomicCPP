#include<stack>
#include<iostream>
#include<queue>
using namespace std;

class MyStack
{
        queue<int> q1,q2;
    public:
        void push(int item)
        {
            q1.push(item);
        }

        int pop()
        {
            if(q1.size() == 1)
            {
                int x = q1.front();
                q1.pop();
                return x;
            }
            else
            {
                while(q1.size() == 1)
                {
                    int x = q1.front();
                    q1.pop();
                    q2.push(x);
                }
        
                int x = q1.front();
                q1.pop();

                queue<int> tq;
                tq = q1;
                q1 = q2;
                q1 = tq;
            
                return x;                

            }
        }
};

int main()
{
    MyStack ms;

    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    ms.push(5);
    ms.push(6);

    cout<<"Delete : \n";
    cout<<ms.pop()<<endl;;
    cout<<ms.pop()<<endl;;

    cout<<"Insert : \n";
    ms.push(7);
    
    
    cout<<"Delete : \n";
    cout<<ms.pop()<<endl;;
    cout<<ms.pop()<<endl;;
}
