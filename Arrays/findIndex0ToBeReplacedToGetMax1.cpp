/*
    Find Index of 0 to be replaced with 1 to get longest continuous sequence of 1s in a binary array
    Given an array of 0s and 1s, find the position of 0 to be replaced with 1 to get longest continuous sequence of 1s. Expected time complexity is O(n) and auxiliary space is O(1).
    Example:

    Input: 
       arr[] =  {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1}
       Output:
         Index 9
         Assuming array index starts from 0, replacing 0 with 1 at index 9 causes
         the maximum continuous sequence of 1s.

         Input: 
            arr[] =  {1, 1, 1, 1, 0}
            Output:
              Index 4
*/


#include<iostream>

using namespace std;

/*
    Keep a count of three indexes, cur,prevZero, prevprevZero.
    If the element is 0 and cur - prevprevZero > max_count then update the max_count.
    Update prev_zero and prev_prev_zero respectively.
*/

int indexToReplace0(int a[], int n)
{
    int index, max_count=0;
    int prev_zero=-1,prev_prev_zero=-1;

    for(int cur=0;cur<n;++cur)
    {
        if(a[cur] == 0)
        {
            if(cur - prev_prev_zero > max_count)
            {
                max_count = cur-prev_prev_zero;
                index = prev_zero;
            }

            prev_prev_zero = prev_zero;
            prev_zero = cur;
        }
    }

    // Update for the last 0 found.

    if(n-prev_prev_zero > max_count)
    {
        index = prev_zero;
    }

    return index;
}


int main()
{
    //int a[]={1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
    int a[]={1,1,1,1,0};
    int size = sizeof(a)/sizeof(a[0]);

    cout<<"Index of 0 to be replaces to get Maximum 1's : "<<indexToReplace0(a,size)<<endl;
    return 0;
}
