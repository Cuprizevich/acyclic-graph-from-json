//
// Created by Владислав on 13.09.2016.
//

#ifndef ACYCLIC_GRAPH_FROM_JSON_NODE_H
#define ACYCLIC_GRAPH_FROM_JSON_NODE_H

#include <vector>

using namespace std;

class mark{
    int weight;
    vector <vector<int>> links;
};

class node {
private:
    int id;
    vector <mark> marks;
    //vector <int> neighbours;

public:
    node(vector<mark> _marks){
        marks.resize(_marks.size());
        marks = _marks;
    }
};




#endif //ACYCLIC_GRAPH_FROM_JSON_NODE_H
