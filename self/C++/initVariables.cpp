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

    short int var9 {23}; // size: 4/2 bytes
    long int var10 {23};  // size: 4*2 bytes
    long long int var11 {23};  // size: 4*2 bytes
    
    std::cout << var7 << " " << var8 << std::endl;
     std::cout << sizeof(var9) << " " << sizeof(var10) << " " << sizeof(var11) << std::endl;   

    return 0;
}

