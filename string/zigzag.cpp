#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {

        // If there is only one row, no zigzag is possible
        if (numRows == 1)
            return s;

        // Create a string for each row
        vector<string> rows(numRows);

        // Start from the first row
        int currentRow = 0;

        // Direction flag
        // true  -> moving down
        // false -> moving up
        bool goingDown = true;

        // Traverse each character
        for (char ch : s)
        {

            // Add current character to the current row
            rows[currentRow] += ch;

            // If we reach the first row, start moving down
            if (currentRow == 0)
                goingDown = true;

            // If we reach the last row, start moving up
            else if (currentRow == numRows - 1)
                goingDown = false;

            // Move to the next row
            if (goingDown)
                currentRow++;
            else
                currentRow--;
        }

        // Combine all rows into the final answer
        string ans = "";

        for (string row : rows)
            ans += row;

        return ans;
    }
};

int main()
{

    Solution obj;

    string s;
    int numRows;

    cin >> s;
    cin >> numRows;

    cout << obj.convert(s, numRows);

    return 0;
}