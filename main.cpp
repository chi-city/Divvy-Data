/* Program_4
    Divvy Bike Data Analysis program.
    Author: Zaid Awaidah
    Date: 11/3/2021
    Class: CS 141, Fall 2021, UIC
    System: Visual Studio 2019 IDE Windows
    Menu Option 5 Extra Credit URL: https://www.google.com/maps/d/u/0/edit?mid=1kEBEpX9wK7_L-cxFBnXy6ZYR_u0mVIs6&usp=sharing // Change when doing option 5
    Coordinates for Home I would like to live in:  41.88727594487027, -87.61551354110455
*/

#include <iostream>   // For Input and Output
#include <fstream>    // For file input and output
#include <cassert>    // For the assert statement
#include <cctype>     // access to tolower() or toupper() function
#include <vector>     // For vectors
#include <string>     // String operations
#include <algorithm>  // use of vector algorithms
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

// Utility functions getting distant between two map points 
// Attribution: https://www.geeksforgeeks.org/program-distance-two-points-earth/  
// converting degrees to radians
long double toRadians(const long double degree);

long double distance(long double lat1, long double long1,
    long double lat2, long double long2);

class DivvyRides{
public:
    //Constructors - Destructors
    DivvyRides() { ; }
    ~DivvyRides() { ; }
    
    //Utility Functions
    void divvyBikeSmallData(vector <string>& divvyBikeSample); // Read in DivvyBike Sample data into vector
    void divvyBikeWeekndWeekddayData(vector <string>& divvyBikeWeekData); // Read in DivvyBike Week data into vector
    void divvyBikeAllSeptData(vector<string>& divvyBikeSeptData); // Read in Sept data
    void menuOptions(int userChoice, bool& userPick, vector <DivvyRides>& divvyRide); // Menu Options
    void menuOpt1(int menuOpt, vector <DivvyRides>& divvyRide);
    void menuOpt2(vector <DivvyRides> divvyRide);
    void menuOpt3(vector <DivvyRides> divvyRide);
    void menuOpt4(int menuOpt, vector <DivvyRides> divvyRide);
    void menuOpt5(vector <DivvyRides> divvyRide);
    void CleanDataFile(vector<DivvyRides>& divvyRide, int& cleanDataCounter);

    //Getters and Setters
    void setRideId(string rideID) { ride_Id = rideID; }
    void setRideableType(string rideableType) { rideable_Type = rideableType; }
    void setStartTime(string startDateAndTIme) { start_Date_And_Time = startDateAndTIme; }
    void setEndTime(string endDateAndTime) { end_Date_And_Time = endDateAndTime; }
    void setStartStation(string startingStation) { start_Station = startingStation; }
    void setEndStation(string endingStation) { end_Station = endingStation; }
    void setStartLatitude( string startingLatitude) { start_Latitude = startingLatitude; }
    void setStartLongitude(string startingLongitude) { start_Longitude = startingLongitude; }
    void setEndLatitude(string endingLatitude) { end_Latitude = endingLatitude; }
    void setEndLongitude(string endingLongitude) { end_Longitude = endingLongitude; }
    void setMemberType(string memberType) { member_Type = memberType; }

    string getStartingLatStr() const { return start_Latitude; }
    string getStartingLongStr() const { return start_Longitude; }
    string getEndingLatStr() const { return end_Latitude; }
    string getEndingLongStr() const { return end_Longitude; }
    string getRideId() const { return ride_Id; }
    string getRideableType() const { return rideable_Type; }
    string getStartTime() const { return start_Date_And_Time; }
    string getEndTime() const { return end_Date_And_Time; }
    string getStartStation() const { return start_Station; }
    string getEndStation() const { return end_Station; }
    string getMemberType() const { return member_Type; }
    long double getStartLatitude() const {
        long double startLatVal = stold(start_Latitude);
        return startLatVal; 
    }
    long double getStartLongitude() const {
        long double startLongVal = stold(start_Longitude);
        return startLongVal;
    }
    long double getEndLatitude() const {
        long double endLatVal = stold(end_Latitude);
        return endLatVal;
    }
    long double getEndLongitude() const {
        long double endLongVal = stold(end_Longitude);
        return endLongVal;
    }

