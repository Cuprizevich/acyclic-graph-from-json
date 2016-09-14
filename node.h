//
// Created by Владислав on 13.09.2016.
//

#ifndef ACYCLIC_GRAPH_FROM_JSON_NODE_H
#define ACYCLIC_GRAPH_FROM_JSON_NODE_H

#include <vector>

using namespace std;

class mark{
public:
    int id;
    int weight;
    int nodesCount;
    vector <vector<int>> links;

    void setmark(int _id, int _weight, int _nodesCount, vector<vector<int>> _links){

        id = _id;
        weight = _weight;
        nodesCount  = _nodesCount;
        links.resize(_links.size());
        for(int i = 0; i < _links.size(); i++)
            links[i].resize(_links[i].size());
        links = _links;
    }
};

class node {
public:
    int id;
    vector <mark> marks;
    //vector <int> neighbours;


    void setnode(int _id, vector<mark> _marks){
        id = _id;
        marks.resize(_marks.size());
        marks = _marks;
    }



};




#endif //ACYCLIC_GRAPH_FROM_JSON_NODE_H
