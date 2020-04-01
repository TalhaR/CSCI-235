#include "PostfixCalculator.hpp"

/**
 * @param infix_expression a string that contains an infix expression 
 * @return a string that contains a postfix expression
 */
std::string PostfixCalculator::convertToPostfix(std::string infix_expression) {
    std::string postfixString = "";
    // adds 1 to parenthesis for '(' and removes 1 for ')'
    // so if the expression is unbalanced then parenthesis will equal a 
    // number other than 0. In which case throws an error
    int parenthesis = 0;
    bool hasNumber = false;
    
    for (int i = 0; i < infix_expression.size(); i++) {
        char ch = infix_expression[i];
        std::string c = std::string(1, ch);
        
        if (isdigit(ch)) {
            // will check if the chars directly after this number are also
            // numbers, it will then add those chars together into one string and 
            // add that to the postfixstring
            hasNumber = true;
            int j = 1;
            int skip = 0;
            while (isdigit(infix_expression[i+j]) && i+j <= infix_expression.size()) {
                c += infix_expression[i+j];
                j++; skip++;
            }
            i += skip;
            
            postfixString += c;
            postfixString += ' ';
        } else if (ch == '(') {
            operatorStack.push(ch);
            parenthesis++;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // If operators on stack have greater precendence 
            // this will add those to the PostfixString first
            while (!operatorStack.empty() && operatorStack.top() != '('
                    && (precendence(ch) <= precendence(operatorStack.top()))) {
                postfixString += operatorStack.top();
                postfixString += ' ';
                operatorStack.pop();
            } 
            operatorStack.push(ch);
        } else if (ch == ')') {
            // if a closing parenthesis is met all operators in stack
            // until the opening parenthesis need to be added to postfixString
            parenthesis--;
            addOperators(postfixString);
            if (!operatorStack.empty()) operatorStack.pop();
        } else if (!isspace(ch)){
            throw PrecondViolatedExcep("Unknown operator");
        }
    }
    
    if (parenthesis != 0) throw PrecondViolatedExcep("Unbalanced parenthesis");
    if (!hasNumber) throw std::logic_error("No numbers");
    
    addOperators(postfixString); // adds remaining operators to the postfixString
    
    return postfixString;
}

/**
 * @param postfixString a string that will hold a postfix expression
 * @post adds operators from the operatorStack into the postfixString
 *       until an opening parenthesis is met or stack is emptied
 */
void PostfixCalculator::addOperators(std::string& postfixString) {
    while (!operatorStack.empty() && operatorStack.top() != '(') {
        postfixString += operatorStack.top();
        postfixString += ' ';

        operatorStack.pop();
    }
}

/**
 * @pre assumes c is a char 
 * @param c a char that holds an operator
 * @return 1 for + or -, but
 */
int PostfixCalculator::precendence(char& c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
}

/**
 * @pre assumes postfix_expression is well formed
 * @param postfix_expression a string that contains a postfix expression 
 * @return the evaluation of that postfix expression
 */
double PostfixCalculator::calculatePostfix(std::string postfix_expression) {
    for (int i = 0; i < postfix_expression.size(); i++) {
        char ch = postfix_expression[i];
        std::string c(1, ch);
        
        if (isdigit(ch)) {
            // if a digit is found, checks if the upcoming chars are also 
            // digits in which case it combines those chars into one string 
            int j = 1;
            int skip = 0;
            while (isdigit(postfix_expression[i+j]) && i+j <= postfix_expression.size()) {
                c += postfix_expression[i+j];
                j++; skip++;
            }
            i += skip;
            
            postfixStack.push(c);
        } else if (!isspace(ch) && !postfixStack.empty()) {
            // using stod to parse strings into floats 
            double a = std::stod(postfixStack.top());
            postfixStack.pop();
            
            if (!postfixStack.empty()) {
                double b = std::stod(postfixStack.top());
                postfixStack.pop();
            
                if (c == "+") postfixStack.push(std::to_string(a + b));
                if (c == "-") postfixStack.push(std::to_string(b - a));
                if (c == "*") postfixStack.push(std::to_string(a * b));
                if (c == "/") postfixStack.push(std::to_string(b / a));
            } else {
                return a;
            }             
        } 
    }
    
    if (postfixStack.empty()) throw std::logic_error("Stack empty");
    
    double retVal = stod(postfixStack.top());
    postfixStack.pop();
    
    return retVal;
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
                double result = calculatePostfix(postfixString);
                
                postfixFile << postfixString << "\n";
                resultsFile << result << "\n";
            } catch (const PrecondViolatedExcep& e){
                postfixFile << e.what() << "\n";
                resultsFile << e.what() << "\n";
                
                // clears operatorStack of any left over parentheses
                while (!operatorStack.empty()) {
                    operatorStack.pop();
                }
            } catch (const std::logic_error& e){
                // This catches if the stack is empty
                // or if there were no numbers 
                // in which case we just do nothing
            } 
        }
        postfixFile.close();
        resultsFile.close();
    } else {
        std::cerr << "Cannot open file\n";
    }
    infile.close();
}