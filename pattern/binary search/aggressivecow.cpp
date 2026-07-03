#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canplace(vector<int> &arr, int k, int dist)
    {

        int cows = 1;
        int lastpos = arr[0];

        for (int i = 0; i < arr.size(); i++)
        {

            if (arr[i] - lastpos >= dist)
            {
                cows++;
                lastpos = arr[i];

                if (cows == k)
                    return true;
            }
        }

        return false;
    }

    int aggressiveCows(vector<int> &arr, int k)
    {

        sort(arr.begin(), arr.end());

        int left = 1;
        int right = arr[arr.size() - 1] - arr[0];

        int ans = 0;

        while (left <= right)
        {

            int mid = left + (right - left) / 2;

            if (canplace(arr, k, mid))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << obj.aggressiveCows(arr, k);

    return 0;
}