#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// Function to reverse the required characters
string reverseStr(string s, int k) {

    // Start from the beginning of the string.
    //
    // We move by 2*k every time because
    // the rule applies to every block of 2*k characters.
    for (int i = 0; i < s.size(); i += 2 * k) {

        // Reverse the first k characters
        // of the current 2*k block.
        //
        // min() makes sure we don't go beyond
        // the end of the string.
        reverse(
            s.begin() + i,
            s.begin() + min(i + k, (int)s.size())
        );
    }

    // Return the modified string
    return s;
}


int main() {

    // Example
    string s = "abcdefg";
    int k = 2;

    // Call the function
    string result = reverseStr(s, k);

    // Print result
    cout << result << endl;

    return 0;
}