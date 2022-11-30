#include "GraphFST.h"

GraphFST::GraphFST(){
    createFST("/usr/share/dict/american-english");
    dictionary.clear();
    initialNode = GraphNode();
}

GraphFST::GraphFST(std::string filename){
    createFST(filename);
    dictionary.clear();
    initialNode = GraphNode();
}

GraphNode* GraphFST::dictionaryMember(GraphNode& target){
    for(std::list<GraphNode*>::iterator it = dictionary.begin(); it != dictionary.end(); it++){
        if((**it).compareState(target))
            return *it;
    }

    return NULL;        
}

void GraphFST::dictionaryInsert(GraphNode& target){
    dictionary.push_back(&target);
}

void GraphFST::createFST(std::string filename){
    std::ifstream fs;
    fs.open(filename);

    if(!fs.is_open())
        throw std::runtime_error("Could not open dictionary file!");

    std::cout << "Found dictionary file." << std::endl;
    std::string previousWord = "";
    std::string currentWord;

    while(std::getline(fs, currentWord)){
        int i = 1;
        while(i < currentWord.size() && i < previousWord.size() && currentWord[i] == previousWord[i])
            i += 1;








        previousWord = currentWord;
    }

    std::cout << "Created FST." << std::endl;
    fs.close();


}
