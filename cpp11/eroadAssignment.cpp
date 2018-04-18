#include <string>
#include <iostream>
#include <curl/curl.h>
#include <boost/algorithm/string.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <boost/tokenizer.hpp>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include <cstdlib>
			
using namespace boost::posix_time;
using namespace std;


/*
* Please find the below steps followed to compile and run the code.
* 
* a .Compile the program using g++, used libCurl to call the GoolgeMap Rest API
*              g++ -std=c++11 eroadAssignment.cpp -lcurl -lboost_date_time
* 
* PreRequisite : 
* a. Used C++11 and boost features.
* b. Used libCurl  library to call GoogleMaps REST API. https://curl.haxx.se/docs/install.html
* c. input.csv file must be present in the current executing folder with the below syntax.
* 
* How to Use.
* This application will read the data from input.csv file and write the output expected data in output.csv file.
* 
* Executed with the below Input and Output.
* Input: 2013-07- 10 02:52:49,-44.490947,171.220966
* Output : 2013-07- 10 02:52:49,-44.490947,171.220966,Pacific/Auckland,2013- 07-10T14:52:49
* 
* Input: 2013-07-10 02:52:49,-33.912167,151.215820
* Output:2013-07-10 02:52:49,-33.912167,151.215820,Australia/Sydney,2013-07-10T12:52:49
* 
* Input: 2013-07-10 22:39:49,7.904422,98.335718
* Output: 2013-07-10 22:39:49,7.904422,98.335718,Asia/Bangkok,2013-07-11T05:39:49
* 
*/

class EROADData 
{
  public:
    EROADData ():curl(NULL),curlBuffer("") 
    {
    };

    // Method to Read input.csv file and write to output.csv file.
	void readInputAndWriteOutputFile(void);

    // Method to Parse the Response JSON and Build the final expected string. 
    void parseResponseJson(const std::string& iDateTime, const std::string& iLatitude, const std::string& iLongitude,std::ofstream& eroadOutputFile);
    
    // Get the data from given URL using libCurl library
	void parseFromURL(const std::string& url);

    static int curlWriter(char *data, size_t size, size_t nmemb, std::string *buffer) {
      int result = 0;
      if (buffer != NULL) {
        buffer->append(data, size * nmemb);
        result = size * nmemb;
      }
      return result;
    }

    // Return the Data
    std::string& getData () 
    { 
        return curlBuffer; 
    }

    // Convert the given UTC to EpochTime which is needed fro GoogleAPI.
	void convertUTCToEpochTime(const std::string& itime, std::string& oEpochTime);


  private:
    CURL * curl;
    std::string curlBuffer;
};


void EROADData::readInputAndWriteOutputFile()
{
    // OutPut File which contains data in the expected format.
    std::ofstream eroadOutputFile ("output.csv");

	// Read And Parse the File
	std::ifstream eroadInputFile("input.csv");

    // If we couldn't open the output file stream for writing
    if (!eroadInputFile)
    {
        // Print an error and exit
        cerr << "Uh oh, input.csv file could not be found..!!" << endl;
        exit(1);
    }

	std::string line; 

    // Read InputFile line by line
    while (std::getline(eroadInputFile, line))
    {
		vector<std::string> lineVector;
		lineVector.clear();

        // Split Each Line and populate the Vector.
       	boost::split(lineVector, line, boost::is_any_of(","));
	
        // Convert UTC to EpochTime which is needed to retrive the date and time offset using Google API.	
		std::string epochTime;
        this->convertUTCToEpochTime(lineVector.at(0),epochTime);

        // Constructing the URL
		std::string partialURL("https://maps.googleapis.com/maps/api/timezone/json?location=");

        std::ostringstream finalURLPath;

        finalURLPath << partialURL << lineVector.at(1) << "," << lineVector.at(2) << "&timestamp=" << epochTime << "&key=AIzaSyA-TW70df76_PEqEo8e_d-ClIlIks59EDo";

        // Get the Response from the URL and Parse the output into String
		this->parseFromURL(finalURLPath.str());

        this->parseResponseJson(lineVector.at(0),lineVector.at(1),lineVector.at(2),eroadOutputFile);
	}
    eroadOutputFile.close();
}	
 

void EROADData::parseResponseJson(const std::string& iDateTime, const std::string& iLatitude, const std::string& iLongitude,std::ofstream& eroadOutputFile)
{
    cout<<"**************************************************\n";
    vector<std::string> jsonResponseVector; 
       
    // Clear the vector. 
    jsonResponseVector.clear();

    // Split/Tokenize the GoogleAPI resonse and populate the jsonResponseVector
    boost::split(jsonResponseVector, this->getData(), boost::is_any_of(":,\""));


    // Trim the extra spaces from the Offset Value.
    boost::trim(jsonResponseVector.at(7));

    // Get the OffSetHour difference from the UTC to LocalTime.
    int offSetHour = boost::lexical_cast<int>(jsonResponseVector.at(7))/3600;

    // Get the addition New Time from the current UTC time and the OffSet from the local time.
    const boost::posix_time::ptime timeNew = boost::posix_time::time_from_string(iDateTime) + hours(offSetHour) ;

    // Construct the Final Output string as expected.
    std::stringstream finalString;
    finalString << iDateTime<<","<<iLatitude<<","<<iLongitude<<","<<jsonResponseVector.at(18)<<","<<to_iso_extended_string(timeNew);

    cout<<"Final Expected String : "<<finalString.str()<<endl;

    eroadOutputFile <<finalString.str()<<endl; 
        
}


void EROADData::parseFromURL(const std::string& url)
{
    // Clear the String Buffer to store different responses everytime
    curlBuffer.clear();

    curl = curl_easy_init();
	if(!curl)
       	throw std::string ("Curl Could not initialize!");

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &EROADData::curlWriter);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_perform(curl);
}


void EROADData::convertUTCToEpochTime(const std::string& itime, std::string& oEpochTime)
{
    //std::string ts("2013-07-10 02:52:49");
	ptime t(time_from_string(itime));
	ptime start(boost::gregorian::date(1970,1,1)); 
	time_duration dur = t - start; 
	time_t epoch = dur.total_seconds();

	std::ostringstream ss;
	ss << epoch;
    oEpochTime = ss.str();
}

int main (int argc, char ** argv) 
{
	try 
	{
		EROADData eroadProcessFile;
		eroadProcessFile.readInputAndWriteOutputFile();
    }
    catch (std::string & s) 
    {
        std::cerr << "Oops! " << s << std::endl;
    }
}