#include<boost/thread.hpp>
#include<queue>
#include<iostream>
#include<sstream>
#include<stdio.h>

using namespace std;

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

template<class T>
class SynchronisedQueue
{
    private:
        queue<T> m_queue;
        boost::mutex m_mutex;
        boost::condition_variable m_cond;

    public:
        void Enqueue(const T& data)
        {
            // Lock the mutex.
            boost::unique_lock<boost::mutex> lock(m_mutex);
            
            // Push the data to the Queue.
            m_queue.push(data);
            
            cout<<data<<endl;
            // Notify the other thread.
            m_cond.notify_one();
            
        }

        T Dequeue()
        {
            // Lock the mutex
            boost::unique_lock<boost::mutex> lock(m_mutex);
        
            while(m_queue.size() == 0)
                m_cond.wait(lock);

            T result = m_queue.front();
            m_queue.pop();
            cout<<"Consumer : "<<result<<endl;
    
            return result;
        }
};


class Producer
{
    private:
        int m_id;
        SynchronisedQueue<string>* m_queue;

    public:
        Producer(int id, SynchronisedQueue<string>* tqueue)
        {
            m_id = id;
            m_queue = tqueue;
        }

        void operator() ()
        {
            int data = 0;
            while(true)
            {
                string str = "Producer : "+IntToString(m_id)+" Data : "+IntToString(data++);
                m_queue->Enqueue(str);
                //cout<<str<<endl;
                boost::this_thread::sleep(boost::posix_time::seconds(1));
            }
            //boost::this_thread::sleep(boost::posix_time::seconds(1));
            usleep(200);
        }
        
};


class Consumer
{
    private:
        int m_id;
        SynchronisedQueue<string>* m_queue;
    public:
        Consumer(int id, SynchronisedQueue<string>* tQueue)
        {
            m_id = id;
            m_queue = tQueue;
        }

        void operator() ()
        {
            int data = 0;
            while(true)
            {
                string str = "Consumer : "+IntToString(m_id)+"consumed : "+m_queue->Dequeue();
                //cout<<str<<endl;
                // Make sure we can be interrupted
                //boost::this_thread::interruption_point();
            }
        }
};


int main()
{
    int nProducers,nConsumers;
    SynchronisedQueue<string> queue;

    cout<<"Enter Number Of Producers\n";
    cin>>nProducers;

    cout<<"Enter Number Of Consumers\n";
    cin>>nConsumers;

    boost::thread_group producers;
    for(int i=0;i<nProducers;++i)
    {
        Producer p(i,&queue);
        producers.create_thread(p);
    }

    boost::thread_group consumers;
    for(int i=0;i<nConsumers;++i)
    {
        Consumer c(i,&queue);
        consumers.create_thread(c);
    }

    // Wait for enter (two times because the return from the
    // previous cin is still in the buffer)
    getchar(); getchar();

    producers.interrupt_all();
    producers.join_all();

    consumers.interrupt_all();
    consumers.join_all();

}
