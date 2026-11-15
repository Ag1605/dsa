
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {

        // minOpen = Minimum possible number of open brackets.
        // maxOpen = Maximum possible number of open brackets.
        int minOpen = 0;
        int maxOpen = 0;

        // Traverse the string character by character.
        for (int i = 0; i < s.size(); i++) {

            // Case 1: Opening bracket '('.
            // It increases both minimum and maximum open brackets.
            if (s[i] == '(') {
                minOpen++;
                maxOpen++;
            }

            // Case 2: Closing bracket ')'.
            // It decreases both minimum and maximum open brackets.
            else if (s[i] == ')') {
                minOpen--;
                maxOpen--;
            }

            // Case 3: Star '*'.
            // It can represent:
            // '('  -> Increase open brackets.
            // ')'  -> Decrease open brackets.
            // ''   -> Do nothing.
            else {
                minOpen--;
                maxOpen++;
            }

            // If maxOpen becomes negative,
            // even treating every '*' as '(' cannot
            // provide enough opening brackets.
            if (maxOpen < 0) {
                return false;
            }

            // Minimum possible open brackets cannot be negative.
            // We can treat some '*' as empty to avoid negative values.
            minOpen = max(minOpen, 0);
        }

        // At the end, we need at least one possibility
        // where all opening brackets are closed.
        return minOpen == 0;
    }
};

int main() {

    string s = "(*))";

    Solution obj;

    bool result = obj.checkValidString(s);

    if (result) {
        cout << "Valid Parenthesis String" << endl;
    }
    else {
        cout << "Invalid Parenthesis String" << endl;
    }

    return 0;
}
