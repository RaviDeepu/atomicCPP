#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};



// A utility function to print a linked list
void printlist(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// A utility function to create a new node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void recursiveReverse(struct Node** head_ref)
{
    struct Node* first;
    struct Node* rest;
      
    /* empty list */
    if (*head_ref == NULL)
       return;   


    //cout<<"Head->info : "<<(*head_ref)->data<<endl;

 
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;  
    rest  = first->next;
 
    /* List has only one node */
    if (rest == NULL)
       return;   
 
    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first;  
     
    cout<<"first->data : "<<first->data<<endl;
    cout<<"Rest->data : "<<rest->data<<endl;
    /* tricky step -- see the diagram */
    first->next  = NULL;          
 
    /* fix the head pointer */
    *head_ref = rest;              
}


void reverseLinkedListRecursiveUtil(struct Node *cur, struct Node *prev, struct Node **head)
{
    if(cur->next == NULL)
    {
        *head = cur;
        cur->next = prev;
        return;
    }

    struct Node *temp = cur->next;
    cur->next = prev;

    reverseLinkedListRecursiveUtil(temp,cur,head);

}

void reverseLinkedRecursiveList(struct Node **head)
{
    if(*head == NULL)
        return;

    reverseLinkedListRecursiveUtil(*head,NULL,head);
}


// Driver program to test above functions
int main()
{
    Node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = newNode(8);
    cout << "Given linked list\n";
    printlist(head1);
    //reverse(&head1);

    reverseLinkedRecursiveList(&head1);

    cout << "\nReversed linked list\n";
    printlist(head1);
    return 0;
}




