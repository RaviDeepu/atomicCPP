#include<iostream>
#include<string.h>

using namespace std;

// Algorith is to find the centre position and traverse both the sides.
void longestPalindrominSubString(char *str)
{
    int start,maxLength = -1;
    int low,high;
    int i=0;
    int len = strlen(str);
    for(int i=1 ; i<len ; ++i)
    {
        // For Even Length SubString.
        low = i-1;
        high = i;
        while(low >= 0 && high < len && str[low] == str[high] )
        {
            if((high-low+1) > maxLength)
            {
                maxLength = high-low+1;
                start = low;
            }
            low--;
            high++;
        }

        // For Odd Length SubString
        low = i-1;
        high = i+1;
        while(low >= 0 && high < len && str[low] == str[high])
        {
            if((high-low+1) > maxLength)
            {
                maxLength = high-low+1;
                start = low;
            }
            low--;
            high++;
        }
    }

    cout<<"MaxLength : "<<maxLength<<", Start : "<<start<<endl;
    // Print Substring
    for(int i=start;i<=(start+maxLength-1);++i)
    {
        cout<<str[i];
    }
    cout<<endl;

}


int main()
{
    char str[] = "forgeksiskeegfor";
    longestPalindrominSubString(str);
    return 0;
}
