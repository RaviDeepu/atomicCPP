#include<iostream>

using namespace std;

class mbase
{
    public:
        int var;
        void show()
        {
            cout<<var<<endl;
        }
};


class der1:public mbase
{

};

class der2:public mbase
{
};


int main()
{
    der1 *d1 = new der1();
    der2 *d2 = new der2();

    d1->var=100;
    d2->var=200;

    d1->show();
    d2->show();
}




