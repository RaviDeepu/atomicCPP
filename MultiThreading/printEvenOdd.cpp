#include<iostream>
#include<boost/thread.hpp>
#define MAX 10

using namespace std;
//using namespace boost;

int counter;

boost::mutex m_mutex;
boost::condition_variable m_cond;

void even()
{
    while(counter < MAX)
    {
        //m_mutex.lock();
        boost::unique_lock<boost::mutex> lock(m_mutex);

        while(counter%2 != 0)
            m_cond.wait(lock);

        cout<<counter++<<" ";
        //m_mutex.unlock();
        m_cond.notify_one();

    }    
}

void odd()
{
    while(counter < MAX)
    {
        //m_mutex.lock();
        boost::unique_lock<boost::mutex> lock(m_mutex);
        while(counter%2 != 1)
            m_cond.wait(lock);

        cout<<counter++<<" ";
        //m_mutex.unlock();
        m_cond.notify_one();

    }
}

int main()
{
    boost::thread t1(even);
    boost::thread t2(odd);

    t1.join();
    t2.join();
}
