#include <iostream>
#include <string>
using namespace std;
bool acceptsTwoOrThreeOnes(const string& input) {
    int state = 0; // Start at state q0
    int oneCount = 0; // Count of '1's

    for (char ch : input) {
        switch (state) {
            case 0: // q0
                if (ch == '0') {
                    state = 0; // Stay in q0
                } else if (ch == '1') {
                    state = 1; // Move to q1
                    oneCount++;
                }
                break;
            case 1: // q1
                if (ch == '0') {
                    state = 1; // Stay in q1
                } else if (ch == '1') {
                    state = 2; // Move to q2
                    oneCount++;
                }
                break;
            case 2: // q2
                if (ch == '0') {
                    state = 2; // Stay in q2
                } else if (ch == '1') {
                    state = 3; // Move to q3
                    oneCount++;
                }
                break;
            case 3: // q3 (accepting state)
                if (ch == '0') {
                    state = 3; // Stay in q3
                } else if (ch == '1') {
                    state = 4; // Move to q4 (dead state)
                }
                break;
            case 4: // q4 (dead state)
                // Stay in dead state on any input
                break;
        }
    }
    // The string is accepted if we end in q2 or q3
    return (state == 2 || state == 3);
}

int main() {
    string input;

    cout << "Enter a binary string: ";
    getline(cin, input);

    if (acceptsTwoOrThreeOnes(input)) {
        cout << "Accepted: The string contains exactly two or three '1's." << endl;
    } else {
        cout << "Rejected: The string does not contain exactly two or three '1's." << endl;
    }
    return 0; // Indicating successful completion of the program
}