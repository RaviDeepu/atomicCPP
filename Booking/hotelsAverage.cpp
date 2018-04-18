#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;


class Hotel
{
    public:
        int hotel_id, user_id,score;
        Hotel(int iHotelid, int iUserId, int iScore)
        {
            hotel_id = iHotelid;
            user_id = iUserId;
            score = iScore;
        }
};


void get_hotels(vector<Hotel> scores, float min_avg_score )
{
    // Map <HotelId , <Scores,NumberOfScores>>;
    unordered_map<int,pair<int,int> > hash;
    unordered_map<int,pair<int,int> > :: iterator it;
    vector<int> hotels; 
    int sz = scores.size();

    for( int i = 0 ; i < sz ; ++i )
    {
        hash[ scores[i].hotel_id ].first+=scores[i].score;
        hash[ scores[i].hotel_id ].second++;
    }

    //pair<int,int> :: iterator itPair;

    cout<<"--------------------------\n";
    for(it = hash.begin() ; it != hash.end() ; ++it) // Key
    {
        cout<<"Hotel Id - "<<it->first<<endl;

        pair<int, int> pp = it->second;
        cout<<"Scores - "<<pp.first<<" , Number Of : "<<pp.second<<endl;
        /*
        for(itPair = pp.begin() ; itPair != pp.end() ; ++itPair) // Pairs
        {
            cout<<"Scores - "<<itpair->first<<" , Number Of : "<<itPair->second<<endl;
        }
        */
    }    
   
    for( it = hash.begin(); it != hash.end() ; ++it )
    {
        pair<int,int> values = it -> second;
        float avg_current = values.first/(float)(values.second);
        if( avg_current >= min_avg_score )
        {
            cout<<it -> first<<endl;
            //hotels.push_back(it -> first );
        }
    }
    //return hotels;
}

int main()
{
    Hotel a(1001,501,7);
    Hotel b(1001,502,7);
    Hotel c(1001,503,7);
    Hotel d(2001,504,10);
    Hotel e(3001,505,5);
    Hotel f(2001,506,5);

    vector<Hotel> scores;
    scores.push_back(a);
    scores.push_back(b);
    scores.push_back(c);
    scores.push_back(d);
    scores.push_back(e);
    scores.push_back(f);


    get_hotels(scores,5);
}
