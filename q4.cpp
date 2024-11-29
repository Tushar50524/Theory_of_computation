#include <iostream>
#include <string>
using namespace std;
// Function to simulate the FA
bool simulateFA(const string &input) {
    // Define states
    enum State { q0, q1, q2 };
    State currentState = q0;

    // Process each character in the input string
    for (char ch : input) {
        switch (currentState) {
            case q0:
                if (ch == 'a') {
                    currentState = q1;  // Move to q1 on initial 'a'
                } else {
                    return false;  // Reject if it doesn't start with 'a'
                }
                break;

            case q1:
                if (ch == 'a') {
                    currentState = q1;  // Stay in q1 on 'a'
                } else if (ch == 'b') {
                    currentState = q2;  // Move to q2 on 'b'
                }
                break;

            case q2:
                if (ch == 'a') {
                    currentState = q1;  // Return to q1 on 'a'
                } else if (ch == 'b') {
                    currentState = q2;  // Stay in q2 on 'b'
                }
                break;
        }
    }
    // Accept if the final state is q2
    return (currentState == q2);
}
int main() {
    // Test cases
    string testStrings[] = { "ab", "aab", "abb", "aaabb", "abab", "abba", "a", "b" , "ababbab" , "abaab","aababab" };
    for (const string &test : testStrings) {
        cout << "Input: " << test << " => " 
             << (simulateFA(test) ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}

