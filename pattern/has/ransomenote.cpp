#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> mp2;

        // Count frequency of magazine
        for (int i = 0; i < magazine.size(); i++) {
            mp2[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            if (mp2[ransomNote[i]] == 0) {
                return false;
            }
            mp2[ransomNote[i]]--;
        }

        return true;
    }
};

int main() {
    Solution obj;

    string ransomNote, magazine;
    cin >> ransomNote >> magazine;

    if (obj.canConstruct(ransomNote, magazine)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}