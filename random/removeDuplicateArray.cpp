#include<iostream>
#include<set>

using namespace std;

void moveArrayIndex(int a[], int index, int n)
{
	for(int i=index;i<n;i++)
	{
		a[i]=a[i+1];
	}
}



int removeDup(int a[], int n)
{
	set<int> mySet;
	pair<set<int>::iterator, bool> ret;

	int i=0;
	ret = mySet.insert(a[i++]);

	while(i < n)
	{
		ret = mySet.insert(a[i]);
		if(ret.second == false)
		{
			moveArrayIndex(a,i,n);
			n--;
		}
		i++;
	}
	return n;
}


int main()
{
	int a[]={1,2,3,2,4,5,1};
	int max = removeDup(a,7);
	for(int i=0;i<max;i++)
		cout<<a[i]<<endl;
}
