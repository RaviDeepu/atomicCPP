#include<iostream>
#include<string.h>
#include<map>
#include<vector>

using namespace std;

void ProcessWordStream() {
    std::vector<std::string> wordHolder = {"aca","cat","world","hello"};
    std::string inputStream = "acacabcatghhellomvnsdb";
    std::map<std::string, int> wordCounter;
    int len = inputStream.length();
    for(auto word : wordHolder) {
        int count = 0;
        std::string tempWord = inputStream;
        wordCounter[word] = count;
        while(tempWord.length() != 0) 
        {
            cout<<tempWord<<endl;
            std::size_t pos = tempWord.find(word);
            cout<<pos<<endl;
            if (pos != std::string::npos) 
            {
                wordCounter[word] = ++count;
                // If founf then get the string from pos+1
                tempWord = tempWord.substr(pos+1);
            }
            else
            {
                // Increment one one step and try searching.
                tempWord = tempWord.substr(1);
            }
        }
    }
    for(auto w : wordCounter) {
        std::cout << "   " << w.first << " : "<<w.second <<"\n";
    }
}



int main()
{
    ProcessWordStream();
}
