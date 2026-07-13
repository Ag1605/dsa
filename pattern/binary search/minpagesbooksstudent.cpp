#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool can(vector<int>& arr, int k, long long maxpages) {

        int student = 1;
        long long pages = 0;

        for (int bg : arr) {

            if (pages + bg <= maxpages) {
                pages += bg;
            }
            else {
                student++;
                pages = bg;
            }
        }

        return student <= k;
    }

    int findPages(vector<int>& arr, int k) {

        if (k > arr.size())
            return -1;

        long long left = *max_element(arr.begin(), arr.end());
        long long right = accumulate(arr.begin(), arr.end(), 0LL);

        long long ans = right;

        while (left <= right) {

            long long mid = left + (right - left) / 2;

            if (can(arr, k, mid)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return (int)ans;
    }
};

int main() {

    Solution obj;

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << obj.findPages(arr, k);

    return 0;
}