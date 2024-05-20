#include<bits/stdc++.h>
using namespace std;
class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>checkIns;// stores user id's mappings with corresponding start station and the time at that station
    unordered_map<string,pair<int,int>>traveltime;// stores the journey's mappings with corresponding travel times and the count of the times the journey has occurred. 
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id]= { stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string start_Station=checkIns[id].first;
        int travel_In=checkIns[id].second;//retrieving data from mapping

        checkIns.erase(id);// erasing the current station's data as user has already checked out of the station, user can start new journeys now (New entries corressponding to the user can be made)

        string journey= start_Station + " -> " + stationName;//making entry of journey
     
        traveltime[journey].first+= t - travel_In;//calculating travel time for the corresponding journey
        traveltime[journey].second++;//increasing count of times journey has occurred
    }
    
    double getAverageTime(string startStation, string endStation)
    {

        string journey= startStation + " -> " + endStation;
       
        return (double)traveltime[journey].first*1.0/traveltime[journey].second;//calculating average time for the journey (Multiple users or single user)
    }
};
 void input_check_In_Or_Out(UndergroundSystem* obj,bool flag)
 {
     int id,time;
     string stationName;
     if(flag)
     {
         cout<<"For Checking-In, enter the Customer_id, Starting station and time of departure at that station , enter Customer_id=-1 if you don't want to enter"<<endl;
         cin>>id>>stationName>>time;
         while(id!=-1)
         {
         obj->checkIn(id,stationName,time);
         cin>>id>>stationName>>time;
         }
     }
     else
     {
         cout<<"For Checking-Out, enter the Customer_id, Starting station and time of arrival at that station, enter Customer_id=-1 if don't want to enter"<<endl;
         cin>>id>>stationName>>time;
         while(id!=-1)
         {
         obj->checkOut(id,stationName,time);
         cin>>id>>stationName>>time;
         }
     }
 }
 
 void display_time_Journey(UndergroundSystem* obj)
 {
     string start_station,end_station;
     
  cout<<"Enter the start_station and end_station for which you want average time"<<endl;
  cin>>start_station>>end_station;
  
  double ans = obj->getAverageTime(start_station,end_station);
  cout<<"The Average time for Journey - "<<start_station<<" -> "<<
  end_station<<" = "<<ans<<endl;
 }
 int main()
{
  UndergroundSystem* obj = new UndergroundSystem();
  
  input_check_In_Or_Out(obj,true);
  
  input_check_In_Or_Out(obj,false);
  
  display_time_Journey( obj);
}



