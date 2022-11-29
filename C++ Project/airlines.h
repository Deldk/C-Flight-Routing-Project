#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <map>
#include <vector>
#pragma once
using namespace std;

class Airline{
    private:
    int AirlineID;
    string Alias;
    string IATA;
    string ICAO;
    string Country;
    string Active;

    public:
    /**
     * Airline class constructor
    */
    Airline(int airlineId, string alias, string iata, string icao, string country, string active);

    /**
     * Getters for Airline class
    */

   int getAirlineID();

   string getIATA();

   string getICAO();

   string getCountry();

   string toString();
};