
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        // Step 1: Initially give every child 1 candy.
        // Every child must receive at least one candy.
        vector<int> candies(n, 1);

        // Step 2: Left to Right Traversal.
        // If the current child's rating is greater than
        // the previous child's rating, give one extra candy.
        for (int i = 1; i < n; i++) {

            if (ratings[i] > ratings[i - 1]) {

                // Current child must get more candies
                // than the child on the left.
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: Right to Left Traversal.
        // If the current child's rating is greater than
        // the next child's rating, current child needs
        // more candies than the child on the right.
        for (int i = n - 2; i >= 0; i--) {

            if (ratings[i] > ratings[i + 1]) {

                // Take the maximum because we must
                // preserve the candies assigned in the first pass.
                candies[i] = max(
                    candies[i],
                    candies[i + 1] + 1
                );
            }
        }

        // Step 4: Calculate the total number of candies.
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += candies[i];
        }

        // Return minimum candies required.
        return total;
    }
};

int main() {

    // Ratings of children.
    vector<int> ratings = {1, 0, 2};

    Solution obj;

    int result = obj.candy(ratings);

    cout << "Minimum candies required: " << result << endl;

    return 0;
}
