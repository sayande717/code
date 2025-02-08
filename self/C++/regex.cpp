#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {

    std::string expression = "23+5-6";
    // Specify what to identify.
    std::regex pattern0("[+\\-*/%]");                    // General patterns (+,-,*,/,%)
    std::regex patternNumber("[+]?[0-9]+(\\.[0-9]+)?");  // 0, and positive numbers, decimel numbers above 0.
    
    // Standard library iterator: Iterates over matches of regular expressions in strings.
    // Range: `beginning` to `end` of expression, Pattern list: `pattern0`
    std::sregex_iterator iterator(expression.begin(), expression.end(), pattern0);
    std::sregex_iterator end;
    
    // Match the elements one by one.
    while (iterator != end) {
        std::smatch match = *iterator;
        // match provides the matched element, one by one.
        std::cout << match.str()[0];            // Character matching
        std::cout << match.str();               // String matching
        std::cout << std::stoi(match.str());    // Integer matching
        ++iterator;
    }

    return 0;
}

