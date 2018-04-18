#include<iostream>
#include<stdlib.h>
using namespace std;



class base
{

        int a;
    public:
        void fun()
        {

            cout<<a<<endl;
            cout<<"BASE\n";
        }
};


int main()
{
    base *b = NULL;
    b->fun();
}

/*

bool check(int n, bool &status)
{
    if(n>0)
    {
        if(n%2 == 0)
            status=true;
        else
            status=false;

        return true;
    }
    return false;
}

int main()
{
    bool status;
    int number;
    while(1)
    {
        cout<<"Enter number : "<<endl;
        cin>>number;
        if(check(number,status))
        {
            if(status)
                cout<<"EVEN\n";
            else
                cout<<"FALSE\n";
        }
            
    }
}
*/
/*
class base
{
    public:
        void test(const std::string s,const int x, const char c='A') const;
};


void base::test(const std::string s,const int x, const char c) const
{
    cout<<"Disaplay()\n";
}


int main()
{
    base b;
    b.test("xx",2);
    
    bool _isSeatZoneEnabled = false;
    //std::string aa = _isSeatZoneEnabled ? "is" : "NOT";
    //std::string aInfo = "LST_FnD_EnableSeatZone_1A " + aa + " enabled";
    //cout<<aa<<endl;
    std::string aInfo = "LST_FnD_EnableSeatZone_1A " + std::string(_isSeatZoneEnabled ? "is" : "NOT") + " enabled";
    cout<<aInfo<<endl;
    string s="123.456";
    cout<<atoi(s.c_str())<<endl;
}
*/
