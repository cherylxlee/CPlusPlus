// Assignment 9: Cheryl Lee
// This program prints out league standings using structs

#include <iostream>
#include<cstring>
using namespace std;

struct WinRecord {
        int wins;
        char* name;
};

// Provided function from Professor: read in a line of text and return it in a dynamically allocated array
char* getLine() {
        const int BUFFER_SIZE = 1000;

        // Allocate a buffer local to this function
        char buffer[BUFFER_SIZE];

        // Use cin.getline() to input the buffer from the user
        cin.getline(buffer, BUFFER_SIZE);

        // Find the length of the string in buffer
        int length = strlen(buffer);

        // Dynamically allocate an array, to be returned
        char *rValue = new char[length + 1];

        // Copy the string into the dynamically allocated array
        strncpy(rValue, buffer, length);

        // Return the address of the dynamically allocated array
        return rValue;
}

// Function to handle user input and initialize the WinRecord array.
void initializeData(WinRecord* standings, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter team #" << i + 1 << ": ";
        // Ignore any remaining newline character
        cin.ignore();
        standings[i].name = getLine();

        cout << "Enter the wins for team #" << i + 1 << ": ";
        cin >> standings[i].wins;
    }
}

// Function to sort teams and wins in descending order of wins using bubble sort
void sortData(WinRecord* standings, int size) {
        // Will be true if any swaps occur
        bool swapped;

        do {
                // Begins assuming no swaps have occurred
                swapped = false;

                for (int i = 0; i < (size - 1); i++) {
                        // Sort array in descending order by wins or, if equal, alphabetically
            if (standings[i].wins < standings[i + 1].wins || (standings[i].wins == standings[i + 1].wins && strcmp(standings[i].name, standings[i + 1].name) > 0)) {
                                WinRecord temp;
                                temp = standings[i];
                                standings[i] = standings[i + 1];
                                standings[i + 1] = temp;

                                swapped = true;
                        }
                } // Continue until no more swaps occur
        } while (swapped);
}

// Function to display league standings
void displayData(WinRecord* standings, int size) {
        cout << "\nLeague Standings:\n";

        for (int i = 0; i < size; i ++)
                cout << standings[i].name << ": " << standings[i].wins << endl;
}

// Main driver function to call the functions
int main() {
        WinRecord *record = NULL;
        int teamCount;

        cout << "How many teams will you enter? ";
        cin >> teamCount;

        record = new WinRecord[teamCount];

        initializeData(record, teamCount);
        sortData(record, teamCount);
        displayData(record, teamCount);

        // Deallocated memory to system for names and WinRecord to avoid memory leaks
        for (int i = 0; i < teamCount; i++) {
                delete [] record[i].name;
                record[i].name = NULL;
        }

        delete [] record;
        record = NULL;

        return 0;
}

/* SAMPLE OUTPUT
[clee750@hills ~]$ ./a.out
How many teams will you enter? 5
Enter team #1: Giants
Enter the wins for team #1: 2
Enter team #2: Padres
Enter the wins for team #2: 75
Enter team #3: Dodgers
Enter the wins for team #3: 1
Enter team #4: Diamond Backs
Enter the wins for team #4: 88
Enter team #5: Rockies
Enter the wins for team #5: 100

League Standings:
Rockies: 100
Diamond Backs: 88
Padres: 75
Giants: 2
Dodgers: 1
[clee750@hills ~]$ ./a.out
How many teams will you enter? 4
Enter team #1: Golden State Warriors
Enter the wins for team #1: 79
Enter team #2: Pheonix Suns
Enter the wins for team #2: 77
Enter team #3: LA Lakers
Enter the wins for team #3: 50
Enter team #4: Denver Nuggets
Enter the wins for team #4: 77

League Standings:
Golden State Warriors: 79
Denver Nuggets: 77
Pheonix Suns: 77
LA Lakers: 50
[clee750@hills ~]$ ./a.out
How many teams will you enter? 3
Enter team #1: Beans
Enter the wins for team #1: 88
Enter team #2: Pasta
Enter the wins for team #2: 89
Enter team #3: Zucchini
Enter the wins for team #3: 88

League Standings:
Pasta: 89
Beans: 88
Zucchini: 88
[clee750@hills ~]$ ./a.out
How many teams will you enter? 5
Enter team #1: LA Lakers
Enter the wins for team #1: 99
Enter team #2: Golden State Warriors
Enter the wins for team #2: 99
Enter team #3: Denver Nuggets
Enter the wins for team #3: 99
Enter team #4: Memphis Grizzlies
Enter the wins for team #4: 99
Enter team #5: LA Clippers
Enter the wins for team #5: 99

League Standings:
Denver Nuggets: 99
Golden State Warriors: 99
LA Clippers: 99
LA Lakers: 99
Memphis Grizzlies: 99
*/