#include"routes.h"


Route::Route(string airline_code, int airline_ID, string source_airport_code, int source_airport_ID, string destination_airport_code, int destination_airport_ID, string codeshare, string stops){
    this->AirlineCode = airline_code;
    this->AirlineID = airline_ID;
    this->source_AirportCode = source_airport_code;
    this->source_AirportID = source_airport_ID;
    this->destination_AirportCode = destination_airport_code;
    this->destination_AirportID = destination_airport_ID;
    this->codeShare = codeshare;
    this->Stops = stops;
}

/**
 * Getters for Route class
*/

string Route::getAirlineCode(){
    return AirlineCode;
}

int Route::getAirlineID(){
    return AirlineID;
}

string Route::getsource_AirportCode(){
    return source_AirportCode;
}

int Route::getsource_AirportID(){
    return source_AirportID;
}

string Route::getdestination_AirportCode(){
    return destination_AirportCode;
}

int Route::getdestination_AirportID(){
    return destination_AirportID;
}

string Route::getStops(){
    return Stops;
}

string Route::toString(){
    string stringSourceID = to_string(source_AirportID);
    string stringDestinationID = to_string(destination_AirportID);
    return "This flight is from: " + stringSourceID + " to " + stringDestinationID;
}
