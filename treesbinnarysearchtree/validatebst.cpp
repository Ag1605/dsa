
#include <iostream>
#include <climits>
using namespace std;

// Definition of a Binary Tree Node
struct TreeNode {
    int val;

    // Pointer to the left child
    TreeNode* left;

    // Pointer to the right child
    TreeNode* right;

    // Default constructor
    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with a value
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with value and child nodes
    TreeNode(int x, TreeNode* left, TreeNode* right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public:

    // Helper function to validate the BST.
    //
    // minValue = minimum allowed value for this node
    // maxValue = maximum allowed value for this node
    bool solve(TreeNode* root,
               long long minValue,
               long long maxValue) {

        // BASE CASE:
        // An empty subtree is considered a valid BST.
        if (root == nullptr) {
            return true;
        }

        // CHECK CURRENT NODE:
        //
        // The current node must be strictly greater
        // than minValue and strictly smaller than maxValue.
        //
        // If the value is outside this range,
        // the BST property is violated.
        if (root->val <= minValue ||
            root->val >= maxValue) {

            return false;
        }

        // VALIDATE LEFT SUBTREE:
        //
        // Every node in the left subtree must be:
        // greater than minValue
        // AND smaller than root->val.
        //
        // Therefore, root->val becomes the new maximum.
        bool leftValid = solve(
            root->left,
            minValue,
            root->val
        );

        // VALIDATE RIGHT SUBTREE:
        //
        // Every node in the right subtree must be:
        // greater than root->val
        // AND smaller than maxValue.
        //
        // Therefore, root->val becomes the new minimum.
        bool rightValid = solve(
            root->right,
            root->val,
            maxValue
        );

        // The complete tree is valid only if
        // both left and right subtrees are valid.
        return leftValid && rightValid;
    }

    // Main function to check whether the tree is a valid BST
    bool isValidBST(TreeNode* root) {

        // Use long long boundaries instead of INT_MIN and INT_MAX.
        //
        // This allows valid BST nodes to contain:
        // INT_MIN = -2147483648
        // INT_MAX =  2147483647
        //
        // The initial range includes every possible int value.
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {

    // Creating the following binary tree:
    //
    //          10
    //         /  \
    //        5    15
    //       / \   / \
    //      2   7 12  20
    //
    // This is a valid BST.

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);

    Solution solution;

    // Check whether the given tree is a valid BST.
    bool result = solution.isValidBST(root);

    // Print the result.
    if (result) {
        cout << "Valid BST" << endl;
    } else {
        cout << "Invalid BST" << endl;
    }

    return 0;
}
