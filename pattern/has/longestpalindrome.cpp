#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        int ans = 0;
        bool odd = false;

        for (auto it : mp) {
            if (it.second % 2 == 0) {
                ans += it.second;
            } else {
                ans += it.second - 1;
                odd = true;
            }
        }

        if (odd) {
            ans++;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    cout << obj.longestPalindrome(s);

    return 0;
}