
#include <bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    // Constructor
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

    // Function to convert Binary Tree into Sum Tree
    int toSumTree(Node* root)
    {
        // BASE CASE:
        // If node is NULL, its subtree sum is 0.
        if (root == NULL)
        {
            return 0;
        }

        // STEP 1:
        // Store the original value of current node.
        // We need this because we will modify root->data.
        int original = root->data;

        // STEP 2:
        // Recursively calculate the sum of the LEFT subtree.
        // This function also converts the left subtree into Sum Tree.
        int leftSum = toSumTree(root->left);

        // STEP 3:
        // Recursively calculate the sum of the RIGHT subtree.
        // This function also converts the right subtree into Sum Tree.
        int rightSum = toSumTree(root->right);

        // STEP 4:
        // Update current node's value.
        // New value = Original sum of left subtree
        //           + Original sum of right subtree.
        root->data = leftSum + rightSum;

        // STEP 5:
        // Return the original total sum of this subtree.
        // Original current node + left subtree sum + right subtree sum.
        return original + leftSum + rightSum;
    }
};


// Function to print the tree using inorder traversal
void inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}


int main()
{
    // Creating the original Binary Tree:
    //
    //              10
    //            /    \
    //           -2     6
    //          / \    / \
    //         8  -4  7   5

    Node* root = new Node(10);

    root->left = new Node(-2);
    root->right = new Node(6);

    root->left->left = new Node(8);
    root->left->right = new Node(-4);

    root->right->left = new Node(7);
    root->right->right = new Node(5);

    Solution obj;

    // Convert original tree into Sum Tree
    obj.toSumTree(root);

    // Print the updated tree
    cout << "Inorder Traversal of Sum Tree: ";

    inorder(root);

    cout << endl;

    return 0;
}
