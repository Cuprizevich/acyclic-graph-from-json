#include <iostream>
#include "rapidjson/document.h"
#include "node.h"
#include <fstream>

using namespace rapidjson;
using namespace std;

static char * ReadAllBytes(const char * filename, int * read)
{
    ifstream ifs(filename, ios::binary|ios::ate);
    ifstream::pos_type pos = ifs.tellg();

    int length = pos;

    try{
        char *pChars = new char[length];

        ifs.seekg(0, ios::beg);
        ifs.read(pChars, length);

        ifs.close();
        *read = length;
        return pChars;
    }catch (exception e){
        cout<<e.what()<<endl;
    }
}

vector<node> parseJson(const char* fileName){
    int read;
    char * json = ReadAllBytes(fileName, &read);

    Document document;
    document.Parse(json);

    const Value& myNodes = document["nodes"];
    vector<node> resNodes(myNodes.Size());

    for(int i = 0; i < myNodes.Size(); i++){
        vector<mark> resMarks(myNodes[i]["marks"].Size());

        for(int j = 0; j < myNodes[i]["marks"].Size(); j++){

            const Value& myMark = myNodes[i]["marks"][j];
            vector <vector<int>> resLinks(myNodes.Size());

            for(int x =0; x < myNodes.Size(); x++) resLinks[x].resize(myMark["links"].Size());

            for(int x = 0; x < myMark["links"].Size(); x++){
                const Value& myLink = myMark["links"][x];

                for(int y = 0; y < myMark["links"].Size(); y++){
                    resLinks[myLink["toNode"].GetInt()-1][myLink["toMark"].GetInt()-1] = myLink["weight"].GetInt();
                }
            }
            resMarks[j].setmark(j,myMark["weight"].GetInt(),myNodes.Size(),resLinks);
        }
        resNodes[i].setnode(i,resMarks);
    }

    return resNodes;
}

int main() {
    string fileName = "D:\\LAB\\Projects\\GitGub\\acyclic-graph-from-json\\data.json";

    vector<node> myNodes = parseJson(fileName.c_str());
    /*
    const Value& a = document["nodes"];
    const Value& b = a[0];
    const Value& c = b["marks"];
    const Value& d = c[0];
     */
    //MembersCount() - returns count of fields

    cout<<myNodes[1].marks[0].links[3][0];

    return 0;
}