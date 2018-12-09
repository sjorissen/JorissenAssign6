//
// Created by Sarah on 12/1/2018.
//

#include "Graph.hpp"
#include <fstream>

bool is_adjacent(int**, int, int, int);
bool any(bool [], int);

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


// Copy constructor implementation
Graph::Graph(const Graph &graph) {
    copyFrom(graph);
}

// Destructor implementation
Graph::~Graph() {
    deallocate();
}

// Overloaded assignment operator implementation
//const Graph::Graph & operator=(const Graph &graph) {
//
//}

bool Graph::addEdge (int sourceVertex, int targetVertex, int weight) {
    if(sourceVertex > mNumVertices || sourceVertex < 0) {
        return false;
    }
    else if(targetVertex > mNumVertices || targetVertex < 0) {
        return false;
    }
    else if(weight < 0) {
        return false;
    }
    else {
        mMatrix[sourceVertex][targetVertex] = weight;
        mMatrix[targetVertex][sourceVertex] = weight;
        return true;
    }
}

void Graph::shortestPaths (int sourceVertex, int currDist[], int predecessor[]) {
    bool toBeChecked[mNumVertices];

    for(int i = 0; i < mNumVertices; i++) {
        toBeChecked[i] = true;
    }

    for (int i = 0; i < mNumVertices; i++) {
        currDist[i] = MAX_WEIGHT;
    }

    currDist[sourceVertex] = 0;

    //v <-vertex intoBeCheckedwith minimalcurrDist[v]

    while(any(toBeChecked, mNumVertices)) {
        //v <-vertex in toBeChecked with minimal currDist[v]
        int toVisit = -1;
        int smallestChecked = MAX_WEIGHT;
        for (int i = 0; i < mNumVertices; i++) {
            if (toBeChecked[i]) {
                if (currDist[i] < smallestChecked) {
                    toVisit = i;
                    smallestChecked = currDist[toVisit];
                }
            }
        }
        toBeChecked[toVisit] = false;
        //for all vertices u adjacent to v and in toBeChecked do
        for (int u = 0; u < mNumVertices; u++) {
            if (toBeChecked[u] && is_adjacent(mMatrix, toVisit, u, MAX_WEIGHT)) {
                if (currDist[u] > currDist[toVisit] + mMatrix[u][toVisit]) {
                    currDist[u] = currDist[toVisit] + mMatrix[u][toVisit];
                    predecessor[u] = toVisit;
                }
            }
        }
    }
}

void Graph::copyFrom(const Graph &graph) {
    mNumVertices = graph.mNumVertices;

    mMatrix = new int *[mNumVertices];
    for (int row = 0; row < mNumVertices; row++) {
        mMatrix[row] = new int[mNumVertices];
    }

    for(int i = 0; i < mNumVertices; i++) {
        for(int j = 0; j < mNumVertices; j++) {
            mMatrix[i][j] = graph.mMatrix[i][j];
        }
    }
}

void Graph::deallocate() {
    for(int row = 0; row < mNumVertices; row++) {
        delete [] mMatrix[row];
    }
    delete mMatrix;
}

void Graph::displayMatrix() {
    for(int i = 0; i < mNumVertices; i++) {
        for(int j = 0; j < mNumVertices; j++) {
            std::cout  << std::setw(4) << mMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool is_adjacent(int **matrix, int row, int col, int max_weight) {
    return matrix[row][col] != max_weight;
}

bool any(bool arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i]) {
            return true;
        }
    }
    return false;
}