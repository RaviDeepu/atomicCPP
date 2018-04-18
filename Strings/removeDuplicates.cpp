#include<iostream>

/*
Remove all duplicates from a given string
    Input -  geeksforgeek
    Output - geksfor
*/

using namespace std;

void removeDuplicates(char *str)
{
    int ipIndex=0,resIndex=0;
    int hashMap[256]={0};
    char temp;
    while(*(str+ipIndex))
    {
        temp = *(str+ipIndex);
        if(hashMap[temp] == 0)
        {
            hashMap[temp] = 1;
            *(str+resIndex) = *(str+ipIndex);
            resIndex++;
        }
        ipIndex++;

    }
    *(str+resIndex)='\0';
}


int main()
{
    char str[] = "geeksforgeeks";
    cout<<"Original String : "<<str<<endl;
    removeDuplicates(str);
    cout<<"After removing Duplicates : "<<str<<endl;
}
