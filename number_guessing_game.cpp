/* Create a program that generates a random number and asks the
 user to guess it. Provide feedback on whether the guess is too
 high or too low until the user guesses the correct number.*/
#include <iostream>
#include <time.h>
using namespace std;
int main() {
    int number, guess, tries = 0;
    srand(time(0)); // seed random number generator
    number = rand() % 100 + 1; // random number between 1 to 100
    cout << "Guess the Number\n";
    do {
        cout << "Guess a number between 1 to 100 : ";
        cin >> guess;
        tries++;
        if (guess > number) {
            cout << "Too high!\n";
        } else if (guess < number) {
            cout << "Too low!\n";
        } else {
            cout << "\nCorrect! You did it in " << tries << " guesses!\n";
        }
    } while (guess != number);
    return 0;
}

