#include <iostream>
#include <regex>
#include <string>
#include <vector>

std::vector<char> operatorVector(std::string expression) {
    std::vector<char> operatorList;

    // 1st Iteration: 0 + number 0
    operatorList.push_back('+');

    // Define pattern
    std::regex operatorREGEX("[+\\-*/%]");

    // Initialize iterator
    std::sregex_iterator iterator(expression.begin(), expression.end(), operatorREGEX);
    std::sregex_iterator end;
    
    // Add identified elements to vector<char>
    while (iterator != end) {
        std::smatch match = *iterator;
        operatorList.push_back(match.str()[0]);
        ++iterator;
    }

    return operatorList;
}

std::vector<int> expressionVector(std::string expression) {
    std::vector<int> expressionList;

    std::regex expressionREGEX("[+]?[0-9]+(\\.[0-9]+)?");
    std::sregex_iterator iterator(expression.begin(), expression.end(), expressionREGEX);
    std::sregex_iterator end;

    while (iterator != end) {
        std::smatch match = *iterator;
        expressionList.push_back(std::stoi(match.str()));
        ++iterator;
    }

    return expressionList;
}

int findModulo(double dividend, double divisor) {
    return static_cast<int>(dividend - static_cast<int>(dividend/divisor) * divisor);
}

int main() {

    // Input: Expression
    std::string expression;
    std::cout << "> Enter expression: ";
    std::cin >> expression;

    std::vector<int> expressions = expressionVector(expression);
    std::vector<char> operators = operatorVector(expression);

    double result {0};

    // Number of operators will be same as number of integers & decimels, including the explicitely assigned `+`.
    if(expressions.size() != operators.size()) {
        std::cout<<"Invalid Expression";
    }

    for (int index=0 ; index<operators.size() ; index++) {
        std::cout << operators[index] << " " << expressions[index] << std::endl;
        switch(operators[index]) {
            case '%':
                result = findModulo(result,expressions[index]);
            case '/':
                result = result / expressions[index];
                break;
            case '*':
                result = result * expressions[index];
                break;
            case '+':
                result = result + expressions[index];
                break;
            case '-':
                result = result - expressions[index];
                break;
        }
    }

    // Output: Result
    std::cout << "> Result: " << result << std::endl;

    return 0;
}
