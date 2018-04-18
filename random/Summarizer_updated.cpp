//Om Ganeshaya Namah

#include<iostream>
#include<conio.h>
#include<string.h>
#define MAX_LINE 3

#include<map>

using namespace std;

 map<string,int> wordmap;
struct sentence
{
       char line[100];
       int totalValue;
       struct sentence * link;
};

typedef struct sentence * SENTENCE;


int checkStopWord(char word[])
{
   if(!strcmp(word,"is") || !strcmp(word,"good") || !strcmp(word,"a") || !strcmp(word,"hits") || !strcmp(word,"many") || !strcmp(word,"also") || !strcmp(word,"has") || !strcmp(word,"in") || !strcmp(word,"the") || !strcmp(word,"record") || !strcmp(word,"hobby") || !strcmp(word,".") || !strcmp(word,","))
  // if(!strcmp(word,"is") && !strcmp(word,"good") && !strcmp(word,"a") && !strcmp(word,"hits") && !strcmp(word,"many") && !strcmp(word,"also") && !strcmp(word,"has") && !strcmp(word,"in") && !strcmp(word,"the") && !strcmp(word,"order") && !strcmp(word,"hobby"))
                return 1;
    else 
                return 0;
}
//while ( fgets ( line, sizeof(line), fp ) != NULL ) /* read a line */


SENTENCE checkTotalValueOfLine(char * templine, SENTENCE root )
{
    SENTENCE temp,cur;
    int sum = 0;
    char *ptr;
    temp = (SENTENCE) malloc(sizeof(struct sentence));
    strcpy(temp->line ,templine );
    ptr = strtok (templine," ");
    while (ptr != NULL)
    {
        sum = sum + wordmap[ptr];
        ptr = strtok (NULL, " ");
     }
     temp->totalValue = sum;
     temp->link = NULL;
    // cout<<temp->line<<"\t"<<temp->totalValue<<"\n";
     if(root == NULL)
     {
             return temp;
     }
     cur = root;
     while(cur->link != NULL)
     {
                  cur = cur->link;
     }
     cur->link = temp;
     return root;
}


void display(SENTENCE root)
{
     SENTENCE temp;
     temp = root;
     cout<<"The Line and Total Value"<<endl;
     while(temp != NULL)
     {
                cout<<temp->line<<"\t"<<temp->totalValue<<endl;
                temp = temp->link;
     }
     cout<<"\n";
}


void summary(SENTENCE root)
{
     SENTENCE temp;
     int i=0;
     temp = root;
     cout<<"The Overall Summary "<<endl;
     while(temp != NULL && i < MAX_LINE)
     {
                cout<<temp->line;
                temp = temp->link;
                i++;
     }
    // cout<<"\n";
}



int sortByTotalValue(SENTENCE root)
{
    
    SENTENCE first,second,temp;
    first= root;
 
    while(first!=NULL){
    second=first->link;
 
        while(second!=NULL){
            if(first->totalValue < second->totalValue)
            {
                temp = (SENTENCE) malloc(sizeof(struct sentence));
                strcpy(temp->line,first->line);
                temp->totalValue=first->totalValue;
                 strcpy(first->line,second->line);
                first->totalValue=second->totalValue;
                 strcpy(second->line,temp->line);
                second->totalValue=temp->totalValue;
                free(temp);
            }
 
        second=second->link;
        }
 
    first=first->link;
    }

}

int main()
{
    FILE *fp;
    char ch;
    int i=0;
    char words[20];
    char completeline[100];
    SENTENCE root = NULL;
    fp = fopen("words.txt","r");
    while(fscanf(fp,"%s",words) != EOF)
    {
          if(!checkStopWord(words))
          {
                   wordmap[words]++;    
          }
    }
    
    cout << "pairs contains:\nKey\tValue\n";

   // use const_iterator to walk through elements of pairs
   for ( map<string,int>::const_iterator iter = wordmap.begin();
    // for ( map<string,int>::reverse_iterator iter = wordmap.rbegin();
      iter != wordmap.end(); ++iter )
        cout << iter->first << "\t" << iter->second << "\n";
       
    fseek(fp, 0, SEEK_SET);
    while(!feof(fp))
    {
              while ( (ch=fgetc(fp)) != EOF ) /* read a line */
              {
                    if(ch != '.')
                          completeline[i++]=ch;
                    else
                    {
                        completeline[i++]='\0';
                        cout<<"Complete Line "<<completeline<<"\n";
                         root = checkTotalValueOfLine(completeline,root);
                         i=0;
                    }
                            //strcat(completeline,ch);
              }
            //  strcat(completeline,"\0");
              
    }
    sortByTotalValue(root);
    display(root);
    
    summary(root);
    /*
     cout << "pairs contains:\nKey\tValue\n";

   // use const_iterator to walk through elements of pairs
   for ( map<string,int>::const_iterator iter = wordmap.begin();
    // for ( map<string,int>::reverse_iterator iter = wordmap.rbegin();
      iter != wordmap.end(); ++iter )
        cout << iter->first << "\t" << iter->second << "\n";
*/
   cout << endl;
   fclose(fp);
   getch();
   return 0;
 
}
