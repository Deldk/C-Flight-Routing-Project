#include<string>
#include"vertex.h"
using namespace std;

class Edge{
    public:
    Vertex *startVertex;
    Vertex *destinationVertex;
    double Weight = 0;

    Edge(Vertex start_vertex, Vertex end_vertex, double weight);
};