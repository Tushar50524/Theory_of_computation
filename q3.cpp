#include <iostream>
#include <string>

bool acceptsL1(const std::string &input) {
    int length = input.length();
    // Check if length is less than 4, immediately reject
    if (length < 4) return false;

    // Check if the first two characters match the last two
    return (input[0] == input[length - 2] && input[1] == input[length - 1]);
}

int main() {
    std::string input;
    std::cout << "Enter a string over {a, b}: ";
    std::cin >> input;

    if (acceptsL1(input)) {
        std::cout << "The string is accepted by the FA.\n";
    } else {
        std::cout << "The string is rejected by the FA.\n";
    }

    return 0;
}
