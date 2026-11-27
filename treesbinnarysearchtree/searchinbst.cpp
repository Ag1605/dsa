
#include <iostream>
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
    TreeNode* searchBST(TreeNode* root, int val) {

        // Base Case 1:
        // If the current node is NULL,
        // the target value does not exist in this subtree.
        if (root == nullptr) {
            return nullptr;
        }

        // Base Case 2:
        // If the current node contains the target value,
        // return the current node itself.
        if (root->val == val) {
            return root;
        }

        // If the target value is smaller than the current node,
        // it must be present in the left subtree.
        // Recursively search the left child.
        if (val < root->val) {
            return searchBST(root->left, val);
        }

        // If the target value is greater than the current node,
        // it must be present in the right subtree.
        // Recursively search the right child.
        return searchBST(root->right, val);
    }
};

int main() {

    // Creating the following BST:
    //
    //          4
    //         / \
    //        2   7
    //       / \
    //      1   3

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Target value to search
    int val = 2;

    Solution solution;

    // Search for the target value
    TreeNode* result = solution.searchBST(root, val);

    // Check whether the target node was found
    if (result != nullptr) {

        cout << "Node found: " << result->val << endl;

        // Print the subtree rooted at the found node
        cout << "Left child: ";

        if (result->left != nullptr) {
            cout << result->left->val;
        } else {
            cout << "NULL";
        }

        cout << endl;

        cout << "Right child: ";

        if (result->right != nullptr) {
            cout << result->right->val;
        } else {
            cout << "NULL";
        }

        cout << endl;
    } else {
        cout << "Node not found" << endl;
    }

    return 0;
}
