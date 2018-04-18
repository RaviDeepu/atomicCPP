#include<iostream>
#include<map>
#include<math.h>

using namespace std;

int main()
{
	float x = 1.45;
	cout<<floor(x)<<endl;
	multimap<string,int> m;
	m.insert(pair<string,int>("a",10));
	m.insert(pair<string,int>("a",10));
	m.insert(pair<string,int>("a",10));
	m.insert(pair<string,int>("a",10));
	m.insert(pair<string,int>("b",20));
	m.insert(pair<string,int>("a",20));

	for(multimap<string,int>::iterator it = m.begin() ; it != m.end() ; it++)
	{
		cout<<it->first<<"\t"<<it->second<<endl;
	}

	cout<<"Numner of a Keys "<<m.count("a")<<endl;
}
