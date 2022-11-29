#include"airports.h"
#include"airlines.h"
#include"routes.h"
#include"graph.h"
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

string pre_path = "-insert absolute path here-";

/**
 * Vectors for airport, airline, and route objects
*/
vector<Airport> airports;
vector<Airline> airlines;
vector<Route> routes;

/**
 * Map storing a key value pair of airports and the airports
 * they can get to
*/
map<string, vector<Airport>> map_airport;
map<string, vector<Airport>>::iterator it_dict;

/**
 * Map storing the key value pair of a source code and a list 
 * of routes 
*/
map<string, vector<Route>> map_route;
map<string, vector<Route>>::iterator it_route;

/**
 * Graph to be used for the adjacency matrix
*/



void read_AirportData(){
    string input_airportID, input_name, input_city, input_country, input_iata, input_icao, input_latitude, input_longitude;

    ifstream file;
    file.open(pre_path + "airports.csv"); //Opening the airports file for reading
    if (file.fail()){ // checking if file opening failed
        cout << " File could not be opened...";
    }

    string line = "";
    getline(file, line);
    while(getline(file, line)){
        stringstream stream(line);
        getline(stream, input_airportID, ',');
        getline(stream, input_name, ',');
        getline(stream, input_city, ',');
        getline(stream, input_country, ',');
        getline(stream, input_iata, ',');
        getline(stream, input_icao, ',');
        getline(stream, input_latitude, ',');
        getline(stream, input_longitude, ',');
    
        if (input_city == "\\N" || input_city == "")
            input_city = "Not available";

        if (input_country == "\\N" || input_country == "")
            input_country = "Not available";

        if (input_iata == "\\N" || input_iata == "")
            input_iata = "Not available";

        if (input_icao == "\\N" || input_icao == "")
            input_icao = "Not available";

        if (input_latitude == "\\N" || input_latitude == "")
            input_latitude = "Not available";


        int integer_airportID = stoi(input_airportID);

        Airport airport(integer_airportID, input_name, input_city, input_country, input_iata, input_icao, input_latitude, input_longitude);
        airports.push_back(airport);

        string key = airport.getCity() + "- " + airport.getCountry();

        it_dict = map_airport.find(key);
        if (it_dict != map_airport.end()){
            it_dict->second.push_back(airport);

        }else{

        vector<Airport> vector_of_airports;
        vector_of_airports.push_back(airport);
        map_airport.insert({key, vector_of_airports});
        }
    }

}

void read_AirlineData(){
    string input_airlineId, input_alias, input_iata, input_icao, input_country, input_active;
    ifstream file;
    file.open(pre_path + "airlines.csv"); //Opening the airlines file for reading
    if (file.fail()){ // checking if file opening failed
        cout << " File could not be opened...";
    }

    string line = "";
    getline(file, line);
    while(getline(file, line)){
        stringstream stream(line);
        getline(stream, input_airlineId, ',');
        getline(stream, input_alias, ',');
        getline(stream, input_iata, ',');
        getline(stream, input_icao, ',');
        getline(stream, input_country, ',');
        getline(stream, input_active, ',');

        if (input_iata == "\\N" || input_iata == "")
            input_iata = "Not available";

        if (input_country == "\\N" || input_country == "")
            input_country = "Not available";

        if (input_active == "\\N" || input_active == "")
            input_active = "Not available";

        int integerAirlineID = stoi(input_airlineId);
        Airline airline(integerAirlineID, input_alias, input_iata, input_icao, input_country, input_active);
        airlines.push_back(airline);

    }
}

void read_RouteData(){
    string input_airline_code, input_airline_ID, input_source_airport_code, input_source_airport_ID, input_destination_airport_code, input_destination_airport_ID, input_codeShare, input_stops;
    ifstream file;
    file.open(pre_path + "routes.csv"); //Opening the routes file for reading
    if (file.fail()){ // checking if file opening failed
        cout << " File could not be opened...";
    }

    string line = "";
    getline(file, line);
    while(getline(file, line)){
        stringstream stream(line);
        getline(stream, input_airline_code, ',');
        getline(stream, input_airline_ID, ',');
        getline(stream, input_source_airport_code, ',');
        getline(stream, input_source_airport_ID, ',');
        getline(stream, input_destination_airport_code, ',');
        getline(stream, input_destination_airport_ID, ',');
        getline(stream, input_codeShare, ',');
        getline(stream, input_stops, ',');

        if (input_airline_ID == "\\N" || input_airline_ID == "")
            input_airline_ID = "0";

        if (input_source_airport_code == "\\N" || input_source_airport_code == "")
            input_source_airport_code = "Not available";

        if (input_destination_airport_code == "\\N" || input_destination_airport_code == "")
            input_destination_airport_code = "Not available";

        if (input_source_airport_ID == "\\N" || input_source_airport_ID == "")
            input_source_airport_ID = "0";

        if (input_destination_airport_ID == "\\N" || input_destination_airport_ID == "")
            input_destination_airport_ID = "0";

        int integerAirlineID = stoi(input_airline_ID);
        int integerSourceID = stoi(input_source_airport_ID);
        int integerDestinationID = stoi(input_destination_airport_ID);
        Route route(input_airline_code, integerAirlineID, input_source_airport_code, integerSourceID, input_destination_airport_code, integerDestinationID, input_codeShare, input_stops);
        routes.push_back(route);

        it_route = map_route.find(route.getsource_AirportCode());
        if (it_route != map_route.end()){
            it_route->second.push_back(route);

        }else{

        vector<Route> vector_of_routes;
        vector_of_routes.push_back(route);
        map_route.insert({route.getsource_AirportCode(), vector_of_routes});
        }
    }
}




