#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    string finalString(string s) {

        string ans = "";

        for (char ch : s) {

            // If we type 'i',
            // reverse whatever is currently on screen
            if (ch == 'i') {
                reverse(ans.begin(), ans.end());
            }
            else {
                // Otherwise, simply type the character
                ans += ch;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s = "string";

    cout << obj.finalString(s);

    return 0;
}