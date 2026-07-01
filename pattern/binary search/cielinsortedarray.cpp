#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ceilSearch(vector<int>& arr, int x) {

        int left = 0;
        int right = arr.size() - 1;
        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (arr[mid] >= x) {
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

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    cout << obj.ceilSearch(arr, x);

    return 0;
}