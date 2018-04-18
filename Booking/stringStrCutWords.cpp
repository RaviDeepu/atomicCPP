/*
"Smart substring" 
Write a function that takes maximum 30 characters from a string but without cutting the words. 

Full description: 
"Featuring stylish rooms and moorings for recreation boats, Room Mate Aitana is a designer hotel built in 2013 on an island in the IJ River in Amsterdam." 

First 30 characters: 
"Featuring stylish rooms and mo" 

Smarter approach (max 30 characters, no words are broken): 
"Featuring stylish rooms and"

- ersegun August 20, 2015 in Netherland


*/


#include <iostream>
#include <string>
using namespace std;

string SmartSubstring30Chars(string test, unsigned int limit)
{
  if(test.length() <= limit)
    return test;
  
  string result(" ");
  size_t end = 0;
  size_t begin = 0;
    
    end = test.find(" ",begin);

    if(end > limit)
        return result;

    result += (test.substr(begin,end-begin) + " ");
    begin = end+1;

    while(1)
    {
        end = test.find(" ",begin);
        if(end > limit)
            break;
        result += (test.substr(begin,end-begin) + " ");
        begin = end+1;
        cout<<result<<endl;
    }

    //cout<<result<<endl;
    return result;


    /*
  
  do{
    end = test.find(" ", begin);
    cout<<"Begin : "<<begin<<" , End : "<<end<<endl;
    if(end != string::npos)
    {
      result += (test.substr(begin, end - begin) + " ");
      begin = end + 1;
    }
  }while(end <= limit);
  
  return result;
    */
}

int main() 
{  
  string test = "Featuring stylish rooms and moorings for recreation boats, Room Mate Aitana is a designer hotel built in 2013 on an island in the IJ River in Amsterdam.";

    cout<<test<<endl;  
  string result = SmartSubstring30Chars(test, 30);
  
  //cout << result << endl;
  
  return 0;
}
