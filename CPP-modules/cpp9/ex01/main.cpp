#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: RPN \"<expression>\"" << std::endl;
        return 1;
    }

    std::string expression = argv[1];
    if (!Parentheses(expression)) {
        std::cerr << "Error: Unbalanced parentheses" << std::endl;
        return 1;
    }

    float result = Rpn(expression);
    std::cout << result << std::endl;

    return 0;
}

