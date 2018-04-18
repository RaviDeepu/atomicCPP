#include<iostream>
#include<string.h>

using namespace std;


template<typename T>

class AutoPtr
{
    private:
        T* mPtr;
    public:
        AutoPtr(T* ptr = NULL):mPtr(ptr)
        {
            cout<<"AutoPtr Constructor\n";
        }

        ~AutoPtr()
        {
            cout<<"AutoPtr Destructor\n";
        }

        AutoPtr(AutoPtr& a)
        {
            mPtr = a.mPtr;
            a.mPtr = NULL;
        }

        AutoPtr& operator=(AutoPtr& a)
        {
            if(this == &a)
                return;

            delete mPtr;
            mPtr = a.mPtr;
            a.mPtr = NULL;
            
            return *this;
        }        
    
        T& operator*()
        {
            return *mPtr;
        }
    
        T* operator->()
        {
            return mPtr;
        }

};


