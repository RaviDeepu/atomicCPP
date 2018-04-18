#include<iostream>

using namespace std;

void countSmallerNumbers(int a[], int n)
{
    
    int counter[n];

    for(int i=0;i<n;++i)
        counter[i] = 0;

    for(int i=0;i<n;++i)
    {
       for(int j=i+1;j<n;++j)
       {
           if(a[j] < a[i])
           {
               counter[i]++;
           }
       }
    }

    cout<<"Count Smaller Elements : "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<counter[i]<<endl;
    }
}


int main()
{
    int a[]={12, 1, 2, 3, 0, 11, 4};
    int size = sizeof(a)/sizeof(a[0]);
    
    countSmallerNumbers(a,size);

}
