#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {

        int n = citations.size();

        int left = 0;
        int right = n - 1;

        int ans = n;

        while (left <= right)
        {

            int mid = left + (right - left) / 2;

            // Check if there are (n-mid) papers
            // with at least (n-mid) citations
            if (citations[mid] >= n - mid)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return n - ans;
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<int> citations(n);

    for (int i = 0; i < n; i++)
    {
        cin >> citations[i];
    }

    cout << obj.hIndex(citations);

    return 0;
}