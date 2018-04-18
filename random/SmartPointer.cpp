#include<iostream>

using namespace std;


class Person
{
		char *data;
		int age;
	public:
		Person()
		{
		}
		Person(char *name, int aging):data(name),age(aging)
		{
		}
		~Person()
		{
			cout<<"Person Destructor\n";
		}
		void display()
		{
			cout<<"Name : "<<data<<" Age : "<<age<<"\n";
		}
};

class ReferenceCounting
{
		int count;
	public:
		ReferenceCounting():count(0)
		{
			cout<<"Reference Default\n";
		}
		ReferenceCounting(int number) : count(number)
		{
			cout<<"Reference Parameterized\n";
		}
		void AddRef()
		{

			count++;
			//cout<<count<<endl;
		}
		int DelRef()
		{
			return --count;
		}
		void CurCount()
		{
			cout<<"Count : "<<count<<endl;;
		}
};

class SmartPointer
{
		Person *pObj;
		ReferenceCounting *refCount;
	public:
		
		SmartPointer() : pObj(0),refCount(0)
		{
			refCount = new ReferenceCounting;
			refCount->AddRef();
		}	
		SmartPointer(Person *p):pObj(p),refCount(0)
		{
			cout<<"Smart Constructor\n";
			refCount = new ReferenceCounting;
			refCount->AddRef();
		}

		SmartPointer (const SmartPointer& p) : pObj(p.pObj),refCount(p.refCount)
		{
			cout<<"Smart Copy Constructor\n";
			refCount->AddRef();
		}
		
		SmartPointer& operator=(SmartPointer &sp)
		{
			if(this != &sp)
			{
				if(refCount->DelRef() == 0)
				{
					cout<<"PROBLEM\n";
					delete pObj;
					delete refCount;
				}
				pObj = sp.pObj;
				refCount = sp.refCount;
				refCount->AddRef();
			}
			return *this;
		}
		Person& operator *()
		{
			return *pObj;
		}
		Person* operator->()
		{
			return pObj;
		}
		~SmartPointer()
		{
			if(refCount->DelRef() == 0)
			{
				delete pObj;
				delete refCount;
			}
		}
		void retCount()
		{
			refCount->CurCount();
		}
};

int main()
{
	SmartPointer p(new Person("Ravi",20));
	//p.retCount();
	{
		SmartPointer q;
		q.retCount();
		q = p;
		p.retCount();
	//	q->display();
		//p.retCount();
	}
	//Person *p = new Person;
	//p->display();
	
}

