#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count(vector<int> &arr, int target)
    {

        int first = -1;
        int last = -1;

        int left = 0;
        int right = arr.size() - 1;

        // Find first occurrence
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
            {
                first = mid;
                right = mid - 1;
            }
            else if (arr[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (first == -1)
            return 0;

        left = 0;
        right = arr.size() - 1;

        // Find last occurrence
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
            {
                last = mid;
                left = mid + 1;
            }
            else if (arr[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return last - first + 1;
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

    int target;
    cin >> target;

    cout << obj.count(arr, target);

    return 0;
}