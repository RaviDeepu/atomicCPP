#include<iostream>
#include<string.h>

#define MAX 256
using namespace std;



// The Below function will print the Output as 
/*
Input : aaabbbcccccd
OutPut : a3b3c5d1
*/
void compressString(char *str)
{
	bool hash_bin[MAX] = {0};
	char tempChar;
	char tempString[strlen(str+1)];

	int count=1,i=0,tempStrCounter=0;
	tempChar = *(str+i);
	tempString[tempStrCounter++]=tempChar;

	hash_bin[tempChar]=1;
	i++;
	while(*(str+i))
	{	
		tempChar = *(str+i);
		if(hash_bin[tempChar] == 1)
			count++;
		else
		{
			tempString[tempStrCounter++]=count+'0';
			tempString[tempStrCounter++]=tempChar;
			hash_bin[tempChar]=1;
			count=1;
		}
		i++;	
	}
	tempString[tempStrCounter++]=count+'0';
	tempString[tempStrCounter]='\0';

	cout<<"OutPut : "<<tempString<<endl;
}



int main()
{
	char str[]="aaabbbcccccd";
	compressString(str);
}
