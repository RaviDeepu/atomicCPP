// C++ program to rearrange a string so that all same 
// characters become at least d distance away
#include <iostream>
#include <cstring>
#include <cstdlib>
#define MAX 6
using namespace std;
 
// A structure to store a character 'c' and its frequency 'f'
// in input string
struct charFreq {
    char c;
    int f;
};
 
// A utility function to swap two charFreq items.
void swap(charFreq *x, charFreq *y) {
    charFreq z = *x;
    *x = *y;
    *y = z;
}
 
// A utility function to maxheapify the node freq[i] of a heap 
// stored in freq[]
void maxHeapify(charFreq freq[], int i, int heap_size)
{
    int l = i*2 + 1;
    int r = i*2 + 2;
    int largest = i;
    if (l < heap_size && freq[l].f > freq[i].f)
        largest = l;
    if (r < heap_size && freq[r].f > freq[largest].f)
        largest = r;
    if (largest != i)
    {
        cout<<freq[i].c<<", "<<freq[largest].c<<endl;
        swap(&freq[i], &freq[largest]);
        maxHeapify(freq, largest, heap_size);
    }
}
 
// A utility function to convert the array freq[] to a max heap
void buildHeap(charFreq freq[], int n)
{
    int i = (n - 1)/2;
    while (i >= 0)
    {
        maxHeapify(freq, i, n);
        i--;
    }
}
 
// A utility function to remove the max item or root from max heap
charFreq extractMax(charFreq freq[], int heap_size)
{
    charFreq root = freq[0];
    if (heap_size > 1)
    {
        freq[0] = freq[heap_size-1];
        maxHeapify(freq, 0, heap_size-1);
    }
    return root;
}
 
// The main function that rearranges input string 'str' such that
// two same characters become d distance away 
void rearrange(char str[], int d)
{
    // Find length of input string
    int n = strlen(str);
 
    // Create an array to store all characters and their
    // frequencies in str[]
    charFreq freq[MAX] = {{0, 0}};
 
    int m = 0; // To store count of distinct characters in str[]


    // Traverse the input string and store frequencies of all
    // characters in freq[] array.
    for (int i = 0; i < n; i++)
    {        
        char x = str[i];
 
        // If this character has occurred first time, increment m
//        if (freq[x].c == 0)
//            freq[x].c = x, m++;
 
//        (freq[x].f)++;
        str[i] = '\0';  // This change is used later 
    }
//  abbcccddddeef

    m = 6;
    freq[0].c='a'; freq[0].f=1;
    freq[1].c='b'; freq[1].f=2;
    freq[2].c='c'; freq[2].f=3;
    freq[3].c='d'; freq[3].f=4;
    freq[4].c='e'; freq[4].f=2;
    freq[5].c='f'; freq[5].f=1;
    // Build a max heap of all characters
    buildHeap(freq, MAX);

    cout<<"Print Heap \n";
    for(int i=0;i<MAX;++i)
    {
        cout<<i<<", "<<freq[i].c<<", "<<freq[i].f<<endl;
    }
    // Now one by one extract all distinct characters from max heap
    // and put them back in str[] with the d distance constraint
    for (int i = 0; i < m; i++)
    {
        charFreq x = extractMax(freq, MAX-i);

        cout<<"MAX Character : "<<x.c<<endl;
        // Find the first available position in str[]
        int p = i;
        while (str[p] != '\0')
            p++;
 
        // Fill x.c at p, p+d, p+2d, .. p+(f-1)d
        for (int k = 0; k < x.f; k++)
        {
            // If the index goes beyond size, then string cannot
            // be rearranged.
            if (p + d*k >= n)
            {
                cout << "Cannot be rearranged";
                exit(0);
            }
            str[p + d*k] = x.c;
        }
    }
}
 
// Driver program to test above functions
int main()
{
    char str[] = "abbcccddddeef";
    rearrange(str, 2);
    cout << str<<endl;

}
