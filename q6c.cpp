#include <iostream>
#include <string>

using namespace std;

// FA for L1: Accepts strings that start with 'a' and end with 'b'
bool simulateFA_L1(const string &input) {
    if (input.length() < 2) return false; // Minimum length for "a...b" is 2
    return (input[0] == 'a' && input[input.length() - 1] == 'b');
}

// FA for L2: Accepts strings that contain "aa" as a substring
bool simulateFA_L2(const string &input) {
    for (size_t i = 0; i < input.length() - 1; ++i) {
        if (input[i] == 'a' && input[i + 1] == 'a') {
            return true;
        }
    }
    return false;
}

// Concatenation of L1 and L2: Accept if input can be split such that
// the first part is accepted by L1 and the second part is accepted by L2
bool simulateFA_Concatenation(const string &input) {
    for (size_t i = 1; i < input.length(); ++i) {
        string part1 = input.substr(0, i);    // First part for L1
        string part2 = input.substr(i);       // Second part for L2
        if (simulateFA_L1(part1) && simulateFA_L2(part2)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Test cases
    string testStrings[] = { "ab", "aab", "aabaa", "aabba", "aabaaa", "aaab", "abb", "aaabb", "abbabbbabaab" , "aabbbab"};
    for (const string &test : testStrings) {
        cout << "Input: " << test << " => " 
             << (simulateFA_Concatenation(test) ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}
