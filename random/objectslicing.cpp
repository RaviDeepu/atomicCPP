#include<iostream>

using namespace std;

class base
{
	public:
		virtual void display()
		{
			cout<<"Base\n";
		}

};

class derived:public base
{
	public:
		void display()
		{
			cout<<"Derived\n";
		}
};

void objectSlicing(base b)
{
	b.display();
}


int main()
{
	base b;
	b.display();
	derived d;
	d.display();
	
	b = d;
	objectSlicing(b);
}
