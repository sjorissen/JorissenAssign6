#include <iostream>
#include <fstream>
#include <string>

#include "Graph.hpp"
#include "helpers.h"


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
    graph.displayMatrix();
}