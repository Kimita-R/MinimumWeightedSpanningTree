
//This is the implementation of prim's algorithm
#include <iostream>
#include <queue>
#include "Edge.h"
#include "Graph_list.h"
#include "Vertex.h"

//By default the priority queue sorts by maximum
//Extra struct reverses this default structure

using namespace std;

struct MinQueue{
    bool operator() (const int& l, const int& r)
    {
        return r <l;
    }
};

struct Key{
    vector<Vertex> vertices;
    vector <int> key;
};

int main()
{

    // Priority Queue needs to store vertex or edge?
   // priority_queue<int, vector<int>, MinQueue> pq;
    priority_queue<Edge, vector<Edge>, MinQueue> pq;
    
   
    //Structure to store values
    Graph_list mstGraph = new Graph_list();
    mstGraph.getNumVertices;
    
    // must be away to get and store these vertices
    //get is visited
    /*for(int i = 0; i < mstGraph.getNumVertices(); i++){
        Key.vertices.push_back = getVertex(i);
        Key.key.push_back = INF;
        
    }
    
    int index = 0;
    Key.vertices(0) = 0;
    
    if(Key.vertices(index)!isVisited(){
        if(isConnect(index, value)){
            pq.push(Vertex(value));
        }
    }
    
       mstGraph += pq.top();
       
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    } */
}