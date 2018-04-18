#include<iostream>
#include<stdlib.h>

using namespace std;

/*
xstrlen
xstrncpy
Constructor
Copy Constructor
Assignment Operator
Concatenation Operator
<< Operator
[] Operator
*/

int xstrlen(char *str)
{
	int len=0;
	while(*str++)
		len++;
	return len;
}

void xstrcpy(char *dest,char *src)
{
	while(*dest++ = *src++);
}

class myString
{

		int length;
		char* data;
	public:
		myString():length(0),data(NULL)
		{
			cout<<"Constructor\n";
		}

		myString(char *str):length(xstrlen(str)),data(new char[length])
		{		
			cout<<"Param Constructor\n";
			xstrcpy(data,str);
		}

		myString(const myString &obj):length(obj.length),data(new char[length])
		{
			cout<<"Copy Constructor\n";
			xstrcpy(data,obj.data);
		}

		myString& operator=(const myString &obj)
		{
			if(this != &obj)
			{
				delete data;
				length = xstrlen(obj.data);
				data = new char[length];
				xstrcpy(data,obj.data);
			}
			return *this;
		}

		friend myString operator+(const myString &s1, const myString &s2)
		{
			myString res;
			res.length=s1.length+s2.length;
			res.data = new char[res.length];
			xstrcpy(res.data,s1.data);
			xstrcpy(res.data+s1.length,s2.data);
			return res;
		}


		friend ostream& operator<<(ostream &os, myString &s)
		{
			for(int i=0;i<s.length;i++)
			{
				os.put(s.data[i]);
			}
			return os;
		}

		char& operator[](int index)
		{	
			if(index<0 || index>length)
			{
				cout<<"OutOfBound\n";
				exit(0);
			}
			return data[index];
			
		}
				
	
};


int main()
{
	myString s1("Ravi");
	myString s2 = s1;
	myString s3 =s1 + "Giri";
	cout<<"S1 : "<<s1<<endl;
	cout<<"S2 : "<<s2<<endl;
	cout<<"S3 : "<<s3<<endl;
}

