// Check notes
#include<iomanip>
#include<iostream>
#include <ostream>
int main() {
    std::cout << "something" << std::endl;
    std::cout << "hi" << std::endl;

    // Ensures that the string has been sent to the output stream. This may be useful in some use cases.
    std::cout << "Hello!" << std::endl << std::flush;

    // usual syntax
    std::cout << std::fixed;
    std::cout << 3.14E+10 << std::endl;

    std::cout << std::setprecision(50);
    std::cout << (22.0/7) << std::endl;
}
