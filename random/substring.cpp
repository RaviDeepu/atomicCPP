#include<iostream>
#include<string.h>

using namespace std;

void substring(char *mstr,char *sstr)
{
	int mlen,slen;
	mlen = strlen(mstr);
	slen = strlen(sstr);

	for(int i=0;i<mlen;i++)
	{
		int j;
		for(j=0;j<slen;j++)
		{
			if(sstr[j] != mstr[i+j])
				break;
		}
		if(j == slen)
		{
			cout<<"Substring Found\n";
			return;
		}
	}
	cout<<"Not a substring\n";
}

int main()
{
	char mstr[20],sstr[5];
	cout<<"Enter Main String\n";
	cin>>mstr;
	cout<<"Enter Sub String\n";
	cin>>sstr;
	substring(mstr,sstr);
	
}
