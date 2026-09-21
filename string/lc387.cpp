#include <iostream>
using namespace std;

class Solution {
public:

    // Function returns the index of the first
    // character that appears only once.
    // If no unique character exists, return -1.
    int firstUniqChar(string s) {

        // freq[0] -> frequency of 'a'
        // freq[1] -> frequency of 'b'
        // ...
        // freq[25] -> frequency of 'z'
        //
        // Initially, all frequencies are 0.
        int freq[26] = {0};


        // ------------------------------------------------
        // STEP 1: Count the frequency of every character
        // ------------------------------------------------
        //
        // Example:
        // s = "leetcode"
        //
        // We visit every character:
        //
        // 'l' -> freq['l' - 'a']++
        // 'e' -> freq['e' - 'a']++
        // 'e' -> freq['e' - 'a']++
        // ...
        //
        // s[i] - 'a' converts a character into an index.
        //
        // 'a' - 'a' = 0
        // 'b' - 'a' = 1
        // 'c' - 'a' = 2
        // ...
        // 'z' - 'a' = 25

        for (int i = 0; i < s.length(); i++) {

            // Increase the frequency of current character
            freq[s[i] - 'a']++;
        }


        // ------------------------------------------------
        // STEP 2: Find the first character with frequency 1
        // ------------------------------------------------
        //
        // We again go from LEFT to RIGHT.
        //
        // This is important because the question asks
        // for the FIRST unique character.
        //
        // Example:
        // s = "leetcode"
        //
        // l -> frequency 1 -> return index 0
        //
        // If l was repeated, we would continue.

        for (int i = 0; i < s.length(); i++) {

            // If current character occurs exactly once,
            // then it is the first unique character.
            if (freq[s[i] - 'a'] == 1) {

                // Return its index
                return i;
            }
        }


        // If we reach here, it means every character
        // appears more than once.
        //
        // Therefore, there is no unique character.
        return -1;
    }
};


int main() {

    // Create an object of Solution class
    Solution obj;


    // Example input
    string s = "leetcode";


    // Call the function
    int answer = obj.firstUniqChar(s);


    // Print the answer
    cout << "Index of first unique character: "
         << answer << endl;


    // Print the actual character if a unique
    // character exists
    if (answer != -1) {
        cout << "First unique character: "
             << s[answer] << endl;
    }
    else {
        cout << "No unique character found." << endl;
    }


    return 0;
}