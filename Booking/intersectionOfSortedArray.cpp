#include<iostream>

using namespace std;

void printArray(int a[], int n)
{
    for(int i=0 ; i<n ; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void printIntersection(int a[], int sizeA, int b[], int sizeB)
{
    int i=0,j=0;

    while((i<sizeA) && (j<sizeB))
    {
        if(a[i] < b[j])
            j++;
        else if(a[i] > b[j])
            
    }
}

int main()
{
    int a[]={2,4,6,8,10};
    int b[]={1,2,3,4,5,6,7,8,9};

    int sizeA = sizeof(a)/sizeof(a[0]);
    int sizeB = sizeof(b)/sizeof(b[0]);

    printArray(a,sizeA);
    printArray(b,sizeB);

    printIntersection(a,sizeA,b,sizeB);

}
