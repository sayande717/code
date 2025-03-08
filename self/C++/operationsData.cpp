#include<iostream>

int main() {
    int a {23};
    int b {50};
    
    // Basic operations
    int sum {a+b};
    int sub {a-b};
    int mul {a*b};
    int div {a/b};
    int mod {a%b};

    std::cout << a++ << std::endl;    // Postfix Increment
    ++a;    // Prefix Increment

    std::cout << b-- << std::endl;    // Postfix Decrement   
    --b;    // Prefix Decrement
    
    std::cout << a << ", " << b << std::endl;

    // Compound Assignment
    int sum2 {a+=b};
    int sub2 {a-=b};
    int mul2 {a*=b};
    int div2 {a/=b};
    int mod2 {a%=b};

    // Relational operators
    bool lessThan {a<b};
    bool greaterThan {a>b};
    bool lessThanEquals {a<=b};
    bool greaterThanEquals {a>=b};
    bool Equals {a==b};
    bool notEqual {a!=b};

    // Logical operators
    bool logicalAND {(a<b) && (a>b)};    // FALSE
    bool logicalOR {(a<b) || (a>b)};     // FALSE
    bool logicalNOT {!true};               // FALSE

    return 0;
}
