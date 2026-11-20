
#include <bits/stdc++.h>
using namespace std;

// Structure of Binary Tree Node
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:

    // Stores the maximum path sum found in the tree
    int maxi = INT_MIN;

    // Recursive function to calculate maximum path sum
    int solve(TreeNode* root)
    {
        // BASE CASE:
        // If current node is NULL, return 0.
        if (root == NULL)
        {
            return 0;
        }

        // STEP 1:
        // Calculate maximum path sum from left subtree.
        // If the result is negative, ignore it by taking 0.
        int left = max(0, solve(root->left));

        // STEP 2:
        // Calculate maximum path sum from right subtree.
        // Ignore negative contribution.
        int right = max(0, solve(root->right));

        // STEP 3:
        // Calculate maximum path sum passing through
        // the current node.
        //
        // Current node + left contribution + right contribution.
        int currentSum = root->val + left + right;

        // STEP 4:
        // Update global maximum answer if current path
        // gives a better sum.
        maxi = max(maxi, currentSum);

        // STEP 5:
        // Return only ONE branch to the parent.
        //
        // We cannot return both left and right branches
        // because that would create two paths from the parent.
        return root->val + max(left, right);
    }


    // Main function to find maximum path sum
    int maxPathSum(TreeNode* root)
    {
        // Initialize answer with INT_MIN.
        // Important because tree can contain negative values.
        maxi = INT_MIN;

        // Start DFS from root.
        solve(root);

        // Return the maximum path sum.
        return maxi;
    }
};


int main()
{
    // Creating the binary tree:
    //
    //              -10
    //             /   \
    //            9     20
    //                 /  \
    //                15   7

    TreeNode* root = new TreeNode(-10);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Create Solution object
    Solution obj;

    // Find maximum path sum
    int ans = obj.maxPathSum(root);

    // Print answer
    cout << "Maximum Path Sum: " << ans << endl;

    return 0;
}
