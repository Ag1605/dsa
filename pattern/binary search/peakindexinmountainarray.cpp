#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {

        int left = 0;
        int right = arr.size() - 1;

        while (left < right)
        {

            int mid = left + (right - left) / 2;

            if (arr[mid] < arr[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
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

    cout << obj.peakIndexInMountainArray(arr);

    return 0;
}