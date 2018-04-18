#include<iostream>

using namespace std;


template <typename T>

class AutoPtr
{
        T* mPtr;
    public:
        AutoPtr(T* ptr=nullptr):mPtr(ptr)
        {
            
        }
        
        ~AutoPtr()
        {
            delete mPtr;
        }

        // Copy constructor.
        // Doo deep copy
        AutoPtr(const AutoPtr& aPtr)
        {
            cout<<"Copy --\n";
            mPtr = new T;
            *mPtr = *aPtr.mPtr;
        }

        // Copy assignment operator.
        AutoPtr& operator=(const AutoPtr& a)
        {
            cout<<"== == --\n";
            if(&a == this)
                return *this;

            delete mPtr;
            mPtr = new T;
            *mPtr = *a.mPtr;
            
            return *this;
        }

        // Move constructor
        AutoPtr(AutoPtr&& a):mPtr(a.mPtr)
        {
            a.mPtr = nullptr;
        }

        //Move Assignment
        AutoPtr& operator=(AutoPtr&& a)
        {
            if(&a == this)
                return *this;

            delete mPtr;
            mPtr = a.mPtr;
            a.mPtr = nullptr;
            return *this;
        }

        T& operator*() const
        {
            return *mPtr;
        }

        T* operator->() const
        {
            return mPtr;
        }

        bool isNull() const
        {
            return mPtr == nullptr;
        }
};


class Resource
{
    public:
        Resource()
        {
            cout<<"Resource acquired\n";
        }

        ~Resource()
        {
            cout<<"Resource Destroyed\n";
        }
};


AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource);
    return res;
}


int main()
{
    AutoPtr<Resource> mainRes;
    cout<<"After MainRes\n";
    mainRes = generateResource();
    
    return 0;
}
