#include <iostream>
#include <string>
#include <algorithm>
class TuringMachine {
public:
    TuringMachine(const std::string& input) : tape(input), head(0) {}

    void increment() {
        // Move to the end of the binary number
        head = tape.size() - 1;

        // State: Starting from the rightmost bit
        while (head >= 0) {
            if (tape[head] == '0') {
                // Change '0' to '1' and we're done
                tape[head] = '1';
                return;
            } else {
                // Change '1' to '0' and carry over
                tape[head] = '0';
                head--;
            }
        }
        // If we carried out from the leftmost bit, we need to add '1' at the start
        tape = '1' + tape;
    }

    std::string getResult() const {
        return tape;
    }

private:
    std::string tape;  // The tape with the binary number
    int head;          // The position of the head
};

int main() {
    std::string binaryNumber;
    std::cout << "Enter a binary number: ";
    std::cin >> binaryNumber;

    // Ensure the input is a valid binary number
    if (binaryNumber.find_first_not_of("01") != std::string::npos) {
        std::cerr << "Invalid binary number!" << std::endl;
        return 1;
    }

    TuringMachine tm(binaryNumber);
    tm.increment();
    std::cout << "Incremented binary number: " << tm.getResult() << std::endl;
    return 0;
}

