#include<iostream>
int main() {
    int number1 = 0b1111;  // Binary
    int number2 = 017;      // Octal
    int number3 = 15;      // Decimel
    int number4 = 0x0F;   // Hexadecimel

    // Output is printed as Decimel.
    std::cout << "Binary: " << number1 << std::endl;
    std::cout << "Octal: " << number2 << std::endl;
    std::cout << "Decimel: " << number3 << std::endl;
    std::cout << "Hexadecimel: " << number4 << std::endl;

    return 0;
}
