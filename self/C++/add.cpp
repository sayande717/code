#include <iostream>

int sumFunc(int number1, int number2) {
    return (number1+number2);
}

int main() {
    int first_number {3};  // Variable 1
    int second_number {7}; // Variable 2
    int sum = first_number + second_number;
    
    std::cout << "First number: " << first_number << std::endl;
    std::cout << "Second number: " << second_number << std::endl;
    std::cout << "Sum: " << sumFunc(first_number,second_number) << std::endl;

    return 0;
}
