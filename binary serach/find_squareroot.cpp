#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to compute the floor of
       square root of a given integer */
    int floorSqrt(int n) {
        int low = 1, high = n;
        
        // Binary search on the answer space
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long val = 1LL * mid * mid;  // compute mid*mid in 64-bit if we dont use long long it may cause overflow for large mid values
            
            // Check if val is less than or equal to n
            if (val <= (long long)n) {
                // Move to the right part
                low = mid + 1;
            } else {
                // Move to the left part
                high = mid - 1;
            }
        }
        
        // Return the floor of square root
        return high;
    }
};

int main() {
    int n = 28;
    
    // Create an object of the Solution class
    Solution sol;
    
    int ans = sol.floorSqrt(n);
    
    // Print the result
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    
    return 0;
}
