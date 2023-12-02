// Assignment 11: Cheryl Lee
// NumberGuesser header - NumberGuesser.h

#ifndef NUMBERGUESSER_H
#define NUMBERGUESSER_H

class NumberGuesser {
	private:
		int lowerBound;             // Current lower bound for the guess
		int upperBound;             // Current upper bound for the guess
		int originalLowerBound;     // Original lower bound for resetting
		int originalUpperBound;     // Original upper bound for resetting

	public:
		// Constructors
		NumberGuesser();            // Default constructor with a standard range of 1 to 100
		NumberGuesser(int lowerBound, int upperBound); // Constructor with specified range

		// Member functions
		void higher();              // Adjust the range assuming the guess needs to be higher
		void lower();               // Adjust the range assuming the guess needs to be lower
		int getCurrentGuess() const; // Calculate and return the current guess
		void reset();               // Reset the guess range to the original bounds

		// Accessor methods
		int getLowerBound() const { return lowerBound; } // Get the current lower bound
		int getUpperBound() const { return upperBound; } // Get the current upper bound
};

#endif
