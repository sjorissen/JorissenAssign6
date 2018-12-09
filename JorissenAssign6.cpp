#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Graph.hpp"
//#include "helpers.h"

int search_array(std::string [], std::string, int, int);
int pred_traverse(int [], std::string [], int, int, int);

int main() {
    int numVertices;
    std::ifstream distance_file;
    distance_file.open("distances.txt");
    distance_file >> numVertices;

    Graph graph(numVertices);

    auto *cities = new std::string[numVertices];
    // Reads file and builds array of vertices (cities)
    if (distance_file.is_open()) {
        for (int i = 0; i < numVertices; i++) {
            distance_file >> cities[i];
        }
    }
    int numRows, numCols, counter, dist, cities_row, cities_col;
    std::string city1, city2;
    cities_row = cities_col = 0;
    distance_file >> counter;

    for(int i = 0; i < counter; i++) {
        distance_file >> city1;
        distance_file >> city2;
        distance_file >> dist;

        cities_row = search_array(cities, city1, cities_row, cities_row + 1);
        cities_col = search_array(cities, city2, cities_row + 1, numVertices);

        // Store dist value where cities intersect on matrix
        graph.addEdge(cities_row, cities_col, dist);
    }
    distance_file.close();
//    graph.displayMatrix();

    std::string start = "Nashville";
    std::string end = "Columbus";

    int sourceVertex = search_array(cities,start,0,numVertices);
    int endVertex = search_array(cities,end,0,numVertices);

    int predecessor[numVertices];
    int currDist[numVertices];

    graph.shortestPaths(sourceVertex, currDist, predecessor);

    for (int i = 0; i < numVertices; i++) {
        pred_traverse(predecessor, cities, i, sourceVertex, currDist[i]);
//        pred_traverse(predecessor, cities, 1, sourceVertex);
//        pred_traverse(predecessor, cities, 2, sourceVertex);
//        pred_traverse(predecessor, cities, 3, sourceVertex);
//        pred_traverse(predecessor, cities, 4, sourceVertex);
//        pred_traverse(predecessor, cities, 5, sourceVertex);
//        pred_traverse(predecessor, cities, 6, sourceVertex);
//        pred_traverse(predecessor, cities, 7, sourceVertex);
//        std::cout << std::endl;
    }



}

int search_array(std::string cities_arr[], std::string city, int start, int end) {
    for(int i = start; i <= end; i++) {
        if(cities_arr[i] == city) {
            return i;
        }
    }
    return -1;
}

int pred_traverse(int predecessor [], std::string cities_arr[], int endVertex, int sourceVertex, int dist) {
    if(endVertex == sourceVertex) {
        return -1;
    }
    int _predecessor = endVertex;
    std::vector<int> cities_path;
    while (_predecessor != sourceVertex){
        cities_path.push_back(_predecessor);
        _predecessor = predecessor[_predecessor];

    }

    std::cout << cities_arr[endVertex] << " " << dist << " ";
    std::cout << cities_arr[sourceVertex] << " -> ";
    for (int i = (int) cities_path.size() - 1; i > 0; i--){
        std::cout << cities_arr[cities_path[i]] << " -> ";
    }
    std::cout << cities_arr[cities_path[0]] << std::endl;
    return _predecessor;
}