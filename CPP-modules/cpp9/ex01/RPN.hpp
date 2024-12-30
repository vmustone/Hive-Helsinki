#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

float Operation(float operand1, float operand2, char op);
float Rpn(const std::string& expression);
bool Parentheses(const std::string& expression);
#endif