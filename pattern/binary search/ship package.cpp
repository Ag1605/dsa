#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool can(vector<int>& weights, int days, int capacity) {

        int curweight = 0;
        int useddays = 1;

        for (int ok : weights) {

            if (curweight + ok <= capacity) {
                curweight += ok;
            }
            else {
                useddays++;
                curweight = ok;
            }
        }

        return useddays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        int ans = right;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (can(weights, days, mid)) {

                ans = mid;
                right = mid - 1;
            }
            else {

                left = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int n;
    cin >> n;

    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int days;
    cin >> days;

    cout << obj.shipWithinDays(weights, days);

    return 0;
}