
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    string largestGoodInteger(string num) {

        // Stores the largest good integer found
        string ans = "";

        // Get the length of the string
        int n = num.size();

        // Check every substring of length 3
        for (int i = 0; i < n - 2; i++) {

            // Check whether all three digits are equal
            if (num[i] == num[i + 1] &&
                num[i + 1] == num[i + 2]) {

                // If answer is empty,
                // this is the first good integer
                //
                // Otherwise, compare the current digit
                // with the digit stored in ans
                if (ans == "" || num[i] > ans[0]) {

                    // Create a string containing
                    // three copies of the same digit
                    ans = string(3, num[i]);
                }
            }
        }

        // Return the largest good integer
        // If no good integer exists, return ""
        return ans;
    }
};

int main() {

    // Input string
    string num = "6777133339";

    // Create Solution object
    Solution obj;

    // Find the largest good integer
    string result = obj.largestGoodInteger(num);

    // Print the answer
    cout << "Largest Good Integer: " << result << endl;

    return 0;
}
