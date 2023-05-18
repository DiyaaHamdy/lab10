//
//  Directedunweightedgraph.h
//  Lab 10
//
//  Created by Diyaa Hamdy on 18/05/2023.
//

#ifndef Directedunweightedgraph_h
#define Directedunweightedgraph_h


#endif /* Directedunweightedgraph_h */

#include <queue>
#include <vector>
#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int source;
    int destination;
    string weight;
};

class UndirectedweightedGraph
{
private:
    int numberOfVertices;
    vector<vector<string>> adjacencyList;
public:
    UndirectedweightedGraph(int size);
    void addEdge(const Edge& edge);
    void printGraph() const;
};
