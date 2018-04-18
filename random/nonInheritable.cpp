#include<iostream>

using namespace std;

class Final;

class MakeFinal
{
	friend class Final;
	private:
	MakeFinal()
	{
		cout<<"MakeFinal Constructor\n";
	}
};

class Final:public virtual MakeFinal
{

};

int main()
{
	Final aa;
}
