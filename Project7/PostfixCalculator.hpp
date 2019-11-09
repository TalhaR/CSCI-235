#pragma once
#include "PrecondViolatedExcep.hpp"
#include <string>
#include <stack>
#include <fstream>

class PostfixCalculator {
private:

public:
    PostfixCalculator() = default;
    
    std::string convertToPostfix(std::string infix_expression);

    double calculatePostfix(std::string postfix_expression);
    
    void testCalculator(std::string input_file_name);
};