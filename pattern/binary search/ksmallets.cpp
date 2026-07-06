#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Count how many elements are <= mid
    int countLessEqual(vector<vector<int>> &matrix, int mid)
    {

        int n = matrix.size();

        // Start from bottom-left
        int row = n - 1;
        int col = 0;

        int count = 0;

        while (row >= 0 && col < n)
        {

            if (matrix[row][col] <= mid)
            {

                // All elements above are also <= mid
                count += row + 1;
                col++;
            }
            else
            {
                row--;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>> &matrix, int k)
    {

        int n = matrix.size();

        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        while (left < right)
        {

            int mid = left + (right - left) / 2;

            if (countLessEqual(matrix, mid) < k)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int k;
    cin >> k;

    cout << obj.kthSmallest(matrix, k);

    return 0;
}