#include <iostream>
#include <string>

int main() {
    int age;
    std::string name;

    std::cout << "Enter Name: ";
    //std::cin >> name; // Name without spaces
    std::getline(std::cin,name); // Name with spaces

    std::cout << "Enter Age: ";
    std::cin >> age;

    std::cout << "Name: " << name;
    std::cout << ", Age: " << age << std::endl;

    std::cout << "Hello " << name << "! You are " << age << " years old." << std::endl;

    // These messages will be printed regardless of if an error has occured or not.
    std::cerr << "Error" << std::endl;
    std::clog << "Log" << std::endl;

    return 0;

}

