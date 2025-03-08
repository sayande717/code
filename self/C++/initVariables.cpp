#include <iomanip>
#include <ios>
#include <iostream>

// {}: Does not implicitely convert,(): Implicitely converts

int main() {
    int var1 {23};  // Braced initialization, Default format
    //int var2 {23.2};// Error: cannot implicitely convert
    int var3 (23);    // Functional initialization, 
    int var4 (23.2);  // Will implicitely convert & remove the decimel part.
    int var5 = 23;   // Assignment initialization
    int var6 = 23.2; // Will implicitely convert & remove the decimel part.

    std::cout << var1 << " ";
    //std::cout << var2 << " ";
    std::cout << var3 << " " << var4 << " " << var5 << " " << var6;
    std::cout << std::endl;

    std::cout << sizeof(var1) << std::endl;

    signed int var7 {-23};  // Allows all integers
    unsigned int var8 {23}; // Only allows >=0
    // int var8 {23u};      // also unsigned

    short int var9 {23}; // size: 4/2 bytes
    long int var10 {23};  // size: 4*2 bytes
    long long int var11 {23};  // size: 4*2 bytes

    std::cout << var7 << " " << var8 << std::endl;
    std::cout << sizeof(var9) << " " << sizeof(var10) << " " << sizeof(var11) << std::endl;   

    // Initializing fractional numbers
    float var12 {1.12345f};
    double var13 {1.12345};
    long double var14 {1.12345678L};
    double var15 {1.924e8}; // ^{10^8}
    double var16 {1.924e-8}; // ^10{^-8}

    std::cout << std::setprecision(20); // Set precision to 20 (including number on the LHS of decimel)

    double var17 {5.6};
    double var18 {}; // initialized to 0
    std::cout << "Infinity, NaN" << std::endl;
    
    std::cout << var17/var18 << std::endl;      // +ve Infinity
    std::cout << (var17*-1)/var18 << std::endl; // -ve Infinity
    std::cout << var18/var18 << std::endl; // NaN

    bool var19 {true};
    std::cout << var19 << std::endl;        // Prints 1
    std::cout << std::boolalpha;

    char var20 {'a'};
    char var21 {65};
    std::cout << var20 << var20+2 << var21 << std::endl;        // Prints 'a'
    std::cout << static_cast<int>(var20) << std::endl;          // Prints 97

    auto var22 {123u};
    auto var23 {124.0f};
    // auto var23 {-2};     // Will fail, because the data type was automatically deduced as an unsigned integer, which does not allow negative numbers.
    std::cout << var22 << " " << var23 << std::endl;

    return 0;
}

