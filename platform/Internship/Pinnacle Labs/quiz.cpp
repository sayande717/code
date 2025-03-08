#include <iostream>
#include <string>
#include <chrono>
#include <map>
#include <cstdlib>

std::string* returnQuestion(int inIndex) {

    static std::string outArr[2]; 

    std::map<std::string,std::string> questionList = {
        {"Who is considered the father of modern computing?","Turing"},
        {"What is the first high-level programming language?","Fortran"},
        {"What is the basic unit of storage in a computer?","Bit"},
        {"What does HTML stand for?","Hypertext Markup Language"},
        {"What symbol is commonly used to end a statement in many programming languages?",";"},
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

void continueFlow() {
    std::cout << "\n\nPress Enter to continue...";
    std::cin.ignore();
}

void startQuiz() {
    std::cout << "\033[2J\033[H";

    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Welcome to the Quiz Session!" << std::endl;
    std::cout << "Here, you will be asked 10 questions, with a timeout of 10 seconds per question. Try to answer as many as possible." << std::endl;
    std::cout << std::endl << "Rules: " << std::endl;
    std::cout << "- For each correct answer, you get 4 marks." << std::endl;
    std::cout << "- For each wrong answer, 1 mark is deducted." << std::endl;

    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------";

    continueFlow();
    //std::cout << "" << std::endl;
}

void endQuiz(int marks) {

    std::cout << "\033[2J\033[H";

    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------"; 

    std::cout << "\nThanks for attending this quiz session!"; 
    std::cout << "\nYou've obtained " << marks << " points.";

    std::cout << std::endl << "---------------------------------------------------------------------------------------------------------------------------------------------------";

    continueFlow();

}

void noReview() {
    std::cout << " This will not be considered for review.";
    continueFlow();
    //std::cin.ignore();
}

int main() {
    // Select a random question. [0]
    srand(time(NULL));              // [0] Seed

    startQuiz();

    // Setup Timeout [1]
    // [1] Set the timeout duration in seconds
    constexpr int timeout {10};
    int marks {0};

    for(int qsNumber=1;qsNumber<=10;qsNumber++) {
        // [1] Get the Quiz Start Time 
        auto startTime = std::chrono::steady_clock::now();

        int randomPick = rand() % 10;   // [0] Generate
        std::cout << "\033[2J\033[H";
        std::string* question = returnQuestion(randomPick);
        std::string userInput;

        std::cout << "[ Question " << qsNumber << " ]" << std::endl;
        std::cout << std::endl << "> " <<  question[0]; 
        std::cout << std::endl << "-> ";
    
        // [1] Get user input.
        std::getline(std::cin, userInput);

        // [1] Get current time, and amount of seconds elapsed.
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
            
        // [1] Check if the timeout duration has elapsed
        if (elapsedTime >= timeout) {
            // Timeout occurred
            std::cout << std::endl << "NOTE: Timeout!";
            noReview();
            continue;
        }

        if(userInput.empty()) {
            std::cout << std::endl << "NOTE: You have not responded to this question.";
            noReview();
        }

        else if (!userInput.empty()) {
            // [1] User entered input before the timeout
            //std::cout << "User input received: " << userInput << std::endl;
            if(userInput==question[1]) {
                marks+=4;
            } else {
                marks-=1;
            }
        }
    }
    
    endQuiz(marks);

    return 0;
}
