#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumRateToEatBananas(vector<int>& piles, int h) {
    int low = 1;
    int high = 0;

    // Find maximum pile 
    for (int bananas : piles)
        high = max(high, bananas);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long totalHours = 0;

        // Calculate total hours needed at speed = mid
        for (int bananas : piles)
            totalHours += (bananas + mid - 1) / mid;

        if (totalHours <= h)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    vector<int> piles = {7, 15, 6, 3};
    int h = 8;

    int result = minimumRateToEatBananas(piles, h);

    cout << "Minimum eating speed: " << result << endl;

    return 0;
}
