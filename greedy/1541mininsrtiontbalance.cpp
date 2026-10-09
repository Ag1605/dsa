
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {

        int ans = 0;   // Minimum insertions required
        int need = 0;  // Closing ')' characters still required

        for (int i = 0; i < s.size(); i++) {

            // Case 1: Opening parenthesis '('
            if (s[i] == '(') {

                // If need is odd, we have an unmatched ')'
                // requirement from a previous opening bracket.
                // Insert one ')' to complete the pair.
                if (need % 2 == 1) {
                    ans++;
                    need--;
                }

                // Every '(' requires two closing parentheses.
                need += 2;
            }

            // Case 2: Closing parenthesis ')'
            else {

                // This ')' satisfies one required closing bracket.
                need--;

                // More ')' appeared than required.
                // Insert an '(' to match this closing bracket.
                if (need < 0) {
                    ans++;

                    // The inserted '(' requires one additional ')'.
                    need = 1;
                }
            }
        }

        // Insert all missing closing parentheses.
        ans += need;

        return ans;
    }
};

int main() {

    Solution obj;

    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    cout << "Minimum insertions: "
         << obj.minInsertions(s) << endl;

    return 0;
}
