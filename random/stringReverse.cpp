#include<iostream>
//#include<>

using namespace std;

int xstrlen(char *str)
{
	int len = 0;
	while(*str++)
		len++;
	return len;
}

void xstrrev(char *str)
{
	int len = xstrlen(str) - 1;	
	int i=0;
	char temp;
	while(i <= len/2)
	{
		temp = str[i];
		str[i] = str[len-i];
		str[len-i] = temp;
		i++;
	}
}

void reverse_words_in_sentence(char *str)
{
	int index = 0,i;
	xstrrev(str);
	cout<<"Full Reverse == "<<str<<"\n";
	int len = xstrlen(str);
	for(i=0 ; i<=len ; i++)
	{
		if(str[i] == ' ' || str[i] == '\0')
		{	
			str[i] = '\0';
			xstrrev(&str[index]);
			index = i+1;
			str[i] = ' ';
		}
	}	
	str[i] = '\0';
}

int main()
{
	char str[150];
	cout<<"Enter any random string\n";
	gets(str);
	cout<<"Length of "<<str<<" is == "<<xstrlen(str)<<"\n";
	cout<<"Reverse of "<<str<<" is == ";
	reverse_words_in_sentence(str);
	cout<<str<<"\n";
}
