#include "RPN.hpp"

float Operation(float operand1, float operand2, char op) {
    switch(op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                std::cerr << "Error: Division by zero!" << std::endl;
                std::exit(1);
            }
            return operand1 / operand2;
        default:
            std::cerr << "Error: Invalid operator!" << std::endl;
            std::exit(1);
    }
}

float Rpn(const std::string& expression) {
    std::istringstream iss(expression);
    std::stack<float> operands;

    std::string token;
    while (iss >> token) {
        if (std::isdigit(token[0])) {
            operands.push(std::stof(token));
        } else if (token.size() == 1 && std::strchr("+-*/", token[0])) {
            if (operands.size() < 2) {
                std::cerr << "Error: Insufficient operands for operator " << token << std::endl;
                std::exit(1);
            }
            float operand1 = operands.top(); operands.pop();
            float operand2 = operands.top(); operands.pop();
            float result = Operation(operand1, operand2, token[0]);
            operands.push(result);
        } else {
            std::cerr << "Error" << std::endl;
            std::exit(1);
        }
    }

    if (operands.size() != 1) {
        std::cerr << "Error: Invalid expression" << std::endl;
        std::exit(1);
    }

    return operands.top();
}

bool Parentheses(const std::string& expression) {
    int count = 0;
    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (c == '(') {
            count++;
        } else if (c == ')') {
            count--;
        }
        if (count < 0) {
            return false;
        }
    }
    return count == 0;
}