#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<set>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


class TreeNode
{

	public:
			int info;
		TreeNode *left;
		TreeNode *right;
        TreeNode *parent;
        bool visited;
		
		TreeNode(int item=0)
		{
			info = item;
			left = NULL;
			right = NULL;
            parent = NULL;
            visited = false;
		}
};

class binarytree
{
		TreeNode *root;
	public:
		binarytree()
		{
			root = NULL;
		}
		void insert(int item)
		{
			TreeNode *newNode = new TreeNode(item);
			if(root == NULL)
			{
				root = newNode;
				return;
			}
			
			TreeNode *temp = root;
			TreeNode *prev = NULL;
			while(temp != NULL)
			{
				prev = temp;
				if(item > temp->info)
				{
					temp = temp->right;
				}
				else
				{
					temp = temp->left;
				}
			}
			
			if(item > prev->info)
            {
				prev->right = newNode;
            }
			else
            {
				prev->left = newNode;
            }
            newNode->parent = prev;
			
		}
		
        void parentOfAllNodes(TreeNode *node)
        {
            if(node != NULL)
            {
                cout<<node->info<<endl;
                parentOfAllNodes(node->left);
                if(node->parent == NULL)
                    cout<<"Child : "<<node->info<<", Parent : NULL"<<endl;
                else
                    cout<<"Child : "<<node->info<<", Parent : "<<node->parent->info<<endl;
                //cout<<node->info<<" ";
                parentOfAllNodes(node->right);
            }

        }

		void inorder(TreeNode* node)
		{
			if(node != NULL)
			{
				inorder(node->left);
				cout<<node->info<<" ";
				inorder(node->right);
			}
		}
		
		int heightOFTree(TreeNode* node)
		{
			if(node == NULL)
				return 0;
				
			return 1 + max(heightOFTree(node->left), heightOFTree(node->right));
		}
		
		int max(int a, int b)
		{
			return a>b?a:b;
		}
		
		int numberOfNodes(TreeNode* node)
		{
			if(node == NULL)
				return 0;
				
			return ( 1 + numberOfNodes(node->left) + numberOfNodes(node->right));
		}
		
		void deleteTree(TreeNode* node)
		{
			if(node != NULL)
			{
				deleteTree(node->left);
				deleteTree(node->right);
				cout<<"Deleting Node : "<<node->info<<endl;
				delete(node);
				
			}
		}
		
		
		TreeNode* getRoot()
		{
			return root;
		}

        void setRoot(TreeNode* node)
        {
            root = node;
        }

        void setRootToNULL()
        {
            root = NULL;
        }

        void inorderWithoutRecursion(TreeNode* node)
        {
            stack<TreeNode*> s;
            if(node == NULL)
            {
                cout<<"Tree Empty\n";
                return;
            }
            TreeNode* cur = node;
            //s.push(cur);
            while(!s.empty() || cur)
            {
                   if(cur)
                   {
                       s.push(cur);
                       cur = cur->left;
                   }
                   else
                   {
                       cur = s.top();
                       s.pop();
                       cout<<cur->info<<" ";
                       cur = cur->right;
                   }
            }
            cout<<endl;
        }

        void preorderWithoutRecursion(TreeNode* node)
        {
            if(node == NULL)
            {
                cout<<"Tree Empty\n";
                return;
            }

            stack<TreeNode*> s; 
            TreeNode *cur = node;

            s.push(cur);
            while(!s.empty())
            {
                cur = s.top();
                s.pop();
                cout<<cur->info<<" ";
                if(cur->right)
                    s.push(cur->right);
                if(cur->left)
                    s.push(cur->left);

            }
            cout<<"\n";
        }

        void printRootToLeafPath(TreeNode* node, int path[], int pathlength)
        {
            if(node == NULL)
                return;

            path[pathlength] = node->info;
            pathlength++;

            if(node->left == NULL && node->right == NULL)
            {
                printPath(path, pathlength);
            }
            else
            {
                printRootToLeafPath(node->left, path, pathlength);
                printRootToLeafPath(node->right, path, pathlength);

            }
        }

        void printPath(int a[], int length)
        {
            for(int i=0 ; i<length ; i++)
                cout<<a[i];
            cout<<endl;
        }


