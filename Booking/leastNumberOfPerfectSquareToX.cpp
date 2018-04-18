#include<iostream>
#include<math.h>

using namespace std;

int min(int a, int b)
{
    return (a<b?a:b);
}

void findPerfectSquare(int n)
{
    int table[n+1];
    table[0]=0;
    table[1]=1;
    table[2]=2;
    table[3]=3;


    int denom[n+1];

    denom[0]=0;
    denom[1]=1;
    denom[2]=1;
    denom[3]=1;

    int temp = sqrt(n);

    if(n*n == temp)
    {
        cout<<"Number itself is Perfect Square\n";
        return;
    }


    for(int i=4 ; i<=n ; ++i)
    {
        table[i] = i;
        for(int j=1 ; j<=sqrt(i) ; ++j)
        {
            int temp = j*j;
            if(temp > n)
                break;

            table[i] = min(table[i], 1 + table[i-temp]);
            denom[i] = temp;   
        }
    }

    //int ;
    while(n)
    {
        cout<<denom[n]<<" ";
        n = n-denom[n];
    }

}


int main()
{
    int n;

    while(1)
    {
        cout<<"Enter N\n";
        cin>>n;
        findPerfectSquare(n);
    }
}
