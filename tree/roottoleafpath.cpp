
#include <bits/stdc++.h>
using namespace std;

// Structure of Binary Tree Node
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

    // DFS function to find all root-to-leaf paths
    void solve(Node* root,
               vector<int>& path,
               vector<vector<int>>& ans) {

        // BASE CASE:
        // If current node is NULL, stop recursion
        if (root == NULL) {
            return;
        }


        // STEP 1:
        // Add current node's value to the current path
        path.push_back(root->data);


        // STEP 2:
        // Check whether current node is a leaf node
        // Leaf node has no left child and no right child

        if (root->left == NULL && root->right == NULL) {

            // We have reached a leaf node.
            // Store the complete root-to-leaf path.
            ans.push_back(path);
        }

        else {

            // STEP 3:
            // Explore the left subtree
            solve(root->left, path, ans);


            // STEP 4:
            // Explore the right subtree
            solve(root->right, path, ans);
        }


        /*
            STEP 5: BACKTRACKING

            Remove the current node from the path.

            Why?

            Because we have finished exploring this node.
            Now we need to return to its parent and explore
            another possible path.

            This keeps the path correct for every branch.
        */

        path.pop_back();
    }


    // Main function to find all root-to-leaf paths
    vector<vector<int>> Paths(Node* root) {

        // Stores all root-to-leaf paths
        vector<vector<int>> ans;


        // Stores the current path during DFS
        vector<int> path;


        // Start DFS from root
        solve(root, path, ans);


        // Return all paths
        return ans;
    }
};


// MAIN FUNCTION
int main() {

    /*
                1
               / \
              2   3
             / \
            4   5
               / \
              6   7
    */

    // Create root node
    Node* root = new Node(1);

    // Second level
    root->left = new Node(2);
    root->right = new Node(3);

    // Third level
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Fourth level
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);


    // Create Solution object
    Solution obj;


    // Find all root-to-leaf paths
    vector<vector<int>> ans = obj.Paths(root);


    // Print all paths
    cout << "Root to Leaf Paths:" << endl;

    for (int i = 0; i < ans.size(); i++) {

        for (int j = 0; j < ans[i].size(); j++) {

            cout << ans[i][j];

            // Print arrow between nodes
            if (j != ans[i].size() - 1) {
                cout << " -> ";
            }
        }

        cout << endl;
    }

    return 0;
}
