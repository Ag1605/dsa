
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Structure of a Binary Tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
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

    // Tracks the current position in preorder
    int preorderIndex = 0;

    // Recursive function to build the tree
    TreeNode* build(vector<int>& preorder,
                    int left,
                    int right) {

        // If the range is empty,
        // there is no node to create
        if (left > right) {
            return nullptr;
        }

        // Preorder gives the root first
        int rootValue = preorder[preorderIndex];

        // Move to the next preorder element
        preorderIndex++;

        // Create the root node
        TreeNode* root = new TreeNode(rootValue);

        // Find the root position in inorder
        int mid = inorderIndex[rootValue];

        // Everything before mid belongs
        // to the left subtree
        root->left = build(preorder, left, mid - 1);

        // Everything after mid belongs
        // to the right subtree
        root->right = build(preorder, mid + 1, right);

        // Return the constructed root
        return root;
    }

    // Main function to construct the tree
    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        // Store each inorder value
        // along with its index
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        // Start preorder from index 0
        preorderIndex = 0;

        // Build the complete tree
        return build(preorder, 0, inorder.size() - 1);
    }
};

// Print tree using inorder traversal
void printInorder(TreeNode* root) {

    // Base case
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

// Print tree using preorder traversal
void printPreorder(TreeNode* root) {

    if (root == nullptr) {
        return;
    }

    // Print root first
    cout << root->val << " ";

    // Visit left subtree
    printPreorder(root->left);

    // Visit right subtree
    printPreorder(root->right);
}

int main() {

    // Given preorder and inorder arrays
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Create Solution object
    Solution obj;

    // Construct the binary tree
    TreeNode* root = obj.buildTree(preorder, inorder);

    // Print the constructed tree
    cout << "Inorder Traversal: ";
    printInorder(root);

    cout << endl;

    cout << "Preorder Traversal: ";
    printPreorder(root);

    cout << endl;

    return 0;
}
