#include<iostream>
#include<string>
#include<vector>


using namespace std;


class Node
{
    private:
        char mLetter;
        bool mTerminator;
        vector<Node*> mChildren;
    
    public:
        Node():mLetter(' '),mTerminator(false)
        {
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

        void appendChild(Node* child)
        {
            mChildren.push_back(child);
        }
    
        Node* findChild(char c)
        {
            for(int i=0 ; i<mChildren.size() ; ++i)
            {
                Node* child = mChildren.at(i);
                if(child->getLetter() == c)
                {
                    return child;
                }
            }
            return NULL;
        }

        void printNode()
        {
            char word[200];
            for(int i=0 ; i<mChildren.size() ; ++i)
            {
                printBranch(mChildren.at(i),word,0);
            }
        }

        void printBranch(Node* node, char word[], int count)
        {
            if(node->mLetter != ' ')
                word[count++] = node->mLetter;
            
            if(node->hasTerminator())
            {
                cout<<endl;
                for(int i=0 ; i<count ; ++i)
                    cout<<word[i];

                cout<<endl;
            }
            for(int i=0 ; i<(node->mChildren).size() ; ++i)
            {
                printBranch((node->mChildren).at(i),word,count);
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
            cout<<"Adding : "<<s<<endl;

            Node* cur = root;
            if(s.length() == 0)
            {
                cur->setTerminator();
                return;
            }
    
            for(int i=0 ; i<s.length() ; ++i)
            {
                Node* child = cur->findChild(s[i]);
                if(child != NULL)
                {
                    cout<<s[i]<<" Found\n";
                    cur = child;
                }
                else
                {
                    cout<<s[i]<<" Not Found\n";
                    Node* child = new Node;
                    child->setLetter(s[i]);
                    cur->appendChild(child);
                    cur = child;
                }

                if(i == s.length()-1)
                {
                    cur->setTerminator();
                }
            }
        }


        bool searchWord(string s)
        {
            Node* cur = root;
            while(cur != NULL)  
            {
                for(int i=0 ; i<s.length() ; ++i)
                {
                    Node* child = cur->findChild(s[i]);
                    if(child == NULL)
                    {
                        cout<<s[i]<<" Not Found\n";
                        return false;
                    }
                    cur = child;
                }
                if(cur->hasTerminator())
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
    Trie *trie = new Trie;

    trie->addWord("ravi");

    trie->addWord("ram");

    trie->addWord("ramesh");

    if(trie->searchWord("ram"))
        cout<<"Ram Found\n";
    else
        cout<<"Ram Not Found\n";

    trie->printTrie();

}
