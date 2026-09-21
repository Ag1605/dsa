#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Function to sort characters of a string
    // based on their frequency.
    //
    // Example:
    // s = "tree"
    //
    // Frequencies:
    // t -> 1
    // r -> 1
    // e -> 2
    //
    // Answer can be:
    // "eetr" or "eert"
    //
    // because 'e' has the highest frequency.

    string frequencySort(string s) {

        // ------------------------------------------------
        // STEP 1: Create frequency array
        // ------------------------------------------------
        //
        // ASCII characters range from 0 to 127.
        //
        // freq[i] = number of times character with
        // ASCII value i appears.
        //
        // Initially every frequency is 0.

        int freq[128] = {0};


        // ------------------------------------------------
        // STEP 2: Count frequency of every character
        // ------------------------------------------------
        //
        // Example:
        // s = "tree"
        //
        // 't' -> freq['t']++
        // 'r' -> freq['r']++
        // 'e' -> freq['e']++
        // 'e' -> freq['e']++
        //
        // Final:
        // t -> 1
        // r -> 1
        // e -> 2

        for (int i = 0; i < s.length(); i++) {

            // Character automatically converts to
            // its ASCII value and is used as an index.
            freq[s[i]]++;
        }


        // ------------------------------------------------
        // STEP 3: Store character + frequency
        // ------------------------------------------------
        //
        // We create a vector of pairs.
        //
        // pair<char, int>
        //
        // first  -> character
        // second -> frequency
        //
        // Example:
        // ('t', 1)
        // ('r', 1)
        // ('e', 2)

        vector<pair<char, int>> v;


        // Check all possible ASCII characters
        for (int i = 0; i < 128; i++) {

            // Only store characters that actually
            // appeared in the string.
            if (freq[i] > 0) {

                // char(i) converts ASCII number back
                // into a character.
                v.push_back({char(i), freq[i]});
            }
        }


        // ------------------------------------------------
        // STEP 4: Sort characters by frequency
        // ------------------------------------------------
        //
        // We want HIGH frequency first.
        //
        // Example:
        //
        // ('t', 1)
        // ('r', 1)
        // ('e', 2)
        //
        // After sorting:
        //
        // ('e', 2)
        // ('t', 1)
        // ('r', 1)
        //
        // a.second = frequency of character a
        // b.second = frequency of character b
        //
        // > means higher frequency comes first.

        sort(v.begin(), v.end(),
             [](pair<char, int> a, pair<char, int> b) {

                 return a.second > b.second;
             });


        // ------------------------------------------------
        // STEP 5: Build the answer
        // ------------------------------------------------
        //
        // ans will contain characters arranged
        // according to their frequency.

        string ans = "";


        // Visit every character-frequency pair
        for (int i = 0; i < v.size(); i++) {

            // Repeat the character according to
            // its frequency.
            //
            // Example:
            // v[i] = ('e', 2)
            //
            // This loop adds:
            // 'e'
            // 'e'

            for (int j = 0; j < v[i].second; j++) {

                ans += v[i].first;
            }
        }


        // Return the final sorted string
        return ans;
    }
};


int main() {

    // Create an object of Solution class
    Solution obj;


    // Input string
    string s = "tree";


    // Call frequencySort()
    string answer = obj.frequencySort(s);


    // Print original string
    cout << "Original string: " << s << endl;


    // Print sorted string
    cout << "Frequency sorted string: "
         << answer << endl;


    return 0;
}