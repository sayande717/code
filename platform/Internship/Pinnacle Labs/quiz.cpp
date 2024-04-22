#include <iostream>
#include <string>
#include <chrono>
#include <map>
#include <cstdlib>
#include <thread>

std::string* returnQuestion(int inIndex) {

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
    


    // Retrieve the question from the map.
    int index = 0;
    for(std::map<std::string,std::string>::iterator iter = questionList.begin(); iter != questionList.end();iter++) {
        
        if(index==inIndex) {
            outArr[0] = iter->first;
            outArr[1] = iter->second;
        }

        index++;
    }

    return outArr;
}

void welcome() {
    std::cout << "Welcome to the Quiz Session!" << std::endl;
    std::cout << "Here, you will be asked 10 questions, with a timeout of 15 seconds per question. Try to answer as many as possible." << std::endl;
    std::cout << std::endl;
    
    std::cout << "Rules: " << std::endl;
    std::cout << "> For each correct answer, you get 4 marks." << std::endl;
    std::cout << "> For each wrong answer, 1 mark is deducted." << std::endl;

    std::cout << std::endl;

    //std::cout << "" << std::endl;
}

int main() {
    int marks {0};

    // Select a random question. [0]
    srand(time(NULL));              // [0] Seed

    welcome();

    // Setup Timeout [1]
    // [1] Set the timeout duration in seconds
    constexpr int timeout = 15;
    // [1] Get the Quiz Start Time 
    auto startTime = std::chrono::steady_clock::now();

    for(int i=0;i<10;i++) {

        int randomPick = rand() % 10;   // [0] Generate
        std::string* question = returnQuestion(randomPick);
        std::string userInput;

        std::cout << question[0] << std::endl << "> ";
    
        // [1] Get user input.
        std::thread inputThread([&]() {
        std::getline(std::cin, userInput);
        });

        while (true) {
            // [1] Get current time, and amount of seconds elapsed.
            auto currentTime = std::chrono::steady_clock::now();
            auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
            
            // [1] Check if the timeout duration has elapsed
            if (elapsedTime >= timeout) {
                // Timeout occurred
                std::cout << std::endl << "Timeout!" << std::endl;
                break;
            }

            if (!userInput.empty()) {
                // [1] User entered input before the timeout
                //std::cout << "User input received: " << userInput << std::endl;
                if(userInput==question[1]) {
                    marks+=4;
                } else {
                    marks-=1;
                }

            continue;
            }

            // [1] Sleep for a short duration before checking again
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    inputThread.join();
    }
    return 0;
}
