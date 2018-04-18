#include<boost/thread.hpp>

using namespace std;

int globalVariable;

class Reader
{
    private:
        int _waitTime;
    public:
        Reader(int waittime)
        {
            _waitTime = waittime;
        }

        void operator() ()
        {
            for(int i=0;i<10;++i)
            {
                cout<<"Reader : "<<globalVariable<<endl;
                usleep(_waitTime);
            }

        }
};

class Writer
{
    private:
        int _writerVariable;
        int _waitTime;
        static boost::mutex _writerMutex;
    public:
        Writer(int variable, int waittime)
        {
            _writerVariable = variable;
            _waitTime = waittime;
        }

        void operator() ()
        {
            for(int i=0 ; i<10 ; ++i)
            {
                usleep(_waitTime);
                boost::mutex::scoped_lock lock(_writerMutex);
                globalVariable = _writerVariable;
                _writerVariable++;
            }
        }

};

boost::mutex Writer::_writerMutex;

int main()
{
    Writer writer(100,20);
    Reader reader(10);

    boost::thread writerThread(writer);
    boost::thread readerThread(reader);

    readerThread.join();
    writerThread.join();

}

