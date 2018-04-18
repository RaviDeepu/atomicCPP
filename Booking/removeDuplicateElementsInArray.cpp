#include<iostream>
#include<set>
#include<vector>

using namespace std;

void printArray(int *a, int n)
{
    for(int i=0 ; i<n ; ++i)
    {
        cout<<a[i]<<endl;
    }
}

void removeDuplicates(int* a, int& size)
{
    int removeIndex=0;
    set<int> s;

    for(int i=0 ; i<size ; ++i)
    {
        if(s.find(a[i]) != s.end())
        {
            if(removeIndex == 0)
                removeIndex = i;
        }
        else if(removeIndex > 0)
        {
            a[removeIndex++] = a[i];
        }        
        s.insert(a[i]);
    }

    if(removeIndex > 0)
        size = removeIndex;

}

int main()
{
    int a[]={2,1,3,4,1,4,6,7,3,8};
    int size = sizeof(a)/sizeof(a[0]);

    printArray(a,size);
    removeDuplicates(a,size);
    cout<<"==============\n";

    printArray(a,size);

    vector<int> v {1,2,3,4,5,6,7};

    v.erase(v.begin()+4,v.end());

    cout<<"VVVVVVVVVVVV\n";
    for(auto aa: v)
    {
        cout<<aa<<endl;
    }

}
