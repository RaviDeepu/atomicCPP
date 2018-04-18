#include<iostream>
#include<map>
#include<cstdlib>
#include<unordered_map>
#include<ctime>

using namespace std;

int main()
{
    int n=1000000;
    unordered_map<int, int> myMap;
    int i=0;
    const clock_t begin_time = clock();

    
    while(i < n)
    {
        int num = rand() % n;
        myMap[num]++;
        i++;
    }

    cout<<float(clock() - begin_time)/CLOCKS_PER_SEC<<endl;;
}
