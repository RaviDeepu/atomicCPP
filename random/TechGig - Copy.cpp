#include<iostream>
#include<stdlib.h>

using namespace std;


struct TreeNode
{
    float key;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
    int size; // size of the tree rooted with this TreeNode
};
 
int max(int a, int b);
 
int treeHeight(struct TreeNode *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int size(struct TreeNode *N)
{
    if (N == NULL)
        return 0;
    return N->size;
}
 
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
struct TreeNode* newNode(int key)
{
    struct TreeNode* TreeNode = (struct TreeNode*)
                        malloc(sizeof(struct TreeNode));
    TreeNode->key   = key;
    TreeNode->left   = NULL;
    TreeNode->right  = NULL;
    TreeNode->height = 1;  // new TreeNode is initially added at leaf
    TreeNode->size = 1;
    return(TreeNode);
}
 
struct TreeNode *rightRotate(struct TreeNode *y)
{
    struct TreeNode *x = y->left;
    struct TreeNode *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(treeHeight(y->left), treeHeight(y->right))+1;
    x->height = max(treeHeight(x->left), treeHeight(x->right))+1;
 
    y->size = size(y->left) + size(y->right) + 1;
    x->size = size(x->left) + size(x->right) + 1;
 
    return x;
}
 
struct TreeNode *leftRotate(struct TreeNode *x)
{
    struct TreeNode *y = x->right;
    struct TreeNode *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(treeHeight(x->left), treeHeight(x->right))+1;
    y->height = max(treeHeight(y->left), treeHeight(y->right))+1;
 
    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;
 
    return y;
}
 
int getBalance(struct TreeNode *N)
{
    if (N == NULL)
        return 0;
    return treeHeight(N->left) - treeHeight(N->right);
}
 
struct TreeNode* insert(struct TreeNode* TreeNode, float key, int& countNumberOfSwaps)
{
    if (TreeNode == NULL)
        return(newNode(key));
 
    if (key < TreeNode->key)
        TreeNode->left  = insert(TreeNode->left, key, countNumberOfSwaps);
    else if(key > TreeNode->key)
    {
        TreeNode->right = insert(TreeNode->right, key, countNumberOfSwaps);
 
        countNumberOfSwaps = countNumberOfSwaps + size(TreeNode->left) + 1;
    }
    /*
    else
    {
        TreeNode->right = insert(TreeNode->right, key, countNumberOfSwaps);
    }
    */
 
 
    TreeNode->height = max(treeHeight(TreeNode->left), treeHeight(TreeNode->right)) + 1;
    TreeNode->size   = size(TreeNode->left) + size(TreeNode->right) + 1;
 
    int balance = getBalance(TreeNode);
 
    if (balance > 1 && key < TreeNode->left->key)
        return rightRotate(TreeNode);
 
    if (balance < -1 && key > TreeNode->right->key)
        return leftRotate(TreeNode);
 
    if (balance > 1 && key > TreeNode->left->key)
    {
        TreeNode->left =  leftRotate(TreeNode->left);
        return rightRotate(TreeNode);
    }
 
    if (balance < -1 && key < TreeNode->right->key)
    {
        TreeNode->right = rightRotate(TreeNode->right);
        return leftRotate(TreeNode);
    }
 
    /* return the (unchanged) TreeNode pointer */
    return TreeNode;
}
 
void constructHeightArray (float arr[], int& countNumberOfSwaps, int n)
{
  int i, j;
  struct TreeNode *root = NULL;

 
  for (i = n-1; i >= 0; i--)
  {
     root = insert(root, arr[i], countNumberOfSwaps);
  }
  
}




float getCmsFromFeet(int feet)
{
    return 30.48 * feet;
}

float getCmsFromInches(int inch)
{
    return 2.54 * inch;
}

int getHeight(char* input1[],int input2)
{
    float heightArray[input2];
    int noOfSwaps = -1;

    for(int i = 0; i < input2; i++)
    {
        int tempFeet = input1[i][0] - '0'; //atoi(input1[i][0]);
        int tempInch = input1[i][2] - '0'; //atoi(input1[i][2]);

        // Base Feet checking
        if( (tempFeet < 4) && (tempFeet > 7) )
        {
            return -1;
        }

        // Base Inch checking
        if( (tempInch < 0) && (tempInch > 11))
        {
            return -1;
        }

        float feetInCms = getCmsFromFeet(tempFeet);
        float inchesInCms = getCmsFromInches(tempInch);
        heightArray[i] = feetInCms + inchesInCms;
        cout<<"Feet : "<<feetInCms<<" , "<<inchesInCms<<endl;
    }

    constructHeightArray(heightArray, noOfSwaps, input2);
    return noOfSwaps;


}