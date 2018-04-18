#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*
Time Complexity: O(nLogn), assuming that a O(nLogn) sorting algorithm for sorting arr[] and dep[].
*/

int findNumberOfExecutives(vector<int>& arr, vector<int>& dep, int noOfExecutives) 
{
    // Sort Arrival and Departure arrays.
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());


    int i=1,j=0;

    int callOperatorNeeded=1;
    int result=1;
    int n = arr.size();

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

    result = result-noOfExecutives;;

    return result;
}

// Driver program to test methods of graph class
int main()
{
    //int arr[] = {900, 940, 950, 1100, 1500, 1800};
    //int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int noOfExecutives;
    int n,temp;
    vector<int> arrival;
    vector<int> departure;
    
    cin>>noOfExecutives;

    cin>>n;

    for(int i=0 ; i<n ; ++i)
    {
        cin>>temp;
        arrival.push_back(temp);

        cin>>temp;
        departure.push_back(temp);     
    }   
 
    //int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findNumberOfExecutives(arrival, departure, noOfExecutives)<<endl;
    return 0;
}

