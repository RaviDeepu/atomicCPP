#include<iostream>
#include<string>

using namespace std;


void fun(string& s)
{
    cout<<s<<endl;
}
int main()
{
    char s[]="Ravi Giri";
    fun(s);
}
