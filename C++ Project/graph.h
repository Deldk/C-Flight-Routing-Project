#include<iostream>
#include<string>
#include <map>
#include <vector>
#include"airports.h"
#include"airlines.h"
#include"routes.h"
#include"vertex.h"
#include"edge.h"
#include<set>
#include<list>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Graph{
    public:
    int no_vertex = 0;
    int no_edges = 0;
    int max_vertices = 15000;

    vector<Vertex> vertices;
    unordered_map<int, int> predecessors;
    unordered_map<int, int>:: iterator iterate;
    int **adjacencyMatrix;

    Graph();

    void addVertex(int id, string name);

    void addEdge(int source_id, int destination_id, double weight);

    bool isAdjacent(int source_id, int destination_id) const;

    vector<int> getChildren(int source_id);
    vector<string> solutionPath(int destination_id);
    vector<string> findPath(int source_id, int destination_id);

    private:
    string getVertexName(int source_id);

};


