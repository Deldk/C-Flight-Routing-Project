#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <map>
#include <vector>
#pragma once
using namespace std;

// map<string, vector<Airport>> dict_airport; //takes string key and Airport list
// map<string, vector<Airport>>::iterator it_dict;

// map<string, string> airportID_Code;
// map<string, string>::iterator it_ID;

// map<string, Airport> airportID_object;
// map<string, Airport>::iterator it_obj;


class Airport{

    private:
    int AirportID;
    string Name;
    string City;
    string Country;
    string IATA;
    string ICAO;
    string Latitude;
    string Longitude;


    public:

    // Constructor for the the Airport class
    Airport(int ID, string name, string city, string country, string iata, string icao, string latitude, string longitude);

    /**
     * Getters for airport class
    */

   int getID();

    string getName();

    string getIATA();

    string getCity();

    string getCountry();

    string getLatitude();

    string toString();

    void read_AirportData();

};