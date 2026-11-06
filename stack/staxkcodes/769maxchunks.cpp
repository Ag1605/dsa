
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        // Stores the maximum element encountered so far
        int maxElement = 0;

        // Stores the total number of valid chunks
        int chunks = 0;

        // Traverse the entire array
        for (int i = 0; i < arr.size(); i++) {

            // Step 1: Update the maximum element
            // encountered from index 0 to i
            maxElement = max(maxElement, arr[i]);

            // Step 2: Check whether we can divide
            // the array at the current index
            if (maxElement == i) {

                // All elements up to this index
                // belong to the correct range
                chunks++;
            }
        }

        // Return maximum number of chunks
        return chunks;
    }
};

int main() {

    // Input array (permutation of 0 to n-1)
    vector<int> arr = {1, 0, 2, 3, 4};

    // Create Solution object
    Solution obj;

    // Call the function
    int result = obj.maxChunksToSorted(arr);

    // Print the answer
    cout << "Maximum number of chunks: " << result << endl;

    return 0;
}
