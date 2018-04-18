#include<iostream>
#define NO_OF_CHARS 256

using namespace std;

//  Remove all duplicates from the input string.

=======================================================================
1: Initialize:
    str  =  "test string" /* input string */
    ip_ind =  0          /* index to  keep track of location of next
                             character in input string */
    res_ind  =  0         /* index to  keep track of location of
                            next character in the resultant string */
    bin_hash[0..255] = {0,0, ….} /* Binary hash to see if character is 
                                        already processed or not */
2: Do following for each character *(str + ip_ind) in input string:
              (a) if bin_hash is not set for *(str + ip_ind) then
                   // if program sees the character *(str + ip_ind) first time
                         (i)  Set bin_hash for *(str + ip_ind)
                         (ii)  Move *(str  + ip_ind) to the resultant string.
                              This is done in-place.
                         (iii) res_ind++
              (b) ip_ind++
  /* String obtained after this step is "te sringng" */
3: Remove extra characters at the end of the resultant string.
  /*  String obtained after this step is "te sring" */
===========================================================================


void nonRepeatingChars(char *str)
{
	int ip_index=0,res_index=0;
	int countArray[NO_OF_CHARS]={0};

	int i=0;
	char temp;

	while(*(str+i))
	{
		temp = *(str+i);
		
		if(countArray[temp] == 0)
		{
			countArray[temp] = 1;
			*(str+res_index) = *(str+ip_index);
			res_index++;
		}		
		ip_index++;
		i++;
	}
	*(str+res_index) = '\0';
	cout<<str<<endl;
}

int main()
{
	char str[]="geekforgeeks";
	nonRepeatingChars(str);

}
