#include<iostream>
#include<stdlib.h>
#define MAX_CHAR 256
using namespace std;

// Use a DLL to find the first non repeating char from a stream.
// Will have two arrays , repeated[MAX_CHAR] and array of pointers
// to DLL inDLL[MAX_CHAR]. 
// repeated[x] will be true if x is repeated more than otwo times, else false
// inDLL[x] contains pointer to a DLL node if x is present in DLL
// else NULL.


// If repeated[x] is true. Ignore it as x is repeated more than 2 times.
// If repeated[x] is false and inDLL is NULL, then Append x to DLL
// and assign the node address to inDLL[x].
// If repeated[x] is false and inDLL is not NULL, then x is repeated twice 
// now. Remove the node from DLL and assign NULL to inDLL.

struct node
{
    char a;
    struct node *next, *prev;
};

void appendNode(struct node **head_ref, struct node **tail_ref, char x)
{
    cout<<"Append Node\n";
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->a = x;
    temp->next = temp->prev = NULL;

    if(*head_ref == NULL)
    {
        *head_ref = *tail_ref = temp;
        return;
    }

    (*tail_ref)->next = temp;
    temp->prev = *tail_ref;
    *tail_ref = temp;
}


void removeNode(struct node **head_ref, struct node **tail_ref, struct node *temp)
{
    cout<<"Remove Node\n";
    if(*head_ref == NULL)
        return;

    if(*head_ref == temp)
        *head_ref = (*head_ref)->next;
    if(*tail_ref == temp)
        *tail_ref = (*tail_ref)->prev;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    delete(temp);
}

void firstNonRepeating()
{
    cout<<"firstNonRepeating"<<endl;
    struct node *head = NULL, *tail = NULL;
    bool repeated[MAX_CHAR];
    struct node *inDLL[MAX_CHAR];

    for(int i=0;i<MAX_CHAR;i++)
    {
        repeated[i] = false;
        inDLL[i] = NULL;
    }

    char stream[]="geeksforgeeksandgeeksquizfor";
    for(int i=0;stream[i];i++)
    {
        char x = stream[i];
        if(!repeated[x])
        {
            if(inDLL[x] == NULL)
            {
                appendNode(&head, &tail,x);
                inDLL[x] = tail;
            }
            else
            {
                removeNode(&head,&tail,inDLL[x]);
                inDLL[x] = NULL;
                repeated[x] = true;
            }
        }

        //if(head != NULL)
            //cout<<"First Non Repeating Character is "<<head->a<<endl;
    }
    if(head != NULL)
        cout<<"First Non Repeating Character is "<<head->a<<endl;
}


int main()
{
    firstNonRepeating();
    return 0;
}


