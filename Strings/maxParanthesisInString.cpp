/*

Find maximum depth of nested parenthesis in a string
We are given a string having parenthesis like below
     .( ((X)) (((Y))) ).
     We need to find the maximum depth of balanced parenthesis, like 4 in above example. Since .Y. is surrounded by 4 balanced parenthesis.

     If parenthesis are unbalanced then return -1.


*/


#include<iostream>

using namespace std;

int maxBalancedParanthesis(char *str)
{
    int cur_max=0,max=0;    

    for(int i=0;str[i] != '\0';++i)
    {
        if(str[i] == '(')
        {
            cur_max++;
            if(cur_max > max)
                max = cur_max;

        }
        else if(str[i] == ')')
        {
            if(cur_max > 0)
                cur_max--;
            else
                return -1;
        }
    }
   
   // If Paranthesis are not balanced
   if(cur_max != 0)
       return -1;

   return max;
}

int main()
{
    char str[]="( ((X)) (((Y))) )";
    cout<<maxBalancedParanthesis(str)<<endl;
}

