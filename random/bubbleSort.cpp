#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;


int main()
{
	int number1[]={10,40,34,65,32,56,5};
	
	cout<<"SortFile\n";
	//cout<<"NumberOfLines :"<<numberOfLines<<endl;
	for(int i=0 ;i<7 ; i++)
	{
		//cout<<number1[i]<<endl;;	
	}


	// Sort
	for(int i=0 ;i<7 ; i++)
	{
		for(int j=0; j<7 - i ; j++)
		{
			if(number1[j] > number1[j+1])
			{
				int temp = number1[j];
				number1[j] = number1[j+1];
				number1[j+1] = temp;


			}
		}
	}

	cout<<"After Sort\n";
	cout<<"-----------------------------------------\n";
	for(int i=0 ;i<7 ; i++)
	{
		cout<<number1[i]<<endl;;	
	}
}

