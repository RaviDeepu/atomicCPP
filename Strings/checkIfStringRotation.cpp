/*
A Program to check if strings are rotations of each other or not
Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1 using only one call to strstr routine?
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)
*/

#include<iostream>


using namespace std;

int myStrlen(char *str)
{
    int len = 0;
    while(*str++)
    {
        len++;
    }
    return len;
}

/*
char* myStringConCat(char dest[], char src[])
{
    char temp[100];
    int i=0;
    while(dest[i])
    {
        temp[i] = dest[i];
        i++;
    }
    int j=0;
    while(src[j])
    {
        temp[i] = src[j];
        i++;
        j++;
    }
    return temp;
}
*/

void myStringConCat(char *dest, char *src)
{
    while(*dest)
        dest++;

    while(*dest++ = *src++);
}


// ravigiri
// avig
int mySubString(char* mstr, char* sstr)
{
    int mlen,slen;
    mlen = myStrlen(mstr);
    slen = myStrlen(sstr);

    cout<<"Main String : "<<mstr<<endl;
    cout<<"Sub String : "<<sstr<<endl;
    for(int i=0;i<mlen;i++)
    {
        int j=0;
        for(j=0;j<slen;j++)
        {
            if(mstr[i+j] != sstr[j])
                break;
        }

        if(j == slen)
        {
            cout<<"SubString Found\n";
            return i;
        }
    }
    cout<<"SubString Not Found\n";
    return -1;
}


bool ifStringsAreRotated(char* s1, char* s2)
{
    char temp[100]="";
    myStringConCat(temp,s1);
    myStringConCat(temp,s1);

    cout<<"CONCATENATED : "<<temp<<endl;
    if(mySubString(temp,s2) > 0)
    {
        return true;
    }
    return false;
}


int main()
{
    char s1[100]="abac";
    char s2[100]="acab";

    //myStringConCat(s1,s1);
    
    if(ifStringsAreRotated(s1,s2))
    {
        cout<<"Yes String Are Rotated"<<endl;
    }
    else
    {
        cout<<"NO String Are NOT Rotated"<<endl;
    }
    
}

