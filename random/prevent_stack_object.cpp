// Prevent Creating Object on Stack
// Declare Destructor of a class as Private/Protected.
#include<iostream>
using namespace std;

class base
{
	public:
		base(int a)
		{
			cout<<"Parameter Constructor\n";
		}
		base()
		{
			cout<<"Constructor\n";
		}	
		void destroy()
		{
			delete this;
		}
	private:
		~base();
};

base::~base()
{
	cout<<"Destructor\n";
}

int main()
{
	base *b = new base(10);;
	b->destroy();

	base *bb = new base;
}
