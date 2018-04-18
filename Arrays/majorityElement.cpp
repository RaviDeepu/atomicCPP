#include<iostream>

using namespace std;

class Node
{
    public:
        int item;
        Node *left;
        Node *right;
        int count;
};

Node *root = NULL;

void majorityElementUsingTwoLoops(int a[], int size)
{
    int count=0;
    for(int i=0;i<size;++i)
    {
        count=0;
        for(int j=0;j<size;++j)
        {
            if(a[i] == a[j])
                count++;
            if(count > size/2)
            {
                cout<<"Majority Element : "<<a[i]<<endl;
                return;
            }
        }
    }
    cout<<"Ooooops Sorry....!!!"<<endl;
}

// Insert array values to BST.
// Keep a counter inside every node element.
// While inserting the same item increment the counter and check if the counter is greater than size/2 time
bool insertIntoBST(int value, int size)
{
    //cout<<"Binary Tree Value : "<<value<<endl;
    Node *tNode = new Node;
    tNode->item = value;
    tNode->left = NULL;
    tNode->right = NULL;
    tNode->count = 1;

    if(root == NULL)
    {
        root = tNode;
        return true;
    }
    
    Node *temp = root;
    Node *prev = NULL;
    bool found = false;
    while(temp != NULL)
    {
        found = false;
        prev = temp;
        
        if(temp->item == value)
        {
            temp->count++;
            cout<<"Item : Value : Count : "<<temp->item<<","<<value<<","<<temp->count<<endl;
            found = true;
        }
        else if(value > temp->item)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }

        if(temp && (temp->count > (size/2)))
        {
            cout<<"Count : "<<temp->count<<", Size/2 : "<<(size/2)<<endl;
            return false;
        }
    }
    
    if(found)
        return true;

    if(value > prev->item)
    {
        prev->right = tNode;
    }
    else
    {
        prev->left = tNode;
    }
    return true;
}

void majorityElementUsingBST(int a[], int size)
{
    for(int i=0;i<size;++i)
    {
        //cout<<"Array Value : "<<a[i]<<endl;
        if(insertIntoBST(a[i],size) == false)
        {
            cout<<"Majority Element : "<<a[i]<<endl;
            break;
        }
    }
}

int main()
{
    int a[]={1,1,1,4,2,1,2,1};
    int size = sizeof(a)/sizeof(a[0]);
    //majorityElementUsingTwoLoops(a,size);

    majorityElementUsingBST(a,size);
}
