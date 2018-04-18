#include"singleton.h"

singleton* singleton::m_instance=NULL;

singleton* singleton::getInstance()
{
	if(!m_instance)
		m_instance = new singleton();
	cout<<"Instance already created\n";
	return m_instance;
}

void singleton::display()
{
	cout<<"Display()\n";
}


int main()
{
	singleton *sa = singleton::getInstance();
	sa->display();

	singleton *sb = singleton::getInstance();
	
}
