
#include <bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    // Check whether the current node is a leaf node
    // A leaf node has no left child and no right child
    bool isLeaf(Node* root) {
        return root->left == NULL && root->right == NULL;
    }


    // STEP 1: Add Left Boundary
    // Traverse from root's left child towards the bottom
    // Do not include leaf nodes because they will be added separately

    void leftBoundary(Node* root, vector<int>& ans) {

        // Start from the left child of root
        Node* curr = root->left;

        while (curr != NULL) {

            // Add only non-leaf nodes
            if (!isLeaf(curr)) {
                ans.push_back(curr->data);
            }

            // First priority: Go to the left child
            if (curr->left != NULL) {
                curr = curr->left;
            }

            // If left child does not exist, go right
            else {
                curr = curr->right;
            }
        }
    }


    // STEP 2: Add All Leaf Nodes
    // Traverse the entire tree using DFS
    // Add leaf nodes from left to right

    void addLeaves(Node* root, vector<int>& ans) {

        // Base case: If node does not exist, return
        if (root == NULL) {
            return;
        }

        // If current node is a leaf, add its value
        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }

        // Recursively traverse left subtree first
        addLeaves(root->left, ans);

        // Then recursively traverse right subtree
        addLeaves(root->right, ans);
    }


    // STEP 3: Add Right Boundary
    // Traverse from root's right child towards the bottom
    // Store nodes in a temporary vector
    // Finally add them in reverse order (Bottom to Top)

    void rightBoundary(Node* root, vector<int>& ans) {

        // Start from the right child of root
        Node* curr = root->right;

        // Temporary vector to store right boundary nodes
        vector<int> temp;

        while (curr != NULL) {

            // Add only non-leaf nodes
            if (!isLeaf(curr)) {
                temp.push_back(curr->data);
            }

            // First priority: Go to the right child
            if (curr->right != NULL) {
                curr = curr->right;
            }

            // If right child does not exist, go left
            else {
                curr = curr->left;
            }
        }

        // Add right boundary in reverse order
        // This gives Bottom to Top traversal
        for (int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }


    // MAIN FUNCTION: Boundary Traversal

    vector<int> boundary(Node* root) {

        vector<int> ans;

        // If tree is empty, return empty vector
        if (root == NULL) {
            return ans;
        }

        // Handle root separately
        // If root is not a leaf, add it first
        if (!isLeaf(root)) {
            ans.push_back(root->data);
        }

        // If root itself is a leaf, it is the entire boundary
        else {
            ans.push_back(root->data);
            return ans;
        }

        // STEP 1: Add left boundary (Top to Bottom)
        leftBoundary(root, ans);

        // STEP 2: Add all leaf nodes (Left to Right)
        addLeaves(root, ans);

        // STEP 3: Add right boundary (Bottom to Top)
        rightBoundary(root, ans);

        // Return final boundary traversal
        return ans;
    }
};


// MAIN FUNCTION
int main() {

    /*
              1
             / \
            2   3
           / \ / \
          4  5 6  7
            / \
           8   9

    */

    // Create root node
    Node* root = new Node(1);

    // Create second level
    root->left = new Node(2);
    root->right = new Node(3);

    // Create third level
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Create fourth level
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    // Create Solution object
    Solution obj;

    // Call boundary traversal function
    vector<int> ans = obj.boundary(root);

    // Print boundary traversal
    cout << "Boundary Traversal: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
