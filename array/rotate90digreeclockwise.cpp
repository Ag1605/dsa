#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to rotate the matrix 90 degrees clockwise.
    void rotate(vector<vector<int>>& matrix) {

        // Since the matrix is square,
        // number of rows = number of columns.
        int n = matrix.size();


        // ------------------------------------------------
        // STEP 1: TRANSPOSE THE MATRIX
        // ------------------------------------------------
        //
        // Transpose means:
        //
        // matrix[i][j] becomes matrix[j][i]
        //
        // In simple words:
        // rows become columns and columns become rows.
        //
        // Example:
        //
        // 1 2 3
        // 4 5 6
        // 7 8 9
        //
        // After transpose:
        //
        // 1 4 7
        // 2 5 8
        // 3 6 9


        // i represents the row.
        for (int i = 0; i < n; i++) {

            // Start j from i + 1.
            //
            // Why?
            // We only need to swap elements above
            // the main diagonal.
            //
            // The main diagonal is:
            // matrix[0][0]
            // matrix[1][1]
            // matrix[2][2]
            //
            // Those elements do not need to be swapped.
            for (int j = i + 1; j < n; j++) {

                // Swap the element at [i][j]
                // with the corresponding element at [j][i].
                swap(matrix[i][j], matrix[j][i]);
            }
        }


        // ------------------------------------------------
        // STEP 2: REVERSE EVERY ROW
        // ------------------------------------------------
        //
        // After transposing, reverse each row.
        //
        // Example after transpose:
        //
        // 1 4 7
        // 2 5 8
        // 3 6 9
        //
        // Reverse each row:
        //
        // 7 4 1
        // 8 5 2
        // 9 6 3
        //
        // This is the matrix rotated 90 degrees clockwise.

        for (int i = 0; i < n; i++) {

            // Reverse the current row.
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


int main() {

    // Example 3 x 3 matrix.
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Create an object of Solution class.
    Solution obj;

    // Rotate the matrix 90 degrees clockwise.
    obj.rotate(matrix);

    // Print the rotated matrix.
    cout << "Rotated Matrix:" << endl;

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[i].size(); j++) {

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}