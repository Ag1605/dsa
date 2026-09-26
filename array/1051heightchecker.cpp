#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solution class
class Solution {
public:

    // Function to find how many students are standing
    // in a position different from their expected position
    int heightChecker(vector<int>& heights) {

        // --------------------------------------------------
        // STEP 1: Create a copy of the original array
        // --------------------------------------------------
        //
        // We need to keep the original 'heights' array
        // unchanged because later we have to compare it
        // with the sorted array.
        //
        // Example:
        //
        // heights = [1, 1, 4, 2, 1, 3]
        //
        // expected = [1, 1, 4, 2, 1, 3]
        //
        vector<int> expected = heights;


        // --------------------------------------------------
        // STEP 2: Sort the copied array
        // --------------------------------------------------
        //
        // Students should stand in non-decreasing order
        // of height.
        //
        // Non-decreasing means:
        //
        // 1 <= 1 <= 1 <= 2 <= 3 <= 4
        //
        // Before sorting:
        // [1, 1, 4, 2, 1, 3]
        //
        // After sorting:
        // [1, 1, 1, 2, 3, 4]
        //
        sort(expected.begin(), expected.end());


        // This variable will store the number of
        // positions where the current height and
        // expected height are different.
        int count = 0;


        // --------------------------------------------------
        // STEP 3: Compare both arrays
        // --------------------------------------------------
        //
        // We compare the original array 'heights'
        // with the sorted array 'expected'.
        //
        for (int i = 0; i < heights.size(); i++) {

            // If the height at the current position
            // is different from the expected height,
            // then this student is in the wrong position.
            if (heights[i] != expected[i]) {

                // Increase the count.
                count++;
            }
        }


        // Return the total number of incorrect positions.
        return count;
    }
};


int main() {

    // --------------------------------------------------
    // INPUT
    // --------------------------------------------------
    //
    // Current order of students:
    //
    // Index:     0  1  2  3  4  5
    // heights:  [1, 1, 4, 2, 1, 3]
    //
    vector<int> heights = {1, 1, 4, 2, 1, 3};


    // Create an object of Solution class.
    Solution obj;


    // Call the function.
    int answer = obj.heightChecker(heights);


    // --------------------------------------------------
    // OUTPUT
    // --------------------------------------------------
    cout << "Number of students in wrong positions: "
         << answer << endl;


    return 0;
}