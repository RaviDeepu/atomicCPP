/*
* Can virtual functions be private in C++?
*/
#include<iostream>

using namespace std;

class base
{
	virtual void fun() { cout<<"Base Fun\n"; }
	friend int main();
};

class derived : public base
{
public:
	void fun() { cout<<"Derived Fun\n"; }
};

int main()
{
	base *ptr = new derived;
	ptr->fun();
}
