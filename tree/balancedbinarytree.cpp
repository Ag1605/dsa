
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

    // Function to calculate height and check balance
    int height(TreeNode* root)
    {
        // BASE CASE:
        // If tree is empty, its height is 0.
        // An empty tree is always balanced.
        if (root == NULL)
        {
            return 0;
        }

        // STEP 1:
        // Calculate height of left subtree.
        int left = height(root->left);

        // If left subtree is already unbalanced,
        // return -1 immediately.
        if (left == -1)
        {
            return -1;
        }

        // STEP 2:
        // Calculate height of right subtree.
        int right = height(root->right);

        // If right subtree is already unbalanced,
        // return -1 immediately.
        if (right == -1)
        {
            return -1;
        }

        // STEP 3:
        // Check balance condition at current node.
        // Difference between left and right heights
        // must not be greater than 1.
        if (abs(left - right) > 1)
        {
            return -1;
        }

        // STEP 4:
        // Current subtree is balanced.
        // Return its height to the parent.
        return 1 + max(left, right);
    }


    // Function to check whether the tree is balanced
    bool isBalanced(TreeNode* root)
    {
        // If height() returns -1, tree is unbalanced.
        // Otherwise, tree is balanced.
        return height(root) != -1;
    }
};


int main()
{
    // Creating a balanced binary tree:
    //
    //              1
    //            /   \
    //           2     3
    //          / \   / \
    //         4   5 6   7

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Create Solution object
    Solution obj;

    // Check whether the tree is balanced
    bool ans = obj.isBalanced(root);

    if (ans)
    {
        cout << "Binary Tree is Balanced" << endl;
    }
    else
    {
        cout << "Binary Tree is Not Balanced" << endl;
    }

    return 0;
}
