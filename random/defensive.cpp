#include<iostream>
#include<stdlib.h>
using namespace std;

class A
{
    public:
        A()
        {
            cout<<"CONSTRUCTOR\n";
        }

        A(const A&)
        {
            cout<<"COPY\n";
        }
};

int main()
{
    void *p = malloc(sizeof(A));
    A *a = new(p) A;
    delete a;
}
