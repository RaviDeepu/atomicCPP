#include<iostream>
#include<string.h>
using namespace std;


class RC
{
    public:
        void AddRef()
        {
            ++count;
        }
        
        int DelRef()
        {
            return --count;
        }

    private:
        int count;
};


class SharedPtr
{
    private:
        RC *reference;

    public:


        char *str;

        SharedPtr(char *sptr = 0):str(0),reference(0)
        {
            cout<<"Constructor\n";
            str = sptr;

            reference = new RC();
            reference->AddRef();
        }

        SharedPtr(const SharedPtr &obj)
        {

            cout<<"Copy Constructor\n";
            str = new char[strlen(obj.str)];
            str=obj.str;
            reference=obj.reference;
            reference->AddRef();
        }

        SharedPtr& operator=(const SharedPtr &obj)
        {
            cout<<"Assignment Operator\n";
            str = new char[strlen(obj.str)];
            if(this != &obj)
            {
                if(reference->DelRef() == 0)
                {
                    delete str;
                    delete reference;
                }
                str = obj.str;
                reference = obj.reference;
                reference->AddRef();
            }
        }


        char* operator*()
        {
            cout<<"Operator ****\n";
            return str;
        }

        char& operator->()
        {
        
            cout<<"Operator ->->-> \n";
            return *str;
        }

};

int main()
{
    SharedPtr s1ptr("Giri");
    cout<<s1ptr.str<<endl;

    SharedPtr *s2ptr = new SharedPtr("Ravi");
    cout<<s2ptr->str<<endl;

}
