#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;


struct node
{
    int info;
    struct node* next;
};

typedef struct node* NODE;


void insert(struct node** head, int n)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->info=n;
    temp->next=NULL;

    if(*head == NULL)
    {
        *head=temp;
        return;
    }

    struct node *cur = *head;
    while(cur->next != NULL)
    {
        cur=cur->next;
    }
    cur->next = temp;
    return;

}


void display(struct node *head)
{
    if(head == NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    struct node *cur = head;
    cout<<"List has : "<<endl;
    cout<<"========================\n";
    while(cur != NULL)
    {
        cout<<cur->info<<" ";
        cur=cur->next;
    }
    cout<<endl;
    cout<<"========================\n";

}

void getNthNode(struct node* head, int n)
{
    if(head == NULL)
    {
        cout<<"List is Empty\n";
        return;
    }

    int count=1;
    struct node *cur = head;
    while(cur != NULL && count < n)
    {
        cur=cur->next;
        count++;
    }

    if(cur == NULL)
    {
        cout<<"Cannot get "<<n<<"th node, as the list size is lesser\n";
        return;
    }

    cout<<n<<"th node : "<<cur->info<<endl;
}

// Given only a pointer to a node to be deleted in a singly linked list, how do you delete it
void deleteNode(struct node *delNode)
{
    struct node *temp = delNode->next;

    delNode->info = delNode->next->info;
    delNode->next = delNode->next->next;

    cout<<"Deleted Node is : "<<temp->info<<endl;
    free(temp);
}

// To print the middle of the linked list.
void printMiddleNode(struct node* head)
{
    if(head == NULL)
        return;

    struct node* slow, *fast;
    slow = fast = head;

    while(slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout<<"Middle Element : "<<slow->info<<endl;
}

// Use a Single pointer, but it calculates from length.
// Calculate the length be len, print len-n+1th node.
void getNthLastNode(struct node *head, int n)
{
    struct node* cur = head;
    int len=0;
    while(cur != NULL)
    {
        len++;
        cur = cur->next;
    }

    cout<<"Length of linked list : "<<len<<endl;
    cout<<"Traverse till : "<<len-n+1<<endl;
    cur = head;
    for(int i=0;i<(len-n);++i)
    {
        cur = cur->next;
    }
    cout<<n<<"th Node from last is : "<<cur->info<<endl;
}

void getNthLastNodeRecursive(struct node* head, int n)
{
    static int i=0;
    if(head == NULL)
        return;
    getNthLastNodeRecursive(head->next,n);
    if(++i == n)
        cout<<n<<"th Node from last is : "<<head->info<<endl;
}

// Use two pointers.
// Initialise first and second pointer to head
// Move the first pointer n times.
// Now move both first and second pointer. If the First pointer reaches enc then second pointer is pointing to the last nth node.
void getNthLastNodeUsingTwoPointer(struct node *head, int n)
{
    struct node * firstPtr, *secondPtr;
    firstPtr = secondPtr = head;
    int count=0;
    while(count < n)
    {
        count++;
        firstPtr = firstPtr->next;
    }

    while(firstPtr != NULL)
    {
        firstPtr=firstPtr->next;
        secondPtr=secondPtr->next;
    }

    cout<<n<<"th Node from last is : "<<secondPtr->info<<endl;

}

void deleteLinkedList(struct node **head)
{
    struct node* cur, *temp;
    cur=*head;
    temp=*head;

    int count=0;
    while(cur != NULL)
    {
        count++;
        cur = cur->next;
        free(temp);
        temp=cur;
    }
    *head=NULL;
    cout<<"Deleted "<<count<<" nodes"<<endl;
}

// function that counts the number of times a given int occurs in a Linked List
void countNumberOfOccurence(struct node *head, int n)
{
    if(head == NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    int count=0;
    struct node *cur = head;
    while(cur != NULL)
    {
        if(cur->info == n)
            count++;
        cur=cur->next;
    }
    cout<<n<<" has occurred "<<count<<" times"<<endl;

}


// 1->2->3->4->5

void reverseLinkedListRecursiveUtil(struct node *cur, struct node *prev, struct node **head)
{
    if(cur->next == NULL)
    {
        *head = cur;
        cur->next = prev;
        return;
    }

    struct node *temp = cur->next;
    cur->next = prev;

    reverseLinkedListRecursiveUtil(temp,cur,head);

}

void reverseLinkedRecursiveList(struct node **head)
{
    if(*head == NULL)
        return;

    reverseLinkedListRecursiveUtil(*head,NULL,head);
}

void reverseLinkedListIterative(struct node **head)
{
    if(*head == NULL)
    {
        return;
    }

    struct node *cur=*head;
    struct node *prev = NULL;

    while(cur != NULL)
    {
        struct node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    *head = prev;
}

void isLinkedListPalindromeUsingStack(struct node *head)
{
    if(head == NULL)
        return;

    stack<int> s;
    
    struct node *slow,*fast,*prev_slow;
    slow = fast = head;
     
    //prev_slow = NULL;
    while(fast != NULL && fast->next != NULL)
    {
        s.push(slow->info);
      //  prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // If fast->link is NULL then odd, skip the middle element.
    if(fast != NULL)
    {
        s.pop();
    }
    
    
    struct node *cur = head;
    while(s.size() != 0)
    {
        if(cur->info != s.top())
        {
            cout<<"NOT A Palindrome\n";
            break;
        }
        s.pop();
    }
    cout<<"Palindrome\n";
}


bool isPalindrome(struct node *first, struct node *second)
{
    while(first != NULL && second != NULL)
    {
        if(first->info != second->info)
            return false;

        first = first->next;
        second = second->next;
    }
    
    return true;

}

void isLinkedListPalindromeUsingTwoPointer(struct node *head)
{
    if(head == NULL)
    {
        return ;
    }

    struct node *slow,*fast,*prev_slow,*middle;;
    slow=fast=head;
    prev_slow=middle=NULL;

    while(fast != NULL && fast->next != NULL)
    {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // If Odd then fast->next = NULL
    if(fast->next == NULL)
    {
        middle = slow;
        slow = slow->next;
    }

    prev_slow->next = NULL;
    
    reverseLinkedListIterative(&slow);

    if(isPalindrome(head,slow))
    {
        cout<<"Palindrome \n";
    }
    else
    {
        cout<<"NOT A PALINDROME\n";
    }

    reverseLinkedListIterative(&slow);
    // Fix the linked list
    if(middle)
    {
        prev_slow->next = middle;
        middle->next = slow;
    }
    else
    {
        prev_slow->next = slow;
    }
}

void insertSortedOrder(struct node **head, int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = n;
    temp->next = NULL;

    if(*head == NULL || (*head)->info >= n)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        struct node *cur = *(head);
        while(cur->next != NULL && cur->next->info < n)
        {
            cur = cur->next;
        }
    
        temp->next = cur->next;
        cur->next = temp;
    }
}

void printReverse(struct node *head)
{
    if(head == NULL)
        return;

    printReverse(head->next);
    cout<<head->info<<" ";
}

void removeDuplicatedSorted(struct node *head)
{
    if(head == NULL)
        return;
    struct node *cur = head;
    struct node *next_next = NULL;

    while(cur->next != NULL)
    {
        if(cur->info == cur->next->info)
        {
            next_next = cur->next->next;
            free(cur->next);
            cur->next = next_next;
        }
        else
        {
            cur = cur->next;
        }
    }
}

void removeDuplicateUnsorted(struct node *head)
{
    if(head == NULL)
        return;

    int hash[100]={0};
    struct node *cur = head;
    while(cur->next != NULL)
    {
        hash[cur->info]=1;
        if(hash[cur->next->info] == 1)
        {
            struct node *dup = cur->next;
            free(dup);
            cur->next = cur->next->next;
            
        }
        else
        {
            cur = cur->next;
        }
    }
}

void splitListIntoTwoHalf(struct node *head, struct node **head1, struct node **head2)
{
    if(head == NULL)
    {
        return;
    }

    struct node *slow, *fast;
    slow = fast = head;
    while(fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }    
    
    // Even Nodes. Move fast to last node
    if(fast->next->next == head)
    {
        fast = fast->next;
    }
    
    if(head->next != head)
    {
        *head2 = slow->next;
    }

    // Set first half head
    *head1 = head;
    
    fast->next = slow->next;
    
    slow->next = head;
    
}

void moveLastToFirst(struct node **head)
{   
    if(*head == NULL || (*head)->next == NULL)
        return;

    struct node *last,*seclast;
    last = *head;
    seclast = NULL;
    
    while(last->next != NULL)
    {
        seclast = last;
        last = last->next;
    }
    
    seclast->next = NULL;
    last->next = *head;
    *head = last;    

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void pairWiseSwapElement(struct node *head)
{
    struct node *temp = head;
    while(head != NULL && head->next != NULL)
    {
        swap(&head->info,&head->next->info);
        head = head->next->next; 
    }
}

void pairWiseSwapRecursive(struct node *head)
{
    if(head != NULL && head->next != NULL)
    {
        swap(&head->info, &head->next->info);
        pairWiseSwapRecursive(head->next->next);
    }
}

void copyLinkedList(struct node **dest, struct node *src)
{
   if(src == NULL)
    {
        return;
    } 

    struct node *cur = src;
    while(cur != NULL)
    {
        insert(dest,cur->info);
        cur = cur->next;
    }
}

void intersectionOfTwoLinkedList(struct node *list1, struct node *list2, struct node **res)
{
    if(list1 == NULL || list2 == NULL)
        return;

    while(list1 != NULL && list2 != NULL)
    {
        if(list1->info == list2->info)
        {
            insert(res,list1->info);
            list1 = list1->next;
            list2 = list2->next;
        }
        else if(list1->info <= list2->info)
        {
            list1 = list1->next;
        }
        else
        {
            list2 = list2->next;
        }
    }
}

struct node* intersectionOftwoLinkedListRecursive(struct node *list1, struct node *list2)
{
    if(list1 == NULL || list2 == NULL)
        return NULL;

    cout<<"intersect : "<<list1->info<<" , "<<list2->info<<endl;
    if(list1->info < list2->info)
        return intersectionOftwoLinkedListRecursive(list1->next,list2);

    if(list1->info > list2->info)
        return intersectionOftwoLinkedListRecursive(list1, list2->next);

    cout<<"SAME : Intersect - "<<list1->info<<endl;
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->info = list1->info;
    temp->next = intersectionOftwoLinkedListRecursive(list1->next, list2->next);
    return temp;

}

void deleteAlternateNodes(struct node *head)
{
    if(head == NULL)
        return;

    struct node *prev,*cur;
    prev = head;
    cur = head->next;
    
    while(prev != NULL && cur != NULL)
    {
        prev->next = cur->next;
        free(cur);
        
        prev = prev->next;

        if(prev != NULL)
            cur = prev->next;
    }
}

void deleteAlternateNodesRecursive(struct node *head)
{
    if(head == NULL)
        return;

    struct node *temp = head->next;
    if(temp == NULL)
        return;

    head->next = temp->next;
    free(temp);

    deleteAlternateNodesRecursive(head->next);
}

void split(struct node **a, struct node **head)
{
    if(*head == NULL)
        return;

    if(*a == NULL)
    {
        *a = *head;
        *head = (*head)->next;
        (*a)->next = NULL;   
        return;     
    }
    
    struct node *cur = *a;
    while(cur->next != NULL)
    {   
        cur = cur->next;
    }
    cur->next = *head;
    *head = (*head)->next;
    cur->next->next = NULL;
}

void splitAlternativeUtil(struct node **head)
{
    struct node *a,*b;
    a = NULL;
    b = NULL;
    
    if(*head == NULL)
        return;

    while(*head != NULL)
    {
        cout<<"Split AAAAAA\n";
        split(&a,head);
        if(*head != NULL)
        {
            cout<<"Split BBBBBB\n";
            split(&b,head);
        }
    }
    cout<<"First List : \n";
    display(a);
    cout<<"Second List : \n";
    display(b);
}

void mergeUtil(struct node** dest, struct node** src)
{
    if(*src == NULL)
        return;

    if(*dest == NULL)
    {
        *dest = *src;
        *src = (*src)->next;
        (*dest)->next = NULL;
    }
    else
    {
        struct node *cur = *dest;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = *src;
        *src = (*src)->next;
        cur->next->next = NULL;
    }
}

struct node * mergeTwoSortedList(struct node *a, struct node *b)
{
    struct node *res = NULL;
    
    while(a != NULL && b != NULL)
    {
        if(a == NULL)
        {
            if(res == NULL)
                res = b;
            else
                res->next = b;
        }
        else if(b == NULL)
        {
            if(res == NULL)
                res = a;
            else
                res->next = a;
        }
        else if(a->info <= b->info)
        {
            mergeUtil(&res,&a);
        }
        else
        {
            mergeUtil(&res,&b);
        }
    }
    return res;
}

struct node * mergeTwoSortedListRecursive(struct node *a,struct node *b)
{
    struct node *res = NULL;

    // Base Cases.
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;

    if(a->info < b->info)
    {
        res = a;
        res->next = mergeTwoSortedListRecursive(a->next,b);
    }
    else 
    {
        res = b;
        res->next = mergeTwoSortedListRecursive(a,b->next);
    }

    return res;
}

bool identicalLinkedList(struct node *a, struct node *b)
{
    if(a == NULL && b == NULL)
        return true;

    while(a != NULL && b != NULL)
    {
        if(a->info != b->info)
            return false;

        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
}

bool identicalLinkedListRecursive(struct node *a, struct node *b)
{
    if(a == NULL && b == NULL)
        return true;

    if(a != NULL && b != NULL)
        return ((a->info == b->info) && identicalLinkedListRecursive(a->next,b->next));

    return false;
}

void splitListIntoTwoHalves(struct node **a, struct node **b, struct node *head)
{
    struct node *slow,*fast;
    if(head == NULL || head->next == NULL)
    {
        *a = head;
        *b = NULL;
        return;
    }
    else
    {
        slow = head;
        fast = head->next;
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *a = head;
        *b = slow->next;
        slow->next = NULL;
    }
}

/*
* Steps :
1. Split list into two halves. Let's say a & b
2. Call MergeSort recursively for a & b.
3. Merge a & b.
*/

void MergeSort(struct node **head)
{
    if(*head == NULL)
        return;

    struct node *a,*b;
    a=b=NULL;

    if(*head == NULL || (*head)->next == NULL)
        return;

    splitListIntoTwoHalves(&a,&b,*head);

    //cout<<"After Split : "<<endl;
    //display(a);
    //display(b);


    MergeSort(&a);
    MergeSort(&b);


    cout<<"- - - A - - -\n";
    display(a);
    cout<<"- - - B - - -\n";
    display(b);

    *head = mergeTwoSortedListRecursive(a,b);

    display(*head);
}

// Reverse a Linked List in group of given sizes.
// 1 2 3 4 5 6 
// 3 2 1 6 5 4 
struct node* reverseListInSizes(struct node *head,int k)
{
    struct node *cur,*prev,*next;
    cur = head;
    prev = NULL;
    next = NULL;
    int count = 0;

    while(cur != NULL && count < k)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }
    
    // Now next will pointing to the (k+1)th node.
    // Call reverse with the next node.
    if(next != NULL)
        head->next = reverseListInSizes(next,k);

    return prev;
}

/*
Steps
1. If List is empty.
    a. Make the node as head and return.
2. If the node to be inserted before head.
    a. Traverse till the last node.
    b. Make last node->next = temp
    c. temp->next = head
    d. head = temp
3. If the node to be inserted is at the middle
    a. Search for the node
        while(cur->next != head && cur->next->data < n)
            cur = cur->next;
    
*/
void sortedInsertCircularList(struct node **head, int data)
{
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->info = data;
    newNode->next = NULL;

    // If the List is Empty
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    // If the newNode to be inserted before head.
    if(newNode->info < (*head)->info)
    {
        struct node *cur = *head;
        while(cur && cur->next != *head)
            cur = cur->next;

        cur->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        // The newNode should be inserted in the middle.
        struct node *cur = *head;
        while(cur->next != *head && cur->next->info < newNode->info)
            cur = cur->next;

        newNode->next = cur->next;
        cur->next = newNode;
    
    }
}

struct node * reverseAlternateKNodes(struct node *head, int k)
{
    struct node *cur,*prev,*next;
    cur = head;
    prev=next=NULL;
    int count=0;

    while(cur != NULL && count < k)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }

    if(head != NULL)
        head->next = cur;

    count = 0;
    while(cur != NULL && count < k-1)
    {
        cur = cur->next;
        count++;
    }
    
    if(cur != NULL)
        cur->next = reverseAlternateKNodes(cur->next,k);

    return prev;
}


void deleteNodesWithGreaterValueonRightSide(struct node **head)
{
    if(*head == NULL)
        return;

    struct node *cur,*maxNode;

    reverseLinkedListIterative(head);
    
    cur = *head;
    maxNode = *head;

    while(cur != NULL && cur->next != NULL)
    {
        if(cur->next->info < maxNode->info)
        {
            struct node *temp = cur->next;
            cur->next = temp->next;
            free(temp);
        }
        else
        {
            cur = cur->next;
            maxNode = cur;
        }
    }
    reverseLinkedListIterative(head);
}


void segregateOddEvenUtil(struct node** dest, struct node** src)
{
    if(*src == NULL)
        return;

    if(*dest == NULL)
    {
        *dest = *src;
        *src = (*src)->next;
        (*dest)->next = NULL;
    }
    else
    {
        struct node *cur = *dest;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = *src;
        *src = (*src)->next;
        cur->next->next = NULL;
    }
}

void segregateEvenAndOdd(struct node **head)
{
    struct node *even,*odd;
    even = odd = NULL;
    
    if(*head == NULL)
        return;

    struct node *cur = *head;
    while(cur != NULL)
    {
        cout<<cur->info;
        if((cur->info)%2 == 0)
        {
            cout<<" : Even\n";
            segregateOddEvenUtil(&even,&cur);
        }
        else
        {
            cout<<" : Odd\n";
            segregateOddEvenUtil(&odd,&cur);
        }
        //cur = cur->next;
    }

    cout<<"Even \n";
    display(even);
    cout<<"Odd\n";
    display(odd);
    if(even != NULL)
    {
        struct node *temp = even;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = odd;
        *head = even;
    }
    else
    {
        *head = odd;
    }
}

struct node* addTwoNumbers(struct node* first, struct node* second)
{
    struct node *res = NULL;
    struct node *prev,*temp;
    prev = temp = NULL;
    int carry=0,sum=0;

    while(first != NULL || second != NULL)
    {
        sum = carry + (first?first->info:0)+(second?second->info:0);
        carry = sum/10;
        sum = sum%10;
    
        temp = (struct node*)malloc(sizeof(struct node));
        temp->info = sum;
        temp->next = NULL;

        if(res == NULL)
            res = temp;
        else
            prev->next = temp;

        prev = temp;

        if(first)
            first = first->next;
        if(second)
            second = second->next;
    }

    if(carry)
    {
        struct node *tmp = (struct node *) malloc(sizeof(struct node));
        tmp->info = carry;
        tmp->next = NULL;

        prev->next = tmp;
    }
    return res;   
}

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct node* head)
{
    int count = 0;
    while(head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

void inorder(struct TreeNode* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

struct TreeNode* sortedListToBST(struct node** head,int n)
{
    if(*head)
        cout<<(*head)->info<<" , "<<n<<endl;
    if(n <= 0)
        return NULL;

    struct TreeNode* left = sortedListToBST(head,n/2);

    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->data = (*head)->info;
    root->left = left;

    *head = (*head)->next;

    root->right = sortedListToBST(head,n-n/2-1);

    return root;
    
}

/*
1. Sort the Array.
2. Union.
  a. Iterate both list and check if it is same or not and populate union list.
3. Intersection
  a

*/


struct node* MergeSortedlist(struct node *a, struct node *b)
{
    struct node *res = NULL;

    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    if(a->info < b->info)
    {
        res = a;
        res->next = MergeSortedlist(a->next,b);
    }
    else
    {
        res = b;
        res->next = MergeSortedlist(a,b->next);
    }
    return res;
}

void splitListIntoTwoHalvesUtil(struct node *head, struct node **a, struct node **b)
{
    if(head == NULL || head->next == NULL)
        return;

    struct node *slow,*fast;
    slow = head;
    fast = head->next;
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *a = head;
    *b = slow->next;
    slow->next = NULL;
}

void mergeSort(struct node **head)
{
    struct node *a, *b;
    a = b = NULL;
    if(*head == NULL || (*head)->next == NULL)
    {
        a = *head;
        b = NULL;
        return;
    }
    splitListIntoTwoHalvesUtil(*head,&a,&b);

    //display(a);
    //display(b);

    mergeSort(&a);
    mergeSort(&b);

    struct node *res = MergeSortedlist(a,b);

    *head = res;
}

void unionOfLinkedList(struct node* a, struct node* b)
{

    cout<<"- - - - UNION - - - - \n";
    if(a == NULL)
    {
        display(b);
        return;
    }
    else if(b == NULL)
    {
        display(a);
        return;
    }

    while( a != NULL && b != NULL)
    {
        if(a->info < b->info)
        {
            cout<<a->info<<" ";
            a = a->next;
        }
        else if(b->info < a->info)
        {
            cout<<b->info<<" ";
            b = b->next;
        }
        else
        {
            cout<<a->info<<" ";
            a = a->next;
            b = b->next;
        }
    }

    if(a != NULL)
    {
        while(a != NULL)
        {
            cout<<a->info<<" ";
            a = a->next;
        }
        //display(a);
    }
    if(b != NULL)
    {
        while(b != NULL)
        {
            cout<<b->info<<" ";
            b = b->next;
        }
        //display(b);
    }
    cout<<endl;
}


void unionAndIntersectionOfList(struct node *head,struct node *head1)
{
    mergeSort(&head);
    mergeSort(&head1);

    struct node* unionList = NULL;
    struct node* interSection = NULL;

    unionOfLinkedList(head,head1);

    //intersectionOfLinkedList(head,head1);

}

void rotateALinkedList(struct node** head, int k)
{
    struct node *cur = *head;
    int count = 0;

    while(cur != NULL && count < k-1)
    {
        cur = cur->next;
        count++;         
    }

    struct node* last = cur->next;
    
    while(last->next != NULL)
    {
        last = last->next;
    }

    last->next = *head;
    *head = cur->next;

    cur->next = NULL;

    
}


struct node* addSameSize(struct node* a, struct node* b,int *carry)
{
    if(a == NULL)
        return NULL;

    struct node* res = (struct node*) malloc(sizeof(struct node));
    res->next = addSameSize(a->next,b->next,carry);

    int sum = a->info+b->info+*carry;
    *carry = sum/10;

    sum = sum%10;

    res->info = sum;
    return res;
}

void swapPointer(struct node** a, struct node** b)
{
    struct node* temp = *a;
    *a = *b;
    *b = temp;
}


void insertFront(struct node** head, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->info = data;

    temp->next = *head;
    *head = temp;
}
void addRemainingCarry(struct node* a, struct node* cur, int *carry, struct node** res)
{
    if(a != cur)
    {
        addRemainingCarry(a->next,cur,carry,res);
        int sum = a->info+*carry;

        *carry = sum/10;
        sum = sum%10;        

        insertFront(res,sum);
        display(*res);
    }
}


void addList(struct node* a, struct node* b,struct node** res)
{
    if(a == NULL)
    {
        *res = b;
        return;
    }
    else if(b == NULL)
    {
        *res = a;
        return;
    }

    int n1 = countNodes(a);
    int n2 = countNodes(b);
    cout<<"Size 1 : "<<n1<<", Size 2 : "<<n2<<endl;
    int carry = 0;
    if(n1 == n2)
    {
        *res = addSameSize(a,b,&carry);
    }
    else
    {
        int diff = abs(n1 - n2);

        // Make Sure first list is always bigger.
        if(n1 < n2)
            swapPointer(&a,&b);

        struct node* cur;
    
        // Move diff nodes to make the size equal.
        for(cur=a ; diff-- ; cur=cur->next);

        *res = addSameSize(cur,b,&carry);

        cout<<"half Dispaly\n";
        //display(*res);


        addRemainingCarry(a,cur,&carry,res); 
            
    }

    if(carry)
        insert(res,carry);

    //display(*res);
}


void sortOs1s2s(struct node *head)
{
    int count[3]={0};
    struct node* cur;

    if(head == NULL)
        return;

    cur = head;


    // Traverse the list and populate the count array.
    while(cur != NULL)
    {
        count[cur->info]++;
        cur = cur->next;
    }

    cur = head;

    // Ierate the count array and populate the list
    for(int i=0;i<3;++i)
    {
        while(cur != NULL && count[i])
        {
            cur->info = i;
            count[i]--;  
            cur = cur->next; 
        }
    }
}

void swapkthNodeFromBeginningAndEnd(struct node** head, int k)
{
    if(*head == NULL)
        return;

    int n = countNodes(*head);
    // Check if the kth node is same from beginning and end.
    if(2*k-1 == n)
        return;

    struct node* nodeA,*prevA;
    struct node* nodeB,*prevB;
    int count = 1;

    nodeA = nodeB = *head;
    prevA = prevB = NULL;

    while(nodeA != NULL && count < k)
    {

        prevA = nodeA;
        nodeA = nodeA->next;
        count++;
    }

    cout<<"A : "<<nodeA->info<<endl;
    count = 1;

    while(nodeB != NULL && count < (n-k+1))
    {
        prevB = nodeB;
        nodeB = nodeB->next;
        count++;
    }
    cout<<"B : "<<nodeB->info<<endl;
    if(prevA)
        prevA->next = nodeB;

    if(prevB)
        prevB->next = nodeA;

    // Swap nodeA->next and nodB->next
    struct node* temp = nodeA->next;
    nodeA->next = nodeB->next;
    nodeB->next = temp;

    if(k == 1)
        *head = nodeB;

    if(k == n)
        *head = nodeA;


}

void deleteMnodesAfterNnodes(struct node* head, int m, int n)
{
    if(head == NULL)
        return;

    struct node* cur = head;
    while(cur != NULL)
    {
        // Skip n nodes.
        for(int i=1; i < n && cur != NULL ; ++i )
            cur = cur->next;

        if(cur == NULL)
            return;

        struct node* t = cur->next;

        // Delete m nodes
        for(int i=0;i<m && t != NULL;++i)
        {
            struct node* temp = t;
            t = t->next;
            free(temp);
            
        }

        cur->next = t;
        cur = t;
    }
}
   
void mergeListIntoAnotherList(struct node** p, struct node** q)
{
    struct node* pCur,*pNext;
    struct node* qCur,*qNext;

    pCur = *p;
    qCur = *q;

    while(pCur != NULL && qCur != NULL)
    {
        cout<<pCur->info<<" , "<<qCur->info<<endl;
        pNext = pCur->next;
        qNext = qCur->next;

        pCur->next = qCur;
        qCur->next = pNext;

        pCur = pNext;
        qCur = qNext;
    }


    *q = qNext;
}


int main()
{
    struct node *head=NULL;

    int ch;
    while(1)
    {
        cout<<"1. Insert\t2. Display\t3. Get Nth Node\t4. Which node to delete?\n";
        cout<<"5. Print Middle Node\t6. Nth Node from last\t7. Delete Linked List\n";
        cout<<"8. Count Number of occurence of an list item\t9. Reverse a Linked List\n";
        cout<<"10. Is Linked List Palindrome ?\t";
        cout<<"11. Insert Sorted Order\t";
        cout<<"12. Print Reverse\n13. Remove Duplicated from a sorted list\n";
        cout<<"14. Remove Duplicate from unsoirted list\t";
        cout<<"15. SPlit List into Two Halves\n";
        cout<<"16. Move Last Element to first\t";
        cout<<"17. PairWise Swap Element\n";
        cout<<"18. PairWise Swap Recursive\t19. Copy Linked List\n";
        cout<<"20. Intersection Of Two Sorted Linked List\n";
        cout<<"21. Delete Alternate Nodes\t";
        cout<<"22. Split List Alternatively\t";
        cout<<"23. Merge Two Sorted Linked List\n";
        cout<<"24. Identical Linked Lists\t";
        cout<<"25. Merge Sort\t26. Reverse Linked List in Given Sizes\n";
        cout<<"27. Insert in a sorted Circular list.\n";
        cout<<"28. Reverse Alternate k nodes\n";
        cout<<"29. Delete Nodes with greater value on Right Side\n";
        cout<<"30. Segregate Even and Odd\n";
        cout<<"31. Add Two Numbers (First Node is Least Significant bit)\n";
        cout<<"32. Sorted List to BST\n";
        cout<<"33. Union and IntersectionOfLists\n";
		cout<<"34. Add Two linked list\n";
        cout<<"35. Sort 0s, 1s and 2s\n";
        cout<<"36. Swap kth node from begininning and end\n";
        cout<<"37. Delete M nodes after N nodes\n";
        cout<<"38. Merge One List with Another list\n";

        cin>>ch;

        switch(ch)
        {
            case 1:
                {
                    int n;
                    cout<<"Enter item to be inserted\n";
                    cin>>n;

                    //insert(&head,1);
                    //insert(&head,2);
                    //insert(&head,3);
                    //insert(&head,2);
                    //insert(&head,1);
                    insert(&head,n);
                }
                break;
            case 2:
                display(head);
                break;
            case 3:
                {
                    int n;
                    cout<<"Enter Nth Node to be displayed\n";
                    cin>>n;
                    getNthNode(head,n);
                }
                break;
            case 4:
                {
                    display(head);
                    int n,i=1;
                    cout<<"Enter the node to be deleted\n";
                    cin>>n;
                    struct node* cur = head;
                    while(i < n)
                    {
                        i++;
                        cur = cur->next;
                    }
                    deleteNode(cur);
                }
                break;
            case 5:
                printMiddleNode(head);
                break;
            case 6:
                {
                    int n;
                    display(head);
                    cout<<"Enter the nth Node from last to be displayed\n";
                    cin>>n;
                    getNthLastNodeUsingTwoPointer(head,n);
                }
                break;
            case 7: 
                deleteLinkedList(&head);
                break;
            case 8:
                {
                    int n;
                    cout<<"Enter the item to be searched in the list\n";
                    cin>>n;
                    countNumberOfOccurence(head,n);
                }
                break;
            case 9:
                //reverseLinkedRecursiveList(&head);
                reverseLinkedListIterative(&head);
                display(head);
                break;
            case 10:
                isLinkedListPalindromeUsingStack(head);
                //isLinkedListPalindromeUsingTwoPointer(head);
                break;
            case 11:
                {
                    //display(head);
                    int n;
                    cout<<"Enter the Item to be inserted\n";
                    cin>>n;
                    insertSortedOrder(&head,n);
                    //display(head);
                }
                break;
            case 12:
                cout<<"= = = = Reversed String = = = =\n";
                printReverse(head);
                cout<<endl;
                cout<<"= = = = = = = = = = = = = = =\n";
                break;
            case 13:
                removeDuplicatedSorted(head);
                break;
            case 14:
                removeDuplicateUnsorted(head);
                break;
            case 15:
                {
                    struct node *head1,*head2;
                    head1 = head2 = NULL;
                    splitListIntoTwoHalf(head,&head1,&head2);
                    cout<<"First Half";
                }
                break;
            case 16:
                display(head);
                moveLastToFirst(&head);
                display(head);
                break;
            case 17:
                pairWiseSwapElement(head);
                break;
            case 18:
                pairWiseSwapRecursive(head);
                break;
            case 19:
                {
                    struct node *head2 = NULL;
                    copyLinkedList(&head2,head);
                    display(head);
                    display(head2);
                }
                break;
            case 20:
                {
                    display(head);
                    struct node *head1 = NULL;
                    insert(&head1,2);
                    insert(&head1,6);
                    display(head1);
                    struct node *res = NULL;
                    res = intersectionOftwoLinkedListRecursive(head,head1);
                    //intersectionOfTwoLinkedList(head,head1,&res);
                    display(res);
                }
                break;
            case 21:
                //deleteAlternateNodes(head);
                deleteAlternateNodesRecursive(head);
                display(head);
                break;
            case 22:
                splitAlternativeUtil(&head);
                break;
            case 23:
                {
                    display(head);
                    struct node *head1 = NULL;
                    insert(&head1,2);
                    insert(&head1,6);
                    display(head1);
                    struct node *res = NULL;
                    res = mergeTwoSortedListRecursive(head,head1);
                    display(res);
                }
                break;
            case 24:
                {
                    struct node *head1 = NULL;
                    copyLinkedList(&head1,head);
                    display(head);
                    //display(head1);
                    insert(&head1,5);
                    display(head1);
                    display(head);
                }
                break;
            case 27:
                {
                    insert(&head,2);
                    insert(&head,3);        
                    display(head);
                    head->next->next=head;
                    int item;
                    cout<<"Enter item to be inserted\n";
                    cin>>item;
                    sortedInsertCircularList(&head,item);
                }
                break;
            case 28:
                {
                    int n;
                    cout<<"Enter n to be reversed alternatively\n";
                    cin>>n;
                    head = reverseAlternateKNodes(head,n);
                }
                break;
            case 29:
                deleteNodesWithGreaterValueonRightSide(&head);
                break;
            case 30:
                segregateEvenAndOdd(&head);
                break;
            case 31:
                {
                    struct node *head1 = NULL;
                    insert(&head1,3);
                    insert(&head1,2);
                    insert(&head1,6);

                    display(head);
                    display(head1);

                    struct node* res = addTwoNumbers(head,head1);
                    display(res);
                }
                break;
            case 32:
                {
                    int n = countNodes(head);
                    struct TreeNode* root = sortedListToBST(&head,n);
                    inorder(root);
                }
                break;
            case 33:
                {
                    struct node *head1 = NULL;
                    insert(&head1,6);
                    insert(&head1,8);
                    unionAndIntersectionOfList(head,head1);

                    //display(head);
                }
                break;
			case 34:
				{
                    struct node *head1 = NULL;
                    insert(&head1,8);
                    insert(&head1,3);
                    //insert(&head1,1);

                    display(head);
                    display(head1);
                    struct node* res = NULL;
                    addList(head,head1,&res);
                    display(res);
                }
            case 35:
                sortOs1s2s(head);
                break;
            case 36:
                {
                    display(head);
                    int k;
                    cout<<"Enter K\n";
                    cin>>k;
                    swapkthNodeFromBeginningAndEnd(&head,k);
                }
                break;
            case 37:
                {
                    int m,n;
                    cout<<"Enter M and N\n";
                    cin>>m>>n;
                    deleteMnodesAfterNnodes(head,m,n);
                    display(head);
                }
                break;
            case 38:
                {
                    display(head);
                    struct node *head1 = NULL;
                    insert(&head1,4);
                    insert(&head1,5);
                    insert(&head1,6);
                    display(head1);
                    mergeListIntoAnotherList(&head,&head1);
                    display(head);
                    display(head1);

                }
                break;
            default:
                exit(0);
        }
    }
}