vector<string> readInputFile(){
    string cities [2];
    string countries[2];
    vector<string> city_country;

    ifstream file;
    file.open(pre_path + "inputFile.txt");

    if (file.fail()) {
        cout << "Couldn't open the file!" << endl;
    }

    int count = 0;
    string line = "";
    while (getline(file, line)){
        string city;
        string country ;
        stringstream inputString(line);
        getline(inputString,city, ',');
        getline(inputString, country, ',');

        cities[count] = city;
        countries[count] = country;

        count++;
    }

    file.close();
    city_country.push_back(cities[0]);
    city_country.push_back(cities[1]);
    city_country.push_back(countries[0]);
    city_country.push_back(countries[1]);
    return city_country;
}

/**
 *
 * @param city_country This is a vector of source and destination cities and countries
 * @return source_Airports This will be a vector of source airport IDs
 */
vector<int> getSourceID(vector<string> city_country){
    vector<int> source_Airports;
    string start_location = city_country[0] + "-" + city_country[2];
   string source_key = start_location;
   for (auto [key, airport] : map_airport){
       if(key == source_key){
           for (int i = 0; i < airport.size(); i++){
               source_Airports.push_back(airport[i].getID());
           }
       }
   }

    return source_Airports;
}

/***
 *
 * @param city_country This is a vector of source and destination cities and countries
 * @return destination_Airports This will be a vector of destination airport IDs
 */
vector<int> getDestinationID(vector<string> city_country){
    vector<int> destination_Airports;
    string destination_location = city_country[1] + "-" + city_country[3];
    string source_key = destination_location;
    for (auto [key, airport] : map_airport){

        if(key == source_key){
            for (auto air : airport){
            }
            for (int i = 0; i < airport.size(); i++){
                destination_Airports.push_back(airport[i].getID());
            }
        }
    }
    return destination_Airports;
}

/***
 *
 * @param paths_found This is a vector of vectors containing different solution paths
 * @return valid_path This is a vector of one valid path consisting of the airports codes
 */
vector<string> getValidPath(vector<vector<string>> paths_found){
    vector<string> valid_path;
    for (auto path : paths_found){
        if (path.size() > 1) {
            for (auto pa: path) {
                valid_path.push_back(pa);
            }
            return valid_path;
        }
    }
}

/***
 *
 * @param path
 * @param source
 * @param destination
 */
void writeToFile(vector<string> path, string source, string destination){
    ofstream output;
    output.open(pre_path + source + "-" + destination + "_output.txt");
    string previous_sourceCode = "None";
    int flight_no = 1;
    int total_stops = 0;

    for (int i = 0; i < path.size(); i++){
        if (i != path.size() - 1){
            for (auto [key , value] : map_route){
                for (auto route : value){
                   if (route.getsource_AirportCode() == path[i] && route.getdestination_AirportCode() == path[i+1]) {
                       if (route.getsource_AirportCode() == previous_sourceCode){
                           continue;
                       }else {
                           output << "\t" << flight_no << ". " << route.getAirlineCode() << " from " << route.getsource_AirportCode() << " to "
                                << route.getdestination_AirportCode() << " " << route.getStops() << " stops " << endl;
                            previous_sourceCode = route.getsource_AirportCode();
                            flight_no++;
                            total_stops += stoi(route.getStops());
                       }
                   }
                }
            }
        }
    }
    output << "Total flights: " << flight_no - 1 << endl;
    output << "Total additional stops: " << total_stops;
    output.close();
    cout << "Done" << endl;
}

int main(){
    // read files
    read_AirportData();
    read_AirlineData();
    read_RouteData();

    vector<string> fileInput = readInputFile();

    vector<int> SourceIDs = getSourceID(fileInput);
    vector<int> DestinationIDs = getDestinationID(fileInput);

    // making the graph
    Graph graph;
    for(auto [key, value] : map_airport){
        for(Airport airport : value){
            if (airport.getIATA() == "Not available"){
                continue;
            }
            int airportID = airport.getID();
            string IATA = airport.getIATA();
            graph.addVertex(airportID, IATA);
        }
    }

    // adding the edges
    for (auto [key , value] : map_route){
        for(auto route : value){
            if(route.getsource_AirportCode() != "Not available" &&
               route.getsource_AirportID() != 0 &&
               route.getdestination_AirportCode() != "Not available" &&
               route.getdestination_AirportID() != 0){

                int sourceID = route.getsource_AirportID();
                int destinationID = route.getdestination_AirportID();
                if(sourceID != destinationID){
                    graph.addEdge(sourceID, destinationID, 1);
                }
            }
        }
    }

vector<vector<string>> all_possible_paths;
    for (int sourceID : SourceIDs){
        for (int destinationID : DestinationIDs){
            vector<string> solution = graph.findPath(sourceID, destinationID);
            all_possible_paths.push_back(solution);
        }
    }
    vector<string> valid_path = getValidPath(all_possible_paths);
    writeToFile(valid_path, fileInput[0], fileInput[1]);

    return 0;
}