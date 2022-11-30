#include "Levenshtein.h"

LevenshteinAutomata::LevenshteinAutomata(){
    resetDictionary();
}

LevenshteinAutomata::LevenshteinAutomata(std::vector<std::string> &dictionary){
    updateDictionary(dictionary);
}

LevenshteinAutomata::~LevenshteinAutomata(){
    return;
}

int LevenshteinAutomata::levenshteinDistance(std::string s1, std::string s2){
    // Implementation from:
    // https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C++

    const std::size_t len1 = s1.size(), len2 = s2.size();
	std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

	d[0][0] = 0;
	for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
	for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

	for(unsigned int i = 1; i <= len1; ++i)
		for(unsigned int j = 1; j <= len2; ++j)
                      d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
	return d[len1][len2];
}

void LevenshteinAutomata::updateDictionary(std::vector<std::string> &newDict){
    //std::cout << "Clearing dictionary." << std::endl;
    dictionary.clear();

    for(std::vector<std::string>::iterator it = newDict.begin(); it != newDict.end(); it++)
        dictionary.push_back(*it);

    //std::cout << "Created dictionary with " << dictionary.size() << " words." << std::endl;
}

void LevenshteinAutomata::getWords(std::string word, std::vector<std::string> *matchedStrings, int maxMatches){
    for(std::list<std::string>::iterator it = dictionary.begin(); it != dictionary.end(); it++){
        if(levenshteinDistance((*it), word) == 1)
            matchedStrings->push_back(*it);
    }

    for(int i = matchedStrings->size(); i < maxMatches; i++)
        matchedStrings->push_back("");
}

void LevenshteinAutomata::resetDictionary(){
    //std::cout << "Clearing dictionary." << std::endl;
    dictionary.clear();

    std::ifstream fs;
    fs.open("/usr/share/dict/american-english");

    if(!fs.is_open())
        throw std::runtime_error("Could not open default linux dictionary file!");

    //std::cout << "Found Linux dictionary file." << std::endl;
    std::string currentLine;

    while(std::getline(fs, currentLine))
        dictionary.push_back(currentLine);

    //std::cout << "Created dictionary with " << dictionary.size() << " words." << std::endl;
    fs.close();
}