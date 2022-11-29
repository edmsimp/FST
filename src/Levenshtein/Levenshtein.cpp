#include "Levenshtein.h"

LevenshteinAutomata::LevenshteinAutomata(){
    firstWords = {};
    // Resize dictionary to fit all letters of the alphabet.
    dictionary.resize(26);

    resetDictionary();
}

LevenshteinAutomata::~LevenshteinAutomata(){
    return;
}

int LevenshteinAutomata::levenshteinDistance(std::string firstString, std::string secondString){
    int m = firstString.size();
    int n = secondString.size();

    // wordMatrix[n * i + j] -> wordMatrix[i][j]
    wordMatrix[0] = 0;

    for(int i = 1; i <= m; i++)
        wordMatrix[n * i] = i;

    for(int j = 1; j <= n; j++)
        wordMatrix[j] = j;

    int subCost;

    for(int j = 1; j <= n; j++)
        for(int i = 1; i <= m; i++){
            if(firstString[i] == secondString[j])
                subCost = 1;
            else 
                subCost = 0;
            
            wordMatrix[n * i + j] = std::min(wordMatrix[n * (i - 1) + j] + 1, wordMatrix[n * i + (j - 1)] + 1);
            wordMatrix[n * i + j] = std::min(wordMatrix[n * i + j], wordMatrix[n * (i - 1) + (j - 1)] + subCost);
        }

    return wordMatrix[n * m + n];
}

void LevenshteinAutomata::updateDictionary(std::list<std::string> newDict){

}

void LevenshteinAutomata::resetDictionary(){
    std::cout << "Clearing dictionary." << std::endl;
    dictionary.clear();

    std::ifstream fs;
    fs.open("/usr/share/dict/american-english");

    if(!fs.is_open())
        throw std::runtime_error("Could not open default linux dictionary file!");

    std::cout << "Found Linux dictionary file." << std::endl;
    std::string currentLine;

    while(std::getline(fs, currentLine)){
        if(currentLine.size() > longestWordLength)
            longestWordLength = currentLine.size();

        dictionary.push_back(currentLine);
    }

    std::cout << "Created dictionary with " << dictionary.size() << " words." << std::endl;
    
    // Matrix for the Levenshtein Distance algorithm.
    wordMatrix.resize((longestWordLength + 1) * (longestWordLength + 1));
    fs.close();
}

// void LevenshteinAutomata::resetDictionary(){
//     std::cout << "Clearing dictionary." << std::endl;
//     dictionary.clear();
//     dictionary.resize(26);

//     std::ifstream fs;
//     fs.open("/usr/share/dict/american-english");

//     if(!fs.is_open())
//         throw std::runtime_error("Could not open default linux dictionary file!");

//     std::cout << "Found Linux dictionary file." << std::endl;
//     std::string currentLine;

//     while(std::getline(fs, currentLine)){
//         std::cout << "Pushing " << currentLine << " into position " << int(currentLine[0]) - 97 << " of the vector." << std::endl;
//         dictionary[int(std::tolower(currentLine[0])) - 97].push_back(currentLine);
//     }

//     for(std::vector<std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
//         std::cout << "Current letter has " << (*it).size() << "elements." << std::endl;

//     fs.close();
// }