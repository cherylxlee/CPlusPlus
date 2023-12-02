// Assignment 11: Cheryl Lee
// NumberGuesser main program - main.cpp

#include <iostream>
#include "NumberGuesser.h"
using namespace std;

// Function to prompt the user and get the response to the current guess
char getUserResponseToGuess(int guess) {
    char response;
    cout << "Is the number " << guess << "? (h/l/c): ";
    cin >> response;
    return response;
}

// Function to ask the user if they want to play again
bool shouldPlayAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    return response == 'y';
}

// Play a single game using the provided NumberGuesser
void playOneGame(NumberGuesser &guesser) {
    char response = ' ';
    guesser.reset(); // Reset the guesser to its initial state

    do {
        int guess = guesser.getCurrentGuess();
        response = getUserResponseToGuess(guess);

        // Adjust the guess range based on the user's response
        if (response == 'h') {
            guesser.higher();
        } else if (response == 'l') {
            guesser.lower();
        } else if (response != 'c') {
            cout << "Please enter 'h', 'l', or 'c'." << endl;
        }
    } while (response != 'c'); // Continue until the correct guess is made

    cout << "You picked " << guesser.getCurrentGuess() << "? Great pick." << endl;
}

// Main function to run the number guessing game
int main() {
    // Instantiate a NumberGuesser object with the default range
    NumberGuesser guesser;
    cout << "Think of a number between " << guesser.getLowerBound() << " and "
         << guesser.getUpperBound() << "." << endl;

    do {
        playOneGame(guesser);
    } while (shouldPlayAgain()); // Ask if the user wants to play again

    cout << "Goodbye." << endl;

    return 0;
}

/* SAMPLE OUTPUT
TEST 1: Using default NumberGuesser constructor (between 1 and 100)
[clee750@hills ~]$ ./a.out
Think of a number between 1 and 100.
Is the number 50? (h/l/c): h
Is the number 75? (h/l/c): h
Is the number 88? (h/l/c): l
Is the number 81? (h/l/c): l
Is the number 78? (h/l/c): h
Is the number 79? (h/l/c): c
You picked 79? Great pick.
Do you want to play again? (y/n): y
Is the number 50? (h/l/c): l
Is the number 25? (h/l/c): h
Is the number 37? (h/l/c): h
Is the number 43? (h/l/c): l
Is the number 40? (h/l/c): l
Is the number 38? (h/l/c): h
Is the number 39? (h/l/c): c
You picked 39? Great pick.
Do you want to play again? (y/n): y
Is the number 50? (h/l/c): l
Is the number 25? (h/l/c): l
Is the number 12? (h/l/c): l
Is the number 6? (h/l/c): l
Is the number 3? (h/l/c): l
Is the number 1? (h/l/c): l
Is the number 1? (h/l/c): l
Is the number 1? (h/l/c): c
You picked 1? Great pick.
Do you want to play again? (y/n): y
Is the number 50? (h/l/c): h
Is the number 75? (h/l/c): h
Is the number 88? (h/l/c): h
Is the number 94? (h/l/c): h
Is the number 97? (h/l/c): h
Is the number 99? (h/l/c): h
Is the number 100? (h/l/c): h
Is the number 100? (h/l/c): h
Is the number 100? (h/l/c): c
You picked 100? Great pick.
Do you want to play again? (y/n): n
Goodbye.

TEST 2: Using parameterized constructor: guesser((25,35)
[clee750@hills ~]$ ./a.out
Think of a number between 25 and 35.
Is the number 30? (h/l/c): h
Is the number 33? (h/l/c): h
Is the number 34? (h/l/c): c
You picked 34? Great pick.
Do you want to play again? (y/n): y
Is the number 30? (h/l/c): l
Is the number 27? (h/l/c): h
Is the number 28? (h/l/c): h
Is the number 29? (h/l/c): c
You picked 29? Great pick.
Do you want to play again? (y/n): y
Is the number 30? (h/l/c): l
Is the number 27? (h/l/c): l
Is the number 25? (h/l/c): l
Is the number 25? (h/l/c): c
You picked 25? Great pick.
Do you want to play again? (y/n): y
Is the number 30? (h/l/c): h
Is the number 33? (h/l/c): h
Is the number 34? (h/l/c): h
Is the number 35? (h/l/c): h
Is the number 35? (h/l/c): h
Is the number 35? (h/l/c): c
You picked 35? Great pick.
Do you want to play again? (y/n): n
Goodbye.

TEST 2: Using parameterized constructor: guesser(149,177)
[clee750@hills ~]$ ./a.out
Think of a number between 149 and 177.
Is the number 163? (h/l/c): l
Is the number 155? (h/l/c): l
Is the number 151? (h/l/c): l
Is the number 149? (h/l/c): h
Is the number 150? (h/l/c): c
You picked 150? Great pick.
Do you want to play again? (y/n): y
Is the number 163? (h/l/c): h
Is the number 170? (h/l/c): h
Is the number 174? (h/l/c): h
Is the number 176? (h/l/c): h
Is the number 177? (h/l/c): h
Is the number 177? (h/l/c): h
Is the number 177? (h/l/c): c
You picked 177? Great pick.
Do you want to play again? (y/n): n
Goodbye.
*/