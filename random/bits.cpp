#include<iostream>

using namespace std;

int print_bits(int n)
{
	int size = sizeof(n)*8,number=0;;
	for(int i=0;i<size;i++)
	{
		number=n & 1;
		cout<<number;
		n=n>>1;
	}
	cout<<"\n";
}

int turnOff_K_bit(int &n,int k)
{
	if(k <= 0)	
		return n;
		
	n = n & ~(1 << (k-1));
	return (n);
}

int main()
{
	int n,turnOff;
	cout<<"Enter any number\n";
	cin>>n;
	print_bits(n);
	cout<<"Enter the Bit to be turned off\n";
	cin>>turnOff;
	cout<<turnOff_K_bit(n,turnOff)<<"\n";
	cout<<"After Turning -- "<<n<<"\n";
	print_bits(n);
}
