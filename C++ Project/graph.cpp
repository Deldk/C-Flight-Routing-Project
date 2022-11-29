#include"graph.h"

Graph::Graph(){
    /**
     * Making the adjacency matrix using a 2D array
    */
    this->adjacencyMatrix = new int* [max_vertices];
    for(int i = 0; i < max_vertices; i++){
        adjacencyMatrix[i] = new int [max_vertices];
    }
}


void Graph::addVertex(int id, string name){
    vertices.emplace_back(id, name);
    no_vertex++;
}


string Graph::getVertexName(int source_id){
    for(int i = 0; i < no_vertex; i++){
        if (source_id == vertices[i].getID()){
            return vertices[i].getName();
        }
    }
    return "None";
}

void Graph::addEdge(int source_id, int destination_id, double weight){
    if (source_id != destination_id){
        adjacencyMatrix[source_id][destination_id] = weight;
        no_edges++;
    }
}


bool Graph::isAdjacent(int source_id, int destination_id) const{
    if (adjacencyMatrix[source_id][destination_id] != 0){
        return true;
    }
    return false;
}

vector<int> Graph::getChildren(int source_id){
    vector<int> Children;
    for (int i = 0; i < no_vertex; i++){
        if (isAdjacent(source_id, vertices[i].getID())){
            Children.push_back(vertices[i].getID());
        }
    }
    return Children;
}

/***
 *
 * @param destination_id
 * @return returns a path containing the airport codes leading from the source to the
 * destination
 */
vector<string> Graph::solutionPath(int destination_id){
    vector<string> path_found;
    path_found.push_back(getVertexName(destination_id));
    int current = destination_id;


    while (predecessors.find(current) != predecessors.end()){
        current = predecessors.find(current)->second;

        if(current == 0){
            break;
        }
        path_found.push_back(getVertexName(current));

    }
    reverse(path_found.begin(), path_found.end());
    return path_found;
}

/***
 *
 * @param source_id
 * @param destination_id
 * @return A vector containing a path from the source to the destination
 */
vector<string> Graph::findPath(int source_id, int destination_id){
    predecessors.insert({source_id, 0});

    if (source_id == destination_id){
        return solutionPath(destination_id);
    }

    set<int> explored;
    std::list<int> frontier;
    frontier.push_back(source_id);


    while (!frontier.empty()){
        int current = frontier.front();
        frontier.pop_front();
        explored.insert(current);

        if (current == destination_id){
//            cout << "path found" << endl;
            return solutionPath(current);
        }

        vector<int>Children = getChildren(current);

        for (auto child : Children){
            bool frontier_found = std::find(frontier.begin(), frontier.end(), child) != frontier.end();
            bool explored_found = std::find(explored.begin(), explored.end(), child) != explored.end();
            if (!frontier_found && !explored_found) {

                iterate = predecessors.begin();
                for( ; iterate != predecessors.end(); iterate ++){
                    if(iterate->first != child){
                        predecessors.insert({child,current});
                    }else{
                        predecessors[child] = current;
                    }
                }
                frontier.push_back(child);
            }
        }
    }
    return solutionPath(destination_id);

}