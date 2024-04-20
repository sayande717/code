#include <iostream>
#include <future>
#include <iterator>
#include <string>
#include <chrono>
#include <map>
#include <cstdlib>
#include <vector>

std::string* returnQuestion() {

    static std::string outArr[2]; 

    std::map<std::string,std::string> questionList = {
        {"Who is considered the father of modern computing?","Turing"},
        {"What is the first high-level programming language?","Fortran"},
        {"What is the basic unit of storage in a computer?","Bit"},
        {"What does HTML stand for?","HyperText Markup Language"},
        {"What symbol is commonly used to end a statement in many programming languages?","Semicolon"},
        {"What is the binary representation of the decimal number 7?","111"},
        {"What is the binary representation of the decimal number 10?","1010"},
        {"What programming language was developed by Dennis Ritchie in the early 1970s?","C"},
        {"Who is the creator and lead developer of the Linux kernel?","Linus Torvalds"},
        {"Who conceptualized the first digital programmable computer?","Charles Babbage"}
    };
    
    // Select a random question.
    srand(time(NULL));              // Seed
    int randomPick = rand() % 10;   // Generate

    // Retrieve the question from the map.
    int index = 0;
    for(std::map<std::string,std::string>::iterator iter = questionList.begin(); iter != questionList.end();iter++) {
        
        if(index==randomPick) {
            outArr[0] = iter->first;
            outArr[1] = iter->second;
        }

        index++;
    }

    return outArr;
}

int main() {

    std::cout << returnQuestion()[0] << std::endl;
    
    return 0;
}
