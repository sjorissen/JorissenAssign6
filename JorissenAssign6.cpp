// Sarah Jorissen
// CSCI 3250
// Programming Assignment 6
// Main function; asks user for a starting city
// and displays shortest path to all other cities

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

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

    // Fills matrix with the distance between cities from the file
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

    int starting_city;

    std::cout << "Please choose a starting city:" << std::endl;
    std::cout << "0 - Atlanta\n1 - Birmingham\n2 - Charlotte\n3 - Chattanooga\n";
    std::cout << "4 - Charleston(WV)\n5 - Cincinnati\n6 - Columbus\n7 - Indianapolis\n";
    std::cout << "8 - Knoxville\n9 - Lexington\n10 - Louisville\n11 - Memphis\n";
    std::cout << "12 - Nashville\n13 - StLouis" << std::endl << std::endl;

    std::cin >> starting_city;

    std::string start = "Nashville";
    std::string end = "Columbus";

    int predecessor[numVertices];
    int currDist[numVertices];

    graph.shortestPaths(starting_city, currDist, predecessor);

    std::cout << std::setw(20) << std::left << "City" << std::setw(6) << "Dist" << " " << "Route" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < numVertices; i++) {
        pred_traverse(predecessor, cities, i, starting_city, currDist[i]);
    }
}

// Takes a city name and returns its corresponding index number
int search_array(std::string cities_arr[], std::string city, int start, int end) {
    for(int i = start; i <= end; i++) {
        if(cities_arr[i] == city) {
            return i;
        }
    }
    return -1; // City cannot be found in array
}

// Builds & prints the shortest path taken between two cities
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

    std::cout << std::setw(20) << std::left << cities_arr[endVertex] << " " << std::setw(5);
    std::cout << dist << " ";
    std::cout << cities_arr[sourceVertex] << " -> ";
    for (int i = (int) cities_path.size() - 1; i > 0; i--){
        std::cout << cities_arr[cities_path[i]] << " -> ";
    }
    std::cout << cities_arr[cities_path[0]] << std::endl;
    return _predecessor;
}