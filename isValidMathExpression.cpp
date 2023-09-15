#include <iostream>
#include <stack>
#include <cstring>

bool isValidMathExpression(const char* expression) {
    std::stack<char> parenthesesStack;

    for (int i = 0; i < strlen(expression); i++) {
        char currentChar = expression[i];

        if (currentChar == '(') {
            parenthesesStack.push('(');
        } else if (currentChar == ')') {
            if (parenthesesStack.empty() || parenthesesStack.top() != '(') {
                return false; // Unmatched closing parenthesis
            }
            parenthesesStack.pop();
        } else if (currentChar != ' ' && currentChar != '\t') {
            // Check if the character is a valid digit or operator
            if (!(isdigit(currentChar) || currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/')) {
                return false; // Invalid character in the expression
            }
        }
    }

    // Check if all parentheses are matched
    return parenthesesStack.empty();
}

int main() {
    char expression[1000];
    std::cout << "Enter a mathematical expression: ";
    std::cin.getline(expression, sizeof(expression));

    if (isValidMathExpression(expression)) {
        std::cout << "Valid mathematical expression." << std::endl;
    } else {
        std::cout << "Invalid mathematical expression." << std::endl;
    }

    return 0;
}

