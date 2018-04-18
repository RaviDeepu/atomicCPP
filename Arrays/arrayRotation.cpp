#include<iostream>

using namespace std;

void shift(int a[], int size)
{

    // Shift all the elements in a to the left.
    for(int i=0;i<size-1;++i)
    {
        a[i] = a[i+1];
    }
}

void displayArray(int a[], int n)
{

    cout<<"Display The Array : "<<endl;
    // Print the Array.
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<endl;
    }
}

// Copy d elements into an tempArray.
// Shift all the elements from main array to left.
// Copy back from tempArray to main array a at appropriate place.
void rotateArrayUsingTempArray(int a[], int size, int d)
{
    int tempArray[d];
    // Copy only d elements into the tempArray.
    for(int i=0;i<=d;++i)
    {
        tempArray[i] = a[i];
    }

    for(int i=0 ; i<d ; ++i)
    {
        shift(a,size);
    }

    for(int i=0;i<size;++i)
    {
        cout<<a[i]<<endl;
    }

    int index = 0;
    // Now copy the tempArray elements into the main array a[].
    for(int i=size-d;i<size;++i)
    {
        // i points to the index which needs to be replaced.
        // i-d points from the starting index in tempArray.
        a[i] = tempArray[index++];
    }
    displayArray(a,size);
}

void reverse(int a[], int start, int end)
{
    while(start < end)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

void rotateUsingReversalAlgorithm(int a[], int size, int d)
{
    reverse(a,0,d-1);

    displayArray(a,size);
    reverse(a,d,size-1);

    displayArray(a,size);
    reverse(a,0,size-1);

    displayArray(a,size);
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8};

    int rotateby;
    cout<<"Please enter the number by which array will be rotated.";
    cin>>rotateby;

    int n = sizeof(a)/sizeof(a[0]);
    //rotateArrayUsingTempArray(a,n,rotateby);

    rotateUsingReversalAlgorithm(a,n,rotateby);

}
