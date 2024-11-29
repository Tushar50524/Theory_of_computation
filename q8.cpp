#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to simulate the PDA
bool simulatePDA(const string &input) {
    stack<char> pdaStack;
    size_t i = 0;

    // Step 1: Push characters of `w` onto the stack until we reach 'X'
    while (i < input.length() && input[i] != 'X') {
        pdaStack.push(input[i]);
        i++;
    }

    // Step 2: Check for the presence of 'X' in the middle
    if (i == input.length() || input[i] != 'X') {
        return false; // Reject if there's no 'X' separating `w` and `w^r`
    }

    // Skip the 'X' character
    i++;

    // Step 3: Pop from the stack and match with `w^r`
    while (i < input.length()) {
        if (pdaStack.empty() || pdaStack.top() != input[i]) {
            return false; // Mismatch or stack empty before finishing `w^r`
        }
        pdaStack.pop();
        i++;
    }

    // Step 4: Accept if the stack is empty after processing all input
    return pdaStack.empty();
}

int main() {
    // Test cases
    string testStrings[] = { "aXa", "abbaXabba", "abXba", "abbXaab", "bXb", "aabXbaa", "aaXaa" , "aaabbaXabbaaa"};
    for (const string &test : testStrings) {
        cout << "Input: " << test << " => " 
             << (simulatePDA(test) ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}
