#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int ans = right;

        while (left <= right)
        {

            int mid = left + (right - left) / 2;

            long long hours = 0;

            for (int x : piles)
            {
                hours += ceil((double)x / mid);
            }

            if (hours <= h)
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

    vector<int> piles(n);

    for (int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }

    int h;
    cin >> h;

    cout << obj.minEatingSpeed(piles, h);

    return 0;
}