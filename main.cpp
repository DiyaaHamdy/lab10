//
//  main.cpp
//  Lab 10
//
//  Created by Diyaa Hamdy on 18/05/2023.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Directedunweightedgraph.h"

using namespace std;

UndirectedweightedGraph::UndirectedweightedGraph(int size)
    : numberOfVertices(size), adjacencyList(size, vector<string>(30, "")) {}

void UndirectedweightedGraph::addEdge(const Edge& edge) {
    adjacencyList[edge.source][edge.destination] = edge.weight;
}

void UndirectedweightedGraph::printGraph() const {
    cout << "Adjacency Matrix:" << endl;

    for (int i = 0; i < adjacencyList.size(); i++){
        for (int j = 0; j <= 29; j = j+3) {
            cout << adjacencyList[i][j]<<' ';
        }
        cout << endl;
    }

}

string getSubStr(const vector<string>& str, int &i, int &k) {

    int counter = 0;
    string sub{};

    if (i == 30) {
        k++;
        i = 0;
    }
    else {
        while (counter < 3 && i <= 30) {
            
            if (str[k][i] == ' ') {
                counter++;
                i++;
            }
            else {
                sub += str[k][i];
                counter++;
                i++;
            }
                
        }

    }


    return sub;
}

int main() {
    ifstream file("Users/diyaahamdy/Desktop/board.txt");


    vector<string> text;
    string line;


    while (getline(file, line)) {
        text.push_back(line);
    }

    file.close();

    int size = text.size();
    int k = 0;
    int l = 0;
    UndirectedweightedGraph graph(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= 29; j+=3) {
                Edge edge;
                edge.source = i;
                edge.destination = j;
                edge.weight = getSubStr(text, k, l);
                graph.addEdge(edge);
        }
    }

    graph.printGraph();

    return 0;
}
