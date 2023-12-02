// Assignment 2: Cheryl Lee
// This program simulates a simplified version of the card game blackjack.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
        // Initiate variables, one set of "cards" for each player (dealer and you)
        char validate = 'y';
        int n1, n2, card, sum = 0, d1, dealCard, dealSum = 0;

        // Set general while loop for replaying the whole game
        while(validate == 'y') {
                // Set dealer's first random card at top of the game
                srand(time(0));
                d1 = rand() % 10 + 1;
                dealSum = d1;
                cout << "Dealer starts with a " << d1 << endl;

                // Show your cards and current total at game start
                srand(time(0));
                cout << "Your first cards: ";
                n1 = rand() % 10 + 1;
                n2 = rand() % 10 + 1;
                cout << n1 << ", " << n2 << endl;
                sum = n1 + n2;// sum of two cards
                cout << "Total: " << sum << endl;

                // Set while loop for additional "hits" of cards
                cout << "Do you want another card? (y/n): ";
                cin >> validate;

                while (validate == 'y') {
                        srand(time(0));
                        card = rand() % 10 + 1;
                        cout << "Card: " << card << endl;
                        sum += card;
                        cout << "Total: " << sum << endl;

                        if (sum > 21)
                                break;
                        else {
                                cout << "Do you want another card? (y/n): ";
                                cin >> validate;
                        }
                }

                // Sets conditions for whether the dealer begins to play
                if (sum > 21)
                        cout << "Bust. Dealer wins!" << endl;
                else {
                        cout << "The dealer has a " << d1 << "..." << endl;
                        validate = 'c';

                        // Set while loop for dealer to play, with the condition they must
                        // draw at least the total of 17
                        while (validate == 'c') {
                                srand(time(0));
                                dealCard = rand() % 10 + 1;
                                cout << "Dealer gets a " << dealCard << endl;
                                dealSum += dealCard;
                                cout << "Dealer Total: " << dealSum << endl;

                                if (dealSum > 21)
                                        break;
                                else {
                                        cout << "(c to continue, anything else to stop): ";
                                        cin >> validate;

                                        if (dealSum < 17 && validate != 'c') {
                                                cout << "Dealer Total must be at least 17!" << endl;
                                                validate = 'c';
                                        }
                                }
                        }

                        // Depending on the results, determine the winner
                        if (sum == dealSum)
                                cout << "Push!";
                        else if (dealSum > 21)
                                cout << "Dealer busts. You win!";
                        else if (sum > dealSum && sum < 22)
                                cout << "You win!";
                        else
                                cout << "Dealer wins!";

                        cout << endl;
                }

                cout << "Would you like to play again? (y/n): ";
                cin >> validate;
        }
}


/* SAMPLE OUTPUT
[clee750@hills ~]$ ./a.out
Dealer starts with a 10
Your first cards: 10, 9
Total: 19
Do you want another card? (y/n): n
The dealer has a 10...
Dealer gets a 5
Dealer Total: 15
(c to continue, anything else to stop): n
Dealer Total must be at least 17!
Dealer gets a 8
Dealer Total: 23
Dealer busts. You win!
Would you like to play again? (y/n): y
Dealer starts with a 5
Your first cards: 5, 9
Total: 14
Do you want another card? (y/n): n
The dealer has a 5...
Dealer gets a 1
Dealer Total: 6
(c to continue, anything else to stop): c
Dealer gets a 1
Dealer Total: 7
(c to continue, anything else to stop): c
Dealer gets a 5
Dealer Total: 12
(c to continue, anything else to stop): c
Dealer gets a 4
Dealer Total: 16
(c to continue, anything else to stop): c
Dealer gets a 2
Dealer Total: 18
(c to continue, anything else to stop): n
Dealer wins!
Would you like to play again? (y/n): n
[clee750@hills ~]$ ./a.out
Dealer starts with a 8
Your first cards: 8, 3
Total: 11
Do you want another card? (y/n): y
Card: 3
Total: 14
Do you want another card? (y/n): y
Card: 5
Total: 19
Do you want another card? (y/n): n
The dealer has a 8...
Dealer gets a 7
Dealer Total: 15
(c to continue, anything else to stop): c
Dealer gets a 5
Dealer Total: 20
(c to continue, anything else to stop): n
Dealer wins!
Would you like to play again? (y/n): y
Dealer starts with a 3
Your first cards: 3, 2
Total: 5
Do you want another card? (y/n): y
Card: 9
Total: 14
Do you want another card? (y/n): y
Card: 5
Total: 19
Do you want another card? (y/n): n
The dealer has a 3...
Dealer gets a 9
Dealer Total: 12
(c to continue, anything else to stop): n
Dealer Total must be at least 17!
Dealer gets a 10
Dealer Total: 22
Dealer busts. You win!
Would you like to play again? (y/n): y
Dealer starts with a 4
Your first cards: 4, 10
Total: 14
Do you want another card? (y/n): y
Card: 5
Total: 19
Do you want another card? (y/n): n
The dealer has a 4...
Dealer gets a 5
Dealer Total: 9
(c to continue, anything else to stop): c
Dealer gets a 8
Dealer Total: 17
(c to continue, anything else to stop): c
Dealer gets a 2
Dealer Total: 19
(c to continue, anything else to stop): n
Push!
Would you like to play again? (y/n): y
Dealer starts with a 2
Your first cards: 2, 1
Total: 3
Do you want another card? (y/n): y
Card: 1
Total: 4
Do you want another card? (y/n): y
Card: 6
Total: 10
Do you want another card? (y/n): y
Card: 7
Total: 17
Do you want another card? (y/n): y
Card: 3
Total: 20
Do you want another card? (y/n): n
The dealer has a 2...
Dealer gets a 10
Dealer Total: 12
(c to continue, anything else to stop): c
Dealer gets a 9
Dealer Total: 21
(c to continue, anything else to stop): n
Dealer wins!
Would you like to play again? (y/n): n
*/