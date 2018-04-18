/*
Print list items containing all characters of a given word
There is a list of items. Given a specific word, e.g., .sun., print out all the items in list which contain all the characters of .sun..

For example if the given word is .sun. and the items are .sunday., .geeksforgeeks., .utensils., ..just. and .sss., then the program should print .sunday. and .utensils..
*/

#include<string.h>
#include<iostream>

using namespace std;

/*
word : sun
1. Initialize a map, and set the values of Word in the map.
    map[s]='1'
    map[u]='1'
    map[n]='1'

2. Iterate through the words from the list, let it be listWord.
    Let "ch" be the character of the picked word. If map[ch] is set then increment the counter and unset the value.
    If the count matches the word Length the listWord has all the characters of word.

3. Set the map again.

*/


void printListMatchingWords(char *list[], char *word, int n)
{
    int hashMap[256]={0};
    int lengthOfWord = strlen(word);

    for(int i=0 ; word[i] ; ++i)
    {
        hashMap[word[i]] = 1;
    }

    int count = 0;
    for(int i=0 ; i<n ; ++i)
    {
        for(int j=0,count=0 ; *(list[i] + j) ; ++j)
        {
            if(hashMap[*(list[i]+j)] == 1)
            {
                //cout<<*(list[i]+j)<<" is set"<<endl;
                count++;
                hashMap[*(list[i]+j)] = 0;
            }

            if(count == lengthOfWord)
            {
                cout<<"List Word "<<list[i]<<" has all the characters of "<<word<<endl;
                break;
            }
        }

        for(int i=0 ; word[i] ; ++i)
        {
            hashMap[word[i]] = 1;
        }
    }
}


int main()
{
    char *list[] = {"sunday","sss","utensils"};
    char *word = "sun";

    printListMatchingWords(list,word,3);
}
