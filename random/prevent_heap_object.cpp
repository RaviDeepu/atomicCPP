// Prevent Heap Based Objects.
// Declare the operator new as private.

#include<iostream>

using namespace std;

class base
{
	public:
		int a;
		void display()
		{
			cout<<"A : "<<a<<endl;		
		}	
		base():a(10)
		{
			cout<<"Constructor\n";
		}


	
	private:
//	public:
		void * operator new (size_t size)
		{
			return ::operator new(size);
		}
		
		void * operator new [](size_t size)
		{
			return ::operator new[](size);
		}
};

//const int base::a;

int main()
{
	//base *b ;//= new base();
	base bb;
	bb.display();
	base *bbb= new base[10];
}

