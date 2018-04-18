#include<iostream>

using namespace std;



#include <stdio.h>
/* 
 *  buy day j and sell day i where  max(a[i] - a[j]) and i > j
 *  */

typedef struct
{
    int buy, sell, profit;
}Return;

Return maxprofit(int a[], int n)
{
    Return r = {n-1, n-1, 0};

    Return tmp = r;
    n--;

    while(n--)
    {
        if(a[n] < a[tmp.buy])
            tmp.buy = n;

        if(a[n] > a[tmp.sell])
	{
		cout<<"a[n] > a[tmp.sell] -- "<<a[n]<<"\n\n";
            tmp.buy = tmp.sell = n;
	}

        if(tmp.buy < tmp.sell)
        {
            tmp.profit = a[tmp.sell] - a[tmp.buy];
            if(r.profit < tmp.profit)
                r = tmp;
        }
    }

    return r;
}

int main()
{
	/*
    int n;
    scanf("%d", &n);

    int i;
    int a[n];

    for(i = 0; i < n; ++i)
        scanf("%d", a + i);
	*/
    int arr[] = {104, 2, 80, 10,99,102,88};
    int size = sizeof(arr)/sizeof(arr[0]);


    Return r = maxprofit(arr, size);

    printf("buy on: %d and sell on: %d and profit: %d\n", r.buy, r.sell, r.profit);
}
