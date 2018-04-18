#include<iostream>

using namespace std;


template<typename T, int n>
class MyArray
{
        T* a;
    public:
        MyArray()
        {
            a = new T[n];
        }
        ~MyArray()
        {
            delete []a;
        }

        T& operator[](int i)
        {
            return *(a+i);
        }
};

int main()
{
    MyArray<int,5> arr;
    for(int i=0;i<5;++i)
    {
        cout<<arr[i]<<endl;
    }

    cout<<"My Array\n";
    int *aa = new int[10];
    for(int i=0;i<10;++i)
    {
        cout<<aa[i]<<endl;;
    }
}

