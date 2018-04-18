//set_unexpected.
#include<iostream>

#include<algorithm>

using namespace std;

class UnExpectedException
{
};

void convertUnexpected()
{
	cout<<"Unexpected Exception Called\n";
	throw UnExpectedException();
}

class base
{
	public:
		void throwUnexpected() throw (UnExpectedException)
		{
			int a = 10;
			throw (a);
		}
	
};

int main()
{
	set_unexpected(convertUnexpected);
	base b;
	try
	{
		b.throwUnexpected();
	}
	catch(UnExpectedException)
	{
		cout<<"CATCH : Unexpected Exception Called\n";
	}
}

