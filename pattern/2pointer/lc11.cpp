#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Function to find the maximum amount of water
    // that can be stored between two vertical lines.
    int maxArea(vector<int>& height) {

        // left pointer starts from the first element
        int left = 0;

        // right pointer starts from the last element
        int right = height.size() - 1;

        // Stores the maximum area found so far
        int ans = 0;

        // Continue until the two pointers meet
        while (left < right) {

            // Width is the distance between the two pointers
            // Example: left = 1, right = 5
            // width = 5 - 1 = 4
            int width = right - left;

            // The water level is limited by the shorter line.
            // So we take the minimum of the two heights.
            int h = min(height[left], height[right]);

            // Area = width × height
            int area = width * h;

            // Compare the current area with the maximum area
            // found previously.
            //
            // IMPORTANT:
            // We are NOT declaring a new variable here.
            // We are updating the existing 'ans'.
            ans = max(area, ans);

            // If the left line is shorter,
            // move the left pointer to the right.
            //
            // Why?
            // Because keeping the shorter left line and
            // decreasing the width cannot give us a better
            // area. We need a potentially taller line.
            if (height[left] < height[right]) {
                left++;
            }

            // Otherwise, move the right pointer to the left.
            //
            // This includes the case where both heights are equal.
            else {
                right--;
            }
        }

        // Return the maximum area found
        return ans;
    }
};


int main() {

    // Example input
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Create an object of Solution class
    Solution obj;

    // Call maxArea() and store the returned answer
    int result = obj.maxArea(height);

    // Print the answer
    cout << "Maximum Area = " << result << endl;

    return 0;
}