    //Member Variables
private:
    string ride_Id;
    string rideable_Type;
    string start_Date_And_Time;
    string end_Date_And_Time;
    string start_Station;
    string end_Station;
    string member_Type;
    string start_Latitude;
    string start_Longitude;
    string end_Latitude;
    string end_Longitude;
};

int main(){
    DivvyRides divvy_Ride;
    vector<DivvyRides> divvyRides;
    divvyRides.push_back(divvy_Ride);

    cout << "Analyze Divvy bike ride information using September trip data.\n"
         << "First select option 1 to read and clean the data.\n\n";

    int userChoice;
    bool pickOpt1 = false;
    bool menu_Options = true;
    do {
       cout << "Select a menu option:\n"
                << "   1. Select datafile, display rides totals and clean data\n"
                << "   2. Display overall trip information\n"
                << "   3. Display percentage of members vs. casual riders\n"
                << "   4. Display weekday vs weekend usage\n"
                << "   5. Extra Credit: find closest station\n"
                << "   6. Exit"
                << endl;
       cout << "Your choice --> ";
       cin >> userChoice;

       if (((userChoice == 2) || (userChoice == 3) || (userChoice == 4) || (userChoice == 5)) && (pickOpt1 == false)) {
           cout << "   First read in data by selecting menu option 1\n\n";
           continue;
       }
       divvy_Ride.menuOptions(userChoice,pickOpt1, divvyRides);

    } while (menu_Options == true);
        
    return 0;
}

void DivvyRides::menuOptions(int user_Choice, bool& userPick, vector<DivvyRides>& divvyRides){
    
    switch (user_Choice) {
    case 1:
        userPick = true;
        int userSubChoice;
        cout << "   Select datafile:\n"
            << "      1. Small subset of data with 14 rides to help create your program\n"
            << "      2. Week day vs weekend rides\n"
            << "      3. All September 2021 data (not tested in Zybooks)\n"
            << "   Your selection--> ";
        cin >> userSubChoice;
        divvyRides.clear();
        menuOpt1(userSubChoice, divvyRides);
        break;

    case 2:
        menuOpt2(divvyRides);
        break;

    case 3: 
        menuOpt3(divvyRides);
        break;

    case 4:
        int userChoice;
        cout << "   Select type of display:\n"
            << "      1. Counts of rides per hour in the day\n"
            << "      2. Proportional 50 column graph with @ for weekday and + for weekend\n"
            << "   Your selection--> ";
        cin >> userChoice;
        menuOpt4(userChoice, divvyRides);
        break;

    case 5:
        menuOpt5(divvyRides);
        break;

    case 6:
        exit(0);
    }
}

