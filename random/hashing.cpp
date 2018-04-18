#include<iostream>
#include<stdlib.h>
//#include<stdlib>
#define MAX_SIZE 20
using namespace std;



class HashNode
{
    public:
        int value;
        int key;
        HashNode *next;
        HashNode(int ivalue, int ikey)
        {
            value = ivalue;
            key = ikey;
            next = NULL;
        }
};


class HashMap
{
        HashNode **hashTable;
    public:
        HashMap()
        {
            hashTable = new HashNode*[MAX_SIZE];
            for(int i=0;i<MAX_SIZE;i++)
            {
                hashTable[i]= NULL;
            }
        }


        void Insert(int ikey, int ivalue)
        {
            int hashValue = HashFunction(ikey);
			cout<<"HashValue : "<<hashValue<<endl;
            HashNode *entry = hashTable[hashValue];
            HashNode *prev = NULL;
            while(entry != NULL)
            {
                prev = entry;
                entry = entry->next;
            }

            if(entry == NULL)
            {
                entry = new HashNode(ivalue, ikey);
                if(prev == NULL)
                    hashTable[hashValue] = entry;
                else
                    prev->next = entry;
            }
        }

        int HashFunction(int ikey)
        {
            return ikey % MAX_SIZE;
        }

        void Display(int ikey)
        {
            int hashValue = HashFunction(ikey);
			cout<<"HashValue : "<<hashValue<<endl;
            HashNode *node = hashTable[hashValue];
            
            if(node == NULL)
            {
                cout<<"Empty "<<endl;
                return;
            }
            
            while(node != NULL)
            {
                cout<<node->value<<",";
                node = node->next;
            }
            cout<<endl;
        }

        void Remove(int ikey, int ivalue)
        {
            int hashValue = HashFunction(ikey);
			cout<<"HashValue : "<<hashValue<<endl;
            HashNode *node = hashTable[hashValue];
            HashNode *prev = NULL;
            bool found = false;
            if(node  == NULL)
            {
                cout<<"Hash Table is Empty\n";
                return;
            }

            if(node->value == ivalue)
            {
                hashTable[hashValue] = node->next;
				cout<<"Deleting : "<<node->value<<endl;
                delete node;
				return;
            }
            while(node != NULL)
            {
                prev = node;
                node = node->next;
                if(node->value == ivalue)
                {
                    cout<<"Deleting : "<<node->value<<endl;
                    prev->next = node->next;
                    delete node;
                    found = true;
                }
            }
            if(!found)
            {
                cout<<ivalue<<" Not Found.\n";
            }
        }
		
		 /*
         * Search Element at a key
         */
        int Search(int key)
        {
            bool flag = false;
            int hash_val = HashFunction(key);
            HashNode* entry = hashTable[hash_val];
            while (entry != NULL)
			{
                if (entry->key == key)
				{
                    cout<<entry->value<<" ";
                    flag = true;
                }
                entry = entry->next;
            }
            if (!flag)
                return -1;
        }
};



/*
 * Main Contains Menu
 */
int main()
{
    HashMap hash;
    int key, value;
    int choice;
    while (1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search element from the key"<<endl;
        cout<<"3.Delete element at a key"<<endl;
		cout<<"4. Display elements from key "<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter element to be inserted: ";
            cin>>value;
            cout<<"Enter key at which element to be inserted: ";
            cin>>key;
            hash.Insert(key, value);
            break;
        case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>key;
            cout<<"Element at key "<<key<<" : ";
            if (hash.Search(key) == -1)
            {
	        cout<<"No element found at key "<<key<<endl;
	        continue;
	    }
            break;
        case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>key;
			cout<<"Enter value to be deleted: ";
            cin>>value;
            hash.Remove(key,value);
            break;
		case 4:
            cout<<"Enter key of the element to be Displayed: ";
            cin>>key;
            hash.Display(key);
            break;
        case 5:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}
