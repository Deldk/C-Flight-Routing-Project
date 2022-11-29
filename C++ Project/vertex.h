#include<string>
#pragma once
using namespace std;

class Vertex{
    public:
    int ID;
    string Name;
    Vertex(int id, string name);

    int getID();

    string getName();

    string toString();
};