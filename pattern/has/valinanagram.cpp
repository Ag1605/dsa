#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;

        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]--;

            if (mp[t[i]] < 0)
                return false;
        }

        return true;
    }
};

int main() {
    Solution obj;

    string s, t;
    cin >> s >> t;

    if (obj.isAnagram(s, t))
        cout << "true";
    else
        cout << "false";

    return 0;
}