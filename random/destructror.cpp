//Output of the above program is “i = 3″.
//Why the output is i= 3 and not 10?
//While returning from a function, destructor is the last method to be executed. The destructor for the object “ob” is called after the value of i is copied to the return value of the function. So, before destructor could change the value of i to 10, the current value of i gets copied & hence the output is i = 3.

#include <iostream>
using namespace std;

/* 
int i;
 
class A
{
public:
    ~A()
    {
        i=10;
    }
};
 
int foo()
{
    i=3;
    {
    	A ob;
    }
    return i;
}
 
int main()
{
    cout << "i = " << foo() << endl;
    return 0;
}
*/

class base
{
	public:
		base()
		{
		}
		~base()
		{
			display();
			cout<<"Destructor\n";
		}
		
		virtual void display()
		{
			cout<<"Base\n";
		}
};

class derived:public base
{
	public:
	derived()
	{
	}
	
	~derived()
	{
		display();
		cout<<"Derived Destructor\n";
	}
	
	void display()
	{
		cout<<"Derived\n";
	}
};

int main()
{
	derived *b = new derived;
	delete b;	
}


