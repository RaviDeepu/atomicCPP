/*
Count triplets with sum smaller than a given value
Given an array of distinct integers and a sum value. Find count of triplets with sum smaller than given sum value. Expected Time Complexity is O(n2).

Examples:

Input : arr[] = {-2, 0, 1, 3}
        sum = 2.
        Output : 2
Explanation :  Below are triplets with sum less than 2
(-2, 0, 1) and (-2, 0, 3) 

Input : arr[] = {5, 1, 3, 4, 7}
sum = 12.
Output : 4
Explanation :  Below are triplets with sum less than 4
(1, 3, 4), (1, 3, 5), (1, 3, 7) and 
(1, 4, 5)
*/


#include<iostream>

using namespace std;

int countTriplet(int a[], int n, int sum)
{
    int counter=0;
    int i,j,k;
    for(i=0;i<n;++i)
    {
        j=i+1;
        k=n-1;
        while(j<k)
        {
            if(a[i] + a[j] + a[k] >= sum)
                k--;
            else
            {
                int jj=j,kk=k;
                while(jj < kk)
                {
                    cout<<a[i]<<" , "<<a[jj]<<" , "<<a[kk]<<endl;
                    //jj++;
                    kk--;
                }
                // For current i and j value, there can be total k-j third elements.
                counter += k-j;
                j++;

            }
        }
    }
    return counter;
}


int main()
{
    int a[]={1,3,4,5,7};
    int sum = 12;
    int size = sizeof(a)/sizeof(a[0]);


    cout<<"Number Of Triplets : "<<countTriplet(a,size,sum)<<endl;
}
