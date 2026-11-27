
#include <iostream>
#include <vector>
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
    // Helper function to perform DFS and backtracking
    void solve(TreeNode* root,
               vector<int>& path,
               vector<vector<int>>& result) {

        // BASE CASE:
        // If the current node is NULL,
        // there is no path to explore.
        if (root == nullptr) {
            return;
        }

        // STEP 1:
        // Add the current node's value to the path.
        // This means we have moved from the parent
        // to the current node.
        path.push_back(root->val);

        // STEP 2:
        // Check whether the current node is a leaf.
        //
        // A leaf node has:
        // left == nullptr AND right == nullptr
        if (root->left == nullptr && root->right == nullptr) {

            // We have reached a complete root-to-leaf path.
            //
            // Store a COPY of the current path in result.
            // We must copy because path will be modified
            // during backtracking.
            result.push_back(path);
        }

        // STEP 3:
        // Explore the left subtree.
        // The current path is passed by reference,
        // so the same vector is used during recursion.
        solve(root->left, path, result);

        // STEP 4:
        // Explore the right subtree.
        solve(root->right, path, result);

        // STEP 5: BACKTRACKING
        //
        // Remove the current node from the path.
        //
        // This restores the path to its previous state
        // before exploring another branch.
        path.pop_back();
    }

    // Main function that returns all root-to-leaf paths
    vector<vector<int>> rootToLeaf(TreeNode* root) {

        // Stores all completed root-to-leaf paths.
        vector<vector<int>> result;

        // Stores the current path during DFS.
        vector<int> path;

        // Start DFS from the root node.
        solve(root, path, result);

        // Return all collected paths.
        return result;
    }
};

// Function to print all root-to-leaf paths
void printPaths(vector<vector<int>>& result) {

    // Loop through every path stored in result.
    for (int i = 0; i < result.size(); i++) {

        // Print the current path.
        for (int j = 0; j < result[i].size(); j++) {

            cout << result[i][j];

            // Print an arrow between nodes.
            if (j < result[i].size() - 1) {
                cout << " -> ";
            }
        }

        // Move to the next line after each path.
        cout << endl;
    }
}

int main() {

    // Creating the following binary tree:
    //
    //          1
    //         / \
    //        2   3
    //       / \
    //      4   5

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;

    // Find all root-to-leaf paths.
    vector<vector<int>> result = solution.rootToLeaf(root);

    // Print the paths.
    cout << "Root-to-leaf paths:" << endl;

    printPaths(result);

    return 0;
}
