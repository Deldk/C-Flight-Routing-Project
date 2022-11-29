#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <map>
#include <vector>
#include"airports.h"
using namespace std;




// Constructor for the the Airport class
Airport::Airport(int ID, string name, string city, string country, string iata, string icao, string latitude, string longitude){
    AirportID = ID;
    Name = name;
    City = city;
    Country = country;
    IATA = iata;
    ICAO = icao;
    Latitude = latitude;
    Longitude = longitude;
}

int Airport::getID(){
    return AirportID;
}


string Airport::getName(){
    return Name;
}

string Airport::getIATA(){
    return IATA;
}

string Airport::getCity(){
    return City;
}

string Airport::getCountry(){
    return Country;
}

string Airport::toString(){
    string ID = to_string(AirportID);
    return "This is airport ID: " + ID + " City: " + City + " IATA: " + IATA;
}



// void Airport::read_AirportData(){
//     string input_airportID, input_name, input_city, input_country, input_iata, input_icao, input_latitude, input_longitude;

//     ifstream file;
//     file.open("airports.csv"); //Opening the airports file for reading 
//     if (file.fail()){ // checking if file opening failed
//         cout << " File could not be opened...";
//     }

//     string line = "";

//     while(getline(file, line)){
//         stringstream stream(line);
//         getline(stream, input_airportID, ',');
//         getline(stream, input_name, ',');
//         getline(stream, input_city, ',');
//         getline(stream, input_country, ',');
//         getline(stream, input_iata, ',');
//         getline(stream, input_icao, ',');
//         getline(stream, input_latitude, ',');
//         getline(stream, input_longitude, ',');
    
//         if (input_city == "\\N" || input_city == "")
//             input_city = "Not available";

//         if (input_country == "\\N" || input_country == "")
//             input_country = "Not available";

//         if (input_iata == "\\N" || input_iata == "")
//             input_iata = "Not available";

//         if (input_icao == "\\N" || input_icao == "")
//             input_icao = "Not available";

//         if (input_latitude == "\\N" || input_latitude == "")
//             input_latitude = "Not available";    

//         Airport airport(input_airportID, input_name, input_city, input_country, input_iata, input_icao, input_latitude, input_longitude);
//        cout<< airport.toString()<<endl;
//         // string key = input_city + "- " + input_country;

//         // airportID_Code.insert(pair<string, string>(input_iata, input_airportID));
//         // it_dict = dict_airport.find(key);
//         // if (it_dict != dict_airport.end()){
//         //     it_dict->second.push_back(airport);
//         //     // dict_airport.find(input_iata).push_back(airport);
//         // }else{
//         //     vector<Airport> new_airport_list;
//         //     new_airport_list.push_back(airport);
//         //     dict_airport.insert({key, new_airport_list});

//         // }

//         // airportID_object.insert(pair<string, Airport>(input_iata, airport));

        
//     }


// }

// string Airport::getName(Airport airport_object){
//     return airport_object.Name;
// }


// string Airport::toString(){
//     return "id " + AirportID + " name " + Name;
// }


// int main(){

//     Airport airport;

//     airport.read_AirportData();

//     return 0;
// }