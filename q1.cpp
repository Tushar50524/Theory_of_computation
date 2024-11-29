#include <iostream>
#include <string>

using namespace std;

bool acceptsThreeConsecutiveOnes(const string& input) {
    int state = 0; // Start at state q0

    for (char ch : input) {
        switch (state) {
            case 0: // q0
                if (ch == '0') {
                    state = 0; // Stay in q0
                } else if (ch == '1') {
                    state = 1; // Move to q1
                }
                break;
            case 1: // q1
                if (ch == '0') {
                    state = 0; // Go back to q0
                } else if (ch == '1') {
                    state = 2; // Move to q2
                }
                break;
            case 2: // q2
                if (ch == '0') {
                    state = 0; // Go back to q0
                } else if (ch == '1') {
                    state = 3; // Move to q3 (accepting)
                }
                break;
            case 3: // q3 (accepting)
                // Remain in accepting state on '0' or '1'
                state = 3; // Stay in q3
                break;
        }
    }

    // Check if we are in an accepting state
    return (state == 3 || state == 4);
}

int main() {
    string input;

    cout << "Enter a binary string: ";
    getline(cin, input);

    if (acceptsThreeConsecutiveOnes(input)) {
        cout << "Accepted: The string contains '111'." << endl;
    } else {
        cout << "Rejected: The string does not contain '111'." << endl;
    }

    return 0; // Indicating successful completion of the program
}