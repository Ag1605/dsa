#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to generate Pascal's Triangle
    // with numRows rows.
    vector<vector<int>> generate(int numRows) {

        // 2D vector to store the complete
        // Pascal's Triangle.
        vector<vector<int>> ans;


        // Loop through each row.
        //
        // i = 0 → first row
        // i = 1 → second row
        // i = 2 → third row
        // ...
        for (int i = 0; i < numRows; i++) {

            // Create the current row with i + 1 elements.
            //
            // Every row starts and ends with 1,
            // so initially we fill the entire row with 1.
            //
            // Example:
            //
            // i = 0 → [1]
            // i = 1 → [1, 1]
            // i = 2 → [1, 1, 1]
            // i = 3 → [1, 1, 1, 1]
            vector<int> row(i + 1, 1);


            // Calculate the middle elements.
            //
            // We start from index 1 because index 0
            // is always 1.
            //
            // We stop at i - 1 because the last element
            // is also always 1.
            for (int j = 1; j < i; j++) {

                // Each middle element is calculated by
                // adding the two elements directly above it.
                //
                //             1
                //           1   1
                //         1   2   1
                //
                // For example, to calculate 2:
                //
                // 1 + 1 = 2
                //
                // Therefore:
                //
                // current row[j] =
                // previous row[j-1] + previous row[j]
                row[j] = ans[i - 1][j - 1]
                       + ans[i - 1][j];
            }


            // Add the completed row to the answer.
            ans.push_back(row);
        }


        // Return the complete Pascal's Triangle.
        return ans;
    }
};


int main() {

    // Number of rows we want.
    int numRows = 5;

    // Create an object of Solution class.
    Solution obj;

    // Generate Pascal's Triangle.
    vector<vector<int>> answer = obj.generate(numRows);


    // Print Pascal's Triangle.
    cout << "Pascal's Triangle:" << endl;

    for (int i = 0; i < answer.size(); i++) {

        for (int j = 0; j < answer[i].size(); j++) {

            cout << answer[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}