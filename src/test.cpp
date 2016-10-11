//
//  test.cpp
//  MaxSubArray test file
//
//  Created by Tyson on 2016/9/27.
//  Copyright © 2016 Tyson Cross. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdexcept>
#include "GraphList.h"
#include "GraphMatrix.h"

using namespace std;

int main(void){
    //srand(double(time(NULL)));

    const string fileInName = "../../data/sparse.dat";
    //const string fileInName = "../../data/dense.dat";

    ifstream input(fileInName, ios::in);

    // error checking
    if (!input.is_open()) { cout << "Unable to open file:" << fileInName << endl; return -1;}

    // Read in file
    string line;
    int numVertex, numEdge, vert1, vert2;
    long int linesCount = 0;
    double weight;

    // Get no. of lines in the file.
    while (getline(input, line)) linesCount++;
    input.clear();
    input.seekg(0, ios::beg);
    long int linesReduce = linesCount;

    // read in an build graph, while there is data to read
    while (linesReduce>1) {
        getline(input, line);
        istringstream ss_1(line);
        ss_1 >> numVertex;
        linesReduce--;
        getline(input, line);
        istringstream ss_2(line);
        ss_2 >> numEdge;
        linesReduce--;

        GraphList* g = new GraphList(numVertex);
        for (int i = 0; i < numEdge; i++) {
            getline(input, line);
            linesReduce--;
            istringstream ss(line);
            ss >> vert1 >> vert2 >> weight;
            g->addEdge(vert1, vert2, weight);
        };

        // Do something with the graph here....
        g->display();

        delete g;
    };

    std::cout << "========================================================" << std::endl;

    //test Matrix implementation....
    input.clear();
    input.seekg(0, ios::beg);
    linesReduce = linesCount;

    // read in an build graph, while there is data to read
    while (linesReduce>1) {
        getline(input, line);
        istringstream ss_1(line);
        ss_1 >> numVertex;
        linesReduce--;
        getline(input, line);
        istringstream ss_2(line);
        ss_2 >> numEdge;
        linesReduce--;

        GraphMatrix* g1 = new GraphMatrix(numVertex);
        for (int i = 0; i < numEdge; i++) {
            getline(input, line);
            linesReduce--;
            istringstream ss(line);
            ss >> vert1 >> vert2 >> weight;
            g1->addEdge(vert1, vert2, weight);
        };

        // Do something with the graph here....
        g1->display();

        //delete g1;
    };

    // end and close
    input.close();

    return 0;
}
