/*
Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.
*/

//including necessary header files

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Function to display the operation history
void displayHistory(const vector<string>& history) {
    cout << "Operation History:" << endl;
    for (const string& entry : history) {
        cout << entry << endl;
    }
}

int main() {
    char operation;
    double num1, num2;
    vector<string> history;  // To store the history of operations
    cout << "*****************" << endl;
    cout << "Simple Calculator" << endl;
    cout << "*****************" << endl;

    while (true) {
        cout<<endl;
        cout << "----------------------" << endl;

        cout << "Options:" << endl;
        cout << "1. Calculate" << endl;
        cout << "2. History" << endl;
        cout << "3. Exit" << endl;
        cout<<endl;

        cout << "Choose an option (1/2/3): ";
        int choice;
        cin >> choice;
        cout<<endl;

        if (choice == 1) {
            // Input the first number
            cout << "Enter the first number: ";
            cin >> num1;

            // Input the second number
            cout << "Enter the second number: ";
            cin >> num2;

            // Choose the operation
            cout << "Choose an operation (+, -, *, /, %): ";
            cin >> operation;
            cout<<endl;

            string operationStr = to_string(num1) + " " + operation + " " + to_string(num2) + " = ";

            // Perform the operation and add it to history
            switch (operation) {
                case '+':
                    cout << "Result: " << num1 + num2 << endl;
                    operationStr += to_string(num1 + num2);
                    break;
                case '-':
                    cout << "Result: " << num1 - num2 << endl;
                    operationStr += to_string(num1 - num2);
                    break;
                case '*':
                    cout << "Result: " << num1 * num2 << endl;
                    operationStr += to_string(num1 * num2);
                    break;
                case '/':
                    if (num2 != 0) {
                        cout << "Result: " << num1 / num2 << endl;
                        operationStr += to_string(num1 / num2);
                    } else {
                        cout << "Error: Division by zero is not allowed." << endl;
                        operationStr += "Error: Division by zero";
                    }
                    break;
                case '%':
                    if (num2 != 0) {
                        cout << "Result: " << fmod(num1, num2) << endl;
                        operationStr += to_string(fmod(num1, num2));
                    } else {
                        cout << "Error: Modulo by zero is not allowed." << endl;
                        operationStr += "Error: Modulo by zero";
                    }
                    break;
                default:
                    cout << "Error: Invalid operation." << endl;
                    operationStr += "Error: Invalid operation";
            }

            history.push_back(operationStr); // Add the operation to history
        } else if (choice == 2) {
            displayHistory(history);
        } else if (choice == 3) {
            break; // Exit the program
        } else {
            cout << "Invalid option. Please choose 1, 2, or 3." << endl;
        }
    }

    return 0;
}