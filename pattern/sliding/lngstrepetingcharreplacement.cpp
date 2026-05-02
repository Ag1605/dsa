#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(vector<int> &a) {
        int maxc = -1;
        for (int i = 0; i < 256; i++) {
            maxc = max(maxc, a[i]);
        }
        return maxc;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0, high = 0, res = 0; // better to use 0 instead of INT_MIN
        vector<int> f(256, 0);

        for (high = 0; high < n; high++) {
            f[s[high]]++;

            int maxcnt = find(f);
            int len = high - low + 1;
            int diff = len - maxcnt;

            while (diff > k) {
                f[s[low]]--;
                low++;

                maxcnt = find(f);
                len = high - low + 1;
                diff = len - maxcnt;
            }

            res = max(res, len);
        }
        return res;
    }
};

int main() {
    Solution obj;

    string s = "AABABBA";
    int k = 1;

    int ans = obj.characterReplacement(s, k);
    cout << "Answer: " << ans << endl;

    return 0;
}