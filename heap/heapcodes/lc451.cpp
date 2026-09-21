#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:

    string frequencySort(string s) {

        // ------------------------------------------------
        // STEP 1: Create frequency array
        // ------------------------------------------------
        //
        // ASCII characters range from 0 to 127.
        //
        // freq[i] = how many times the character
        //           with ASCII value i appears.
        //
        // Initially all values are 0.

        int freq[128] = {0};


        // ------------------------------------------------
        // STEP 2: Count frequency of each character
        // ------------------------------------------------
        //
        // Example:
        // s = "tree"
        //
        // t -> 1
        // r -> 1
        // e -> 2

        for (int i = 0; i < s.length(); i++) {

            // s[i] is used as an ASCII index.
            //
            // For example:
            // s[i] = 'e'
            //
            // freq['e']++
            //
            // This increases the frequency of 'e'.

            freq[s[i]]++;
        }


        // ------------------------------------------------
        // STEP 3: Create a MAX HEAP
        // ------------------------------------------------
        //
        // pair<int, char>
        //
        // first  -> frequency
        // second -> character
        //
        // priority_queue is a MAX HEAP by default.
        //
        // Therefore, the pair with the largest
        // frequency will come to the top.
        //
        // Example:
        //
        // {2, 'e'}
        // {1, 't'}
        // {1, 'r'}
        //
        // pq.top() will be:
        //
        // {2, 'e'}

        priority_queue<pair<int, char>> pq;


        // ------------------------------------------------
        // STEP 4: Put character + frequency into heap
        // ------------------------------------------------
        //
        // Check all 128 ASCII characters.

        for (int i = 0; i < 128; i++) {

            // Only insert characters that exist
            // in the string.

            if (freq[i] > 0) {

                // Store:
                //
                // {frequency, character}
                //
                // Example:
                // {2, 'e'}

                pq.push({freq[i], char(i)});
            }
        }


        // ------------------------------------------------
        // STEP 5: Build the answer
        // ------------------------------------------------

        string ans = "";


        // Continue until the heap becomes empty.

        while (!pq.empty()) {

            // Get the pair at the top.
            //
            // Since this is a MAX HEAP,
            // highest frequency is at the top.

            int frequency = pq.top().first;

            char ch = pq.top().second;


            // Remove this element from the heap.

            pq.pop();


            // ------------------------------------------------
            // STEP 6: Add the character 'frequency' times
            // ------------------------------------------------
            //
            // Example:
            //
            // frequency = 2
            // ch = 'e'
            //
            // We add:
            //
            // e
            // e

            for (int i = 0; i < frequency; i++) {

                ans += ch;
            }
        }


        // Return the final string.

        return ans;
    }
};


int main() {

    // Create object of Solution class.

    Solution obj;


    // Input string.

    string s = "tree";


    // Call frequencySort().

    string answer = obj.frequencySort(s);


    // Print original string.

    cout << "Original string: " << s << endl;


    // Print frequency sorted string.

    cout << "Frequency sorted string: "
         << answer << endl;


    return 0;
}