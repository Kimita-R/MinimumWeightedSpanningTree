#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
#include <stdio.h>
#include <vector>
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
using namespace std;

class GraphMatrix{
 public:
	GraphMatrix(long int size = 0);
	~GraphMatrix();
	bool isEmpty();
	long int numEdges() const;
	long int numVertice() const;
	void addEdge(int vert1, int vert2, double weight);
	void removeEdge(int i, int j);//long int ->int:remove Vertex::long int name into int name
	void initGraph(int size);
	bool isConnected(int vert1, int vert2);
	Edge* getEdge(int i, int j);
	vector<Edge*> getEdgeList();//getEdgeList()
	//or
	void display();
 private:
	int capacity;//change the use of capacity into (capacity^2)/2 to designate space entries  available. 
	int sizeOfGraph;
	int numOfEdges;
	int numOfVertice; 
	Edge*** Edges;

};
//add:
//numVertice
//

#endif 
