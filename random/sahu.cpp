#include<iostream>
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

using namespace std;

int a[]={1,2,3,4,5};

void fun()
{
    cout<<"******FUN*******\n";
    cout<<"Sizeof(a) : "<<ARRAY_SIZE(a)<<endl;
    cout<<"Sizeof(a[0]) : "<<sizeof(a[0])<<endl;
}
int main()
{
    //int a[]={1,2,3,4,5};
    //int size = sizeof(a)/sizeof(a[0]);
    int size = ARRAY_SIZE(a);
    cout<<"Size : "<<size<<endl;
    cout<<"Sizeof(int) : "<<sizeof(int)<<endl;
    fun();
}
