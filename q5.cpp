#include <iostream>
#include <string>

using namespace std;

// Function to simulate the FA for EVEN-EVEN
bool simulateEvenEvenFA(const string &input) {
    // Define states
    enum State { q_ee, q_eo, q_oe, q_oo };
    State currentState = q_ee;

    // Process each character in the input string
    for (char ch : input) {
        switch (currentState) {
            case q_ee:
                if (ch == 'a') {
                    currentState = q_oe;
                } else if (ch == 'b') {
                    currentState = q_eo;
                }
                break;

            case q_eo:
                if (ch == 'a') {
                    currentState = q_oo;
                } else if (ch == 'b') {
                    currentState = q_ee;
                }
                break;

            case q_oe:
                if (ch == 'a') {
                    currentState = q_ee;
                } else if (ch == 'b') {
                    currentState = q_oo;
                }
                break;

            case q_oo:
                if (ch == 'a') {
                    currentState = q_eo;
                } else if (ch == 'b') {
                    currentState = q_oe;
                }
                break;
        }
    }

    // Accept if the final state is q_ee
    return (currentState == q_ee);
}

int main() {
    // Test cases
    string testStrings[] = { "", "aa", "bb", "aabb", "abab", "abba", "a", "b", "ab", "ba", "bbb", "aaabbbb"};
    for (const string &test : testStrings) {
        cout << "Input: " << test << " => " 
             << (simulateEvenEvenFA(test) ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}