void DivvyRides::menuOpt1(int menuOpt, vector<DivvyRides>& divvyRides) {
    DivvyRides divvy_Rides_Trips; //local object
    vector <string> divvyBikeSample; //Vector to fill with all sample data
    vector <string> divvyBikeWeekData;
    vector<string> divvyBikeSeptData;
    int cleanDataCounter = 0;
    int totalTripsCounter = 0;
    
    int idIndex, rideableTypeIndex, startTimeIndex, endTimeIndex, startStationIndex, endStationIndex,
            startLatIndex, startLongIndex, endLatIndex, endLongIndex, memberIndex;
    
    //Separate into clean and unclean, then use clean 
    string line;

    if (menuOpt == 1) {
        divvyBikeSample.clear();
        divvy_Rides_Trips.divvyBikeSmallData(divvyBikeSample);

        for (unsigned int i = 1; i < divvyBikeSample.size(); ++i) {
        
            line = divvyBikeSample.at(i);

            idIndex = line.find(','); //Find the index of the first occurance of ','
            rideableTypeIndex = line.find(',', idIndex + 1);
            startTimeIndex = line.find(',', rideableTypeIndex + 1);
            endTimeIndex = line.find(',', startTimeIndex + 1);
            startStationIndex = line.find(',', endTimeIndex + 1);
            endStationIndex = line.find(',', startStationIndex + 1);
            startLatIndex = line.find(',', endStationIndex + 1);
            startLongIndex = line.find(',', startLatIndex + 1);
            endLatIndex = line.find(',', startLongIndex + 1);
            endLongIndex = line.find(',', endLatIndex + 1);
            memberIndex = line.length();

            //Ride Id
            divvy_Rides_Trips.setRideId(line.substr(0, line.find(','))); // parsing then set the categories, each category starts at the end index of prev one

            //Rideable Type
            divvy_Rides_Trips.setRideableType(line.substr(idIndex + 1, rideableTypeIndex - idIndex - 1));

            //Starting Time
            divvy_Rides_Trips.setStartTime(line.substr(rideableTypeIndex + 1, (startTimeIndex - rideableTypeIndex - 1)));

            //Ending Time
            divvy_Rides_Trips.setEndTime(line.substr(startTimeIndex + 1, (endTimeIndex - startTimeIndex - 1)));

            //Starting Station
            divvy_Rides_Trips.setStartStation(line.substr(endTimeIndex + 1, (startStationIndex - endTimeIndex - 1)));

            //Ending Station
            divvy_Rides_Trips.setEndStation(line.substr(startStationIndex + 1, (endStationIndex - startStationIndex - 1)));

            //Starting Latitude
            divvy_Rides_Trips.setStartLatitude(line.substr(endStationIndex + 1, (startLatIndex - endStationIndex - 1)));

            //Starting Longitude
            divvy_Rides_Trips.setStartLongitude(line.substr(startLatIndex + 1, (startLongIndex - startLatIndex - 1)));

            //Ending Latitude
            divvy_Rides_Trips.setEndLatitude(line.substr(startLongIndex + 1, (endLatIndex - startLongIndex - 1)));

            //Ending Longitude
            divvy_Rides_Trips.setEndLongitude(line.substr(endLatIndex + 1, (endLongIndex - startLongIndex - 1)));

            //Member Type
            divvy_Rides_Trips.setMemberType(line.substr(endLongIndex + 1, (memberIndex - endLongIndex - 1)));
            divvyRides.push_back(divvy_Rides_Trips);
        }
        totalTripsCounter = divvyBikeSample.size() - 1;

    }cout << endl;

    if (menuOpt == 2) {
        divvyBikeWeekData.clear();
        divvy_Rides_Trips.divvyBikeWeekndWeekddayData(divvyBikeWeekData);

        for (unsigned int i = 1; i < divvyBikeWeekData.size(); ++i) {
            line = divvyBikeWeekData.at(i);

            idIndex = line.find(','); //Find the index of the first occurance of ','
            rideableTypeIndex = line.find(',', idIndex + 1);
            startTimeIndex = line.find(',', rideableTypeIndex + 1);
            endTimeIndex = line.find(',', startTimeIndex + 1);
            startStationIndex = line.find(',', endTimeIndex + 1);
            endStationIndex = line.find(',', startStationIndex + 1);
            startLatIndex = line.find(',', endStationIndex + 1);
            startLongIndex = line.find(',', startLatIndex + 1);
            endLatIndex = line.find(',', startLongIndex + 1);
            endLongIndex = line.find(',', endLatIndex + 1);
            memberIndex = line.length();

            //Ride Id
            divvy_Rides_Trips.setRideId(line.substr(0, line.find(','))); // parsing then set the categories, each category starts at the end index of prev one

            //Rideable Type
            divvy_Rides_Trips.setRideableType(line.substr(idIndex + 1, rideableTypeIndex - idIndex - 1));

            //Starting Time
            divvy_Rides_Trips.setStartTime(line.substr(rideableTypeIndex + 1, (startTimeIndex - rideableTypeIndex - 1)));

            //Ending Time
            divvy_Rides_Trips.setEndTime(line.substr(startTimeIndex + 1, (endTimeIndex - startTimeIndex - 1)));

            //Starting Station
            divvy_Rides_Trips.setStartStation(line.substr(endTimeIndex + 1, (startStationIndex - endTimeIndex - 1)));

            //Ending Station
            divvy_Rides_Trips.setEndStation(line.substr(startStationIndex + 1, (endStationIndex - startStationIndex - 1)));

            //Starting Latitude
            divvy_Rides_Trips.setStartLatitude(line.substr(endStationIndex + 1, (startLatIndex - endStationIndex - 1)));

            //Starting Longitude
            divvy_Rides_Trips.setStartLongitude(line.substr(startLatIndex + 1, (startLongIndex - startLatIndex - 1)));

            //Ending Latitude
            divvy_Rides_Trips.setEndLatitude(line.substr(startLongIndex + 1, (endLatIndex - startLongIndex - 1)));

            //Ending Longitude
            divvy_Rides_Trips.setEndLongitude(line.substr(endLatIndex + 1, (endLongIndex - startLongIndex - 1)));

            //Member Type
            divvy_Rides_Trips.setMemberType(line.substr(endLongIndex + 1, (memberIndex - endLongIndex - 1)));
            divvyRides.push_back(divvy_Rides_Trips);
        }
        totalTripsCounter = divvyBikeWeekData.size() - 1;
    }

    if (menuOpt == 3) {
        divvyBikeSeptData.clear();
        divvy_Rides_Trips.divvyBikeAllSeptData(divvyBikeSeptData);

        for (unsigned int i = 1; i < divvyBikeSeptData.size(); ++i) {
            line = divvyBikeSeptData.at(i);

            idIndex = line.find(','); //Find the index of the first occurance of ','
            rideableTypeIndex = line.find(',', idIndex + 1);
            startTimeIndex = line.find(',', rideableTypeIndex + 1);
            endTimeIndex = line.find(',', startTimeIndex + 1);
            startStationIndex = line.find(',', endTimeIndex + 1);
            endStationIndex = line.find(',', startStationIndex + 1);
            startLatIndex = line.find(',', endStationIndex + 1);
            startLongIndex = line.find(',', startLatIndex + 1);
            endLatIndex = line.find(',', startLongIndex + 1);
            endLongIndex = line.find(',', endLatIndex + 1);
            memberIndex = line.length();

            //Ride Id
            divvy_Rides_Trips.setRideId(line.substr(0, line.find(','))); // parsing then set the categories, each category starts at the end index of prev one

            //Rideable Type
            divvy_Rides_Trips.setRideableType(line.substr(idIndex + 1, rideableTypeIndex - idIndex - 1));

            //Starting Time
            divvy_Rides_Trips.setStartTime(line.substr(rideableTypeIndex + 1, (startTimeIndex - rideableTypeIndex - 1)));

            //Ending Time
            divvy_Rides_Trips.setEndTime(line.substr(startTimeIndex + 1, (endTimeIndex - startTimeIndex - 1)));

            //Starting Station
            divvy_Rides_Trips.setStartStation(line.substr(endTimeIndex + 1, (startStationIndex - endTimeIndex - 1)));

            //Ending Station
            divvy_Rides_Trips.setEndStation(line.substr(startStationIndex + 1, (endStationIndex - startStationIndex - 1)));

            //Starting Latitude
            divvy_Rides_Trips.setStartLatitude(line.substr(endStationIndex + 1, (startLatIndex - endStationIndex - 1)));

            //Starting Longitude
            divvy_Rides_Trips.setStartLongitude(line.substr(startLatIndex + 1, (startLongIndex - startLatIndex - 1)));

            //Ending Latitude
            divvy_Rides_Trips.setEndLatitude(line.substr(startLongIndex + 1, (endLatIndex - startLongIndex - 1)));

            //Ending Longitude
            divvy_Rides_Trips.setEndLongitude(line.substr(endLatIndex + 1, (endLongIndex - startLongIndex - 1)));

            //Member Type
            divvy_Rides_Trips.setMemberType(line.substr(endLongIndex + 1, (memberIndex - endLongIndex - 1)));
            divvyRides.push_back(divvy_Rides_Trips);
        }
        totalTripsCounter = divvyBikeSeptData.size() - 1;
        
    }
    
    CleanDataFile(divvyRides, cleanDataCounter );
   
    cout << "   Total # of trips found in datafile : " << totalTripsCounter << endl;
    cout << "   Total # of trips in clean data:  " << cleanDataCounter << endl;
}

