/*Develop a calculator program that performs basic arithmetic
 operations such as addition, subtraction, multiplication, and
 division. Allow the user to input two numbers and choose an
 operation to perform.*/
#include <iostream>
using namespace std;
int main() {
    float num1, num2, result;
    char op;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            cout << "Invalid operator!";
            return 1;
    }
    cout << "Answer: " << num1 << " " << op << " " << num2 << " = " << result << endl;
    return 0;
}