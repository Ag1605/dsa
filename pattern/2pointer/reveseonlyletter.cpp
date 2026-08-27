#include <iostream>
#include <string>
#include <cctype>
using namespace std;


// Function to reverse only the letters
string reverseOnlyLetters(string s) {

    // Two pointers
    // left starts from the beginning
    // right starts from the end
    int left = 0;
    int right = s.length() - 1;


    // Continue until the two pointers meet
    while (left < right) {

        // If the character at left is NOT a letter,
        // we cannot swap it.
        // So simply move left forward.
        if (!isalpha(s[left])) {
            left++;
        }

        // If the character at right is NOT a letter,
        // we cannot swap it.
        // So move right backward.
        else if (!isalpha(s[right])) {
            right--;
        }

        // If both characters are letters,
        // swap them.
        else {
            swap(s[left], s[right]);

            // Move both pointers toward the center
            left++;
            right--;
        }
    }

    // Return the modified string
    return s;
}


int main() {

    // Test case
    string s = "ab-cd";

    // Call the function
    string result = reverseOnlyLetters(s);

    // Print the answer
    cout << result << endl;

    return 0;
}