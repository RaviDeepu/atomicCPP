#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
using namespace std;


void printArray(vector<string>& str)
{
        for(auto a: str)
            cout<<a<<endl;
}

bool compare(const pair<int, int>&p1, const pair<int,int>&p2)
{
    if(p1.second == p2.second)
    {
        cout<<"p1.first : "<<p1.first<<" , p2.second : "<<p2.second<<endl;
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}


/*

a. Tokenise the main review words into an vector
b. Store the input hotelId and reviews in a map.
c. Copy from the map to pair.
d. Sort pair based on second value.

*/

int main()
{
    int n=100000;
    int ii=0;

    while(1)
    {
        int numberOfReviews=0;
        
        string str;
        vector<pair<int,int>> pairOfHotelReviewCountWithIDs;
        unordered_map<int, int> mapOfHotelReviewWithIds;

        cout<<"Enter total review word list\n";
        getline(cin,str);
        string buf;

        stringstream ss(str);

        vector<string> strTokens;
        while(ss >> buf)
            strTokens.push_back(buf);

        cout<<"Enter Number Of Reviews\n";
        cin>>numberOfReviews;
        
        printArray(strTokens);

        //cout<<"Number Of Reviews - "<<numberOfReviews<<endl;
        
        for(int i=0 ; i<numberOfReviews ; ++i)
        {
            int hotelID;
            string hotelReview;
            int reviewCounter=0;

            cout<<"Enter Hotel ID\n";
            cin>>hotelID;
            //cin.clear();


            cin.ignore();
    
            cout<<"Enter hotel Review\n";
            getline(cin,hotelReview);

            transform(hotelReview.begin(), hotelReview.end(), hotelReview.begin(), ::tolower);


            //cout<<"Hotel Id : "<<hotelID<<endl;

            //cout<<"Hotel Reviews : "<<hotelReview<<endl;            
        
            for(auto a : strTokens)
            {
                //reviewCounter = 0;
                int pos = hotelReview.find(a,0);

                while(pos != string::npos)
                {
                    reviewCounter++;
                    pos = hotelReview.find(a,pos+1);

                    //mapOfHotelReviewWithIds[hotelID]++;
                    //reviewCounter++;
                }                
            }
            cout<<"Total Count : "<<reviewCounter<<endl;
            mapOfHotelReviewWithIds[hotelID] = mapOfHotelReviewWithIds[hotelID] + reviewCounter;
            //cout<<"Total Words found in the above review : "<<reviewCounter<<endl;
            //hotelReviewCountWithIDs.push_back(make_pair(hotelID,reviewCounter)); 
        }
        /*
        for(auto a: mapOfHotelReviewWithIds)
        {
            cout<<a.first<<" "<<a.second<<endl;
        }
        */

        copy(mapOfHotelReviewWithIds.begin(), mapOfHotelReviewWithIds.end(), back_inserter(pairOfHotelReviewCountWithIDs));


        sort(pairOfHotelReviewCountWithIDs.begin(), pairOfHotelReviewCountWithIDs.end(), compare);

        cout<<"Final\n";
        for(auto a: pairOfHotelReviewCountWithIDs)
        {
            cout<<"Hotel Id : "<<a.first<<" Review Count : "<<a.second<<endl;
        }

    }
}


