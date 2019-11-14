#pragma once
#include "PrecondViolatedExcep.hpp"
#include <string>
#include <stack>
#include <fstream>
#include <iostream>
#include <cctype>
#include <sstream>

class PostfixCalculator {
private:
    std::stack<std::string> postfixStack;
    std::stack<char> operatorStack;
    
    int precedence(char c);

public:
    PostfixCalculator() = default;
    
    /**
     * @param infix_expression a string that contains an infix expression 
     * @return a string that contains a postfix expression
     */
    std::string convertToPostfix(std::string infix_expression);

    /**
     * @param postfix_expression a string that contains a postfix expression 
     * @return the evaluation of that postfix expression
     */
    double calculatePostfix(std::string postfix_expression);
    
    /**
     * @param input_file_name a file that contains infix expressions
     * @post creates a 'postfix.txt' file that converts the infix expression
     * of the 'input_file_name' to postfix expressions. Also creates a 
     * 'results.txt' file that contains the evaluation of the postfix expressions
     */
    void testCalculator(std::string input_file_name);
};