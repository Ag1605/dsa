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
        Stores the maximum diameter found
        during the DFS traversal.

        Diameter is measured in NUMBER OF EDGES.
    */
    int diameter = 0;


    /*
        ----------------------------------------------------
        FUNCTION: height()
        ----------------------------------------------------

        This function does TWO things:

        1. Calculates the height of the current subtree.
        2. Updates the maximum diameter.

        This allows us to calculate both values
        in a SINGLE traversal.
    */
    int height(TreeNode* root) {

        /*
            BASE CASE:

            If the current node is NULL,
            its height is 0.
        */
        if (root == nullptr)
            return 0;


        /*
            Recursively calculate the height
            of the LEFT subtree.

            We need this height to calculate:

                diameter through current node
        */
        int leftHeight = height(root->left);


        /*
            Recursively calculate the height
            of the RIGHT subtree.
        */
        int rightHeight = height(root->right);


        /*
            Diameter passing THROUGH the current node:

                    left subtree
                         |
                         |
                        root
                         |
                         |
                    right subtree

            Number of edges:

                leftHeight + rightHeight

            Example:

                    1
                   / \
                  2   3
                 /
                4

            leftHeight = 2
            rightHeight = 1

            Diameter through node 1:

                2 + 1 = 3
        */
        diameter = max(diameter,
                       leftHeight + rightHeight);


        /*
            Return the height of the current subtree.

            Current node contributes 1.

            Therefore:

                height =
                    1 + max(leftHeight, rightHeight)
        */
        return 1 + max(leftHeight, rightHeight);
    }


    /*
        ----------------------------------------------------
        FUNCTION: diameterOfBinaryTree()
        ----------------------------------------------------

        This is the main function that the
        LeetCode problem calls.
    */
    int diameterOfBinaryTree(TreeNode* root) {

        /*
            Start DFS traversal.

            height() will:
            - calculate heights
            - update diameter
        */
        height(root);


        /*
            After the DFS is complete,
            diameter contains the maximum diameter
            found anywhere in the tree.
        */
        return diameter;
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
        Calculate diameter of the binary tree
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