        void postOrderWithoutRecursion(TreeNode *node)
        {
            stack<TreeNode*> s1,s2;

            TreeNode *cur = node;
            s1.push(cur);
            while(!s1.empty())
            {
                cur = s1.top();
                s2.push(cur);
                s1.pop();

                if(cur->left)
                    s1.push(cur->left);
                if(cur->right)
                    s1.push(cur->right);
            }

            while(!s2.empty())
            {
                cur = s2.top();
                cout<<cur->info<<",";
                s2.pop();
            }
            cout<<endl;
        }

        int isIdenticalTrees(TreeNode *tree1, TreeNode *tree2)
        {
            if(tree1 == NULL && tree2 == NULL)
                return 1;

            if(tree1 != NULL && tree2 != NULL)
            {
                return(tree1->info == tree2->info && isIdenticalTrees(tree1->left, tree2->left) && isIdenticalTrees(tree1->right, tree2->right));
            }
            return 0;
        }

        void mirrorTree(TreeNode *node)
        {
            if(node != NULL)
            {
                mirrorTree(node->left);

                // Swap the nodes
                TreeNode *cur = node->left;
                node->left = node->right;
                node->right = cur;

                mirrorTree(node->right);
            }
        }

        void mirrorTreeWithoutRecursion(TreeNode *node)
        {
            stack<TreeNode*> s;
            TreeNode *cur = node;

            s.push(cur);
            while(!s.empty())
            {
                TreeNode *temp;
                cur = s.top();
                
                s.pop();

                // Swap
                temp = cur->left;
                cur->left = cur->right;
                cur->right = temp;

                if(cur->left)
                    s.push(cur->left);
                if(cur->right)
                    s.push(cur->right);

            }
        }

        int heightOfTreeWithoutRecursion()
        {
            queue<TreeNode*> q;
            int height = 0;
            TreeNode* cur = root;
            q.push(cur);

            while(!q.empty())
            {
                height++;
                int nodeCount = q.size();
                while(nodeCount > 0)
                {
                    cur = q.front();
                    //cout<<cur->info;
                    q.pop();
                    if(cur->left)
                        q.push(cur->left);
                    if(cur->right)
                        q.push(cur->right);
                    nodeCount--;
                }
                cout<<endl;
            }
            return height;

        }


        void LevelOrderTraversalWithoutRecursion()
        {
            queue<TreeNode*> q;
            int height = 0;
            TreeNode* cur = root;
            q.push(cur);

            while(!q.empty())
            {
                height++;
                int nodeCount = q.size();
                while(nodeCount > 0)
                {
                    cur = q.front();
                    cout<<cur->info<<",";
                    q.pop();
                    if(cur->left)
                        q.push(cur->left);
                    if(cur->right)
                        q.push(cur->right);
                    nodeCount--;
                }
                cout<<endl;
            }
           // return height;

        }


        TreeNode* LCA(TreeNode *node, int firstChild, int secondChild)
        {
            if(node == NULL)
                return NULL;

            if(node->info == firstChild || node->info == secondChild)
            {
                return node;
            }

            TreeNode* left = LCA(node->left, firstChild, secondChild);
            TreeNode* right = LCA(node->right, firstChild, secondChild);

            return left ? left : right;
        }

        void printGivenLevel(TreeNode* node, int level)
        {
            if(!node)
                return;

            if(level == 1)
                cout<<node->info<<",";
            else
                printGivenLevel(node->left,level-1);
                printGivenLevel(node->right,level-1);
        }

        void levelOrderTraversal(TreeNode* node)
        {
            int height = heightOFTree(node);
            for(int i=1; i<=height; ++i)
            {
                printGivenLevel(node,i);
                cout<<endl;
            }
        }

        int minimumValue(TreeNode *node, int min)
        {
            if(node == NULL)
                return min;

            if(node->info < min)
                min = node->info;
            cout<<node->info<<endl; 
            min = minimumValue(node->left,min);
            min = minimumValue(node->right,min);
            return min;

        }

