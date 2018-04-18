#include<iostream>
#include<vector>

using namespace std;

class Node
{
    private:
        char mLetter;
        bool mTerminator;
        vector<Node*> mChildren;
    
    public:

        Node()
        {
            mLetter = ' ';
            mTerminator = false;
        }

        void setLetter(char c)
        {
            mLetter = c;
        }
    
        char getLetter()
        {
            return mLetter;
        }

        void setTerminator()
        {
            mTerminator = true;
        }

        bool hasTerminator()
        {
            return mTerminator;
        }

        void appendChild(Node* ptr)
        {
            mChildren.push_back(ptr);

        }

        Node* findChild(char c)
        {
            for(int i=0 ; i<mChildren.size() ; ++i)
            {
                Node* ptr = mChildren.at(i);
                if(ptr->getLetter() == c)
                {
                    return ptr;
                }
            }

            return NULL;
        }    

        void printBranch(Node* node, char word[], int count)
        {
            if(node->mLetter != ' ')
            {
                word[count++] = node->mLetter;
            }

            if(node->hasTerminator())
            {
                cout<<endl;
                for(int i=0 ; i<count ; ++i)
                    cout<<word[i];
            }

            for(int i=0 ; i<(node->mChildren).size() ; ++i)
            {
                printBranch((node->mChildren).at(i), word,count);
            }
        }

        void printNode()
        {
            char *word = new char[200];

            for(int i=0 ; i<mChildren.size() ; ++i)
            {
                Node* ptr = mChildren.at(i);
                printBranch(ptr,word,0);
            }
        }

};


class Trie
{
    private:
        Node* root;

    public:
        Trie()
        {
            root = new Node;
        }

        void addWord(string s)
        {
            Node* current = root;

            if(s.length() == 0)
            {
                current->setTerminator();
                return;
            }   

            for(int i=0 ; i<s.length() ; ++i)
            {
                Node* child = current->findChild(s[i]);
                if(child != NULL)
                {   
                    current = child;
                }
                else
                {
                    Node* ptr = new Node;
                    ptr->setLetter(s[i]);
                    current->appendChild(ptr);
                    current = ptr;
                }

                if(i == s.length() -1)
                {
                    current->setTerminator();
                }
            }
        }


        bool searchWord(string s)
        {
            Node* current = root;
            while(current != NULL)
            {
                for(int i=0 ; i<s.length() ; ++i)
                {
                    Node* ptr = current->findChild(s[i]);
                    if(ptr == NULL)
                        return false;
            
                    current = ptr;
                }
                if(current->hasTerminator())
                    return true;
                else
                    return false;
            }
            return false;
        }


        void printTrie()
        {
            root->printNode();
        }


};



int main()
{
    Trie* trie = new Trie;

    trie->addWord("cat");
    trie->addWord("car");
    trie->printTrie();
    cout<<endl;


}
