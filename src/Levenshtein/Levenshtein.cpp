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