#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canmake(vector<int> &bloomDay, int day, int m, int k)
    {

        int flowers = 0;
        int bouquet = 0;

        for (int i = 0; i < bloomDay.size(); i++)
        {

            if (bloomDay[i] <= day)
            {
                flowers++;
            }
            else
            {
                bouquet += flowers / k;
                flowers = 0;
            }
        }

        // Count bouquets from the last group
        bouquet += flowers / k;

        return bouquet >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {

        if (1LL * m * k > bloomDay.size())
        {
            return -1;
        }

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = right;

        while (left <= right)
        {

            int mid = left + (right - left) / 2;

            if (canmake(bloomDay, mid, m, k))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
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

    vector<int> bloomDay(n);

    for (int i = 0; i < n; i++)
    {
        cin >> bloomDay[i];
    }

    int m, k;
    cin >> m >> k;

    cout << obj.minDays(bloomDay, m, k);

    return 0;
}