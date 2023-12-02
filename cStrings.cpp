// Assignment 8: Cheryl Lee
// This program deals with null terminated C-strings

#include <iostream>
#include <cstring>
using namespace std;

// Function 1: Returns the last index where target char can be found
int lastIndexOf(char *s, char target) {
        // Initialize the index to -1, indicating not found
    int index = -1;
    int i = 0;

    // Iterate through until the null terminator is reached
    while (s[i] != '\0') {
        // Update the index when the target character is found
        if (s[i] == target)
            index = i;
        i++;
    }
    return index;
}

// Function 2: Reverses the input string
void reverse(char *s) {
    int length = strlen(s);

    // Go through the string from both sides and swap characters
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

// Function 3: Replaces target characters with replacement characters
int replace(char *s, char target, char replacementChar) {
        int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == target) {
                // Replace target character
                s[i] = replacementChar;
                // Increment the replacements
                count++;
        }
    }
    return count;
}

// Function 4: Searches for a substring within the string and returns index
int findSubstring(char *s, char substring[]) {
        int strLen = strlen(s), subLen = strlen(substring);
    // Make sure there are enough characters to compare with the substring
    for (int i = 0; i <= strLen - subLen; i++) {
        bool found = true;

        // Compare characters from the current position to check for a match
        for (int j = 0; j < subLen; j++) {
            if (s[i + j] != substring[j]) {
                found = false;
                // Exit inner loop if mismatch is found
                break;
            }
        }
        if (found)
            return i;
    }
    return -1;
}

// Function 5: Determines if a string is a Palindrome
bool isPalindrome(char *s) {
        int length = strlen(s);

    // Go through string from both sides to check if same
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        if (s[i] != s[j])
            return false;
    }

    return true;
}

// EXTRA CREDIT: Function 6: Reverses the words within the string
void reverseWords(char *s) {
        int length = strlen(s);

    // Reverse the entire string with existing reverse function
    reverse(s);

    // Reverse individual words
    int start = 0;
    int end = 0;

    while (start < length) {
        // Find the start of a word
        while (start < length && s[start] == ' ') {
            start++;
        }

        // Find the end of the word
        end = start;
        while (end < length && s[end] != ' ') {
            end++;
        }

         // Reverse the word but keep spaces and punctuation.
        for (int i = start, j = end - 1; i < j; i++, j--) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }

        start = end;
    }
}

int main() {
    char str1[] = "Giants";
    char str2[] = "flower";
    char str3[] = "go giants";
    char str4[] = "Skyscraper";
    char substring[] = "ysc";
    char str5[] = "abba";
    char str6[] = "The Giants won the Pennant!";

    cout << "1. lastIndexOf: " << lastIndexOf(str1, 'a') << endl;
    reverse(str2);
    cout << "2. reverse: " << str2 << endl;
    cout << "3. replace: " << replace(str3, 'g', 'G') << ", " << str3 << endl;
    cout << "4. findSubstring: " << findSubstring(str4, substring) << endl;
    cout << "5. isPalindrome: ";
    if (isPalindrome(str5))
        cout << str5 << " is a Palindrome!" << endl;
    else
        cout << str5 << " is NOT a Palindrome." << endl;
    reverseWords(str6);
    cout << "6. reverseWords: " << str6 << endl;

    return 0;
}

/* SAMPLE OUTPUT
Test 1: Examples from Assignment Prompt (program output as is)
Output:
[clee750@hills ~]$ ./a.out
1. lastIndexOf: 2
2. reverse: rewolf
3. replace: 2, Go Giants
4. findSubstring: 2
5. isPalindrome: abba is a Palindrome!
6. reverseWords: Pennant! the won Giants The

Test 2: My Own Tests! Paste below into main function!
    char str1[] = "Hello, World!";
    char str2[] = "deified";
    char str3[] = "This is a test sentence.";
    char str4[] = "Happy feet";
    char substring[] = "ee";
    char str5[] = "Never odd or even";
    char str6[] = "Testing 1, 2, 3.";

    cout << "1. lastIndexOf: " << lastIndexOf(str1, 'l') << endl;
    reverse(str2);
    cout << "2. reverse: " << str2 << endl;
    cout << "3. replace: " << replace(str3, 't', 'T') << ", " << str3 << endl;
    cout << "4. findSubstring: " << findSubstring(str4, substring) << endl;
    cout << "5. isPalindrome: ";
    if (isPalindrome(str5))
    	cout << str5 << " is a Palindrome!" << endl;
    else
    	cout << str5 << " is NOT a Palindrome." << endl;
    reverseWords(str6);
    cout << "6. reverseWords: " << str6 << endl;
Output:
[clee750@hills ~]$ ./a.out
1. lastIndexOf: 10
2. reverse: deified
3. replace: 3, This is a TesT senTence.
4. findSubstring: 7
5. isPalindrome: Never odd or even is NOT a Palindrome.
6. reverseWords: 3. 2, 1, Testing

Test 3: My Own Tests! Paste below into main function!
    char str1[] = "osmosis otto";
    char str2[] = "spins";
    char str3[] = "hahahaha";
    char str4[] = "Mind the Gap";
    char substring[] = "gap";
    char str5[] = "++c++";
    char str6[] = "now? sense make this Does";

    cout << "1. lastIndexOf: " << lastIndexOf(str1, 'o') << endl;
    reverse(str2);
    cout << "2. reverse: " << str2 << endl;
    cout << "3. replace: " << replace(str3, 'a', 'h') << ", " << str3 << endl;
    cout << "4. findSubstring: " << findSubstring(str4, substring) << endl;
    cout << "5. isPalindrome: ";
    if (isPalindrome(str5))
    	cout << str5 << " is a Palindrome!" << endl;
    else
    	cout << str5 << " is NOT a Palindrome." << endl;
    reverseWords(str6);
    cout << "6. reverseWords: " << str6 << endl;
Output:
[clee750@hills ~]$ ./a.out
1. lastIndexOf: 11
2. reverse: snips
3. replace: 4, hhhhhhhh
4. findSubstring: -1
5. isPalindrome: ++c++ is a Palindrome!
6. reverseWords: Does this make sense now?
*/