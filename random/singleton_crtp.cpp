#include "singleton.h"
#include<iostream>

class B : public CSingleton<B>
{
public:
		B()
		{
			std::cout<<"BBBBBBB\n";
		}
};



class A: public CSingleton<A>
{
	public:
		A()
		{
			std::cout<<"AAAAAA\n";
		}
   //Rest of functionality 
};

/*
int main()
{
	A *a = A::Instance();
	A *aa= A::Instance();
	
	B *b = B::Instance();

    float f=0.00001;
    std::cout<<f<<std::endl;
}
*/
