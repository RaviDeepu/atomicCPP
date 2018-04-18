#include<iostream>
#include<algorithm>
using namespace std;

void myReverse(string& s, int start, int end)
{
    cout<<"MyReverse : Start - "<<s.c_str()<<endl;

    cout<<"Start - "<<start<<" , End : "<<end<<endl;
    while(start < end)
    {
        char temp = s[start];
        s[start] = s[end-1];
        s[end-1] = temp;
    
        start++;
        end--;
    }
    cout<<"MyReverse : End - "<<s.c_str()<<endl;
}


char* myItoa(int n)
{
    string s;
    int neg = 0;
    int res;
    int i=0;     

    if(n < 0)
        neg = 1;

    if(neg)
    {
        n = n*-1;
        i=1;
    }

    while(n > 0)
    {
        res = n%10;
        s[i] = res+'0';
        i++;
        n = n/10; 
    }

    s[i] = '\0';
    cout<<s.c_str()<<endl;

    if(neg)
        s[0]='-';

    if(neg)
        myReverse(s,1,i);
    else
        myReverse(s,0,i);
    cout<<s.c_str()<<endl;
}

int main()
{
    int a = -1234;
    cout<<a<<endl;
    cout<<myItoa(a)<<endl;
}
