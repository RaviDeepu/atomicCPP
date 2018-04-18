#include<iostream>

using namespace std;

/*
// Program to Find Factorial of a number using recursion.

int fact(int n)
{
	if(n == 0) return 1;
	return n*fact(n-1);
}
int main()
{
	int n=3;
	cout<<"Factorial of "<<n<<" is == "<<fact(n)<<"\n";
}
*/

/*
// Program to Print array elements in reverse order using recursion.

void print_array(int *a,int n)
{
	if(n == -1)
		return;
	
	cout<<a[n]<<"\n";
	//n-=1;
	return print_array(a,n-1); 
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<"Size : "<<n<<"\n";
	print_array(a,n-1);	
}
*/

// Program to sum all the array elements using recursion.
int sum_array(int *a,int n)
{
	if(n == -1)
		return 0;
	
	cout<<a[n]<<"\n";
	//n-=1;
	return a[n]+sum_array(a,n-1); 
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<"Size : "<<n<<"\n";
	cout<<"Sum of All the Array Elements : "<<sum_array(a,n-1)<<"\n";	
}
