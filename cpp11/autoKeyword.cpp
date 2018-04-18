#include<iostream>
#include<vector>
using namespace std;

void foo(char *c)
{
    cout<<"Foo = char*c\n";
}

void foo(int i)
{
    cout<<"Foo = int(i)\n";
}

int main()
{
    vector<int> v {1,2,3,4,5};
    vector<int> a,b;
    
    for(auto item : v)
        a.push_back(item);

    for(auto item : v)
        b.push_back(item);

    cout<<"A Vector\n";
    for(auto iter = a.begin() ; iter != a.end() ; ++iter)
        cout<<*iter<<endl;

    cout<<"B Vector\n";
    for(auto iter = b.begin() ; iter != b.end() ; ++iter)
        cout<<*iter<<endl;

    foo(NULL);
    //cout<<decltype(v.begin());
}
