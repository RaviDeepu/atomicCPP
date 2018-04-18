#include<iostream>

using namespace std;

// a[]={1,0,0,0,1,1,0,1,1}
// Count number of 0's in a[]. 
// Let the number od 0's be C. Push C number of 0's at begininng and replace n-c 1's at end in a[].
void segregateByCounting(int a[], int n)
{
    int count0=0;
    for(int i=0;i<n;++i)
    {
        if(a[i] == 0)
            count0++;
    }

    int count1 = n - count0;


    cout<<"Number of 0 : "<<count0<<endl;
    cout<<"Number of 1 : "<<count1<<endl;
    // Push number of 0s count0 at the beginning of a[].
    for(int i=0;i<count0;++i)
    {
        a[i]=0;
    }
    //Push number of 1's count1 at the beginning of a[].
    for(int i=count0;i<n;++i)
    {
        //cout<<"1"<<endl;
        a[i] = 1;
    }
}

void segregateBySwapping(int a[], int size)
{
    int i=0,j=size-1;

    while(i<j)
    {
        while(a[i] == 0 && i<j)
            i++;
        while(a[j] == 1 && i<j)
            j--;
        
        if(i<j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
}

void printArray(int a[], int size)
{
    for(int i=0;i<size;++i)
    {
        cout<<a[i]<<endl;
    }
}

int main()
{
    int a[]={1,0,0,1,0,1,0,1,0,1,1};
    int size = sizeof(a)/sizeof(a[0]);

    //segregateByCounting(a,size);

    cout<<"Segregate By Swapping "<<endl;
    segregateBySwapping(a,size);

    printArray(a,size);
}


























//DCS_LOG_DEBUG("")









