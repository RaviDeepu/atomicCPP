#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;

void remove_repetitions(int* a, int& size)
{
        if (size<2) return;
        set<int> s;
        unsigned removeIndex = 0;
        for (unsigned i=0; i<size; i++)
        {
                if (s.find(a[i]) != s.end()){
                        if (removeIndex == 0) removeIndex = i;
                } else if (removeIndex>0) {
                        a[removeIndex++] = a[i];
                }
                s.insert(a[i]);
        }
        if (removeIndex>0) size = removeIndex;
}


int main()
{
    unordered_set<int> aa;
    aa.insert(1);
    aa.insert(20);
    aa.insert(30);
    aa.insert(100);
    aa.insert(200);
    aa.insert(300);


    for(auto a : aa)
    {
        //cout<<a<<endl;
    }

    int a[]={1,2,3,4,5,6,7,1,2,3,5,8};

    int size = sizeof(a)/sizeof(a[0]);

    for(int i=0 ; i<size ; ++i)
    {
        cout<<a[i]<<endl;
    }

    cout<<"=====================\n";
    remove_repetitions(a,size);
        
    for(int i=0 ; i<size ; ++i)
    {
        cout<<a[i]<<endl;
    }


}