        void morrisTraversalInorder()
        {
            if(root == NULL)
                return;

            cout<<"Morris Inorder Traversal\n";
            TreeNode* cur, *pre;
            cur = root;
            while(cur != NULL)
            {
                // This will print Only the Leaf nodes.
                if(cur->left == NULL)
                {
                    //cout<<"Leaf Succ of "<<cur->info<<" is "<<pre->info<<endl;
                    cout<<"Leaf : "<<cur->info<<endl;
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
                        //cout<<"Root Succ of "<<pre->info<<" is "<<cur->info<<endl;
                        // Create a link from Predeccesor to the next node.
                        pre->right = cur;
                        cur = cur->left;
                    }
                    else
                    {
                        cout<<"Root Succ of "<<pre->info<<" is "<<cur->info<<endl;
                        // Correct the Tree.
                        //cout<<"Node : "<<cur->info<<endl;
                        pre->right = NULL;
                        cur = cur->right;
                    }
                }
            }
        }

        void morrisTraversalPostorder()
        {
            if(root == NULL)
                return;

            TreeNode* cur, *pre;
            cur = root;
            pre = root;
            while(cur != NULL)
            {
                
                if(pre->right != cur && pre->left != NULL)
                {
                   // cout<<pre->right->info<<endl;
                    cout<<"Out : "<<cur->info<<endl;;
                    //cur->visited = true;
                }

                // This will print Only the Leaf nodes.
                if(cur->left == NULL)
                {

                    //cout<<"Leaf : "<<cur->info<<endl;
                    cur = cur->right;
                }
                else
                {

                //cout<<"Out : "<<pre->info<<endl;;
                // This will print Only the Leaf nodes.
                    pre = cur->left;
                    // Find the inorder predecessor.
                    while(pre->right != NULL && pre->right != cur)
                        pre = pre->right;

                    if(pre->right == NULL)
                    {
                       // cout<<"if : "<<pre->info<<endl;
                        // Create a link from Predeccesor to the next node.
                        pre->right = cur;
                        cur = cur->left;
                    }
                    else
                    {
                         //Correct the Tree.
                         pre->right = NULL;
                         cur = cur->right;
                    }
                }
            }
        }
        
        /*
        void morrisTraversalPostorder()
        {
            if(root == NULL)
                return;

            TreeNode* cur, *pre;
            cur = root;
            pre = root;
            while(cur != NULL)
            {
                
                if(cur->visited == false)
                {
                    cout<<"Out : "<<cur->info<<endl;;
                    cur->visited = true;
                }

                // This will print Only the Leaf nodes.
                if(cur->left == NULL)
                {

                    //cout<<"Leaf : "<<cur->info<<endl;
                    cur = cur->right;
                }
                else
                {

                //cout<<"Out : "<<pre->info<<endl;;
                // This will print Only the Leaf nodes.
                    pre = cur->left;
                    // Find the inorder predecessor.
                    while(pre->right != NULL && pre->right != cur)
                        pre = pre->right;

                    if(pre->right == NULL)
                    {
                       // cout<<"if : "<<pre->info<<endl;
                        // Create a link from Predeccesor to the next node.
                        pre->right = cur;
                        cur = cur->left;
                    }
                    else
                    {
                         //Correct the Tree.
                        //cout<<"else : "<<pre->info<<endl;
                        pre->visited = true;
                        pre->right = NULL;
                        cur = cur->right;
                    }
                }
            }
        }
        */


        bool morrisTraversalISBST()
        {
            if(root == NULL)
                return true;

            TreeNode* cur, *pre;
            cur = root;
            while(cur != NULL)
            {
                // This will print Only the Leaf nodes.
                if(cur->left == NULL)
                {
                    if(cur->right && cur->right->info < cur->info)
                        return false;

                    cout<<"Leaf : "<<cur->info<<endl;
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
                        if(cur->left && cur->right && (cur->left->info > cur->info || cur->right->info < cur->info))
                            return false;
                        // Correct the Tree.
                        cout<<"Node : "<<cur->info<<endl;
                        pre->right = NULL;
                        cur = cur->right;
                    }
                }
            }
            return true;
        }


        // Using Parent pointer, we can traverse upwards from first child and second child
        // and pusing it back to HashSet, if we encounter the collision the current node will
        // be the LCA.
        TreeNode* LCAUsingHashSet_Iterative(TreeNode* node, TreeNode* firstChild, TreeNode* secondChild)
        {
            set<TreeNode*> visited;
            while(firstChild != NULL || secondChild != NULL)
            {
                if(firstChild)
                {
					//STL set<>.insert(elem) returns pair<iterator,bool> where the second value in the pair is true if the element was successfully inserted, false otherwise.
                    if(!visited.insert(firstChild).second)
                        return firstChild;
                    firstChild = firstChild->parent;
                }

                if(secondChild)
                {
                    if(!visited.insert(secondChild).second)
                        return secondChild;
                    secondChild = secondChild->parent;
                }
            }
            return NULL;
        }

        // If the root info is greater than first and Second child info
        // then the LCA lies in left subtree, else right subtree.
        TreeNode* LCABST(TreeNode* node, int n1, int n2)
        {
            if(node == NULL)
                return NULL;

            // LCA lies in left subtree
            if(node->info > n1 && node->info > n2)
                return LCABST(node->left,n1,n2);

            if(node->info < n1 && node->info < n2)
                return LCABST(node->right,n1,n2);

            return root;
        }

        int search(int a[], int start, int end, int n)
        {
            for(int i=start; i<end; i++)
            {
                if(a[i] == n)
                    return i;
            }
        }

        TreeNode* constructTreeFromInorderAndPreorder(int in[], int pre[], int iStart, int iEnd)
        {
            static int preIndex = 0;
            
            if(iStart > iEnd)
                return NULL;

            int info = pre[preIndex++];
            cout<<"info : "<<info<<",iStart : "<<iStart<<", iEnd : "<<iEnd<<endl;

            TreeNode* node = new TreeNode(info);
            node->left = NULL;
            node->right = NULL;
            // If this node has no children then return.
            if(iStart == iEnd)
                return node;

            int inIndex = search(in,iStart, iEnd, info);

            node->left = constructTreeFromInorderAndPreorder(in, pre, iStart, inIndex-1);
            node->right = constructTreeFromInorderAndPreorder(in, pre, inIndex+1,iEnd);

            return node;
        }


        int getLevelWidth(TreeNode *node, int level)
        {
            if(node == NULL)
                return 0;

            if(level == 1)
                return 1;

            return (getLevelWidth(node->left,level-1) + getLevelWidth(node->right,level-1));
        }

        int maximumWidthOfBinaryTreeRecursive(TreeNode *node)
        {
            int height = heightOFTree(node);
            int width,maxwidth;
            width=maxwidth=0;
            for(int i=1 ; i<height ; i++)
            {
                width = getLevelWidth(node,i);
                if(width > maxwidth)
                    maxwidth = width;
            }
            return maxwidth;
        }


        int maximumWidthOfBinaryTreeWithoutRecursion(TreeNode *node)
        {
            queue<TreeNode*> q;
            TreeNode *temp = node;
            q.push(temp);
            int maxWidth=0;

            while(!q.empty())
            {
                int nodeCount = q.size();
                if(nodeCount > maxWidth)
                    maxWidth = nodeCount;
                while(nodeCount > 0)
                {
                    nodeCount--;
                    temp = q.front();
                    q.pop();
                    if(temp->right)
                        q.push(temp->right);
                    if(temp->left)
                        q.push(temp->left);
                }

            }

            return maxWidth;
        }


        bool rootToLeafSum(TreeNode* node, int sum)
        {
            if(root == NULL)
                return false;
            cout<<node->info<<endl;
            //int subSum = sum - node->info;
            if(node->data == sum && node->left == NULL && node->right == NULL)
                return true;

            return rootToLeafSum(node->left,sum-node->data) || rootToLeafSum(node->right,sum-node->data);

        }


        void kth_Smallest(TreeNode* node, int k)
        {
            static int count;
            if(node == NULL)
                return ;

            kth_Smallest(node->left,k);

            count++;
            if(count == k)
                cout<<node->info;

             kth_Smallest(node->right,k);
        }



        // To find the Kth Largest element, we need to do
        // reverse inorder traversal.
        void kth_Largest(TreeNode* node, int k)
        {
            static int count;

            if(node == NULL)
                return;

            kth_Largest(node->right,k);

            count++;
            if(count == k)
                cout<<node->info;

            kth_Largest(node->left,k);
        }
        
        // Convert tree to a Sum tree.
        void convertTree(TreeNode *node)
        {
            if(node == NULL || (node->left == NULL && node->right == NULL))
            {
                return;
            }
            else
            {
                cout<<"ConvertTree : "<<node->info<<endl;
                int left_info=0,right_info=0;
                convertTree(node->left);
                convertTree(node->right);

                if(node->left != NULL)
                    left_info = node->info;

                if(node->right != NULL)
                    right_info = node->info;

                int diff = left_info + right_info - node->info;

                if(diff > 0)
                    node->info = node->info + diff;
                
                if(diff < 0)
                    increment(node,-diff);

            }
        }

        void increment(TreeNode *node, int diff)
        {
            cout<<"Increment : "<<node->info<<endl;
            if(node->left != NULL)
            {
                node->left->info += diff;
                increment(node->left,diff);
            }
            else if(node->right != NULL)
            {
                node->right->info += diff;
                increment(node->right,diff);
            }
        }

        void printNodesDistanceK(TreeNode *node, int k)
        {
            if(k == 0)
            {
                cout<<node->info<<endl;
                return;
            }
            else
            {
                printNodesDistanceK(node->left,k-1);
                printNodesDistanceK(node->right,k-1);
            }
        }


        TreeNode* constructBSTFromArray(int a[], int n)
        {
            static int index=0;
            if(n <=0 )
                return NULL;

            // Recursively construct the left sub tree.
            TreeNode* left = constructBSTFromArray(a,n/2);

            TreeNode *head = new TreeNode(a[index++]);
            head->left = left;

            // The number of nodes in right sub tree is 
            // Number of nodes - number of nodes in left sub tree -1.
            head->right = constructBSTFromArray(a,n-n/2-1);

            return head;

        }


        TreeNode* constructBSTFromArray_1(int a[], int start, int end)
        {
            if(start > end)
                return NULL;

            int mid = (start + end)/2;
            TreeNode *temp = new TreeNode(a[mid]);

            temp->left = constructBSTFromArray_1(a,start,mid-1);

            temp->right = constructBSTFromArray_1(a,mid+1,end);

            return temp;
        }


};


