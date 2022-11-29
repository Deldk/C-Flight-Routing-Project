#include"edge.h"

Edge::Edge(Vertex start, Vertex end, double weight){
    this->startVertex = &start;
    this->destinationVertex = &end;
    this->Weight = weight;
}