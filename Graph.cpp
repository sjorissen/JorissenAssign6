//
// Created by Sarah on 12/1/2018.
//

#include "Graph.hpp"
#include <fstream>

int search_array(std::string [], std::string, int, int);

// Constructor implementation
Graph::Graph(int numVertices) {
    mNumVertices = numVertices;


    // Constructs two-dimensional array
    mMatrix = new int *[numVertices];
    for (int row = 0; row < numVertices; row++) {
        mMatrix[row] = new int[numVertices];
    }

    // Fill matrix with MAX_WEIGHT & 0 so only vertices with edges overwrite intended coordinate
    for(int i = 0; i < mNumVertices; i++) {
        for(int j = 0; j < i; j++) {
            mMatrix[i][j] = MAX_WEIGHT;
        }
        mMatrix[i][i] = 0;
        for(int j = i+1; j < mNumVertices; j++) {
            mMatrix[i][j] = MAX_WEIGHT;
        }
    }
}


//// Copy constructor implementation
//Graph::Graph(const Graph &gcopy) {
//
//}

bool Graph::addEdge (int sourceVertex, int targetVertex, int weight) {
    mMatrix[sourceVertex][targetVertex] = weight;
    mMatrix[targetVertex][sourceVertex] = weight;
}

void Graph::shortestPaths (int sourceVertex, int currDist[], int predecessor[]) {

}

void Graph::copyFrom(const Graph &gcopy) {

}

void Graph::deallocate() {

}

void Graph::displayMatrix() {
    for(int i = 0; i < mNumVertices; i++) {
        for(int j = 0; j < mNumVertices; j++) {
            std::cout  << std::setw(4) << mMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}