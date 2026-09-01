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
        ----------------------------------------------------
        FUNCTION 1: Calculate Height of Binary Tree
        ----------------------------------------------------

        Height means the maximum number of nodes
        present on a path from the current node
        down to a leaf.

        Example:

                1
               /
              2
             /
            3

        height(3) = 1
        height(2) = 2
        height(1) = 3
    */
    int height(TreeNode* root) {

        /*
            BASE CASE:

            If there is no node,
            height is 0.
        */
        if (root == nullptr)
            return 0;


        /*
            Recursively calculate the height
            of the LEFT subtree.
        */
        int leftHeight = height(root->left);


        /*
            Recursively calculate the height
            of the RIGHT subtree.
        */
        int rightHeight = height(root->right);


        /*
            Current node contributes 1.

            Therefore:

            Height =
                1 + maximum height of
                    left and right subtree
        */
        return 1 + max(leftHeight, rightHeight);
    }


    /*
        ----------------------------------------------------
        FUNCTION 2: Calculate Diameter of Binary Tree
        ----------------------------------------------------

        Diameter = Longest path between any two nodes.

        The path does NOT necessarily have to
        pass through the root.

        Example:

                1
               / \
              2   3
             / \
            4   5

        Longest path:

                4 -> 2 -> 1 -> 3

        Diameter = 3 edges
    */
    int diameterOfBinaryTree(TreeNode* root) {

        /*
            BASE CASE:

            Empty tree has diameter 0.
        */
        if (root == nullptr)
            return 0;


        /*
            Find height of LEFT subtree.

            This tells us the longest path
            from the current node into the left side.
        */
        int leftHeight = height(root->left);


        /*
            Find height of RIGHT subtree.

            This tells us the longest path
            from the current node into the right side.
        */
        int rightHeight = height(root->right);


        /*
            Diameter passing THROUGH the current node:

                    left subtree
                         |
                         v
                        root
                         ^
                         |
                    right subtree

            Number of edges =
                leftHeight + rightHeight

            Example:

                    1
                   / \
                  2   3
                 /
                4

            leftHeight = 2
            rightHeight = 1

            currentDiameter = 2 + 1 = 3
        */
        int currentDiameter = leftHeight + rightHeight;


        /*
            The longest diameter might NOT pass
            through the current node.

            So we recursively calculate the
            diameter of the LEFT subtree.
        */
        int leftDiameter =
            diameterOfBinaryTree(root->left);


        /*
            Similarly, calculate the diameter
            of the RIGHT subtree.
        */
        int rightDiameter =
            diameterOfBinaryTree(root->right);


        /*
            The final answer is the maximum of:

            1. Diameter passing through current node
            2. Diameter entirely inside left subtree
            3. Diameter entirely inside right subtree
        */
        return max(currentDiameter,
                   max(leftDiameter, rightDiameter));
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
             / \
            4   5

        Longest path:

                4 -> 2 -> 1 -> 3

        Number of edges = 3

        Therefore:

        Diameter = 3
    */

    // Create root
    TreeNode* root = new TreeNode(1);

    // Create children of root
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Create children of node 2
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


    /*
        Create Solution object
    */
    Solution obj;


    /*
        Calculate diameter
    */
    int diameter =
        obj.diameterOfBinaryTree(root);


    /*
        Print the result
    */
    cout << "Diameter of Binary Tree: "
         << diameter << endl;


    return 0;
}