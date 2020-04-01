#pragma once

#include <regex>
#include <queue>
#include <string>
#include <list>
#include <stack>

class CodewordGenerator {
private:
    std::queue<std::string> q; // used in BFS
    std::stack<std::string> wordStack; // ised om DFS
    std::list<std::string> wordList; // used in both BFS & DFS

public:
    CodewordGenerator() = default;   
    
    /**
     * @param pattern that contains a pattern
     * @return the shortest string that matches the pattern.
     *         Explores the space of possible alphabet permutations
     *         in Breadth First Search order. Uses a queue & list.
     */
    std::string generateShortestWord(std::string pattern);
     /**
     * @param pattern a string with a pattern
     * @param length an integer that holds the length
     * @return a string of length n that matches the pattern. 
     *         Explores the space of possible alphabet permutations 
     *         In Depth First Search order. Uses a stack & list
     */
    std::string generateLengthWord(std::string pattern, int length); 
};