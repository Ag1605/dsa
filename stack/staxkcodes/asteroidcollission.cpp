#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {

        // Stack stores the asteroids that survive
        stack<int> st;

        // Process each asteroid
        for (int x : asteroids)
        {

            // Assume current asteroid is alive
            bool alive = true;

            // Collision occurs only when:
            // Stack top moves right (+)
            // Current asteroid moves left (-)
            while (!st.empty() && st.top() > 0 && x < 0 && alive)
            {

                // Current asteroid is larger
                if (st.top() < -x)
                {
                    st.pop(); // Right-moving asteroid explodes
                }

                // Both are equal in size
                else if (st.top() == -x)
                {
                    st.pop(); // Both explode
                    alive = false;
                }

                // Stack asteroid is larger
                else
                {
                    alive = false; // Current asteroid explodes
                }
            }

            // If current asteroid survives, push it
            if (alive)
                st.push(x);
        }

        // Convert stack into vector
        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<int> asteroids(n);

    for (int i = 0; i < n; i++)
        cin >> asteroids[i];

    vector<int> ans = obj.asteroidCollision(asteroids);

    for (int x : ans)
        cout << x << " ";

    return 0;
}