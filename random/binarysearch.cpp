#include<iostream>

using namespace std;


int binarysearch(int a[],int first, int last,int item)
{
	if(first < last)
	{
		int mid=(first+last)/2;
		if(a[mid] == item)
		{
			cout<<"Hurrrrrrrrrrrrrr\n";
			return mid;
		}
		if(item < a[mid])
			binarysearch(a,0,mid-1,item);
		else
			binarysearch(a,mid+1,last,item);
	}
}


int main()
{
	int a[]={1,2,3,4,5,6,7,8};
	int size=sizeof(a)/sizeof(a[0]);
	binarysearch(a,0,size,7);
}
