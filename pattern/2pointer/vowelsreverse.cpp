#include <iostream>
#include <string>
using namespace std;

// ---------------------------------------------------------
// Function: isvowel
// Purpose : Checks whether a given character is a vowel
// ---------------------------------------------------------
bool isvowel(char ch)
{

    // Return true if character is one of:
    // a, e, i, o, u
    // OR
    // A, E, I, O, U

    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' ||
           ch == 'O' || ch == 'U';
}

// ---------------------------------------------------------
// Function: reverseVowels
// Purpose : Reverse only the vowels of the string
// ---------------------------------------------------------
string reverseVowels(string s)
{

    // 'left' starts from the beginning of the string
    int left = 0;

    // 'right' starts from the end of the string
    int right = s.size() - 1;

    // Continue until the two pointers meet
    while (left < right)
    {

        // -------------------------------------------------
        // Move 'left' forward until we find a vowel
        //
        // Example:
        // "hello"
        //  ^
        // left = 0 -> 'h' is not vowel
        // left = 1 -> 'e' is vowel
        // -------------------------------------------------
        while (left < right && !isvowel(s[left]))
        {
            left++;
        }

        // -------------------------------------------------
        // Move 'right' backward until we find a vowel
        //
        // Example:
        // "hello"
        //       ^
        // right = 4 -> 'o' is vowel
        // -------------------------------------------------
        while (left < right && !isvowel(s[right]))
        {
            right--;
        }

        // -------------------------------------------------
        // Now:
        // s[left]  = vowel
        // s[right] = vowel
        //
        // Swap these two vowels.
        //
        // Example:
        // "hello"
        //  e     o
        //
        // After swap:
        // "holle"
        // -------------------------------------------------
        swap(s[left], s[right]);

        // Move both pointers towards the center
        left++;
        right--;
    }

    // Return the string after reversing the vowels
    return s;
}

// ---------------------------------------------------------
// main() - Program starts here
// ---------------------------------------------------------
int main()
{

    // Input string
    string s;

    cout << "Enter a string: ";
    cin >> s;

    // Call reverseVowels() function
    string result = reverseVowels(s);

    // Print the final answer
    cout << "After reversing vowels: " << result << endl;

    return 0;
}                   