#include <iostream>
#include <string>
bool simulateTM(std::string tape) {
    int head = 0;  // Start at the beginning of the tape
    
    while (true) {
        // Find the first unmarked 'a' and mark it as 'X'
        head = tape.find('a');
        if (head != std::string::npos) {
            tape[head] = 'X';
        } else {
            // If there are no more 'a's, we should also have no 'b's or 'c's left
            if (tape.find('b') == std::string::npos && tape.find('c') == std::string::npos) {
                return true;  // Accepted
            } else {
                return false; // Rejected due to mismatched count
            }
        }

        // Find the first unmarked 'b' after marking 'a' and mark it as 'Y'
        head = tape.find('b', head); 
        if (head != std::string::npos) {
            tape[head] = 'Y';
        } else {
            return false; // Rejected if no matching 'b' is found for 'a'
        }

        // Find the first unmarked 'c' after marking 'b' and mark it as 'Z'
        head = tape.find('c', head); 
        if (head != std::string::npos) {
            tape[head] = 'Z';
        } else {
            return false; // Rejected if no matching 'c' is found for 'a' and 'b'
        }
    }
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;
    
    if (simulateTM(input)) {
        std::cout << "Accepted" << std::endl;
    } else {
        std::cout << "Rejected" << std::endl;
    }

    return 0;
}