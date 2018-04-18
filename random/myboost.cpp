#include <vector>
#include <iostream>
#include <algorithm>
#include <boost/shared_ptr.hpp>

using namespace::std;

struct Boost_Example
{ 
  Boost_Example( int _x ) : x(_x)
  {

  }
  ~Boost_Example()
  {
	  std::cout << "  Destroying Boost_Example x = " << x << "\n";
	  std::cout << endl << endl << "  ";
	  system("PAUSE");
	  std::cout << endl << endl;
  }
  int x;
};

typedef boost::shared_ptr<Boost_Example> Boost_ExamplePtr;

struct Boost_ExamplePtrOps
{
  bool operator()( const Boost_ExamplePtr & a, const Boost_ExamplePtr & b )
  {
		return a->x < b->x;
  }
  void operator()( const Boost_ExamplePtr & a )
  {
		std::cout << " " << a->x;
  }
};

int main()
{
  std::vector<Boost_ExamplePtr> Boost_Example_vector;

  Boost_Example_vector.push_back( Boost_ExamplePtr(new Boost_Example(3)) );
  Boost_Example_vector.push_back( Boost_ExamplePtr(new Boost_Example(2)) );
  Boost_Example_vector.push_back( Boost_ExamplePtr(new Boost_Example(1)) );

  std::cout << endl << endl;
  std::cout << "  Original Boost_Example_vector:  ";
  std::for_each( Boost_Example_vector.begin(), Boost_Example_vector.end(), Boost_ExamplePtrOps() );
  std::cout << "\n";

  std::sort( Boost_Example_vector.begin(), Boost_Example_vector.end(), Boost_ExamplePtrOps() );

  std::cout << endl << endl;
  std::cout << "  Sorted Boost_Example_vector:	";
  std::for_each( Boost_Example_vector.begin(), Boost_Example_vector.end(), Boost_ExamplePtrOps() );
  std::cout << "\n";

  std::cout << endl << endl << "  ";
  system("PAUSE");
  std::cout << endl << endl;
  return 0;
  
}


