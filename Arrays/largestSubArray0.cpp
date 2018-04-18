/*
Largest subarray with equal number of 0s and 1s
Given an array containing only 0s and 1s, find the largest subarray which contain equal no of 0s and 1s. Expected time complexity is O(n).

Examples:

Input: arr[] = {1, 0, 1, 1, 1, 0, 0}
Output: 1 to 6 (Starting and Ending indexes of output subarray)
*/

#include<iostream>

using namespace std;

void findSubArray(int a[],int n)
{
    int sum=0;
    int maxSize=-1;
    int startIndex=0;
    for(int i=0;i<n;++i)
    {
        sum = (a[i] == 0)?-1:1;

        for(int j=i+1;j<n;j++)
        {
            (a[j] == 0) ? sum+=-1:sum+=1;
            if(sum == 0 && maxSize < (j-i+1))
            {
                maxSize = j-i+1;
                startIndex = i;
            }
        }
    }

    if(maxSize == -1)
        cout<<"No SubArray Found "<<endl;
    else
        cout<<"SubArray Found from : "<<startIndex<<" and "<<startIndex+maxSize-1<<endl;
}

int main()
{
    int a[]={1,0,0,1,0,1,1};
    int size = sizeof(a)/sizeof(a[0]);
    findSubArray(a,size);
    return 0;

}
