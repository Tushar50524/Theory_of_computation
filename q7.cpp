#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to simulate the PDA
bool simulatePDA(const string &input) {
    stack<char> pdaStack;

    // Step 1: Push 'A' onto the stack for each 'a' in the input
    size_t i = 0;
    while (i < input.length() && input[i] == 'a') {
        pdaStack.push('A');  // Push a marker for each 'a'
        i++;
    }

    // Step 2: Pop 'A' from the stack for each 'b' in the input
    while (i < input.length() && input[i] == 'b') {
        if (pdaStack.empty()) {
            return false; // More 'b's than 'a's, so reject
        }
        pdaStack.pop(); // Pop a marker for each 'b'
        i++;
    }

    // Step 3: Check if the stack is empty and we have processed the entire input
    return (pdaStack.empty() && i == input.length());
}

int main() {
    // Test cases
    string testStrings[] = { "ab", "aabb", "aaabbb", "aaaabbbb", "aaabb", "aabbb", "abbb", "a" };
    for (const string &test : testStrings) {
        cout << "Input: " << test << " => " 
             << (simulatePDA(test) ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}
