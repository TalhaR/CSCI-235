#include "PostfixCalculator.hpp"

std::string PostfixCalculator::convertToPostfix(std::string infix_expression) {
    std::string postfixString = "";
    
    for (char c : infix_expression) {
        //if (isdigit(c))
    }
    
    return postfixString;
}

double PostfixCalculator::calculatePostfix(std::string postfix_expression) {
    
}

void PostfixCalculator::testCalculator(std::string input_file_name) {
    std::ifstream infile(input_file_name);
    
    if (infile.good()) {
        std::ofstream postfixFile("postfix.txt");
        std::ofstream resultsFile("results.txt");
        std::string line;
        
        while(getline(infile, line)) {
            std::string postfixString = convertToPostfix(line);
            
            postfixFile << postfixString << "\n";
            
            resultsFile << calculatePostfix(postfixString) << "\n";
             
        }
        postfixFile.close();
        resultsFile.close();
    } else {
        std::cerr << "Cannot open file\n";
    }
    infile.close();
}