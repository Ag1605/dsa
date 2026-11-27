
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
    TreeNode* deleteNode(TreeNode* root, int key) {

        // Base Case:
        // If the current node is NULL,
        // the key does not exist in this subtree.
        if (root == nullptr) {
            return nullptr;
        }

        // If the key is smaller than the current node,
        // search for it in the left subtree.
        if (key < root->val) {

            // Recursively delete the key from the left subtree.
            // Connect the updated subtree back to root->left.
            root->left = deleteNode(root->left, key);
        }

        // If the key is greater than the current node,
        // search for it in the right subtree.
        else if (key > root->val) {

            // Recursively delete the key from the right subtree.
            // Connect the updated subtree back to root->right.
            root->right = deleteNode(root->right, key);
        }

        // If key == root->val,
        // we have found the node that needs to be deleted.
        else {

            // CASE 1:
            // The node has no left child.
            // It may have a right child or no child at all.
            if (root->left == nullptr) {

                // Store the right child before deleting root.
                TreeNode* temp = root->right;

                // Delete the current node from memory.
                delete root;

                // Return the right child.
                // If it is NULL, this was a leaf node.
                return temp;
            }

            // CASE 2:
            // The node has no right child.
            // It has only a left child.
            if (root->right == nullptr) {

                // Store the left child before deleting root.
                TreeNode* temp = root->left;

                // Delete the current node from memory.
                delete root;

                // Return the left child to connect it
                // with the parent of the deleted node.
                return temp;
            }

            // CASE 3:
            // The node has both left and right children.
            // We use the inorder successor.

            // Start from the right subtree.
            TreeNode* successor = root->right;

            // Find the smallest value in the right subtree.
            // The smallest node is the leftmost node.
            while (successor->left != nullptr) {
                successor = successor->left;
            }

            // Copy the inorder successor's value
            // into the node that we want to delete.
            root->val = successor->val;

            // Now delete the original successor node.
            // It is located somewhere in the right subtree.
            root->right = deleteNode(root->right, successor->val);
        }

        // Return the updated root of this subtree.
        return root;
    }
};

// Inorder traversal prints BST values in sorted order.
void inorder(TreeNode* root) {

    // If the current node is NULL, stop.
    if (root == nullptr) {
        return;
    }

    // Visit the left subtree.
    inorder(root->left);

    // Print the current node's value.
    cout << root->val << " ";

    // Visit the right subtree.
    inorder(root->right);
}

int main() {

    // Creating the following BST:
    //
    //          5
    //         / \
    //        3   8
    //           / \
    //          6   9
    //
    // We will delete the node with value 5.

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(8);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Key to delete
    int key = 5;

    Solution solution;

    // Delete the node and update the root pointer.
    root = solution.deleteNode(root, key);

    // Print the updated BST.
    cout << "BST after deletion: ";

    inorder(root);

    cout << endl;

    return 0;
}
