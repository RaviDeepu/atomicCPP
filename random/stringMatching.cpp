#include<iostream>
#include<string.h>


// In a string replace all occurrence of the given pattern to 'X'


using namespace std;


bool Matched(char *str, char *pat)
{
	int i=0;
	cout<<str<<endl;
	while(pat[i] != '\0')
	{
		if(pat[i] != str[i])
			return false;
		else
			i++;
	}
	return true;
}


char * replace(char *str, char *pat)
{
	int index=0,found=0,templength=0;
	int mainlen=strlen(str);
	int patlen = strlen(pat);
	char temp[256];
	char replace='X';
	while( index < mainlen )
	{
		found = 0;
		if(Matched((str+index),pat))
		{
			found = 1;
			index = index+patlen;
		}

		if(found)
		{
			temp[templength++]=replace;
		}
		else
		{
			temp[templength++]=str[index++];
		}
	}

	temp[templength]='\0';
	return temp;
}

int main()
{
	char *str="dabcabcfgabc";
	char *pattern="abc";

	str = replace(str,pattern);
	cout<<str<<endl;
}
