#include<iostream>
#include"tempAutoClass.cpp"

using namespace std;

template<class T>
class AutoPointer
{
	private:
		T* ptr;
	public:
		explicit AutoPointer(T* p = 0):ptr(p)
		{
			cout<<"AutoPointer Constructor\n";
		}
		
		~AutoPointer()
		{
			cout<<"AutoPointer Destructor\n";
			delete ptr;
		}
		
		T& operator*()
		{
			cout<<"operator*\n";
			return *ptr;
		}	
		
		T* operator->()
		{
			cout<<"operator->\n";
			return ptr;
		}

		// Copy Constructor
		AutoPointer(AutoPointer<T> &source)
		{
			//delete ptr;
			//ptr = 0;
			cout<<"AUtoPointer : Copy Constructor\n";
			ptr = source.ptr;
			source.ptr = 0;
			//return *this;
		}
		
		AutoPointer& operator=(AutoPointer<T> &source)
		{
			cout<<"AutoPointer : Assignment Operator\n";
			if(ptr != source.ptr)
			{
				delete ptr;
				ptr = 0;
				
				ptr = source.ptr;
				source.ptr = 0;
			}
			return *this;
		}

		void reset(T* val)
		{
			cout<<"AutoPointer : reset\n";
			delete ptr;
			ptr = val;
		}

		T* release()
		{
			cout<<"AutoPointer : release\n";
			T* t = ptr;			
			ptr = 0;
			return t;
		}

		T* get()
		{
			cout<<"AutoPointer : get\n";
			return ptr;
		}
};


int main()
{
	AutoPointer<TestAutoClass> p(new TestAutoClass("Giri",25));
	cout<<"Name :"<<p->getName()<<": Age :"<<p->getAge()<<endl;
	
	AutoPointer<TestAutoClass> p2;
	p2.reset(new TestAutoClass("Ravi",26));
	cout<<p2.get()->getName()<<endl;
}
































































/*
class Person
{
	private:
		int pAge;
		char *pName;
	public:
		Person():pAge(0),pName(0)
		{
			cout<<"Default Constructor\n";
		}
		Person(char *name,int age):pAge(age),pName(name)
		{
			cout<<"Parameterized Constructor\n";
		}
		
		void display();
		void shout();
};

void Person::display()
{
	cout<<"Name :"<<pName<<endl<<"Age :"<<pAge<<endl;
}

void Person::shout()
{
	cout<<"OooooooooHooooooooo\n";
}


int main()
{
	Person *p = new Person("Scott",25);
	p->display();
	p->shout();
}
*/

