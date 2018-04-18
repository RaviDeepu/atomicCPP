#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int findPlatform(int arr[], int dep[], int n) 
{
    // Sort Arrival and Departure arrays.
    sort(arr,arr+n);
    sort(dep,dep+n);


    int i=1,j=0;
    int callOperatorNeeded=1;
    int result=2;
    
    while(i<n && j<n)
    {
        if(arr[i] < dep[j])
        {
            callOperatorNeeded++;
            i++;

            if(callOperatorNeeded > result)
                result = callOperatorNeeded;
        }
        else
        {
            callOperatorNeeded--;
            j++;
        }
    }

    return result;

}

// Driver program to test methods of graph class
int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n)<<endl;
    return 0;
}

