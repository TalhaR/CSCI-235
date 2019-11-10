#include "PostfixCalculator.hpp"

std::string PostfixCalculator::convertToPostfix(std::string infix_expression) {
    std::string postfixString = "";
    
    for (char& c : infix_expression) {
        if (isdigit(c)) {
            numberStack.push(c);
            
            postfixString += c;
            postfixString += " ";
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            operatorStack.push(c);
        } else if (c == '(' || c == ')') {
            // TODO
        } else if (!isspace(c)){
            return PrecondViolatedExcep("Unknown operator").what();
        }
    }
    
    for(int i = 0; i < operatorStack.size(); i++) {
        postfixString += operatorStack.top();
        operatorStack.pop();
    }
    
    return postfixString;
}

double PostfixCalculator::calculatePostfix(std::string postfix_expression) {
    
    return -1;
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