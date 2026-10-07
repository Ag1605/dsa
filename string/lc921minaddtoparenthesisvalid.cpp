#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {

        // balance = number of '(' that are currently
        // waiting for a matching ')'.
        int balance = 0;

        // ans = number of brackets we need to add
        // to make the string valid.
        int ans = 0;

        // Traverse the string character by character.
        for (int i = 0; i < s.size(); i++) {

            // If current character is '(',
            // we need one ')' in the future to match it.
            if (s[i] == '(') {
                balance++;
            }
            else {

                // Current character is ')'.
                // If we already have an unmatched '(',
                // this ')' can match it.
                if (balance > 0) {
                    balance--;
                }
                else {

                    // There is no '(' available to match
                    // this ')'.
                    //
                    // So we must add one '(' before it.
                    ans++;
                }
            }
        }

        // Any remaining '(' does not have a matching ')'.
        //
        // We need to add one ')' for every remaining '('.
        ans += balance;

        // Return the minimum number of brackets
        // that need to be added.
        return ans;
    }
};

int main() {

    // Example input
    string s = "()))((";

    // Create an object of Solution class.
    Solution obj;

    // Call the function.
    int answer = obj.minAddToMakeValid(s);

    // Print the minimum number of brackets
    // that need to be added.
    cout << "Minimum additions required: " << answer << endl;

    return 0;
}