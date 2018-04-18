#include<iostream>
#include<stdio.h>
#include<string.h>

#define MAX_CHARS	256


// Program to Check whether two strings are anagram or not. 
using namespace std;


bool AreAnagram(char *s1,char *s2)
{
	int count1[MAX_CHARS]={0};
	int count2[MAX_CHARS]={0};

	int i=0;

	for(i=0;s1[i] && s2[i];i++)
	{
		count1[s1[i]]++;
		count2[s2[i]]++;
	}


	/*

	if(s1[i] || s2[i])
		return false;
	*/

	for(i=0;i<256;i++)
	{
		if(count1[i] != count2[i])
			return false;
	}

	return true;
}

int main()
{
	char str1[]="aaca";
	char str2[] = "aca";
	if(AreAnagram(str1,str2))
		cout<<"Anagram\n";
	else	
		cout<<"NOT Anagram\n";
}
