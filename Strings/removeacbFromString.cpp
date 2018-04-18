#include<iostream>
#define ONE 1
#define TWO 2

using namespace std;

/*
 Algorithm 
 Remove b and ac from string.
 Input : acbac
 Output : ""

 Use two indexes, one index to iterate the string and another index to copy the resultant character.
 Maintain two STATE : ONE and TWO.
 If STATE is TWO then the previos character is "a", else ONE.
 
 Steps:
 1. Initialize the STATE = ONE, as the previous character is not "a".
 2. Iterate through the string, 
 3. If STATE is ONE , then do not copy if 
    a. The current character is "b" (We need to remove b) 
    b. The current character is "a" (Next character may be c)
    Copy "a".
 4. If STATE is TWO and the character is not "c", then copy "a" into the result and then check if the character is not "b" and character is not "a" then copy the character into the result.
 5. Update STATE .


*/
void removebacFromString(char *str)
{
    int STATE = ONE;
    int i=0,j=0;

    for(i=0 ; str[i] != '\0' ; ++i)
    {
        if(STATE == ONE && str[i] != 'a' && str[i] != 'b')
        {
            str[j] = str[i];
            j++;
        }

        if(STATE == TWO && str[i] != 'c')
        {
            // First copy the previous character "a"
            str[j] = 'a';
            j++;

            // Copy if the current character is not a and b
            if(str[i] != 'a' && str[i] != 'b')
            {
                str[j] = str[i];
                j++;
            }
        }

        STATE = (str[i] == 'a')? TWO :ONE;
    }

    // If the last character is "a"
    if(STATE == TWO)
    {
        str[j] = 'a';
        j++;
    }

    str[j] = '\0';

    cout<<"j : "<<j<<endl;
    cout<<"Replaced String : "<<str<<endl;
}


int main()
{
    char str[]="dddd";
    removebacFromString(str);
    return 0;
}
