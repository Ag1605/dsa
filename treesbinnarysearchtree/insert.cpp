
#include <iostream>
using namespace std;

// Structure representing a node of the Binary Search Tree
struct TreeNode {
    int val;

    // Pointer to the left child
    TreeNode* left;

    // Pointer to the right child
    TreeNode* right;

    // Constructor to initialize a new node
    TreeNode(int value) {
        val = value;

        // Initially, the new node has no children
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a value into the BST
TreeNode* insertIntoBST(TreeNode* root, int val) {

    // Base Case:
    // If the current position is empty,
    // this is the correct position for the new value.
    if (root == nullptr) {

        // Create a new node and return its address
        return new TreeNode(val);
    }

    // If the new value is smaller than the current node,
    // it belongs in the left subtree.
    if (val < root->val) {

        // Recursively insert into the left subtree.
        // The returned node is connected to root->left.
        root->left = insertIntoBST(root->left, val);
    }

    // If the new value is greater than the current node,
    // it belongs in the right subtree.
    else if (val > root->val) {

        // Recursively insert into the right subtree.
        // The returned node is connected to root->right.
        root->right = insertIntoBST(root->right, val);
    }

    // If val == root->val, no insertion is performed.
    // This implementation does not insert duplicate values.

    // Return the current root.
    // This maintains the original tree structure.
    return root;
}

// Function to print the BST using inorder traversal
// Inorder traversal of a BST prints values in sorted order.
void inorder(TreeNode* root) {

    // Stop if the current node is NULL
    if (root == nullptr) {
        return;
    }

    // Visit the left subtree
    inorder(root->left);

    // Print the current node
    cout << root->val << " ";

    // Visit the right subtree
    inorder(root->right);
}

int main() {

    // Creating the initial BST:
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

    // Value to insert into the BST
    int val = 5;

    // Insert the new value into the BST
    root = insertIntoBST(root, val);

    // Print the updated BST using inorder traversal
    cout << "BST after insertion: ";

    inorder(root);

    cout << endl;

    return 0;
}
