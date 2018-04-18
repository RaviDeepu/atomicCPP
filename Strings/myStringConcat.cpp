#include<iostream>

using namespace std;

void mystrcat(char *src, char *dest)
{
    while(*dest)
        dest++;

    while(*dest++ = *src++);
}


int main()
{
    char src[]="Giri";
    char dest[]="Ravi";

    mystrcat(src,dest);

    cout<<dest<<endl;

}
