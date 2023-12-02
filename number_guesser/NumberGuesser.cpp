// Assignment 11: Cheryl Lee
// NumberGuesser class implementation - NumberGuesser.cpp

#include "NumberGuesser.h"

// Default constructor implementation
NumberGuesser::NumberGuesser()
    : lowerBound(1), upperBound(100), originalLowerBound(1), originalUpperBound(100) {}

// Constructor with specified range implementation
NumberGuesser::NumberGuesser(int lowerBound, int upperBound)
    : lowerBound(lowerBound), upperBound(upperBound), originalLowerBound(lowerBound), originalUpperBound(upperBound) {}

// Increase the lower bound to be one more than the current guess
void NumberGuesser::higher() {
    lowerBound = getCurrentGuess() + 1;
}

// Decrease the upper bound to be one less than the current guess
void NumberGuesser::lower() {
    int currentGuess = getCurrentGuess();
    if (currentGuess <= lowerBound) {
        // If the current guess is already at or below the lower bound, do nothing
        return;
    }
    upperBound = currentGuess - 1;
}

// Calculate the midpoint between the current upper and lower bounds to guess
int NumberGuesser::getCurrentGuess() const {
    return (lowerBound + upperBound) / 2;
}

// Reset the guess range to the original bounds
void NumberGuesser::reset() {
    lowerBound = originalLowerBound;
    upperBound = originalUpperBound;
}
