#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0, high = 0;
        int res = 0;   // ✅ better initialization
        unordered_map<int,int> f;
        int n = fruits.size();

        for(high = 0; high < n; high++){
            f[fruits[high]]++;

            while(f.size() > 2){
                f[fruits[low]]--;
                if(f[fruits[low]] == 0){
                    f.erase(fruits[low]);
                }
                low++;
            }

            int len = high - low + 1;
            res = max(res, len);
        }

        return res;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of fruits: ";
    cin >> n;

    vector<int> fruits(n);
    cout << "Enter fruit types: ";
    for(int i = 0; i < n; i++){
        cin >> fruits[i];
    }

    int result = obj.totalFruit(fruits);

    cout << "Maximum fruits in baskets: " << result << endl;

    return 0;
}