#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool can(vector<int> &candies, long long k, int x)
    {

        long long child = 0;

        for (int ch : candies)
        {

            child += ch / x;

            if (child >= k)
                return true;
        }

        return false;
    }

    int maximumCandies(vector<int> &candies, long long k)
    {

        int left = 1;
        int right = *max_element(candies.begin(), candies.end());

        int ans = 0;

        while (left <= right)
        {

            int mid = left + (right - left) / 2;

            if (can(candies, k, mid))
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

    vector<int> candies(n);

    for (int i = 0; i < n; i++)
    {
        cin >> candies[i];
    }

    long long k;
    cin >> k;

    cout << obj.maximumCandies(candies, k);

    return 0;
}