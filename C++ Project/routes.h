#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <map>
#include <vector>
#pragma once
using namespace std;


class Route{
    private:
    string AirlineCode;
    int AirlineID;
    string source_AirportCode;
    int source_AirportID;
    string destination_AirportCode;
    int destination_AirportID;
    string codeShare;
    string Stops;
    string Equipment;

    public:
    Route(string airline_code, int airline_ID, string source_airport_code, int source_airport_ID, string destination_airport_code, int destination_airport_ID, string codeShare, string stops);

    /**
     * Getters for Route class
    */

   string getAirlineCode();

   int getAirlineID();

   string getsource_AirportCode();

   int getsource_AirportID();

   string getdestination_AirportCode();

   int getdestination_AirportID();

   string getStops();

   string toString();
};