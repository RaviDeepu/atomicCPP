#include<iostream>
#include<set>
#include<fstream>
#include<string.h>
#include<memory>
#include<vector>
#include<algorithm>
using namespace std;


class User
{
    public:

        char* uName;
        int age;
        User():uName(NULL),age(0)
        {
            
        }

        User(char* iName, int iAge):uName(new char[strlen(iName)]),age(iAge)
        {
            strcpy(uName,iName);
        }
    
        char* getName()
        {
            return uName;
        }

        int getAge()
        {
            return age;
        }
   
        ~User()
        {
            cout<<"Destructor\n";
        } 
        /*
        bool operator< (const User* tUser) const
        {
            cout<<"Operato < \n";
            return age < tUser->age;
        }
        */

};

class myComp
{
    public:
        bool operator() (const User* user1, const User* user2)
        {
            cout<<"Operator < "<<endl;
            return user1->age < user2->age;
        }
};


bool myCompVec(const User* v1, const User* v2)
{
    return v1->age < v2->age;
}

int main()
{
    vector<User*> v;
    ifstream file("UsersInput.txt");

    {
        char tName[100];
        int tAge;
        while(file >> tName >> tAge)
        {
            cout<<tName<<" "<<tAge<<endl;
            User *tUser = new User(tName,tAge);

            v.push_back(tUser);
        }
    }

    cout<<"After"<<endl;

    sort(v.begin(),v.end(),myCompVec);

    for(vector<User*>::iterator iter = v.begin() ; iter != v.end() ; ++iter)
    {
        cout<<(*iter)->getName()<<" "<<(*iter)->getAge()<<endl;
    }

    /*
    for(set<User*>::iterator it = setOfUsers.begin() ; it != setOfUsers.end() ; ++it)
    {
        delete(*it);
    }
    */
    //unique_ptr<Person>
}
