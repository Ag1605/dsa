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
        Calculate Sum of All Nodes

        Example:

                1
               / \
              2   3
             / \
            4   5

        Sum = 1 + 2 + 3 + 4 + 5
            = 15
    */
    int sumNodes(TreeNode* root) {

        /*
            BASE CASE:

            If the current node is NULL,
            there is nothing to add.

            Therefore, return 0.
        */
        if (root == nullptr)
            return 0;


        /*
            RECURSIVE CASE:

            Recursively calculate the sum
            of all nodes in the LEFT subtree.
        */
        int leftSum = sumNodes(root->left);


        /*
            Recursively calculate the sum
            of all nodes in the RIGHT subtree.
        */
        int rightSum = sumNodes(root->right);


        /*
            Now combine all three parts:

            Current node value
            +
            Sum of left subtree
            +
            Sum of right subtree

            Therefore:

            Total Sum = root->val + leftSum + rightSum
        */
        return root->val + leftSum + rightSum;
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

        Node values:

        1, 2, 3, 4, 5

        Expected Sum:

        1 + 2 + 3 + 4 + 5 = 15
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
        and call sumNodes().
    */
    Solution obj;

    int totalSum = obj.sumNodes(root);


    // Print the result
    cout << "Sum of All Nodes: "
         << totalSum << endl;


    return 0;
}