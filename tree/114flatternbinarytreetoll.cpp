
#include <bits/stdc++.h>
using namespace std;


// Structure of a Binary Tree Node
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};


class Solution
{
public:

    // Stores the previously processed node.
    //
    // Initially NULL because we have not processed
    // any node yet.
    TreeNode* prev = NULL;


    // Function to flatten the binary tree
    void flatten(TreeNode* root)
    {
        // STEP 1: Base Case
        //
        // If the current node is NULL,
        // there is nothing to flatten.
        if (root == NULL)
        {
            return;
        }


        // STEP 2: Reverse Preorder Traversal
        //
        // Normal preorder:
        // Root -> Left -> Right
        //
        // Here we use reverse preorder:
        // Right -> Left -> Root
        //
        // First process the right subtree.
        flatten(root->right);


        // Then process the left subtree.
        flatten(root->left);


        // STEP 3: Connect current node to previous node
        //
        // The previously processed node becomes
        // the next node in our flattened linked list.
        //
        // Connect current node's right pointer
        // to the previously processed node.
        root->right = prev;


        // STEP 4: Make left pointer NULL
        //
        // In the flattened linked list,
        // every node must have its left pointer NULL.
        root->left = NULL;


        // STEP 5: Update previous node
        //
        // Current node is now the previously
        // processed node for the next recursive call.
        prev = root;
    }
};


// Function to print the flattened linked list
void printList(TreeNode* root)
{
    while (root != NULL)
    {
        cout << root->val << " -> ";

        // Move to the next node using right pointer
        root = root->right;
    }

    cout << "NULL" << endl;
}


int main()
{
    /*
              1
             / \
            2   5
           / \   \
          3   4   6

       Expected flattened tree:

       1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);


    Solution obj;

    // Flatten the binary tree into a linked list
    obj.flatten(root);


    // Print the flattened linked list
    cout << "Flattened Linked List:" << endl;

    printList(root);


    return 0;
}
