
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

    // Function to find Lowest Common Ancestor
    TreeNode* lowestCommonAncestor(
        TreeNode* root,
        TreeNode* p,
        TreeNode* q
    )
    {
        // BASE CASE 1:
        // If current node is NULL, return NULL.
        if (root == NULL)
        {
            return NULL;
        }

        // BASE CASE 2:
        // If current node itself is p or q,
        // return the current node.
        if (root == p || root == q)
        {
            return root;
        }

        // STEP 1:
        // Search for p and q in the left subtree.
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // STEP 2:
        // Search for p and q in the right subtree.
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // STEP 3:
        // If both left and right return a node,
        // p and q are present on different sides.
        // Therefore, current root is the LCA.
        if (left != NULL && right != NULL)
        {
            return root;
        }

        // STEP 4:
        // If only left subtree returns a node,
        // return that node.
        if (left != NULL)
        {
            return left;
        }

        // STEP 5:
        // Otherwise return the right subtree result.
        return right;
    }
};

int main()
{
    // Creating the following binary tree:
    //
    //              3
    //            /   \
    //           5     1
    //          / \   / \
    //         6   2 0   8
    //            / \
    //           7   4

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Select two target nodes
    TreeNode* p = root->left;              // Node 5
    TreeNode* q = root->left->right->right; // Node 4

    // Create Solution object
    Solution obj;

    // Find Lowest Common Ancestor
    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    // Print answer
    if (ans != NULL)
    {
        cout << "LCA of " << p->val << " and " << q->val
             << " is: " << ans->val << endl;
    }

    return 0;
}
