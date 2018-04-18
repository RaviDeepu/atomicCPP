#include <boost/thread.hpp>
void readerApi()
{
  for (int i=0; i < 10; i++) {
    //usleep(400);
    std::cout << "readerApi: " << i
              << std::endl;
  }
}
void writerApi()
{
  for (int i=0; i < 10; i++) {
    std::cout << "writerApi: " << i
              << std::endl;
    //usleep(400);
  }
}

int main()
{
  boost::thread readerThread(readerApi);
  boost::thread writerThread(writerApi);

  readerThread.join();
  writerThread.join();
}
