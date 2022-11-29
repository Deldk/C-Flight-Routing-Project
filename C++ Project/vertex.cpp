#include"vertex.h"

Vertex::Vertex(int id, string name){
    ID = id;
    Name = name;
}

int Vertex::getID(){
    return ID;
}

string Vertex::getName(){
    return Name;
}

string Vertex::toString(){
    string string_ID = to_string(ID);
    return "ID: " + string_ID + " Name: " + Name;
}