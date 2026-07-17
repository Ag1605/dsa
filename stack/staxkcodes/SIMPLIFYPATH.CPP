#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {

        // Stack stores valid folder names
        stack<string> st;

        // Stores the current folder name
        string folder = "";

        // Traverse the path
        // i <= path.size() handles the last folder
        for (int i = 0; i <= path.size(); i++)
        {

            // Folder ends when we reach '/' or end of string
            if (i == path.size() || path[i] == '/')
            {

                // Ignore empty folder ("//") and current directory "."
                if (folder == "" || folder == ".")
                {

                    // Do nothing
                }

                // Move to parent directory
                else if (folder == "..")
                {

                    // Pop only if stack is not empty
                    if (!st.empty())
                        st.pop();
                }

                // Normal folder name
                else
                {
                    st.push(folder);
                }

                // Reset folder for the next directory
                folder = "";
            }

            // Build folder name
            else
            {
                folder += path[i];
            }
        }

        // Root directory
        if (st.empty())
        {
            return "/";
        }

        // Store stack elements in correct order
        vector<string> temp;

        while (!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        // Build the final simplified path
        string ans = "";

        for (string x : temp)
        {
            ans += "/";
            ans += x;
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    string path;
    cin >> path;

    cout << obj.simplifyPath(path);

    return 0;
}