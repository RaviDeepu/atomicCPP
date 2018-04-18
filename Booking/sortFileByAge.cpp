#include<iostream>
#include<set>
#include<fstream>
#include<string.h>
#include<memory>

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

int main()
{
    set<User*,myComp> setOfUsers;
    ifstream file("UsersInput.txt");

    {
        char* tName;
        int tAge;
        while(file >> tName >> tAge)
        {
            cout<<tName<<" "<<tAge<<endl;
            //User *tUser = new User(tName,tAge);

            setOfUsers.insert(new User(tName,tAge));
        }
    }

    cout<<"After"<<endl;

    for(set<User*>::iterator iter = setOfUsers.begin() ; iter != setOfUsers.end() ; ++iter)
    {
        cout<<(*iter)->getName()<<" "<<(*iter)->getAge()<<endl;
    }

    for(set<User*>::iterator it = setOfUsers.begin() ; it != setOfUsers.end() ; ++it)
    {
        delete(*it);
    }
    //unique_ptr<Person>
}
