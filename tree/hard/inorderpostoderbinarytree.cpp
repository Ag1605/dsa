
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Structure of a Binary Tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a node
    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    // Stores the index of every value in inorder
    unordered_map<int, int> inorderIndex;

    // Tracks the current position in postorder
    int postorderIndex;

    // Recursive function to construct the tree
    TreeNode* build(vector<int>& postorder,
                    int left,
                    int right) {

        // If the range is empty,
        // there is no node to create
        if (left > right) {
            return nullptr;
        }

        // Last element of postorder is the root
        int rootValue = postorder[postorderIndex];

        // Move backward to the previous element
        postorderIndex--;

        // Create the root node
        TreeNode* root = new TreeNode(rootValue);

        // Find the root position in inorder
        int mid = inorderIndex[rootValue];

        // Build the RIGHT subtree first
        root->right = build(postorder, mid + 1, right);

        // Build the LEFT subtree second
        root->left = build(postorder, left, mid - 1);

        // Return the constructed root
        return root;
    }

    // Main function to construct the binary tree
    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        // Store every inorder value
        // along with its index
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        // Start from the last index of postorder
        postorderIndex = postorder.size() - 1;

        // Construct the complete tree
        return build(postorder, 0, inorder.size() - 1);
    }
};

// Print tree using inorder traversal
void printInorder(TreeNode* root) {

    if (root == nullptr) {
        return;
    }

    // Visit left subtree
    printInorder(root->left);

    // Print current node
    cout << root->val << " ";

    // Visit right subtree
    printInorder(root->right);
}

// Print tree using postorder traversal
void printPostorder(TreeNode* root) {

    if (root == nullptr) {
        return;
    }

    // Visit left subtree
    printPostorder(root->left);

    // Visit right subtree
    printPostorder(root->right);

    // Print root at the end
    cout << root->val << " ";
}

int main() {

    // Given inorder and postorder arrays
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Create Solution object
    Solution obj;

    // Construct the binary tree
    TreeNode* root = obj.buildTree(inorder, postorder);

    // Print the constructed tree
    cout << "Inorder Traversal: ";
    printInorder(root);

    cout << endl;

    cout << "Postorder Traversal: ";
    printPostorder(root);

    cout << endl;

    return 0;
}
