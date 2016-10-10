/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file GraphList.cpp
 * @Synopsis Implementation file for a GraphList class
 * @author Tyson Cross, Kulani Nukeri, Kopano Malombo, Vassiliki Marantos, Vulombe Mathebula, Kimita Ramalingum, Mfaniseni Thusi
 * @version 1.0
 * @date 2016-09-28
 */
//

#include <iostream>
#include <algorithm>
#include "GraphList.h"


GraphList::GraphList(int verts){
    vertices.reserve(verts);
    for(int i =0; i < verts; i++){
        Vertex* vertex1 = new Vertex(i);
        vertices.push_back(vertex1);
    }
}

//GraphList::GraphList(const GraphList& obj){};

bool GraphList::isEmpty(){
    return vertices.empty();
}

long int GraphList::numVertices(){
    return vertices.size();
}

long int GraphList::numEdges(){
    return edges.size();
}

void GraphList::addVertex(){
    // make a new vertex, add it to the vertices list
    Vertex* vertex1 = new Vertex(vertices.size());
    vertices.push_back(vertex1);
}

void GraphList::addEdge(int vert1, int vert2, double weight){
    // make a new edge, between the two indices of the vertices list, with specified weight
    // update the relevant vertices, to add this new edge to their connectedEdges list
    bool status = true;
    if ( vert1>numVertices()){
        throw std::out_of_range("First vertex does not exist (out of range), unable to addEdge()");
    }
    if ( vert2>numVertices()){
        throw std::out_of_range("Second vertex does not exist (out of range), unable to addEdge()");
    }
    if (vert1==vert2){
        throw std::logic_error("Vertex cannot connect to itself, unable to addEdge()");
    }
    if (isConnected(vert1, vert2)) {
        std::cerr << "Warning : Vertices " << vertices.at(vert1)->getName() << " and " << vertices.at(vert2)->getName() << " are already connected, unable to addEdge()" << std::endl;
        status = false;
    }
    if (status==true){
        Edge* edge1 = new Edge(vertices.at(vert1), vertices.at(vert2), weight);
        vertices.at(vert1)->addEdge(edge1);
        vertices.at(vert2)->addEdge(edge1);
    }
}

void GraphList::removeEdge(int vert1, int vert2){
    // for the specified verts, find the common edge, then remove the edge from the list of connected edges for both vertices
    // delete the specifed edge
    for (long int i = 0; i < vertices.at(vert1)->numEdges() ; i++){
        for (long int j = 0; j < vertices.at(vert2)->numEdges() ; j++){
            if (vertices.at(vert1)->getEdge(i)==vertices.at(vert2)->getEdge(j)){
                Edge* edge1 = vertices.at(vert1)->getEdge(i);
                edge1->getU()->removeEdge(edge1);
                edge1->getV()->removeEdge(edge1);
                for(long int k = 0; k < numEdges(); k++){
                    if(edges.at(k)==edge1){
                        edges.erase(edges.begin()+k);
                        k = numEdges();
                    }
                }
                delete edge1;
                i = vertices.at(vert1)->numEdges();
                j = vertices.at(vert2)->numEdges();
            }
        }
    }
}

bool GraphList::isConnected(int vert1, int vert2){
    // check the connectedEdges lists for both vertices, to see if there is a common edge
    for (int i = 0; i < vertices.at(vert1)->numEdges() ; i++){
        for (int j = 0; j < vertices.at(vert2)->numEdges() ; j++){
            if (vertices.at(vert1)->getEdge(i) == vertices.at(vert2)->getEdge(j)){
                return true;
            }
        }
    }
    return false;
}

Edge* GraphList::getEdge(int vert1, int vert2){
    Edge* edge1 = NULL;
    for (long int i = 0; i < vertices.at(vert1)->numEdges() ; i++){
        for (long int j = 0; j < vertices.at(vert2)->numEdges() ; j++){
            if (vertices.at(vert1)->getEdge(i) == vertices.at(vert2)->getEdge(j)){
                edge1 = vertices.at(vert1)->getEdge(i);
                i = vertices.at(vert1)->numEdges();
                j = vertices.at(vert2)->numEdges();
            }
        }
    }
    if(edge1==NULL) {
        throw std::out_of_range("Edge does not exist, unable to getEdge()");
    }
    else return edge1;
}

Vertex* GraphList::getVertex(long int i){
    return vertices.at(i);
}

std::vector<Edge*> GraphList::getEdgeList(){
    return edges;
}

void GraphList::display(){
    std::cout << "# Adjacency list: Vertex →Vertex(weight of edge)" << std::endl;
    for (int i =0; i< numVertices(); i++){
        Vertex* vertex1 = vertices.at(i);
        std::cout << i << ":  →";
        for (int j = 0 ; j < vertex1->numEdges(); j++){
            Edge* edge1 = vertex1->getEdge(j);
            Vertex* u = edge1->getU();
            Vertex* v = edge1->getV();
            if ((u != vertex1) && ( v != vertex1)){
                //throw exception
                throw std::out_of_range("Warning : Vertex/edge mismatch at vertex index [" + std::to_string(i) + "] with edge index [" + std::to_string(j) + "]");
            }
            else if(u == vertex1){
                std::cout << v->getName();
                std::cout << "(" << edge1->getWeight() << ") ";
            }
            else if(v == vertex1){
                std::cout << u->getName();
                std::cout << "(" << edge1->getWeight() << ") ";
            }
            if (j+1!=vertex1->numEdges())
            std::cout << "  →";
            }
        std::cout << std::endl;
    }
    std::cout << "#" << std::endl;
}

GraphList::~GraphList(){
    for (int i = 0; i < numEdges(); i++){
        delete edges.at(i);
    }
    for (int i = 0; i < numVertices(); i++){
        delete vertices.at(i);
    }
}
