#include<iostream>
using namespace std;

class base
{
	public:
		base()
		{	
			cout<<"Constructor\n";
		}
		void * operator new[](size_t size);
		void * operator new(size_t size);
};

void * base::operator new[](size_t size)
{
	cout<<"NEW []\n";
	return ::operator new[](size);
}

void * base::operator new(size_t size)
{
	cout<<"NEW\n";
	return ::operator new(size);
}

int main()
{
	base *ba = new base;
	base *bb = new base[10];
}

