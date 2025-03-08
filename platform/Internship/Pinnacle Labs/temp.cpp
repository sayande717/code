#include <iostream>
#include <chrono>

int main() {
    const int MAX_TRIES = 10;
    const int TIMEOUT_SECONDS = 2;
    
    for (int i = 0; i < MAX_TRIES; ++i) {
        std::cout << "Enter input #" << i+1 << ": ";
        
        // Start the timer
        auto start = std::chrono::steady_clock::now();
        
        // Read input from the user
        std::string input;
        std::getline(std::cin, input);
        
        // Calculate the elapsed time
        auto end = std::chrono::steady_clock::now();
        auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
        
        // Check if the timeout has been reached
        if (elapsed_seconds >= TIMEOUT_SECONDS) {
            std::cout << "Timeout reached. Exiting." << std::endl;
            continue;
        }
        
        // Process the input
        std::cout << "You entered: " << input << std::endl;
    }
    
    return 0;
}
