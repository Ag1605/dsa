#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    long long thours(vector<int>& piles, int k) {

        long long hours = 0;

        for (int i = 0; i < piles.size(); i++) {

            hours += ((long long)piles[i] + k - 1) / k;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;

        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (thours(piles, mid) <= h) {

                high = mid - 1;
            }
            else {

                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    vector<int> piles = {7, 15, 6, 3};
    int h = 8;

    Solution solution;
    int result = solution.minEatingSpeed(piles, h);

    cout << "Minimum eating speed: " << result << endl;

    return 0;
}
