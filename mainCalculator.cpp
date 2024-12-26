#include <iostream>
#include <sstream>
#include <string>

double evaluateExpression(const std::string& expression) {
    std::istringstream iss(expression);
    double operand1, operand2;
    char operation;

    // Parse input (e.g., "3 * 4" or "4+12")
    iss >> operand1 >> operation >> operand2;

    // Perform the operation
    switch (operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) {
                throw std::invalid_argument("Division by zero is not allowed.");
            }
            return operand1 / operand2;
        default: 
            throw std::invalid_argument("Invalid operator. Supported operators are +, -, *, /.");
    }
}

int main() {
    std::string input;

    std::cout << "Enter a simple arithmetic expression (e.g., 3 * 4, 4 + 12): ";
    std::getline(std::cin, input); // Read the entire line of input

    try {
        double result = evaluateExpression(input);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}