/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file GraphMatrix.cpp
 * @Synopsis Implementation file for a GraphMatrix class
 * @author Tyson Cross, Kulani Nukeri, Kopano Malombo, Vassiliki Marantos, Vulombe Mathebula, Kimita Ramalingum, Mfaniseni Thusi
 * @version 1.0
 * @date 2016-10-10
 */
//

#ifndef GraphMatrix_H
#define GraphMatrix_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Vertex.h"
#include "Edge.h"

class GraphMatrix{
 public:
	GraphMatrix(long int size = 0);
	~GraphMatrix();
	bool isEmpty() const;
	long int numEdges() const;
	long int numVertices() const;
	void addEdge(int vert1, int vert2, double weight);
	void removeEdge(int vert1, int vert2);
	bool isConnected(int vert1, int vert2) const;
	Edge* getEdge(int i, int j);
    //Vertex* getVertex(long int i);
	std::vector<Edge*> getEdgeList();
    void initGraph(int size);
	void display();
 private:
	long int capacity;
	long int sizeOfGraph;
	long int numOfEdges;
	long int numOfVertices;
	Edge*** Edges;

};

#endif /* GraphMatrix_h */
