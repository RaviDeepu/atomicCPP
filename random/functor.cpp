#include <iostream>
using namespace std;

 class myFunctorClass
 {
         public:
                 myFunctorClass (int x) : _x( x ) {}
                         int operator() (int y) { return _x + y; }
                         void printVal()
                         {
                             cout<<_x<<endl;
                         }
                             private:
                                     int _x;
 };
  
  int main()
  {
          myFunctorClass addFive( 5 );
          addFive.printVal();
             // std::cout << addFive( 6 );
          
                   return 0;
  }
