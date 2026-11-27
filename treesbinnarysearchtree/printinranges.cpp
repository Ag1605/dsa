
#include <iostream>
using namespace std;

// Definition of a Binary Search Tree node
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
    void printInRange(TreeNode* root, int low, int high) {

        // Base Case:
        // If the current node is NULL,
        // there is nothing to print.
        if (root == nullptr) {
            return;
        }

        // CASE 1:
        // If the current value is smaller than low,
        // it cannot be part of the required range.
        //
        // Also, every value in the left subtree
        // is smaller than the current value.
        // Therefore, the entire left subtree can be skipped.
        //
        // We only search the right subtree.
        if (root->val < low) {
            printInRange(root->right, low, high);
        }

        // CASE 2:
        // If the current value is greater than high,
        // it cannot be part of the required range.
        //
        // Every value in the right subtree is greater
        // than the current value.
        // Therefore, the entire right subtree can be skipped.
        //
        // We only search the left subtree.
        else if (root->val > high) {
            printInRange(root->left, low, high);
        }

        // CASE 3:
        // The current value lies inside the range.
        // We perform inorder traversal to print values
        // in ascending order.
        else {

            // First, print valid values from the left subtree.
            printInRange(root->left, low, high);

            // Print the current node because
            // low <= root->val <= high.
            cout << root->val << " ";

            // Finally, print valid values
            // from the right subtree.
            printInRange(root->right, low, high);
        }
    }
};

// Function to insert a value into the BST
TreeNode* insertIntoBST(TreeNode* root, int val) {

    // If the current position is empty,
    // create a new node.
    if (root == nullptr) {
        return new TreeNode(val);
    }

    // Smaller values go into the left subtree.
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }

    // Greater values go into the right subtree.
    else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }

    // Return the current root to maintain the BST.
    return root;
}

int main() {

    // Create an empty BST.
    TreeNode* root = nullptr;

    // Insert values into the BST.
    //
    //          10
    //         /  \
    //        5    15
    //       / \     \
    //      3   7     18

    root = insertIntoBST(root, 10);
    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 15);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 7);
    root = insertIntoBST(root, 18);

    // Define the required range.
    int low = 5;
    int high = 15;

    Solution solution;

    // Print all BST values between low and high.
    cout << "Values in range: ";

    solution.printInRange(root, low, high);

    cout << endl;

    return 0;
}
