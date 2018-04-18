#include<iostream>
#include<vector>

#define TOKEN -128

using namespace std;

int main()
{
    bool enterKeyPressed = false;
    vector<int> myVector;
    int i=1;
    int temp;


    while(!enterKeyPressed)
    {
        cin>>temp;
        myVector.push_back(temp);
        if(cin.get() == '\n')
            enterKeyPressed = true;
    }
    
    cout<<"Size of Vector : "<<myVector.size()<<endl;

    cout<<myVector[0]<<" ";
    for(int i=1 ; i<myVector.size() ; ++i)
    {
        int diff = myVector[i] - myVector[i-1];

        if(diff > 127 || diff < -127)
            cout<<TOKEN<<" "<<diff<<" ";
        else
            cout<<diff<<" ";
    }
}
