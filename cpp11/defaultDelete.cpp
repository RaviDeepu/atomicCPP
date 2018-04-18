#include<iostream>

/*
Deleted functions are useful for preventing object copying,
To disable copying, declare these two special member functions =delete:
*/

using namespace std;

/*
class NonCopyable
{
    public:
    NonCopyable()
    {
    
    }
    //void f()=delete;
    NonCopyable(const NonCopyable& obj) = delete;
    NonCopyable& operator=(const NonCopyable& obj) = delete;
};


int main()
{
    NonCopyable n;

    NonCopyable nn;//(n);
    n = nn;
    //h.f();
}
*/


class A
{
    public:
        A(int a)
        {
            cout<<"A Constructor : "<<a<<endl;;
        }
};


int main()
{
    A a(10);
    A b(3.14);
    a = b;
}
