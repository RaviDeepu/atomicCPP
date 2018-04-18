/*
Given a list/array of names(String) sort them such that each name is followed by a name which starts with the last character of the previous name. 
# input 
[ 
Luis 
Hector 
Selena 
Emmanuel 
Amish 
] 

# output: 
[ 
Emmanuel 
Luis 
Selena 
Amish 
Hector 
]

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cctype>
#include <map>
#include <utility>

int main() {
    std::vector<std::string> vec{
        "Luis", "Hector", "Selena", "Emmanuel", "Amish"};
    std::map<char, std::string> map_first_char;
    std::map<char, std::string> map_last_char;
    std::list<std::string> result;

    for(auto s: vec) {
        map_first_char.insert(
            std::pair<char, std::string>(tolower(s[0]), s));
        map_last_char.insert(
            std::pair<char, std::string>(s[s.length() - 1], s));    
    }

    for(auto s: vec) {
        if(result.empty()) {
            result.push_back(s);
            continue;
        }
        
        std::string& front = result.front();
        std::string& back = result.back();
        
        char begin = tolower(front[0]);
        char end = back[back.length() - 1];
        
        std::map<char, std::string>::iterator it;
        
        if((it = map_last_char.find(begin)) != map_last_char.end()) {
            result.push_front(it->second);
            map_last_char.erase(it);
        }
        
        if((it = map_first_char.find(end)) != map_first_char.end()) {
            result.push_back(it->second);
            map_first_char.erase(it);
        }
        
    }
    
    for(auto it = result.begin(); it != result.end(); ++it) {
        std::cout << "result:" << *it << std::endl;
    }

    return 0;
}
