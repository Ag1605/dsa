#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];

            sort(temp.begin(), temp.end());

            mp[temp].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    vector<string> strs(n);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    vector<vector<string>> ans = obj.groupAnagrams(strs);

    for (auto group : ans) {
        cout << "[ ";
        for (auto word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}