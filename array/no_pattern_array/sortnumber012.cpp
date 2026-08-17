#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        // ------------------------------------------------
        // We use 3 pointers:
        //
        // low  -> position where the next 0 should go
        // mid  -> current element we are checking
        // high -> position where the next 2 should go
        //
        // At the beginning:
        //
        // low = 0
        // mid = 0
        // high = last index
        // ------------------------------------------------

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;


        // ------------------------------------------------
        // Continue while mid has not crossed high.
        //
        // Everything before low is already 0.
        // Everything between low and mid-1 is already 1.
        // Everything after high is already 2.
        // ------------------------------------------------

        while (mid <= high) {

            // ============================================
            // CASE 1: nums[mid] == 0
            // ============================================

            if (nums[mid] == 0) {

                // Put 0 at the beginning.
                //
                // nums[low] should contain 0.
                // So swap nums[low] and nums[mid].
                swap(nums[low], nums[mid]);

                // We have successfully placed a 0.
                // Move low forward.
                low++;

                // The current mid position is also processed,
                // so move mid forward.
                mid++;
            }


            // ============================================
            // CASE 2: nums[mid] == 1
            // ============================================

            else if (nums[mid] == 1) {

                // 1 is already in its correct middle region.
                //
                // Nothing needs to be swapped.
                // Just move to the next element.
                mid++;
            }


            // ============================================
            // CASE 3: nums[mid] == 2
            // ============================================

            else {

                // Put 2 at the end.
                //
                // Swap the current 2 with the element
                // at the high position.
                swap(nums[mid], nums[high]);

                // We have successfully placed a 2
                // at the end.
                high--;

                // IMPORTANT:
                // We do NOT increase mid here.
                //
                // Why?
                // Because after swapping, the new element
                // that came from nums[high] is now at nums[mid].
                //
                // We have NOT checked this new element yet.
                // So we must check nums[mid] again.
            }
        }
    }
};


int main() {

    // Example input
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    // Create Solution object
    Solution sol;

    // Sort the array
    sol.sortColors(nums);

    // Print sorted array
    for (int x : nums) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}