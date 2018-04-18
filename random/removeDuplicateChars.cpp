#include <iostream>
# include <stdio.h>
# include <stdlib.h>
# define NO_OF_CHARS 256
# define bool int

using namespace std;
 


/* Function removes duplicate characters from the string
   This function work in-place and fills null characters
   in the extra space left */


char *removeDups(char *str)
{
  bool bin_hash[NO_OF_CHARS] = {0};
  int ip_ind = 0, res_ind = 0;
  char temp;   
 
//  /* In place removal of duplicate characters*/ 
  while(*(str + ip_ind))
  {
    temp = *(str + ip_ind);
	cout<<"Temp :"<<temp<<"\n";
    if(bin_hash[temp] == 0)
    {
        bin_hash[temp] = 1;
        *(str + res_ind) = *(str + ip_ind);
        res_ind++;        
    }
    ip_ind++;
  }     
 
  /* After above step string is stringiittg.
     Removing extra iittg after string*/       
  *(str+res_ind) = '\0';  
   
  return str;
}
 
/* Driver program to test removeDups */
int main()
{
    char str[] = "Bananas";
    printf("%s", removeDups(str));
	//cout<<"'A'"<<'A'<<"\n";
	//printf("%d",'A');
    getchar();
    return 0;
} 
