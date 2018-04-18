#include<iostream>
#include<string.h>
using namespace std;

// Recursive
/*
bool isSubSequence(char *firstStr, char *secondStr, int m, int n)
{
    if(m == 0)
        return true;

    if(n == 0)
        return false;


    if(firstStr[m-1] == secondStr[n-1])
        return isSubSequence(firstStr,secondStr,m-1,n-1);
    else
        return isSubSequence(firstStr,secondStr,m,n-1);

}
*/




//Iterative
bool isSubSequence(char *firstStr, char *secondStr, int m, int n)
{
    int count=0;
    for(int i=0;i<strlen(secondStr);++i)
    {
        if(firstStr[count] == secondStr[i])
        {
            cout<<"Match : "<<firstStr[count]<<" and "<<secondStr[i]<<endl;
            count++;
        }
    }

    cout<<"Count : "<<count<<"Strlen(SecondStr) : "<<strlen(secondStr)<<endl;
    if(count == strlen(firstStr))
        return true;

    return false;

}


int main()
{
    char firstStr[]="ABN";
    char secondStr[]="DANBFVCD";

    bool f = isSubSequence(firstStr,secondStr,strlen(firstStr),strlen(secondStr));
    if(f)
        cout<<"YESSSSSSSSSSS\n";
    else
        cout<<"NOOOOOOOOOOO\n";
}
