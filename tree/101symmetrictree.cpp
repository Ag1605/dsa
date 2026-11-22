
#include <bits/stdc++.h>
using namespace std;


// Structure of a Binary Tree Node
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

    // Function to check whether two trees
    // are mirror images of each other.
    bool isMirror(TreeNode* left, TreeNode* right)
    {
        // STEP 1: Base Case
        //
        // If both nodes are NULL,
        // they are equal and symmetric.
        if (left == NULL && right == NULL)
        {
            return true;
        }


        // STEP 2: Check if only one node is NULL
        //
        // If one side has a node but the other
        // side does not, they cannot be symmetric.
        if (left == NULL || right == NULL)
        {
            return false;
        }


        // STEP 3: Compare node values
        //
        // Both nodes must have the same value.
        // If values are different, they are not mirrors.
        if (left->val != right->val)
        {
            return false;
        }


        // STEP 4: Recursive Mirror Checking
        //
        // Compare opposite children:
        //
        // Left subtree's LEFT child
        //          with
        // Right subtree's RIGHT child
        //
        // Left subtree's RIGHT child
        //          with
        // Right subtree's LEFT child
        //
        // Both comparisons must return true.
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }


    // Main function called by LeetCode
    bool isSymmetric(TreeNode* root)
    {
        // An empty tree is symmetric.
        if (root == NULL)
        {
            return true;
        }

        // Check whether left and right subtrees
        // are mirror images of each other.
        return isMirror(root->left, root->right);
    }
};


int main()
{
    /*
              1
             / \
            2   2
           / \ / \
          3  4 4  3

       This tree is symmetric.
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);


    Solution obj;

    // Check whether the tree is symmetric
    bool result = obj.isSymmetric(root);

    if (result)
    {
        cout << "Tree is Symmetric" << endl;
    }
    else
    {
        cout << "Tree is Not Symmetric" << endl;
    }


    return 0;
}
