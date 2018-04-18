#include<iostream>

using namespace std;


class A
{
    public:
        virtual void f(int i )
        {
            
        }
};

class B : public A
{
    public:
        void f( int a) override
        {
        }
};

int main()
{
    
}
