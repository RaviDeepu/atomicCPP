#include<iostream>
#define MAX_CHARS   256

using namespace std;

struct node
{
    char a;
    struct node *next, *prev;
};


void appendNode(struct node **head, struct node **tail, char c)
{
    cout<<"Append Node : "<<c<<endl;;
    struct node *temp = new node;
    temp->a = c;
    temp->next=temp->prev=NULL;

    if(*head == NULL)
    {
        *head = *tail = temp;
        return;
    }
    
    (*tail)->next = temp;
    temp->prev = *tail;
    *tail = temp;
}

void removeNode(struct node** head_ref, struct node** tail_ref, struct node* temp)
{
    cout<<"Remove Node : "<<temp->a<<endl;
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

}

void findFirstNonRepeatingChar()
{
    struct node* head = NULL;
    struct node* tail = NULL;

    struct node *inDLL[MAX_CHARS];
    bool repeated[MAX_CHARS];

    for(int i=0;i<MAX_CHARS; i++)
    {
        repeated[i] = false;
        inDLL[i] = NULL;
    }

    char str[] = "geeksforgeeks";
    for(int i=0 ; str[i] ; i++)
    {
        char x = str[i];
        if(repeated[x] == false)
        {
            if(inDLL[x] == NULL)
            {
                appendNode(&head,&tail,x);
                inDLL[x] = tail;
            }
            else
            {
                removeNode(&head,&tail,inDLL[x]);
                repeated[x] = true;
            }
        }
    }
    if(head != NULL)
        cout<<"First Non Repeating char is "<<head->a<<endl;
    else
        cout<<"HEAD NULL\n";

    cout<<"DLL CONTENT\n";
    struct node *iter = head;
    while(iter != NULL)
    {
        cout<<iter->a<<endl;
        iter = iter->next;
    }
}

int main()
{
    findFirstNonRepeatingChar();

}
