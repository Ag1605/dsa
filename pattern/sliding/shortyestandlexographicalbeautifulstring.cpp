#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();

        // left = starting point of our sliding window
        int left = 0;

        // Stores how many '1's are currently inside the window
        int count1 = 0;

        // Stores our best answer
        string ans = "";

        // right expands the window one character at a time
        for (int right = 0; right < n; right++) {

            // If current character is '1',
            // increase the number of 1s in the window
            if (s[right] == '1') {
                count1++;
            }

            /*
                Now the window [left ... right] contains exactly k ones.

                We need to find the shortest substring containing
                exactly k ones.

                So we try to shrink the window from the left.
            */
            while (count1 == k) {

                // Create the current substring
                //
                // Example:
                // left = 2, right = 6
                // substring = s[2 ... 6]
                string curr = s.substr(left, right - left + 1);

                /*
                    Update answer if:

                    1. We don't have an answer yet
                       OR
                    2. Current substring is shorter
                       OR
                    3. Both have same length but current substring
                       is lexicographically smaller.
                */

                if (ans == "" || curr.size() < ans.size()) {

                    ans = curr;
                }
                else if (curr.size() == ans.size() && curr < ans) {

                    ans = curr;
                }

                /*
                    Now move left forward.

                    Before moving left, check whether s[left]
                    is '1'.

                    If it is '1', removing it from the window
                    decreases count1.
                */
                if (s[left] == '1') {
                    count1--;
                }

                // Shrink the window from the left
                left++;
            }
        }

        return ans;
    }
};


int main() {

    Solution obj;

    // Test case
    string s = "100011001";
    int k = 3;

    // Call the function
    string answer = obj.shortestBeautifulSubstring(s, k);

    // Print the answer
    cout << "Answer: " << answer << endl;

    return 0;
}