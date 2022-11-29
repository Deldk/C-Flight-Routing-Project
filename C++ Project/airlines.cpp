#include"airlines.h"
using namespace std;


Airline::Airline(int airlineId, string alias, string iata, string icao, string country, string active){
    this->AirlineID = airlineId;
    this->Alias = alias;
    this->IATA = iata;
    this->ICAO = icao;
    this->Country = country;
    this->Active = active;
}

int Airline::getAirlineID(){
    return AirlineID;
}

string Airline::getIATA(){
    return IATA;
}

string Airline::getICAO(){
    return ICAO;
}

string Airline::getCountry(){
    return Country;
}

string Airline::toString(){
    string string_AirlineID = to_string(AirlineID);
    return "This is Airline ID: " + string_AirlineID + " IATA: " + IATA + " in Country: " + Country;
}
