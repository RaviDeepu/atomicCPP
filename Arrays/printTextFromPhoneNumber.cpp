#include<iostream>
#include<string.h>


using namespace std;


const char text[10][5] = {"", ",","abc","def","ghi","jkl","mnop","qrst","uvw","xyz"};

void printTextFromPhoneUtil(int number[], int curIndex, char output[], int size)
{
    int i;
    if(curIndex == size)
    {
        cout<<output<<endl;
        return;
    }

    for(i=0 ; i<strlen(text[number[curIndex]]) ; i++)
    {
        output[curIndex] = text[number[curIndex]][i];
        printTextFromPhoneUtil(number,curIndex+1,output,size);
        if(number[curIndex] == 0 || number[curIndex] == 1)
            return;
    }

}


void printTextFromPhone(int a[], int size)
{
    char result[size];
    result[size]='\0';
    
    printTextFromPhoneUtil(a,0,result,size);
}

int main()
{
    int number[]={2,3,4};

    printTextFromPhone(number,3);
}
