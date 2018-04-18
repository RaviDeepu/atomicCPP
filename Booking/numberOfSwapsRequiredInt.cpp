#include<iostream>
#include<map>

using namespace std;


/*

1. Starting from first digit, check next n digits. Record the position of biggest one. Here n=swapsAllowed.
2. Bubble the biggest digit to the top. Reduce n by no. of swaps. Reset n to -> n=n-(distance of biggest digit from top) 
3. Move to second digit, repeat #1 with new value of n. 
4. Repeat 3 until n or no. of digits are exhausted. 

Time needed - O(n2). Space O(1) 

*/

int findMax(int a[], int start, int end)
{
    int max=start;
    for(int i=start ; i<end ; ++i)
    {
        if(a[i] > a[max])
            max = i;
    }

    return max;
}

void findMaxNumber(int n)
{
    int tNumber = n;
    int count=0;

    while(tNumber > 0)
    {
        tNumber = tNumber/10;
        count++;
    }

    cout<<"Count : "<<count<<endl;

    int newNumber[count+1];
    
    tNumber = n;
    int k=count-1;
    
    while(tNumber > 0)
    {
        newNumber[k] = tNumber%10;
        tNumber = tNumber/10;
        k--;
    }

    int numberOfSwaps = 3;

    for(int i=0 ; i<count && numberOfSwaps > 0 ; ++i)
    {
        int maxId = findMax(newNumber,i+1,count);
        if(newNumber[i] != newNumber[maxId])
        {
            int t = newNumber[maxId];   
            newNumber[maxId] = newNumber[i];
            newNumber[i] = t;
            numberOfSwaps--;
        }
    }
    
    cout<<"Final\n";
    for(int i=0 ; i<count; i++)
    {
        cout<<newNumber[i]<<endl;
    }

}

void findMaxNumberMap(int n)
{
    map<int,int,greater<int>> myMap;
    
    int tNumber = n;

    int count = 0;

    while(tNumber > 0)
    {
        tNumber = tNumber/10;
        count++;
    }

    cout<<"Count : "<<count<<endl;
    int k = count-1;

    tNumber = n;

    while(tNumber > 0)
    {
        int res = tNumber%10;;
        myMap[res] = k;
        tNumber = tNumber/10;
        k--;
    }


    for(auto a : myMap)
    {
        cout<<a.first<<" "<<a.second<<endl;
    }
    
    int i=0;

    for(map<int,int>::iterator it = myMap.begin(), i=0 ; it != myMap.end() , i < numberOfSwaps ; ++it, i++;)
    {
        
    }

}

int main()
{
    int n=123456;

    //findMaxNumber(n);

    findMaxNumberMap(n);

}
