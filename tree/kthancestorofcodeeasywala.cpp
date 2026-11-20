
#include <bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:

    // Stores the answer
    int ans = -1;

    // Recursive function to find the target node
    // and move upwards to find its Kth ancestor.
    Node* solve(Node* root, int node, int &k)
    {
        // BASE CASE:
        // If current node is NULL, target is not found here.
        if (root == NULL)
        {
            return NULL;
        }

        // BASE CASE:
        // If we find the target node,
        // return its address to the parent.
        if (root->data == node)
        {
            return root;
        }

        // STEP 1:
        // Search for target in the left subtree.
        Node* left = solve(root->left, node, k);

        // STEP 2:
        // Search for target in the right subtree.
        Node* right = solve(root->right, node, k);

        // STEP 3:
        // If either left or right returns a node,
        // it means the target exists in that subtree.
        if (left != NULL || right != NULL)
        {
            // We are moving one level upwards.
            // Therefore, decrease k by 1.
            k--;

            // If k becomes 0, current node is
            // the Kth ancestor of the target.
            if (k == 0)
            {
                ans = root->data;
            }

            // Return current node to its parent.
            return root;
        }

        // Target was not found in either subtree.
        return NULL;
    }


    // Main function to find Kth ancestor
    int kthAncestor(Node* root, int k, int node)
    {
        // Initially, no answer is found.
        ans = -1;

        // Start recursive search from root.
        solve(root, node, k);

        // Return the Kth ancestor.
        return ans;
    }
};


int main()
{
    // Creating the binary tree:
    //
    //              1
    //            /   \
    //           2     3
    //          / \
    //         4   5
    //        /
    //       6

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->left->left = new Node(6);

    // Target node
    int node = 6;

    // Find 2nd ancestor of node 6
    int k = 2;

    Solution obj;

    int result = obj.kthAncestor(root, k, node);

    cout << k << "th ancestor of node "
         << node << " is: " << result << endl;

    return 0;
}
