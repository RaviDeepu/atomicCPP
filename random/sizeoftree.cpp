#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<stack>

using namespace std;
 
 /* A binary tree node has data, pointer to left child 
    and a pointer to right child */
    struct node 
    {
            int data;
                struct node* left;
                    struct node* right;
    };
     
     /* Helper function that allocates a new node with the
        given data and NULL left and right pointers. */
        struct node* newNode(int data) 
        {
              struct node* node = (struct node*)
                                     malloc(sizeof(struct node));
                                       node->data = data;
                                         node->left = NULL;
                                           node->right = NULL;
                                              
                                                return(node);
        }
         
         /* Computes the number of nodes in a tree. */
         int size(struct node* node) 
         {  
               if (node==NULL) 
                       return 0;
                         else    
                                 return(size(node->left) + 1 + size(node->right));  
         }
          
        bool morrisTraversalISBST(struct node *root)
        {
            if(root == NULL)
                return true;

            struct node* cur, *pre;
            cur = root;
            while(cur != NULL)
            {
                // This will print Only the Leaf nodes.
                if(cur->left == NULL)
                {
                    if(cur->right && cur->right->data < cur->data)
                        return false;

                    cout<<"Leaf : "<<cur->data<<endl;
                    cur = cur->right;
                }
                else
                {
                    pre = cur->left;
                    // Find the inorder predecessor.
                    while(pre->right != NULL && pre->right != cur)
                        pre = pre->right;

                    if(pre->right == NULL)
                    {
                        // Create a link from Predeccesor to the next node.
                        pre->right = cur;
                        cur = cur->left;
                    }
                    else
                    {
                        if(cur->left && cur->right && (cur->left->data > cur->data || cur->right->data < cur->data))
                            return false;
                        // Correct the Tree.
                        cout<<"Node : "<<cur->data<<endl;
                        pre->right = NULL;
                        cur = cur->right;
                    }
                }
            }
            return true;
        }

		
		/*Non recursive postorder tree trraversal using only one stack.*/
void postorder_non_recursive_1(struct node* nodePtr)
{
    if (!nodePtr)
        return;
    cout<<endl;
    stack<struct node*> s;
    /*We will need current poionter to the node we are currently
    traversing and the pointer to the node we traversed previously.*/
    struct node* current = nodePtr;
    struct node* previous = NULL;
    s.push(current);
    while (!s.empty())
    {
        current = s.top();
        cout<<"cur->top : "<<current->data<<endl;
        /*Traverse the tree down*/
        if (!previous || previous->left == current || previous->right == current)
        {
            if(current->left && current->right)
                cout<<current->left->data<<","<<current->right->data<<endl;
            if (current->left)
                s.push(current->left);
            else if (current->right)
                s.push(current->right);
            else
            {
                cout << "1. "<<current->data << "\t";
                s.pop();
            }
        }
        /*Traverse the tree up from the left*/
        else if (current->left == previous)
        {
            cout<<"2. "<<endl;
            if (current->right)
                s.push(current->right);
            else
            {
                cout << current->data << "\t";
                s.pop();
            }
        }
        else if (current->right == previous)
        {
            cout<<"3. "<<endl;
            cout << current->data << "\t";
            s.pop();
        }
        previous = current;
    }
    cout << endl;
    return;
}

          /* Driver program to test size function*/   
          int main()
          {
                struct node *root = newNode(4);
                  root->left        = newNode(2);
                    root->right       = newNode(6);
                      root->left->left  = newNode(1);
                        root->left->right = newNode(3); 
						root->right->right       = newNode(7);
						root->right->left       = newNode(5);						
                        /*
                        if(morrisTraversalISBST(root))
                            cout<<"Yessss\n";
                        else
                            cout<<"Noooooo\n";
							*/
							postorder_non_recursive_1(root);
                           //printf("Size of the tree is %d", size(root));  
                             getchar();
                               return 0;
          }
