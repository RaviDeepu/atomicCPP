#include <iostream>
#include <string>
#include <ctime>
#include<vector>
#include<sstream>
using namespace std;


int main()
{
    std::string s("Using stringstream as you have works perfectly fine, and do exactly what you wanted. If you're just looking for different way of doing things though, you can use find/find_first_of and substring Using stringstream as you have works perfectly fine, and do exactly what you wanted. If you're just looking for different way of doing things though, you can use Using stringstream as you have works perfectly fine, and do exactly what you wanted. If you're just looking for different way of doing things though, you can use find/find_first_of and substring Using stringstream as you Using stringstream as you have works perfectly fine, and do exactly what you wanted. If you're just looking for different way of doing things though, you can use find/find_first_of and substring Using stringstream as you Using stringstream as you have works perfectly fine, and do exactly what you wanted. If you're just looking for different way of doing things though, you can use find/find_first_of and substring Using stringstream as you ");

    const clock_t begin_time = clock();

    /*
            string buf;

        stringstream ss(s);

        vector<string> strTokens;
        while(ss >> buf)
            strTokens.push_back(buf);
    */

    
    vector<string> myVector;

    std::string::size_type prev_pos = 0, pos = 0;
    while( (pos = s.find(' ', pos)) != std::string::npos )
    {
        std::string substring( s.substr(prev_pos, pos-prev_pos) );

        //std::cout << substring << '\n';

        prev_pos = ++pos;

        myVector.push_back(substring);

    }
    std::string substring( s.substr(prev_pos, pos-prev_pos) ); // Last word
    //std::cout << substring << '\n';
    myVector.push_back(substring);
    
    //cout<<float(clock() - begin_time)/CLOCKS_PER_SEC<<endl;;

    cout<<float(clock() - begin_time)<<endl;;
}
