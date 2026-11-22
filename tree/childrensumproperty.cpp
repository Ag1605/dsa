
#include <bits/stdc++.h>
using namespace std;


// Structure of a Binary Tree Node
class Node
{
public:

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

    // Function to check Children Sum Property
    bool isSumProperty(Node* root)
    {
        // STEP 1: Base Case
        //
        // If the tree is empty, it automatically
        // satisfies the Children Sum Property.
        if (root == NULL)
        {
            return true;
        }


        // STEP 2: Check Leaf Node
        //
        // A leaf node has no left or right child.
        // Leaf nodes automatically satisfy the property.
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }


        // STEP 3: Store the values of left and right children
        //
        // Initially, both values are 0.
        // If a child does not exist, its value remains 0.
        int left = 0;
        int right = 0;


        // If left child exists, get its data.
        if (root->left != NULL)
        {
            left = root->left->data;
        }


        // If right child exists, get its data.
        if (root->right != NULL)
        {
            right = root->right->data;
        }


        // STEP 4: Check Children Sum Property
        //
        // Current node value must equal
        // the sum of its immediate children.
        //
        // Example:
        //       10
        //      /  \
        //     4    6
        //
        // 10 == 4 + 6 (TRUE)
        if (root->data != left + right)
        {
            return false;
        }


        // STEP 5: Recursively check both subtrees
        //
        // Checking the current node is not enough.
        // Every non-leaf node in the entire tree
        // must satisfy the property.
        //
        // Check left subtree AND right subtree.
        return isSumProperty(root->left) &&
               isSumProperty(root->right);
    }
};


int main()
{
    /*
              10
             /  \
            8    2
           / \  / \
          3  5  2  0

       Check:
       10 = 8 + 2  TRUE
        8 = 3 + 5  TRUE
        2 = 2 + 0  TRUE

       All leaf nodes automatically satisfy.
    */

    Node* root = new Node(10);

    root->left = new Node(8);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(5);

    root->right->left = new Node(2);
    root->right->right = new Node(0);


    Solution obj;

    // Check whether the tree satisfies the property
    bool result = obj.isSumProperty(root);


    if (result)
    {
        cout << "Children Sum Property is Satisfied" << endl;
    }
    else
    {
        cout << "Children Sum Property is Not Satisfied" << endl;
    }


    return 0;
}
