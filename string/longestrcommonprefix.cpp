#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    // Function to find the longest common prefix
    // among all strings in the vector
    string longestCommonPrefix(vector<string>& strs) {

        // ---------------------------------------------------
        // STEP 1: Take the first string as our initial prefix
        // ---------------------------------------------------
        //
        // Example:
        // strs = {"flower", "flow", "flight"}
        //
        // Initially:
        // prefix = "flower"
        //
        // We will compare this prefix with every other string.
        string prefix = strs[0];


        // ---------------------------------------------------
        // STEP 2: Compare prefix with every other string
        // ---------------------------------------------------
        //
        // We start from index 1 because strs[0] is already
        // being used as our initial prefix.
        //
        // i = 1 -> compare with "flow"
        // i = 2 -> compare with "flight"
        //
        for (int i = 1; i < strs.size(); i++) {

            // j represents the character position
            // that we are currently comparing.
            //
            // Example:
            // prefix = "flower"
            // strs[i] = "flow"
            //
            // j = 0 -> compare 'f' with 'f'
            // j = 1 -> compare 'l' with 'l'
            // j = 2 -> compare 'o' with 'o'
            // j = 3 -> compare 'w' with 'w'
            int j = 0;


            // ---------------------------------------------------
            // STEP 3: Compare characters one by one
            // ---------------------------------------------------
            //
            // We continue while ALL three conditions are true:
            //
            // 1. j < prefix.size()
            //    -> j must be inside prefix
            //
            // 2. j < strs[i].size()
            //    -> j must be inside the current string
            //
            // 3. prefix[j] == strs[i][j]
            //    -> characters at position j must be equal
            //
            while (j < prefix.size() &&
                   j < strs[i].size() &&
                   prefix[j] == strs[i][j]) {

                // Characters matched successfully,
                // so move to the next character.
                j++;
            }


            // ---------------------------------------------------
            // STEP 4: Keep only the common part
            // ---------------------------------------------------
            //
            // Suppose:
            //
            // prefix = "flower"
            // strs[i] = "flow"
            //
            // Matching characters:
            //
            // f -> match
            // l -> match
            // o -> match
            // w -> match
            //
            // j becomes 4.
            //
            // substr(0, 4) gives:
            // "flow"
            //
            // So:
            // prefix = "flow"
            //
            // Now "flow" becomes our new prefix.
            prefix = prefix.substr(0, j);


            // ---------------------------------------------------
            // STEP 5: If prefix becomes empty
            // ---------------------------------------------------
            //
            // If there is not even ONE common character,
            // then there is no common prefix.
            //
            // Example:
            // strs = {"dog", "racecar", "car"}
            //
            // 'd' != 'r'
            //
            // Therefore j = 0
            // prefix = ""
            //
            // We can immediately return "".
            if (prefix.empty()) {
                return "";
            }
        }


        // ---------------------------------------------------
        // STEP 6: Return the final common prefix
        // ---------------------------------------------------
        //
        // After comparing with every string,
        // prefix contains the longest common prefix.
        return prefix;
    }
};


int main() {

    // ---------------------------------------------------
    // Example input
    // ---------------------------------------------------

    vector<string> strs = {
        "flower",
        "flow",
        "flight"
    };


    // Create an object of Solution class
    Solution obj;


    // Call the function
    string answer = obj.longestCommonPrefix(strs);


    // Print the result
    cout << "Longest Common Prefix: " << answer << endl;


    return 0;
}