void DivvyRides::menuOpt2(vector <DivvyRides> divvyRide) {
    long double tempStartLat, tempStartLong, tempEndLat, tempEndLong = 0;
    long double longestDist = 0, totalDistance = 0;
    double avgMiles;
    int indexOfLongest = 0;

    for (unsigned int i = 0; i < divvyRide.size(); i++) {
        tempStartLat = divvyRide[i].getStartLatitude();
        tempStartLong = divvyRide[i].getStartLongitude();
        tempEndLat = divvyRide[i].getEndLatitude();
        tempEndLong = divvyRide[i].getEndLongitude();
        totalDistance += distance(tempStartLat, tempStartLong, tempEndLat, tempEndLong);

        if (longestDist < distance(tempStartLat, tempStartLong, tempEndLat, tempEndLong)) {
            longestDist = distance(tempStartLat, tempStartLong, tempEndLat, tempEndLong);
            indexOfLongest = i;
        }
    }

    avgMiles = totalDistance / divvyRide.size();

    cout << "   Total # of miles traveled: " << fixed << setprecision(0) << totalDistance << endl;
    cout << "   Average length of trips in miles:  " << fixed << setprecision(1) << avgMiles << endl;

    cout << "   Longest trip information below: \n"
        << "   -------------------------------\n"
        << "   Trip ID: " << divvyRide[indexOfLongest].getRideId() << endl
        << "   Trip start location: " << divvyRide[indexOfLongest].getStartStation() << endl
        << "   Trip end location: " << divvyRide[indexOfLongest].getEndStation() << endl
        << "   Trip distance in miles: " << longestDist << "\n" << endl;
}

