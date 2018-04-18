#include<iostream>

using namespace std;

void swap(int aa[],int i,int j)
{
	int temp = aa[i];
	aa[i] = aa[j];
	aa[j] = temp;
}

int partition(int a[],int left,int right)
{
	int P,i,j;
	static int ii = 1;

	cout<<"\n";
	cout<<ii<<"--Before \n";
	cout<<"Left -- "<<a[left]<<"  Right --"<<a[right]<<"\n"<<endl;
	for(int i=left ; i<=right ; i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	P = a[left];
	i = left;
	j = right + 1;
	for(;;)
	{
		while( a[++i] <= P )
			if(i >= right)
				break;

		while( a[--j] > P)
			if(j <= left)
				break;
	
		if( i < j )
			swap(a,i,j);
		else
			break;
	}
	if( j == left )
	{
		cout<<"\n";
		cout<<ii++<<"-- After\n";
		for(int i=left ; i<=right ; i++)
			cout<<a[i]<<" ";
		cout<<"\n";
		cout<<"Pivot -- "<<a[j]<<"\n"<<endl;


		return j;
	}

	swap(a,left,j);	

	cout<<"\n";
	cout<<ii++<<"-- After\n";
	for(int i=left ; i<=right ; i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	cout<<"Pivot -- "<<a[j]<<"\n"<<endl;

	return j;
}

void qsort(int x[],int first,int last)
{
	int i,j,pivot;
	int q;
	if(first < last)
	{
		q = partition(x,first,last);

		qsort(x,first,q-1);
		qsort(x,q+1,last);
	}
}

int main()
{
	int size,a[10];
	cout<<"Please enter the Size of Array\n";
	cin>>size;
	cout<<"Enter the Array elements\n";
	for(int i=0;i<size;i++)	
		cin>>a[i];
	
	qsort(a,0,size-1);
	
	for(int i=0;i<size;i++)	
		cout<<a[i];
}
