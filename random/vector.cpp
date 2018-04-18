#include<iostream>
#include<vector>

using namespace std;


int main()
{
	// Constructor
    /*
	vector<int> first;
	vector<int> second(4,100);
	vector<int> third(second.begin(),second.end());
	cout<<"First \n";
	for(vector<int>::const_iterator it = first.begin() ; it!=first.end() ; ++it)
	{
		cout<<*it<<endl;
	}
	
	cout<<"Second\n";
	for(vector<int>::const_iterator it = second.begin() ; it!=second.end() ; ++it)
	{
		cout<<*it<<endl;
	}
	
	cout<<"Third\n";
	for(vector<int>::const_iterator it = third.begin() ; it!=third.end() ; ++it)
	{
		cout<<*it<<endl;
	}
	
	int myints[]={1,2,3,4,5};
	vector<int> fourth(myints,myints+4);
	cout<<"Fourth\n";
	for(vector<int>::const_iterator it = fourth.begin() ; it!=fourth.end() ; ++it)
	{
		cout<<*it<<endl;
	}
	
	// operator=
	vector<int> foo(3,0);
	vector<int> bar(5,0);
	
	cout<<"foo size : "<<foo.size()<<endl;
	cout<<"bar size : "<<bar.size()<<endl;
	
	foo=bar;
	
	bar=vector<int>();
	cout<<"foo size : "<<foo.size()<<endl;
	cout<<"bar size : "<<bar.size()<<endl;
    */
    // Assign
    vector<int> first;
    vector<int> second;
    vector<int> third;

    first.assign(7,100);

    vector<int>::iterator itr;
    
    itr = first.begin()+1;
    second.assign(itr,first.end()-1 );


    int myarray[]={1,2,3,4};

    third.assign(myarray, myarray+3);


    cout<<"First\n";
    for(vector<int>::const_iterator it = first.begin() ; it!=first.end() ; ++it)
	{
		cout<<*it<<endl;
	}
	

    cout<<"Second\n";
    for(vector<int>::const_iterator it = second.begin() ; it!=second.end() ; ++it)
	{
		cout<<*it<<endl;
    }


    cout<<"Third\n";
    for(vector<int>::const_iterator it = third.begin() ; it!=third.end() ; ++it)
	{
		cout<<*it<<endl;
    }

    vector<int> aa;
    vector<int> bb;
    bb.push_back(1);
    cout<<"aa size : "<<aa.size();
    cout<<"bb size : "<<bb.size();

    /*
    float f1 = -0.9054,f2 = 0.00001234;

    float f = f1 + f2 ;
    cout<<"\n Float: sum : "<<f<<endl;
    cout<<"f1 : "<<f1<<", f2 : "<<(double)f2<<endl;

    double baba=0.00001234;
    cout<<"Baba : "<<baba;
    //TCWeight : 150/TCIndex : -0.9054
    //CCWeight : 1610/CCIndex : -0.672882
    */

    float f1 = 0.0001, f2 = 0.00001;
    cout<<"F1 : "<<f1<<", F2 : "<<f2<<endl;

}
