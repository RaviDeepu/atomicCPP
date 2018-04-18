#include<iostream>

using namespace std;

int equilibrium(int arr[], int n)
{
       int sum = 0;      // initialize sum of whole array
       int leftsum = 0; // initialize leftsum
       int i;
              
       /* Find sum of the whole array */
       for (i = 0; i < n; ++i)
           sum += arr[i];

        cout<<"Total Sum : "<<sum<<endl;
       for( i = 0; i < n; ++i)
       {

            cout<<"Sum After Subtracting : "<<sum<<" = "<<sum<<" - "<<arr[i]<<endl;
            sum -= arr[i]; // sum is now right sum for index i
            if(leftsum == sum)
                return i;
                                                                         
            leftsum += arr[i];
        }
                                                                                   
        /* If no equilibrium index found, then return 0 */
        return -1;
}
 
 int main()
 {
       int arr[] = {-7, 1, 5, 2, -4, 3, 0};
         int arr_size = sizeof(arr)/sizeof(arr[0]);
         //  printf("First equilibrium index is %d\n", equilibrium(arr, arr_size));

        cout<<"First equilibrium index is : "<<equilibrium(arr, arr_size)<<endl;
            
              //getchar();
                return 0;
 }
