#include<iostream>
#include <limits.h>

using namespace std;



void firstNonRepeatingChar(char *str)
{
    int countArray[256]={0};

    for(int i=0;str[i];++i)
    {
        countArray[str[i]]++;
    }

    for(int i=0;str[i];++i)
    {
        if(countArray[str[i]] == 1)
        {
            cout<<"First Non Repeating Char is : "<<str[i]<<endl;
            break;
        }
    }
}


// If the String is very long with the same chaaracters, then we need to traverse the entire string.
// What if the firstNonRepeatingChar is at the end, 
// So, we traverse the countArray instead of the string.

struct CountIndex
{
    int count;
    int index;
};

void firstNonRepeatingChar_CountIndex(char *str)
{
    struct CountIndex countIndexStruct[256]={0};

    for(int i=0;i<256;++i)
    {
        countIndexStruct[i].count = 0;
    }

    for(int i=0;str[i];++i)
    {
        (countIndexStruct[str[i]].count)++;
        // If this character is encountering first time them store the index value.
        if(countIndexStruct[str[i]].count == 1)
        {
            countIndexStruct[str[i]].index = i;
        }
    }

    int result=INT_MAX;

    for(int i=0;i<256;++i)
    {
        if(countIndexStruct[str[i]].count == 1 && result > countIndexStruct[str[i]].index)
        {
            result = countIndexStruct[str[i]].index;
        }
    }

    cout<<"First Non Repeatinc Char : "<<str[result]<<endl;

}

int main()
{
      char str[] = "gbeeiag";
      firstNonRepeatingChar(str);
      firstNonRepeatingChar_CountIndex(str);
      /*
      int index =  firstNonRepeating(str);
      if (index == INT_MAX)
        printf("First non-repeating character is %c\n", str[index]);
      //getchar();
      */
      return 0;
}
