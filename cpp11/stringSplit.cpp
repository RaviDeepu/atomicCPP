#include <boost/algorithm/string.hpp>
#include<vector>

using namespace std;

int main()
{
	vector<std::string> strs;
	boost::split(strs, "string,to,split", boost::is_any_of(","));

	for(auto it:strs)
	{
		cout<<it<<endl;
	}
}
