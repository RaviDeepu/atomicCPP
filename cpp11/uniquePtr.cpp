#include<iostream>
#include<memory>
#include<vector>

using namespace std;

template<typename T>
class default_delete
{
    public:
        void operator()(T* ptr) noexcept
        {
            delete ptr;
        }
};

template<typename T, typename Deleter = default_delete<T>>
class uniquePtr
{
    private:
        T* _ptr;
        Deleter _deleter;
    public:
        // Constructor that makes empty uniwue_ptr
        uniquePtr() noexcept : _ptr(nullptr),_deleter()
        {
        }

        uniquePtr(std::nullptr_t) noexcept : _ptr(nullptr), _deleter()
        {
        }

        // Cnstructor that makes a unique_ptr that holds the given object
        uniquePtr(T* p) noexcept : _ptr(p),_deleter()
        {
        }

        // Constructor that takes a raw pointer and a deleter.
        uniquePtr(T* p, const Deleter& d) : _ptr(p), _deleter(d)
        {
        }

        uniquePtr(T* p, Deleter&& d) : _ptr(p), _deleter(std::move(d))
        {
        }

        // Move Constructor
        uniquePtr(uniquePtr&& u) : _ptr(u._ptr), _deleter(std::move(u._deleter))
        {
            u._ptr = nullptr;
        }

        // Move Assignment operator
        uniquePtr& operator=(uniquePtr&& u)
        {
            if(this == &u)
                return *this;

            delete _ptr;
            _ptr = u._ptr;
            _deleter = std::move(u._deleter);

            u._ptr = nullptr;
        }

        // Explicitly delete the copy constructor and assignment Operator.
        uniquePtr(const uniquePtr& u) = delete;
        uniquePtr& operator=(const uniquePtr& ) = delete;

        T* get()
        {
            return _ptr;
        }

        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

};

int main()
{
}
