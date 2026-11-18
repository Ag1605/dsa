#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int>& fruits)
    {
        // Stores fruit type and its frequency inside the window
        unordered_map<int, int> mp;

        int left = 0;
        int ans = 0;

        // right expands the window
        for (int right = 0; right < fruits.size(); right++)
        {
            // Include the current fruit in our window
            mp[fruits[right]]++;

            // If we have more than 2 different fruit types,
            // shrink the window from the left
            while (mp.size() > 2)
            {
                mp[fruits[left]]--;

                // If frequency becomes zero, remove that fruit type
                if (mp[fruits[left]] == 0)
                {
                    mp.erase(fruits[left]);
                }

                left++;
            }

            // Calculate the current valid window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> fruits = {1, 1, 2, 2, 2, 3, 3, 3, 3};

    cout << obj.totalFruit(fruits);

    return 0;
}