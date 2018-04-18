/*
Replace every element with the greatest element on right side
Given an array of integers, replace every element with the next greatest element (greatest element on the right side) in the array. Since there is no element next to the last element, replace it with -1. For example, if the array is {16, 17, 4, 3, 5, 2}, then it should be modified to {17, 5, 5, 5, 2, -1}.

The question is very similar to this post and solutions are also similar.
*/



#include<iostream>
#include<stack>

using namespace std;

void getNextGreaterElement_Stack(int a[], int n)
{
    stack<int> st;
    st.push(0);
    for(int i=1;i<n;i++)
    {
        while(!st.empty()&&a[i]>a[st.top()])
        {
              a[st.top()] = a[i];
              st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
         a[st.top()] = -1;
         st.pop();
    }

    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<endl;
    }
}

void getNextGreaterElement(int a[], int size)
{
    int maxNumber;
    maxNumber = a[size-1];

    a[size-1] = -1;

    for(int i=size-2;i>=0;i--)
    {
        if(a[i] < maxNumber)
            a[i] = maxNumber;
        else
        {
            maxNumber = a[i];
            a[i] = -1;
        }
    }

    for(int i=0;i<size;++i)
    {
        cout<<a[i]<<endl;
    }
}

int main()
{
    int a[]={16,17,4,3,5,2};
    int size = sizeof(a)/sizeof(a[0]);


    //getNextGreaterElement_Stack(a,size);

    getNextGreaterElement(a,size);

    return 0;
}
