#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> mp;

        int left = 0;
        int maxfreq = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            maxfreq = max(maxfreq, mp[s[right]]);

            while ((right - left + 1) - maxfreq > k) {
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    int k;

    cin >> s;
    cin >> k;

    cout << obj.characterReplacement(s, k);

    return 0;
}