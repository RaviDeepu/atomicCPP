#include<iostream>
using namespace std;

class top
{
	public:
		top()
		{
			cout<<"Top Default\n";
		}
		top(int val):a(val)
		{
			cout<<"Top Param\n";
		}
		int a;
};

class left:public virtual top
{
	public:
		int d1;
		left()
		{
			cout<<"left Default\n";
		}
		left(int val):d1(val)
		{
			cout<<"left Param\n";
		}
};

class right:public virtual top
{
        public:
                int d2;
		right()
		{
			cout<<"right Default\n";
		}
		right(int val):d2(val)
		{
			cout<<"right Param\n";
		}
};

class bottom:public left,public right
{
        public:
                int d3;

		bottom():left(10),right(20)
		{
			cout<<"bottom Default\n";
		}
		bottom(int val):d3(val)
		{
			cout<<"bottom Param\n";
		}

};

int main()
{
        //derived3 dd;
	bottom b;
//        cout<<dd.a<<endl;

}

