#include<iostream>


using namespace std;


// Search Linearly to find the Leaders in an Array.
// Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side. And the rightmost element is always a leader. For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.

// Use two loops to get a number and check with the other elements in an array to check if there is any other element exists lesser than the current element.

void leadersInArrayLinearSearch(int a[], int n)
{
    for(int i=0;i<n;++i)
    {
        int j;
        for(j=i+1;j<n;++j)
        {
            if(a[i] <= a[j])
                break;
        }
        // Loop did not break, it means it is the Leader.
        if(j == n)
            cout<<a[i]<<endl;
    }
}

void leadersInArrayScanFromRight(int a[], int n)
{
    int max_number = a[n-1];
    cout<<max_number<<endl;
    for(int i=n-2; i>= 0 ; i--)
    {
        if(max_number < a[i])
        {
            max_number = a[i];
            cout<<max_number<<endl;
        }
    }

}

int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    leadersInArrayLinearSearch(arr, n);


    leadersInArrayScanFromRight(arr,n);
    return 0;
}
