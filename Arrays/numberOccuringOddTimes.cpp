#include<iostream>

using namespace std;

// XOR will result to 0 if it is XORed with the same number.
int numberOddTimesXOR(int a[], int size)
{
    int res = 0;
    for(int i=0;i<size;++i)
    {
        res = res ^ a[i];
    }
    return res;
}

int main()
{

    int a[]={1,2,3,2,3,1,1};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<"Array Size : "<<size<<endl;
    cout<<"Number Occuring Odd Number Of Times : "<<numberOddTimesXOR(a,size)<<endl;;

}
