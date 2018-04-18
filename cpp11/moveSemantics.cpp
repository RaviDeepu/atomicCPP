#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Container
{
        int *a;
    public:
        // Constructor
        Container()
        {
            cout<<"Constructor\n";
            a = new int[20];
            for(int i=0 ; i<20 ; ++i)
                a[i] = 0;
        }

        // Copy constructor
        Container(const Container& c)
        {
            cout<<"Copy Constructor\n";
            a = new int[20];
            for(int i=0 ; i<20 ; ++i)
                a[i] = c.a[i];
        }

        // Assignment Operator
        Container& operator=(const Container& c)
        {
            if(this == &c)
                return *this;
            
            cout<<"Assignment Operator\n";
            delete a;
            a = new int[20];

            for(int i=0 ; i<20 ; ++i)
                a[i] = c.a[i];
        }
      
        // Destructor 
        ~Container()
        {
            cout<<"Destructor\n";
            delete a;
        }

        // Move Constructor
        Container(Container&& cc)
        {
            cout<<"Move Constructor\n";
            a = cc.a;
            cc.a = nullptr;
        }

        // Move Assignment Operator
        Container& operator=(Container&& cc)
        {
            if(this == &cc)
                return *this;
    
            cout<<"Move Assignment\n";
            delete a;
            a = cc.a;
            cc.a = nullptr;

            return *this;
        }

};

Container getContainer()
{
    Container cc;
    return cc;
}

int main()
{
    Container c;
    c = getContainer();

    //Container b = c;

}
