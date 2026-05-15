#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n = arr.size();

        int nodel = arr[0];
        int onedel = arr[0];
        int result = arr[0];

        for (int i = 1; i < n; i++) {

            int oldnodel = nodel;
            int oldonedel = onedel;

            // No deletion
            nodel = max(arr[i], oldnodel + arr[i]);

            // One deletion
            onedel = max(oldnodel, oldonedel + arr[i]);

            result = max(result, max(nodel, onedel));
        }

        return result;
    }
};

int main() {

    vector<int> arr = {1, -2, 0, 3};

    Solution obj;

    int ans = obj.maximumSum(arr);

    cout << "Maximum Subarray Sum with One Deletion: " << ans << endl;

    return 0;
}