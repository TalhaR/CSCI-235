#include "PostfixCalculator.hpp"
using namespace std;

/**
 * @param infix_expression a string that contains an infix expression 
 * @return a string that contains a postfix expression
 */
std::string PostfixCalculator::convertToPostfix(std::string infix_expression) {
    std::string postfixString = "";
    int parenthesis = 0;
    
    for (int i = 0; i < infix_expression.size(); i++) {
        char ch = infix_expression[i];
        std::string c = string(1, ch);
        
        
        if (isdigit(ch)) {
            int j = 1;
            int skip = 0;
            while (isdigit(infix_expression[i+j]) && i+j <= infix_expression.size()) {
                c += infix_expression[i+j];
                j++; skip++;
            }
            i += skip;
            
            postfixString += c;
            postfixString += ' ';
        } 
        else if (ch == '(') {
            operatorStack.push(ch);
            parenthesis++;
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!operatorStack.empty() && operatorStack.top() != '('
                    && (precedence(ch) <= precedence(operatorStack.top()))) {
                postfixString += operatorStack.top();
                postfixString += ' ';
                operatorStack.pop();
            } 
            operatorStack.push(ch);
        } 
        else if (ch == ')') {
            parenthesis--;\
            while (!operatorStack.empty()) {
                if (operatorStack.top() != '(') {
                    postfixString += operatorStack.top();
                    postfixString += ' ';
                }
                operatorStack.pop(); 
            }
            if (!operatorStack.empty()) operatorStack.pop();
        } 
        else if (!isspace(ch)){
            throw PrecondViolatedExcep("Unknown operator");
        }
    }
    
    if (parenthesis != 0) throw PrecondViolatedExcep("Unbalanced parenthesis");
    
    while (!operatorStack.empty()) {
        if (operatorStack.top() != '(') {
            postfixString += operatorStack.top();
            postfixString += ' ';
        }
        operatorStack.pop();
    }
    
    return postfixString;
}

int PostfixCalculator::precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '(') return 0;
}

/**
 * @param postfix_expression a string that contains a postfix expression 
 * @return the evaluation of that postfix expression
 */
double PostfixCalculator::calculatePostfix(std::string postfix_expression) {
    
    return -1;
}

/**
 * @param input_file_name a file that contains infix expressions
 * @post creates a 'postfix.txt' file that converts the infix expression
 * of the 'input_file_name' to postfix expressions. Also creates a 
 * 'results.txt' file that contains the evaluation of the postfix expressions
 */
void PostfixCalculator::testCalculator(std::string input_file_name) {
    std::ifstream infile(input_file_name);
    
    if (infile.good()) {
        std::ofstream postfixFile("postfix.txt");
        std::ofstream resultsFile("results.txt");
        std::string line;
        
        while(getline(infile, line)) {
            try {
                std::string postfixString = convertToPostfix(line);
                
                postfixFile << postfixString << "\n";
                
                resultsFile << calculatePostfix(postfixString) << "\n";
            } catch (PrecondViolatedExcep e){
                postfixFile << e.what() << "\n";
                resultsFile << e.what() << "\n";
            }
        }
        postfixFile.close();
        resultsFile.close();
    } else {
        std::cerr << "Cannot open file\n";
    }
    infile.close();
}