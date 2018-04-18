#include<iostream>
#include<set>

using namespace std;

class Person
{

	public:

	int page;
	char *pname;

		Person()//:pname(0),page(0)
		{
		}
		Person(char *name,int age):pname(name),page(age)
		{
		}
		void display()
		{
			cout<<"Name : "<<pname<<" -- Age : "<<page<<endl;
		}
		bool operator< (const Person &pp) const
		{
			return page < pp.page;
		}
};

int main()
{
	Person p("Ravi",26);
	//p.display();
	set<Person> sp;
	sp.insert(Person("Ravi",26));
	sp.insert(Person("Giri",27));
	sp.insert(Person("Prakash",21));
	sp.insert(Person("Agent",28));
	for(set<Person>::iterator i = sp.begin() ; i != sp.end() ; i++)
	{
		cout<<i->pname<<" "<<i->page<<endl;
	}

	cout<<"Find 26\n";
	Person pp("",26);
	set<Person>::iterator i = sp.find(pp);
	if(i != sp.end())
	{
		cout<<i->pname<<" "<<i->page<<endl;
	}

}
