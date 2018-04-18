#include<iostream>

using namespace std;

class Final;

class MakeFinal
{
	private:
		MakeFinal();
		friend class Final;
};

MakeFinal::MakeFinal()
{
	cout<<"MakeFinal Constructos\n";
}

class Final:virtual public MakeFinal
{
};

class derived:public Final
{
};

int main()
{
	derived d;
	
}

