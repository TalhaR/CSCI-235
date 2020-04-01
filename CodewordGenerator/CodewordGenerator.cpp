#include "CodewordGenerator.hpp"

/**
 * @param pattern a string with a regex pattern
 * @return the shortest string that matches the pattern.
 *         Explores the space of possible alphabet permutations
 *         in Breadth First Search order. Uses a queue & list
 */
std::string CodewordGenerator::generateShortestWord(std::string pattern) {
    // need to assign shortestWord to something long 
    // to later compare if a substring is shorter than it 
    // and no possilbe regex can be longer than the pattern
    std::string shortestWord = pattern; 
    
    q.push(""); // need to push empty string to start while loop
    
    while (!q.empty()) {
        std::string s = q.front();
        wordList.push_back(s); // adds all words from q into wordList
        q.pop();
        
        // making all substrings up to size 4
        // and storing into q(ueue) 
        if (s.size() < 4) {
            for (char c = 'A'; c <= 'Z'; c++) {
                std::string temp = s;
                q.push(temp += c);
            }
        }
    }
    
    std::regex re(pattern);
    
    // iterates through all the strings in wordList
    // then assigns the string to the shortestWord
    // if the word is shorter in length than the current
    // shortestWord and is a valid expression that meets the pattern
    for (auto& str : wordList) {
        if (std::regex_match(str, re) && str.size() < shortestWord.size()) {
            shortestWord = str;
        }
    }
    
    wordList.clear();
    
    return shortestWord;
}
/**
 * @param pattern a string with a regex pattern
 * @param length an integer that holds the length
 * @return a string of length n that matches the pattern. 
 *         Explores the space of possible alphabet permutations 
 *         In Depth First Search order. Uses a stack & list
 */
std::string CodewordGenerator::generateLengthWord(std::string pattern, int length) {
    std::string wordWithPattern = "";
    
    wordStack.push(""); // need to push empty string to start the while loop
    
    while (!wordStack.empty()){
        std::string s = wordStack.top();
        wordList.push_back(s); // adds all words in queue into wordList
        wordStack.pop();
        
        // making all substrings up to size 4
        // and storing into stack 
        if (s.size() < length) {
            for (char c = 'A'; c <= 'Z'; c++){
                std::string temp = s;
                wordStack.push(temp += c);
            }
        }
    }
    
    std::regex re(pattern);
    
    // iterates through all the strings in wordList
    // and if one of the strings matches the pattern
    // and is the size of length it will set that to
    // wordWithPattern and escape 
    for (auto& str : wordList) {
        if (std::regex_match(str, re) && str.size() == length) {
            wordWithPattern = str;
            break;
        }
    }
    
    wordList.clear();
    
    return wordWithPattern;
}