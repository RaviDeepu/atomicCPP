#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;


int xstrlen(char *p)
{
	int len=0;
	char *str = p;
	while(*str++)
		len++;
	return len;
}

void xstrncpy(char *dest,char *src,int n)
{
	for(int i=0;i<n;i++)
	{
		dest[i] = src[i];
	}
}


class myString
{
		int length;
		char *data;
	public:
		myString():length(0),data(NULL)
		{
			cout<<"Default Constructor\n";
		}		
		myString(char *s):length(xstrlen(s)),data(new char[length])
		{
			cout<<"Param Constructor\n";
			xstrncpy(data,s,length);

		}

		myString(const myString &s):length(s.length),data(new char[length])
		{
			xstrncpy(data,s.data,length);
			cout<<"Copy Constructor\n";
		}
		
		~myString()
		{
			cout<<"Destructor\n";
			delete [] data;
		}

		myString& operator=(const myString& other)
		{
			if(this != &other)
			{
				delete [] data;
				length = other.length;
				data = new char[length];
				xstrncpy(data,other.data,length);
				cout<<"Assignment Operator\n";
			}
			return *this;
		}

		// Concatenation Operator
		friend myString operator+(const myString &s1, const myString &s2)
		{
			myString res;
			res.length = s1.length+s2.length;
			res.data = new char[res.length];
			xstrncpy(res.data,s1.data,res.length);
			xstrncpy(res.data+s1.length,s2.data,res.length);
			return res;
		}	

		friend ostream& operator<<(ostream& os, const myString& s)
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
				cout<<"OutOfBound Index\n";
				exit(0);
			}
			return data[index];
		}
		
};


int main()
{
	// construction and initialization

	  myString a = "Hello ";
	  myString b = a;
	  myString c;

	  cout << a << b << c << endl;

	  cout << "------------------------------------------" << endl; 

	  // value swap

	  myString u = "123";
	  myString v = "class";
	  
	  c = u;
	  u = v;
	  v = c;

	  cout << u << v << c << endl;

	  cout << "------------------------------------------" << endl; 

	  // creating a few temporaries and testing +

	  myString w = a + u;

	  cout << w << endl; 
	cout<<"Problem\n";

	 // cout << myString("Beam me up") + myString(", Scotty!") << endl;

		cout<<"Problem\n";
	  cout << "------------------------------------------" << endl; 

	  // a miracle: although operator= is defined only for another myString,
	  // the following line has the same effect as 
	  //                                           a = myString( "Hi ");
	  // Notice that a temporary is contsructed and then destroyed.
	  // Lesson: C++ uses your constructor to construct objects as it sees fit.  

	  a = "Hi ";

	  cout << a << b << endl;

	  cout << "------------------------------------------" << endl; 

	  // Copy contructor is also used when passing parameters to functions
	  // by value (but not by reference)

	  myString x = "i am given to foo"; 
	  myString y = "i am given to bar"; 

	  //foo( x );  

	  cout << "And now x is: " << x << endl;

	 // bar( y );                 // notice the call to the copy constr.

	  cout << "And now y is: " << y << endl; 

	  cout << "------------------------------------------" << endl; 

	  // check operator[]

	  myString t = "hello old friend.";
	  t[0] = 'H';
	  t[6] = 'O';
	  t[10] = 'F';

	  cout << t << endl;

	  cout << "------------------------------------------" << endl; 

	  return 0;  // return 0 to signal normal completion to the OS 

}
