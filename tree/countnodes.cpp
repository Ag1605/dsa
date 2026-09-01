#include <iostream>

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
        Count Nodes in a Binary Tree

        Example:

                1
               / \
              2   3
             / \
            4   5

        Total Nodes = 5
    */
    int countNodes(TreeNode* root) {

        /*
            BASE CASE:

            If the current node is NULL,
            there is no node to count.

            Therefore, return 0.
        */
        if (root == nullptr)
            return 0;


        /*
            RECURSIVE CASE:

            Recursively count all nodes
            present in the LEFT subtree.

            For example, if root = 1,
            this will count nodes under node 2.
        */
        int leftCount = countNodes(root->left);


        /*
            Recursively count all nodes
            present in the RIGHT subtree.

            For root = 1,
            this will count nodes under node 3.
        */
        int rightCount = countNodes(root->right);


        /*
            Now combine all three parts:

            1 -> Current node
            leftCount -> Nodes in left subtree
            rightCount -> Nodes in right subtree

            Therefore:

            Total = 1 + leftCount + rightCount
        */
        return 1 + leftCount + rightCount;
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

        Nodes are:

        1
        2
        3
        4
        5

        Total = 5
    */

    // Create root node
    TreeNode* root = new TreeNode(1);

    // Create children of root
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Create children of node 2
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


    /*
        Create Solution object
        and call countNodes().
    */
    Solution obj;

    int totalNodes = obj.countNodes(root);


    // Print the result
    cout << "Total Number of Nodes: "
         << totalNodes << endl;


    return 0;
}