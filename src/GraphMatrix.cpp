/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file GraphMatrix.cpp
 * @Synopsis Implementation file for a GraphMatrix class
 * @author Tyson Cross, Kulani Nukeri, Kopano Malombo, Vassiliki Marantos, Vulombe Mathebula, Kimita Ramalingum, Mfaniseni Thusi
 * @version 1.0
 * @date 2016-10-10
 */
//

#include <stdio.h>
#include <stdlib.h>
#include "GraphMatrix.h"

//removed operator overloader that conflicts with Edge*** GraphMatrix::Edges from Edge
GraphMatrix::GraphMatrix(long int size){
	numOfEdges = 0;
	numOfVertices = size;
	capacity = (size*(size-1))/2;
    if(capacity>0){
        Edges = new Edge**[capacity];
        for(int i = 0;i<capacity;i++){
            Edges[i] = new Edge*[capacity];
        }
    }
    if(capacity>0){
        for(int i=0;i<capacity;i++){
            for(int j=0;j<capacity;j++){
                Edges[i][j] = NULL;
            }
        }
    }
}

bool GraphMatrix::isEmpty() const{
	if(numOfEdges==0) return true;
	else return false;
}

long int GraphMatrix::numEdges() const{
	return numOfEdges;
}
long int GraphMatrix::numVertices() const{
	return numOfVertices;
}

void GraphMatrix::addEdge(int vert1, int vert2, double weight){
    //add extra feature that ensures that vert2>vert1 and never less to avoid duplication; if !(vert2>vert1) it should return an error that edge already exist
	if(!(vert1>capacity)&&!(vert2>capacity)){
		if(capacity>0&&!(numOfEdges>capacity)){
			//pointers	
			Vertex* v1;
			Vertex* v2;
			//point pointers to initilised obj with constructor
			Vertex vertx1(vert1), vertx2(vert2);
			v1 = &vertx1, v2 = &vertx2;
            Edge* edge1 = new Edge(v1, v2, weight);
			//addEdge
			Edges[vert1][vert2] = edge1;
			numOfEdges++;
		}
		else{
			if(!(capacity>0)){
				throw ("Graph not initialised: The graph needs to be initialised with 'initGraph(int size)' member function");
			}
			else{
                throw std::out_of_range("Graph exceeding capacity: The maximum number of edges has been reached; can no longer add edges");
			}
		}
	}
	else{
		throw std::out_of_range("The vertices are out of the range defined by capacity of the graph");
	}
}

void GraphMatrix::removeEdge(int i, int j){
	if(!(i>capacity)&&!(j>capacity)){
		if(numOfEdges>0){
			Edge* temp = Edges[i][j];
			Edges[i][j] = NULL;
			delete temp;
			numOfEdges--;
		}
		else{
			throw std::logic_error("The Graph is empty; cannot delete edges");
		}
	}
	else{
		throw std::out_of_range("The indices are out of bound defined by the capacity of the graph");
	}
}

void GraphMatrix::initGraph(int size){
	capacity = (size*(size-1))/2;
	if(capacity>0){
	Edges = new Edge**[capacity];
		for(int i = 0;i<capacity;i++){
			Edges[i] = new Edge*[capacity];
		}	
	}
	if(capacity>0){
		for(int i=0;i<capacity;i++){
			for(int j=0;j<capacity;i++){

				Edges[i][j] = NULL;
			}
		}
	}
}

bool GraphMatrix::isConnected(int vert1, int vert2) const{
	if(Edges[vert1][vert2]!=NULL){
		return true;
	}
	else{
		return false;	
	}
}

Edge* GraphMatrix::getEdge(int i, int j){
	return Edges[i][j];
}

//sorting algorithm
//within the graph; returns a sorted list of Edges
std::vector<Edge*>  GraphMatrix::getEdgeList(){
	std::vector<Edge*> EdgeList;
	EdgeList.reserve(numOfEdges);
	//extract edges from graph
	for(int i=0; i<capacity;i++){
		for(int j=0; j<capacity;j++){
			if(Edges[i][j]!=NULL){
				EdgeList.push_back(Edges[i][j]);
			}
		}
	}
	//apply sorting algorithm on EdgeList
	
	//return a sorted list of Edges
	return EdgeList;
}

//void GraphMatrix::display(){
//	std::vector<Vertex*> Vertices;
//	Vertices.reserve(capacity);
//	//extract vertices and their adjacent vertices
//	for(int i=0;i<capacity;i++){
//		Vertex u(i);
//		Vertex* v1 = &u;
//		for(int j=0;j<capacity;j++){
//			if(Edges[i][j]!=NULL){
//				v1->addEdge(Edges[i][j]);
//			}
//		}
//		Vertices.push_back(v1);
//	}
//	//display the Vertice
//}

void GraphMatrix::display(){
    std::cout << "# Adjacency Matrix: By edges ( currently not correctly displayed)" << std::endl;
    // need to used the std::fixed output
    for(int i=0;i<numVertices();i++){
        std::cout<<"| "<<i<<" ";
    }
    std::cout<<std::endl;
    for(int i=0;i<numVertices();i++){
        std::cout<<i<<"| ";
        for(int j=0;j<numVertices();j++){
            if(Edges[i][j]==NULL){
                std::cout<<" ∅ |";
            }
            else {
                std::cout << " " <<Edges[i][j]->getWeight()<<"|";
            }
        }
        std::cout<<std::endl;
    }
}

GraphMatrix::~GraphMatrix(){
	for(int i=0; i < capacity; i++){
		for(int j=0; j < capacity; j++){
			delete Edges[i][j];
		}
		delete[] Edges[i];
	}
	delete[] Edges;
}
