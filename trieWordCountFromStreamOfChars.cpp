#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class TrieNode
{
    private:
        char mLetter;;
        bool mTerminator;
        vector<TrieNode*> mChildren;
        string mWord;

    public:
        TrieNode():mLetter(' '),mTerminator(false),mWord(" ")
        {
            
        }

        void setLetter(char c)
        {
            mLetter=c;
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

        TrieNode* findChild(char c)
        {
            for(int i=0 ; i<mChildren.size(); ++i)
            {
                TrieNode* child = mChildren.at(i);
                if(child->getLetter() == c)
                {
                    return child;
                }
                //return NULL;
            }
            return NULL;
        }

        void printBatch(TrieNode* node, char word[], int count)
        {
            if(node->mLetter != ' ')
            {
                word[count++] = node->mLetter;
            }

            if(node->hasTerminator())
            {
                for(int i=0 ; i<count ; ++i)
                    cout<<word[i];

                cout<<endl;
            }

            for(int i=0 ; i<(node->mChildren).size() ; ++i)
            {
                printBatch((node->mChildren).at(i),word,count);
            }
        }

        void printNode(TrieNode* node)
        {
            char word[200];
            for(int i=0 ; i<mChildren.size() ; ++i)
            {
                printBatch(mChildren.at(i),word,0);
            }     
        }
    
        void appendChild(TrieNode* node)
        {
            mChildren.push_back(node);
        }

        void addWordToTerminator(string iWord)
        {
            mWord = iWord;
        }
        
        string getWord()
        {
            return mWord;
        }

        TrieNode* getNodeWhichHasChildrenAsChar(TrieNode* node, char c)
        {
            for(int i=0 ; i<(node->mChildren).size() ; ++i)
            {
                TrieNode *tNode = (node->mChildren).at(i);
                if(tNode->getLetter() == c)
                    return tNode;
            }
            return NULL;
        }

};


/*

Word Frequency in a Stream

    1. Use two Queues Q and R.
    2. For each incoming character c
    2. Add root to Q.
    3. While Q is empty
        a. Remove Node from Q, say it N
        b. Check if N is terminal i.e, some word ends at N.
        c. If N is terminal, then add the word to map or increment the count of map.
        d. Find the child node of N which has the character "c", if any add to R Queue.
    4. Once Q is empty, copy all the elements from R to Q.
    5. Repeat the above process till the stream ends.
    6. Anytime print the map, you will find the frequency of all the words appeared till this point. 

*/

class Trie
{
    
    public:

        TrieNode *root;

        queue<TrieNode*> Q;
        queue<TrieNode*> R;
        unordered_map<string,int> frequentWordsMap;
        
        Trie():root(NULL)
        {
            root = new TrieNode;
        }

        void countFrequentWords()
        {
            string stream = "acacacathellockword";
            TrieNode* cur = root;
            for(int i=0 ; i<stream.length() ; ++i)
            {
                // Push root to W
                Q.push(cur);

                while( !Q.empty() )
                {
                    TrieNode* tNode = Q.front();

                    Q.pop();

                    // Pop from Q and check if it has terminator.
                    // If terminator then increment the count of word.
                    if(tNode->hasTerminator())
                    {
                        frequentWordsMap[tNode->getWord()]++;
                    }

                    // Check if popped node has any children as char
                    // If Yesm then push it to the temporary R Queue.
                    TrieNode *child = tNode->getNodeWhichHasChildrenAsChar(tNode, stream[i]);
                    if(child)
                    {
                        R.push(child);
                    }
                }

                while( !R.empty() )
                {
                    Q.push(R.front());
                    R.pop();
                }
            }

            cout<<"Word Count\n";
            for(auto a : frequentWordsMap)
            {
                cout<<a.first<<" -> "<<a.second<<endl;
            }

        }

        void addWord(string s)
        {
            TrieNode* cur = root;
            if(s.length() == 0)
            {
                cur->setTerminator();
                return;
            }
        
            for(int i=0 ; i<s.length() ; ++i)
            {
                TrieNode* child = cur->findChild(s[i]) ;
                cout<<"Adding : "<<s[i]<<endl;
                if(child != NULL)
                {
                    cur = child;
                }
                else
                {
                    TrieNode* tempNode = new TrieNode;
                    tempNode->setLetter(s[i]) ;
                    cur->appendChild(tempNode);
                    cur = tempNode;          
                }
                if(i == (s.length()-1))
                {
                    cout<<"Set Terminator\n";
                    cur->setTerminator();
                    cur->addWordToTerminator(s);
                }
            }
        }

        bool searchWord(string s)
        {
            TrieNode *cur = root;
            while(cur != NULL)
            {
                for(int i=0 ; i<s.length() ; ++i)
                {
                    TrieNode *child = cur->findChild(s[i]);
                    cout<<"Find : "<<s[i]<<endl;
                    if(child == NULL)
                    {
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

        void printNode()
        {
            root->printNode(root);
        }

};


int main()
{
    Trie* trie = new Trie;

    trie->addWord("aca");
    trie->addWord("cat");
    trie->addWord("hell");
    trie->addWord("hello");
    trie->addWord("lock");
    trie->addWord("world");

    trie->printNode();

    trie->countFrequentWords();

}




