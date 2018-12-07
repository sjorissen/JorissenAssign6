// Nicholas Coleman
// CSCI 3250
// Programming Assignment 6
// Header file for Graph class

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <iomanip>

// The Graph class represents a weighted directed graph using an adjacency matrix
class Graph {

 public:
  
  // Constructor
  Graph( int numVertices );

  // Copy Constructor
  Graph( const Graph &);
  
  // Destructor
//  ~Graph( );

  // Overloaded Assignment Operator
  const Graph & operator=(const Graph &);

  // Adds an edge to the graph
  // Returns false if vertices are out of range or weight is negative
  bool addEdge( int sourceVertex, int targetVertex, int weight );
  
  // Computes the shortest paths from source_vertex to all other vertices
  // using Dijkstra's shortest path algorithm
  // Distances are stored in currDist
  // Predecessors in path are stored in predecessor
  void shortestPaths( int sourceVertex, int currDist[], int predecessor[] );

  // Displays the contents of the adjacency matrix
  void displayMatrix();

 private:

  // The number of vertices in the graph
  int mNumVertices;

  // The adjacency matrix for the graph
  int** mMatrix;

  // The maximum weight for an edge in the graph (used for non-adjacent vertices)
  static const int MAX_WEIGHT = 9999;

  // Deallocate the matrix
  void deallocate();

  // Copy data from an existing Graph object
  void copyFrom(const Graph &);
};

#endif
