#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ans;

        if (n < 10) return ans;

        unordered_map<string, int> freq;

        int low = 0;

        for (int high = 0; high < n; high++) {

            // maintain window size = 10
            if (high - low + 1 == 10) {
                string sub = s.substr(low, 10);

                freq[sub]++;

                // add only once when it becomes 2
                if (freq[sub] == 2) {
                    ans.push_back(sub);
                }

                low++; // slide window
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    vector<string> res = obj.findRepeatedDnaSequences(s);

    for (auto &x : res) {
        cout << x << " ";
    }

    return 0;
}