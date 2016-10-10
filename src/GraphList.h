/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file GraphList.h
 * @Synopsis Definition file for a GraphList class
 * @author Tyson Cross, Kulani Nukeri, Kopano Malombo, Vassiliki Marantos, Vulombe Mathebula, Kimita Ramalingum, Mfaniseni Thusi
 * @version 1.0
 * @date 2016-09-28
 */

#ifndef GraphList_h
#define GraphList_h

#include <stdio.h>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

class GraphList{
public:
    GraphList(int verts = 0);
    ~GraphList();
    bool isEmpty() const;
    long int numVertices() const;
    long int numEdges() const;
    void addEdge(int vert1, int vert2, double weight);
    void removeEdge(int vert1, int vert2);
    bool isConnected(int vert1, int vert2) const;
    Edge* getEdge(int i, int j);
    Vertex* getVertex(long int i);
    std::vector<Edge*> getEdgeList();
    void display();
private:
    void addVertex();
    std::vector<Vertex*> vertices;
    std::vector<Edge*> edges;
};

#endif /* GraphList_h */