void DivvyRides::menuOpt3(vector <DivvyRides> divvyRide) {
    double casualRiderPercnt, memberRiderPercnt;
    double casualRider = 0, memberRider = 0, allRiders;
   
    for (int i = 0; i < divvyRide.size(); i++) {
        if (divvyRide[i].getMemberType() == "casual") { 
            casualRider++;
        }
        else if (divvyRide[i].getMemberType() == "member") {
            memberRider++;
        }
    }
     allRiders = casualRider + memberRider;

     casualRiderPercnt = (casualRider / allRiders) * 100;
     memberRiderPercnt = (memberRider / allRiders) * 100;

     cout << "   Casual Rider Percentage: " << fixed << setprecision(1) << casualRiderPercnt << "%\n"
          << "   Member Rider Percentage: " << fixed << setprecision(1) << memberRiderPercnt << "%\n"
          << endl;
}

void DivvyRides::menuOpt4(int menuOpt, vector <DivvyRides> divvyRide) {
    vector<string> week_Times;
    vector<string>week_Dates;
    vector<int> weekTimes;
    vector<int> weekDays;
    vector<int> weekEnds;
    int LargestNumberOfRides = 0;
    int sizeOfVector = 15;
    
    for (unsigned int i = 0; i < divvyRide.size(); i++) {
        if (divvyRide.size() < sizeOfVector) {
            week_Times.push_back(divvyRide[i].getStartTime().substr((divvyRide[i].getStartTime().find(' ')), (divvyRide[i].getStartTime().find(':')) -1 )); //Sample File
            week_Dates.push_back(divvyRide[i].getStartTime().substr(0, (divvyRide[i].getStartTime().find(' '))));
        }
        else {
            week_Times.push_back(divvyRide[i].getStartTime().substr((divvyRide[i].getStartTime().find(' ')),(divvyRide[i].getStartTime().find(':')) - 1)); //Week File
            week_Dates.push_back(divvyRide[i].getStartTime().substr(0, (divvyRide[i].getStartTime().find(' '))));
        }
        weekTimes.push_back(stoi(week_Times[i]));
    }


    if (menuOpt == 1) {
        for (int hours = 0; hours <= 23; hours++) {
            int tempCountForWeekDayHours = 0;
            int tempCountForWeekendHours = 0;

            for (int j = 0; j < weekTimes.size(); j++) {
                if ((weekTimes[j] == hours) && ( (week_Dates[j] == "9/1/2021") || (week_Dates[j] == "9/2/2021") || (week_Dates[j] == "9/3/2021") || (week_Dates[j] == "9/6/2021") || (week_Dates[j] == "9/7/2021") || 
                   (week_Dates[j] == "9/8/2021") || (week_Dates[j] == "9/9/2021") || (week_Dates[j] == "9/10/2021") || (week_Dates[j] == "9/13/2021") || (week_Dates[j] == "9/14/2021") || (week_Dates[j] == "9/15/2021") || 
                    (week_Dates[j] == "9/16/2021") || (week_Dates[j] == "9/17/2021") || (week_Dates[j] == "9/20/2021") || (week_Dates[j] == "9/21/2021") || (week_Dates[j] == "9/22/2021") || (week_Dates[j] == "9/23/2021") || 
                    (week_Dates[j] == "9/24/2021") || (week_Dates[j] == "9/27/2021") || (week_Dates[j] == "9/28/2021") || (week_Dates[j] == "9/29/2021") || (week_Dates[j] == "9/30/2021") ) ) 
                {
                    tempCountForWeekDayHours++;
                }
                else if ((weekTimes[j] == hours) && ( (week_Dates[j] == "9/4/2021") || (week_Dates[j] == "9/5/2021") || (week_Dates[j] == "9/11/2021") || (week_Dates[j] == "9/12/2021") || (week_Dates[j] == "9/18/2021") || 
                    (week_Dates[j] == "9/19/2021") || (week_Dates[j] == "9/25/2021") || (week_Dates[j] == "9/26/2021") ) ) {
                    tempCountForWeekendHours++;
                }
            }

            if ((LargestNumberOfRides < tempCountForWeekDayHours) || (LargestNumberOfRides < tempCountForWeekendHours)) {
                if (tempCountForWeekDayHours < tempCountForWeekendHours) {
                    LargestNumberOfRides = tempCountForWeekendHours;
                }
                else {
                    LargestNumberOfRides = tempCountForWeekDayHours;
                }
            }
            weekDays.push_back(tempCountForWeekDayHours);
            weekEnds.push_back(tempCountForWeekendHours);
            tempCountForWeekDayHours = 0;
            tempCountForWeekendHours = 0;
        }

        cout << "   LargestNumberOfRides is: " << LargestNumberOfRides << endl;
        cout << "   Rides per hour for weekday and weekend:\n";
        for (int i = 0; i <= 23; i++) {
            cout << "    " << setw(2) << i << ":" << setw(7) << weekDays[i] << setw(7) << weekEnds[i] << endl;
        }
    }

    if (menuOpt == 2) {
        for (int hours = 0; hours <= 23; hours++) {
            int tempCountForWeekDayHours = 0;
            int tempCountForWeekendHours = 0;

            for (int j = 0; j < weekTimes.size() ; j++) {
                if ((weekTimes[j] == hours) && ((week_Dates[j] == "9/1/2021") || (week_Dates[j] == "9/2/2021") || (week_Dates[j] == "9/3/2021") || (week_Dates[j] == "9/6/2021") || (week_Dates[j] == "9/7/2021") ||
                    (week_Dates[j] == "9/8/2021") || (week_Dates[j] == "9/9/2021") || (week_Dates[j] == "9/10/2021") || (week_Dates[j] == "9/13/2021") || (week_Dates[j] == "9/14/2021") || (week_Dates[j] == "9/15/2021") ||
                    (week_Dates[j] == "9/16/2021") || (week_Dates[j] == "9/17/2021") || (week_Dates[j] == "9/20/2021") || (week_Dates[j] == "9/21/2021") || (week_Dates[j] == "9/22/2021") || (week_Dates[j] == "9/23/2021") ||
                    (week_Dates[j] == "9/24/2021") || (week_Dates[j] == "9/27/2021") || (week_Dates[j] == "9/28/2021") || (week_Dates[j] == "9/29/2021") || (week_Dates[j] == "9/30/2021"))) {
                    tempCountForWeekDayHours++;
                }
                else if ((weekTimes[j] == hours) && ( (week_Dates[j] == "9/4/2021") || (week_Dates[j] == "9/5/2021") || (week_Dates[j] == "9/11/2021") || (week_Dates[j] == "9/12/2021") || (week_Dates[j] == "9/18/2021") ||
                    (week_Dates[j] == "9/19/2021") || (week_Dates[j] == "9/25/2021") || (week_Dates[j] == "9/26/2021") ) ) {
                    tempCountForWeekendHours++;
                }
            }

            if ((LargestNumberOfRides < tempCountForWeekDayHours) || (LargestNumberOfRides < tempCountForWeekendHours)) {
                if (tempCountForWeekDayHours < tempCountForWeekendHours) {
                    LargestNumberOfRides = tempCountForWeekendHours;
                }
                else {
                    LargestNumberOfRides = tempCountForWeekDayHours;
                }
            }
            weekDays.push_back(tempCountForWeekDayHours);
            weekEnds.push_back(tempCountForWeekendHours);
            tempCountForWeekDayHours = 0;
            tempCountForWeekendHours = 0;
        }

        for (int i = 0; i <= 23 ; i++) {

            double numWeekDays = (double(weekDays[i]) / double(LargestNumberOfRides)) * 50.0;
            double numWeekEnds = (double(weekEnds[i]) / double(LargestNumberOfRides)) * 50.0;
            cout << "    " << i << ": ";
            
           for (int j = 0; j < int(numWeekDays); j++) {
                cout << "@";
           }
           cout << "\n       ";
           
           for (int j = 0; j < int(numWeekEnds); j++) {
               cout << "+";
           }cout << endl;
        }
    }
}

