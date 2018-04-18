#include<iostream>

using namespace std;



int findCandidate(int a[], int size)
{
    int majIndex=0;
    int count=1;
    for(int i=1;i<size;++i)
    {
        if(a[majIndex] == a[i])
            count++;
        else
            count--;

        if(count == 0)
        {
            majIndex = i;
            count = 1;
        }
    }
    
    return a[majIndex];
}

void isMajority(int a[], int size, int item)
{
    int count=0;
    for(int i=0;i<size;++i)
    {
        if(item == a[i])
            count++;
    }

    if(count > (size/2))
    {
        cout<<"Majority Element : "<<item<<endl;       
    }
    else
    {
        cout<<"Sorry...!!!\n";
    }
    
}

int main()
{
    int a[]={2,3,2,1,2};
    int cand = findCandidate(a,5);
    cout<<"Canditate : "<<cand<<endl;
    isMajority(a,5,cand);
}
