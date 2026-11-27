
#include <iostream>
#include <vector>
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
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> predecessorSuccessor(TreeNode* root, int key) {

        // Initially, predecessor and successor do not exist.
        // We use -1 to represent a missing value.
        int predecessor = -1;
        int successor = -1;

        // ==========================================
        // PART 1: FIND INORDER PREDECESSOR
        // ==========================================

        // Start searching from the root.
        TreeNode* curr = root;

        // Continue until we reach an empty position.
        while (curr != nullptr) {

            // If the current value is smaller than key,
            // it can be a possible predecessor.
            if (curr->val < key) {

                // Store the current value as a candidate.
                predecessor = curr->val;

                // Move right to search for a larger value
                // that is still smaller than key.
                curr = curr->right;
            }

            // If current value is greater than or equal to key,
            // it cannot be the predecessor.
            else {

                // Move left because smaller values
                // may exist in the left subtree.
                curr = curr->left;
            }
        }

        // ==========================================
        // PART 2: FIND INORDER SUCCESSOR
        // ==========================================

        // Start searching again from the root.
        curr = root;

        // Continue until we reach an empty position.
        while (curr != nullptr) {

            // If the current value is greater than key,
            // it can be a possible successor.
            if (curr->val > key) {

                // Store the current value as a candidate.
                successor = curr->val;

                // Move left to search for a smaller value
                // that is still greater than key.
                curr = curr->left;
            }

            // If current value is smaller than or equal to key,
            // it cannot be the successor.
            else {

                // Move right because greater values
                // may exist in the right subtree.
                curr = curr->right;
            }
        }

        // Return both values:
        // index 0 = predecessor
        // index 1 = successor
        return {predecessor, successor};
    }
};

// Function to insert a value into a BST
TreeNode* insertIntoBST(TreeNode* root, int val) {

    // If the current position is empty,
    // create a new node here.
    if (root == nullptr) {
        return new TreeNode(val);
    }

    // Smaller values go to the left subtree.
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }

    // Greater values go to the right subtree.
    else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }

    // Return the current root.
    return root;
}

int main() {

    // Create an empty BST.
    TreeNode* root = nullptr;

    // Insert values into the BST.
    // Resulting tree:
    //
    //          50
    //         /  \
    //        30   70
    //       / \   / \
    //      20 40 60 80

    root = insertIntoBST(root, 50);
    root = insertIntoBST(root, 30);
    root = insertIntoBST(root, 70);
    root = insertIntoBST(root, 20);
    root = insertIntoBST(root, 40);
    root = insertIntoBST(root, 60);
    root = insertIntoBST(root, 80);

    // Target value
    int key = 50;

    Solution solution;

    // Find predecessor and successor.
    vector<int> result =
        solution.predecessorSuccessor(root, key);

    // Print predecessor.
    cout << "Predecessor: " << result[0] << endl;

    // Print successor.
    cout << "Successor: " << result[1] << endl;

    return 0;
}
