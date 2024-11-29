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

// Union of L1 and L2: Accept if either L1 or L2 accepts the string
bool simulateFA_Union(const string &input) {
    return simulateFA_L1(input) || simulateFA_L2(input);
}

int main() {
    // Test cases
    string testStrings[] = { "ab", "aab", "aa", "bbaa", "ba", "aabb", "aaab", "bb","aaaaab" };
    for (const string &test : testStrings) {
        cout << "Input: " << test << " => " 
             << (simulateFA_Union(test) ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}
