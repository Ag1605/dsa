#include <iostream>
#include <algorithm>

using namespace std;


/*
    Definition of Binary Tree Node
*/
struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
public:

    /*
        Find Maximum Depth of Binary Tree

        Example:

                1
               / \
              2   3
             /
            4

        Depth = 3

        Level 1 -> 1
        Level 2 -> 2, 3
        Level 3 -> 4
    */
    int maxDepth(TreeNode* root) {

        /*
            BASE CASE:

            If the current node is NULL,
            there is no tree/subtree.

            Therefore, its depth is 0.
        */
        if (root == nullptr)
            return 0;


        /*
            RECURSIVE CASE:

            Recursively find the maximum depth
            of the LEFT subtree.

            Example:

                    1
                   /
                  2
                 /
                4

            maxDepth(1->left)
            will calculate the depth of
            the subtree rooted at 2.
        */
        int leftHeight = maxDepth(root->left);


        /*
            Recursively find the maximum depth
            of the RIGHT subtree.
        */
        int rightHeight = maxDepth(root->right);


        /*
            We have calculated:

                leftHeight
                rightHeight

            The current node contributes +1
            to the depth.

            Therefore:

            Depth = 1 + maximum of
                    left and right subtree
        */
        return 1 + max(leftHeight, rightHeight);
    }
};


/*
    Main Function
*/
int main() {

    /*
        Create the following binary tree:

                1
               / \
              2   3
             /
            4

        Maximum Depth = 3
    */

    // Create root
    TreeNode* root = new TreeNode(1);

    // Create left and right children
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Create child of node 2
    root->left->left = new TreeNode(4);


    /*
        Create Solution object
        and call maxDepth().
    */
    Solution obj;

    int depth = obj.maxDepth(root);


    // Print result
    cout << "Maximum Depth of Binary Tree: "
         << depth << endl;


    return 0;
}