int main()
{
	binarytree b;
	
	
	int ch,item;
	for(;;)
	{
		cout<<"\n1. Insert\n2. Inorder Traversal\n3. Height Of Tree\n";
		cout<<"4. Number Of nodes\n5. Delete A Tree\n6. Inorder Without Recursion\n";
        cout<<"7. PreOrder Without Recursion\n";
        cout<<"8. Print Root To Leaf Path\n";
        cout<<"9. PostOrder Without Recursion\n";
        cout<<"10. Mirror Tree\n";
        cout<<"11. Mirror Tree without Recursion\n";
        cout<<"12. Height Of Tree Without Recursion\n";
        cout<<"13. Parent Of All Nodes\n";
        cout<<"14. Lowest Common Ancestor\n";
        cout<<"15. Level Order Traversal\n";
        cout<<"16. Level Order Traversal Without Recursion\n";
        cout<<"17. Minimum Value of a Tree\n";
        cout<<"18. Morris Traversal Inorder\n";
        cout<<"19. Is Binary Search Tree ? Morris Traversal ?\n";
        cout<<"20. Lowest Common Ancestor without recursion\n";
        cout<<"21. Lowest Common Ancestor of a BST\n";
        cout<<"22. Construct Binary tree from Inorder and Preorder\n";
        cout<<"23. Maximum width of a binary tree Recursive\n";
        cout<<"24. Maximum Width of a binary tree Iterative\n";
        cout<<"25. Root to Leaf eqaul to Sum\n";
        cout<<"26. K-th Smallest element in BST\n";
        cout<<"27. K-th Largest element in BST\n";
        cout<<"28. Convert the tree to children sum property.\n";
        cout<<"29. Print nodes at K distance\n";
        cout<<"30. Construct BST from array\n";
        cout<<"31. Construct BST from Array _1\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
					//cout<<"Enter the item to be inserted\n";
					//cin>>item;
					b.insert(4);
					b.insert(2);
					b.insert(3);
					b.insert(1);
					b.insert(6);
					b.insert(5);
					b.insert(7);
					//b.insert(8);
					break;
			case 2:
					cout<<"The elements are\n";
					b.inorder(b.getRoot());
					break;
			case 3:
					cout<<"Height of a tree : "<<b.heightOFTree(b.getRoot())<<endl;
					break;
			case 4:
                
					cout<<"Number of Nodes : "<<b.numberOfNodes(b.getRoot());
					break;
			case 5:
					b.deleteTree(b.getRoot());
					b.setRootToNULL();
					break;
            case 6:
                    b.inorderWithoutRecursion(b.getRoot());
                    break;
            case 7:
                    b.preorderWithoutRecursion(b.getRoot());
                    break;
            case 8:
                    {
                        int path[100],length=0;
                        b.printRootToLeafPath(b.getRoot(),path,length);
                    }
                    break;
            case 9: 
                    b.postOrderWithoutRecursion(b.getRoot());
                    break;

            case 10:
                    b.mirrorTree(b.getRoot());
                    break;
                    
            case 11:
                    b.mirrorTreeWithoutRecursion(b.getRoot());
                    break;
            case 12:
                    cout<<"Height Of a Tree : "<<b.heightOfTreeWithoutRecursion()<<endl;
                    break;
            case 13:
                    b.parentOfAllNodes(b.getRoot());
                    break;
            case 14:
                    {
                        int one,two;
                        cout<<"Enter the node whose LCA to be found\n";
                        cin>>one>>two;
                        cout<<"LCA is : "<<b.LCA(b.getRoot(),one,two)->info<<endl;;
                    }
                    break;
            case 15:
                    b.levelOrderTraversal(b.getRoot());
                    break;
            case 16:
                    b.LevelOrderTraversalWithoutRecursion();
                    break;
            case 17:
                    cout<<"Minimum Value of a tree is : "<<b.minimumValue(b.getRoot(),b.getRoot()->info)<<endl;
                    break;
            case 18:
                    b.morrisTraversalInorder();
                    break;
            case 19:
                    if(b.morrisTraversalISBST())
                        cout<<"Yessssss\n";
                    else
                        cout<<"Nooooooo\n";
                    break;
            case 20:
                    {
                        //int one,two;
                        //cout<<"Enter the node whose LCA to be found\n";
                        //cin>>one>>two;
                        cout<<"LCA is : "<<b.LCAUsingHashSet_Iterative(b.getRoot(),b.getRoot()->left,b.getRoot()->left->right)->info<<endl;;
                    }
                    break;

            case 21:
                    {
                        int one,two;
                        cout<<"Enter the node whose LCA to be found\n";
                        cin>>one>>two;
                        cout<<"LCA is : "<<b.LCABST(b.getRoot(),one,two)->info<<endl;;
                    }
                    break;
            case 22:
                    {
                        int inorder[]={1,2,3,4,5,6,7,8};
                        int preorder[]={4,2,1,3,6,5,7,8};

                        TreeNode* root = b.constructTreeFromInorderAndPreorder(inorder, preorder,0,sizeof(inorder)/sizeof(inorder[0])-1);
                        b.setRoot(root);
                    }
                    break;
            case 23:
                    cout<<"Maximum width Of Binary Tree : "<<b.maximumWidthOfBinaryTreeRecursive(b.getRoot())<<endl;
                    break;
            case 24:
                    cout<<"Maximum width Of Binary Tree : "<<b.maximumWidthOfBinaryTreeWithoutRecursion(b.getRoot())<<endl;
                    break;
            case 25:
                    {
                        int sum;
                        cout<<"Enter any sum : ";
                        cin>>sum;
                        if(b.rootToLeafSum(b.getRoot(),sum))
                            cout<<"Yesssss\n";
                        else
                            cout<<"Noooooo\n";
                    }
                    break;

            case 26:
                    {
                        int n;
                        cout<<"Enter n\n";
                        cin>>n;

                        cout<<n<<"th Smallest element in BST : ";
                        b.kth_Smallest(b.getRoot(),n);
                    }
                    break;

            case 27:
                    {
                        int n;
                        cout<<"Enter n\n";
                        cin>>n;
                        cout<<n<<"th Largest element in BST : ";
                        b.kth_Largest(b.getRoot(),n);
                    }
                    break;
            case 28:
                    b.convertTree(b.getRoot());
                    break;
            case 29:
                    b.printNodesDistanceK(b.getRoot(),2);
                    break;
            case 30:
                    {
                        int a[]={1,2,3,4,5};
                        TreeNode *node = b.constructBSTFromArray(a,5);
                        b.setRoot(node);
                    }
                    break;
            case 31:
                    {
                        int a[]={1,2,3,4,5};
                        TreeNode *node = b.constructBSTFromArray_1(a,0,4);
                        b.setRoot(node);
                    }
                    break;
			default:
					exit(0);
		}
	}
}
