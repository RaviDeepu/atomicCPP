#include<iostream>
#include<vector>
#include<sstream>
#include <cstdio>


using namespace std;


int main()
{
    int i=0;
    
    int noOfSquare=0, noOfRectangle=0, noOfPolygon=0;

    vector< vector<int> > myVector;
    int n;
    string str;

vector<string> vs;
while(getline(cin, str)) {
    vs.push_back(str);
}

    /*
    //for(i=0 ; i<6 ; ++i)
    while(getline(cin,str))
    {
        string buf;
        stringstream ss(str);

        vector<int> tVector;
    */
       // while(ss >> buf)
         //   tVector.push_back(stoi(buf)) ;
   
        /*        
        vector<int> tVector;

        cin>>n;
        tVector.push_back(n);

        cin>>n;
        tVector.push_back(n);

        cin>>n;
        tVector.push_back(n);

        cin>>n;
        tVector.push_back(n);
        */
        //myVector.push_back(tVector);
    //}

    cout<<"Reading Done\n";

    for(i=0 ; i<6 ; ++i)
    {
        //noOfSquare=0;
        //noOfRectangle=0;
        //noOfPolygon=0;

        vector<int> tmpVector = myVector[i];

        int a,b,c,d;
        
        a = tmpVector[0];
        b = tmpVector[1];
        c = tmpVector[2];
        d = tmpVector[3];

        if((a > 2000 || a < 2000) || (b > 2000 || b < 2000) || (c > 2000 || c < 2000) || (d > 2000) || (d < 2000))
        {
            cout<<"Negative  - Ignore\n";
        }
        if((a > 0) && (b > 0) && (c > 0) && (d > 0) && (a == b) && (b == c) && (c == d))
        {
            noOfSquare++;
        }
        else if((a > 0) && (b > 0) & (c > 0) & (d > 0) && (a == c) && (b == d))
        {
            noOfRectangle++;
        }
        else
        {
            noOfPolygon++;
        }
    } 

    cout<<"Squares  : "<<noOfSquare<<endl;;
    cout<<"Rectanle : "<<noOfRectangle<<endl;;
    cout<<"Polygon : "<<noOfPolygon<<endl;;
}
