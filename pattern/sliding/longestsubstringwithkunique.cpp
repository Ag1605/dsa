#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int low = 0, high = 0;
        int res = 0;
        int n = s.size();
        
        unordered_map<char,int> f;

        for(high = 0; high < n; high++) {
            f[s[high]]++;

            while(f.size() > k) {
                f[s[low]]--;
                
                if(f[s[low]] == 0) {
                    f.erase(s[low]);
                }
                low++;
            }

            if(f.size() == k) {
                int len = high - low + 1;
                res = max(res, len);
            }
        }

        return res;
    }
};

int main() {
    Solution obj;
    
    string s;
    int k;

    // Input
    cout << "Enter string: ";
    cin >> s;
    
    cout << "Enter k: ";
    cin >> k;

    // Function call
    int result = obj.longestKSubstr(s, k);

    // Output
    cout << "Longest substring length with exactly " << k 
         << " unique characters: " << result << endl;

    return 0;
}