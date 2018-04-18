#include"autoPtr.cpp"


class Person
{
        int mLength;
        char* name;
    public:
        
        Person():mLength(0),name(NULL)
        {
            cout<<"Person Constructor"<<endl;
        }

        Person(char* iName):mLength(strlen(iName)),name(new char[mLength])
        {
            cout<<"Person Constructor\n";
            strcpy(name,iName);
        }        

        // Copy constructor
        Person(const Person& iPerson)
        {
            mLength = iPerson.mLength;
            name = new char[mLength];
            strcpy(name,iPerson.name);
        }

        // Assignment operator
        const Person& operator=(const Person& a)
        {
            if(this == &a)
                return *this;

            delete name;
            name = new char[mLength];
            mLength = a.mLength;
            strcpy(name,a.name);
    
            //a.name = NULL;
            //a.mLength = 0;

            return *this;        
        }    

        void show()
        {
            cout<<"Name - "<<name<<endl;
        }
};


int main()
{
    AutoPtr<Person> pp(new Person("RaviGiri"));
    pp->show();
}
