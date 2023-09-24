#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stk;

    while (true) {
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: // Push
                int value;
                cin >> value;
                stk.push(value);
                break;

            case 2: // Pop
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    cout << "Stack is empty. Cannot perform a pop operation." << endl;
                }
                break;

            case 3: // Display
                if (stk.empty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Elements in the stack:";
                    stack<int> tempStk = stk;
                    while (!tempStk.empty()) {
                        cout << " " << tempStk.top();
                        tempStk.pop();
                    }
                    cout << endl;
                }
                break;

            case 4: // Exit
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}

