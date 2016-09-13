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

    // What happens if the OS supports really big files.
    // It may be larger than 32 bits?
    // This will silently truncate the value/
    int length = pos;

    // Manuall memory management.
    // Not a good idea use a container/.
    try{
        char *pChars = new char[length];

        ifs.seekg(0, ios::beg);
        ifs.read(pChars, length);

        // No need to manually close.
        // When the stream goes out of scope it will close the file
        // automatically. Unless you are checking the close for errors
        // let the destructor do it.
        ifs.close();
        *read = length;
        return pChars;
    }catch (exception e){
        cout<<e.what()<<endl;
    }
}

int main() {
    string fileName = "D:\\LAB\\Projects\\GitGub\\acyclic-graph-from-json\\data.json";
    int read;
    char * json = ReadAllBytes(fileName.c_str(), &read);

    Document document;
    document.Parse(json);

    /*
    const Value& a = document["nodes"];
    const Value& b = a[0];
    const Value& c = b["marks"];
    const Value& d = c[0];
     */
    //MembersCount() - returns count of fields

    int nodesCount = document["nodes"].Size();
    const Value& nodes = document["nodes"];

    vector<node> myNodes;
    myNodes.resize(nodesCount);

    for(int i = 0; i < nodesCount; i++){
        const Value& myNode = nodes[i];
        const Value& marks = myNode["marks"];

    }

    return 0;
}