void DivvyRides::menuOpt5(vector <DivvyRides> divvyRide) {
    int indxOfDivvy = 0;
    long double userLat, userLong;
    double tempMiles = INT_MAX; 

    cout << "   Input latitude and longitude of the home: ";
    cin >> userLat >> userLong;
    
    for (unsigned int i = 0; i < divvyRide.size(); i++) {
        long double tempLat = divvyRide[i].getStartLatitude();
        long double tempLong = divvyRide[i].getStartLongitude();
        long double totalDist = distance(userLat, userLong, tempLat, tempLong);

        if (totalDist < tempMiles) {
            tempMiles = totalDist;
            indxOfDivvy = i;
        }
    }

    cout << "   You entered: " << fixed << setprecision(1) << userLat << " for latitude and " << fixed << setprecision(1) << userLong << " for longitude\n";
    cout << "   Closest Divvy station is: " << divvyRide[indxOfDivvy].getStartStation() << " at " << setprecision(8) << divvyRide[indxOfDivvy].getStartLatitude() << ", "
         << setprecision(8) << divvyRide[indxOfDivvy].getStartLongitude() << ", " << setprecision(1) << tempMiles << " miles away.\n";
}

void DivvyRides::CleanDataFile(vector<DivvyRides>& divvyRides, int& finalCleanDataCounter) {
    vector<DivvyRides> cleanDivvyDataFile;
    vector<DivvyRides>divvyBikeUncleanData;
    string uncleanData = "";
    int cleanDataCounter = 0;

    //Loop thru each obj and compare its members for each category
    for (int i = 0; i < divvyRides.size(); i++) {
        if ((divvyRides[i].getRideId().compare(uncleanData) == 0) || (divvyRides[i].getRideableType().compare(uncleanData) == 0) || (divvyRides[i].getStartTime().compare(uncleanData) == 0)
            || (divvyRides[i].getEndTime().compare(uncleanData) == 0) || (divvyRides[i].getStartStation().compare(uncleanData) == 0) || (divvyRides[i].getEndStation().compare(uncleanData) == 0)
            || (divvyRides[i].getStartingLatStr().compare(uncleanData) == 0) || (divvyRides[i].getStartingLongStr().compare(uncleanData) == 0) || (divvyRides[i].getEndingLatStr().compare(uncleanData) == 0)
            || (divvyRides[i].getEndingLongStr().compare(uncleanData) == 0) || (divvyRides[i].getMemberType().compare(uncleanData) == 0)) 
        {

            divvyBikeUncleanData.push_back(divvyRides[i]);
        }
        else {
            cleanDataCounter++;
            cleanDivvyDataFile.push_back(divvyRides[i]);
        }
    }
    divvyRides = cleanDivvyDataFile;
    finalCleanDataCounter = cleanDataCounter;
}
   
