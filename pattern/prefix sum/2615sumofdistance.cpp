#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<long long> distance(vector<int>& nums) {

        // n = size of the array
        int n = nums.size();

        // ans[i] will store the total distance for index i
        //
        // Example:
        // nums = [1, 3, 1, 1, 2]
        //
        // For index 0 (value 1):
        // matching values are at index 2 and 3
        //
        // answer = |0-2| + |0-3|
        //         = 2 + 3
        //         = 5
        vector<long long> ans(n, 0);


        // count[x] = how many times value x has appeared so far
        //
        // sum[x] = sum of all indexes where value x has appeared
        //
        // Example:
        // If we have seen value 5 at indexes 2, 4, 7:
        //
        // count[5] = 3
        // sum[5] = 2 + 4 + 7 = 13
        unordered_map<int, long long> count;
        unordered_map<int, long long> sum;


        // =========================================================
        //                LEFT TO RIGHT
        // =========================================================
        //
        // Here we calculate the distance from every index
        // to the SAME values appearing on its LEFT side.
        //
        // Suppose:
        //
        // nums = [1, 2, 1, 1]
        //                 ^
        //                 i = 3
        //
        // Value = 1
        //
        // Same values on the left are at indexes 0 and 2.
        //
        // Distance:
        // |3 - 0| + |3 - 2|
        // = 3 + 1
        // = 4
        //
        // We calculate this without checking every previous index.
        // =========================================================

        for (int i = 0; i < n; i++) {

            // Current value
            int x = nums[i];


            // Suppose the same value x appeared at indexes:
            //
            // p1, p2, p3, ...
            //
            // Since all these indexes are LEFT of i:
            //
            // |i - p| = i - p
            //
            // So:
            //
            // (i-p1) + (i-p2) + (i-p3)
            //
            // = i + i + i - (p1+p2+p3)
            //
            // = i * count[x] - sum[x]
            //
            // Therefore:
            //
            // i * count[x] = total contribution of i
            // sum[x]       = total previous indexes
            //
            ans[i] += (long long)i * count[x] - sum[x];


            // Now include the current index in our data.
            //
            // We do this AFTER calculating ans[i]
            // because we don't want index i to compare with itself.
            count[x]++;

            // Add current index to the sum of indexes.
            sum[x] += i;
        }


        // =========================================================
        // Reset the maps
        // =========================================================
        //
        // Now we want to calculate distances from the RIGHT side.
        //
        // So we start again with empty count and sum.
        // =========================================================

        count.clear();
        sum.clear();


        // =========================================================
        //                RIGHT TO LEFT
        // =========================================================
        //
        // Now we calculate the distance from every index
        // to the SAME values appearing on its RIGHT side.
        //
        // Example:
        //
        // nums = [1, 2, 1, 1]
        //        ^
        //        i = 0
        //
        // Same values on the right:
        // indexes 2 and 3
        //
        // Distance:
        //
        // |0 - 2| + |0 - 3|
        // = 2 + 3
        // = 5
        // =========================================================

        for (int i = n - 1; i >= 0; i--) {

            // Current value
            int x = nums[i];


            // All indexes stored in sum[x] are to the RIGHT of i.
            //
            // For a right-side index p:
            //
            // |i - p| = p - i
            //
            // Therefore:
            //
            // (p1-i) + (p2-i) + (p3-i)
            //
            // = (p1+p2+p3) - (i+i+i)
            //
            // = sum[x] - i * count[x]
            //
            ans[i] += sum[x] - (long long)i * count[x];


            // Add current index after calculating its answer.
            //
            // Again, we don't want the current index
            // to compare with itself.
            count[x]++;

            // Add current index to the sum.
            sum[x] += i;
        }


        // Return the final answer.
        //
        // At this point:
        //
        // ans[i] =
        // distance to same values on LEFT
        // +
        // distance to same values on RIGHT
        return ans;
    }
};


int main() {

    // Example input
    vector<int> nums = {1, 3, 1, 1, 2};

    // Create Solution object
    Solution obj;

    // Call the distance function
    vector<long long> result = obj.distance(nums);


    // Print the answer
    cout << "Answer: ";

    for (long long x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}