void DivvyRides::divvyBikeSmallData(vector <string>& divvyBikeSample) {

    //Reading in:
    ifstream streamObj;
    streamObj.open("divvyridesampledata.csv");      //Opens file
    assert(streamObj.fail() == false);     //Ensures file opened

    //clear vector if it was used before
    divvyBikeSample.clear();

    string wordInput;
    while (getline(streamObj, wordInput)) {
        //Push word to end of vector(increases size)
        divvyBikeSample.push_back(wordInput);
    }
    streamObj.close();      //close file  
}

void DivvyRides::divvyBikeWeekndWeekddayData(vector <string>& divvyBikeWeekData) {

    //Reading in:
    ifstream streamObj;
    streamObj.open("weekdayweekend.csv");      //Opens file
    assert(streamObj.fail() == false);     //Ensures file opened

    //clear vector if it was used before
    divvyBikeWeekData.clear();

    string wordInput;
    while (getline(streamObj, wordInput)) {
        //Push word to end of vector(increases size)
        divvyBikeWeekData.push_back(wordInput);
    }
    streamObj.close();      //close file  
}

void DivvyRides::divvyBikeAllSeptData(vector<string>& divvyBikeSeptData) {
    ifstream streamObj;
    streamObj.open("all_divvy_rides_september.csv");      //Opens file
    assert(streamObj.fail() == false);     //Ensures file opened

    //clear vector if it was used before
    divvyBikeSeptData.clear();

    string wordInput;
    while (getline(streamObj, wordInput)) {
        //Push word to end of vector(increases size)
        divvyBikeSeptData.push_back(wordInput);
    }
    streamObj.close();
}

long double toRadians(const long double degree){
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    long double one_deg = (3.14159265358979323846) / 180;
    return (one_deg * degree);
}

long double distance(long double lat1, long double long1,
    long double lat2, long double long2){
    // Convert the latitudes
    // and longitudes
    // from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);

    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;

    long double ans = pow(sin(dlat / 2), 2) +
        cos(lat1) * cos(lat2) *
        pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 3956;

    // Calculate the result
    ans = ans * R;

    return ans;
}