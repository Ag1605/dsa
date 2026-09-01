#include <iostream>
#include <vector>
#include <queue>
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
        Bottom-Up Level Order Traversal

        Example Tree:

                1
               / \
              2   3
             / \
            4   5

        Normal Level Order:

        [1]
        [2, 3]
        [4, 5]

        Bottom-Up Level Order:

        [4, 5]
        [2, 3]
        [1]
    */
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        // Stores the final answer
        vector<vector<int>> ans;


        /*
            If the tree is empty,
            there are no levels to return.
        */
        if (root == nullptr)
            return ans;


        /*
            Queue is used for BFS
            (Breadth First Search).

            Initially:

                q = [1]
        */
        queue<TreeNode*> q;

        // Start BFS from root
        q.push(root);


        /*
            Continue until the queue becomes empty.
        */
        while (!q.empty()) {

            /*
                Store the number of nodes
                present in the CURRENT level.

                This is important because while processing
                the current level, we will add children
                belonging to the NEXT level.
            */
            int size = q.size();


            // Stores values of the current level
            vector<int> level;


            /*
                Process all nodes of the current level.
            */
            for (int i = 0; i < size; i++) {

                // Get the front node
                TreeNode* node = q.front();

                // Remove it from the queue
                q.pop();


                // Store the node's value
                level.push_back(node->val);


                /*
                    Add LEFT child to the queue.

                    It will be processed
                    in the next level.
                */
                if (node->left != nullptr)
                    q.push(node->left);


                /*
                    Add RIGHT child to the queue.

                    It will also be processed
                    in the next level.
                */
                if (node->right != nullptr)
                    q.push(node->right);
            }


            /*
                Store the current level.

                BFS naturally gives us:

                Top → Bottom

                Example:

                [1]
                [2, 3]
                [4, 5]
            */
            ans.push_back(level);
        }


        /*
            At this point, ans contains levels
            from TOP to BOTTOM.

            Example:

                ans = [
                    [1],
                    [2, 3],
                    [4, 5]
                ]

            But the problem wants BOTTOM to TOP.

            So reverse the complete answer:

                ans = [
                    [4, 5],
                    [2, 3],
                    [1]
                ]
        */
        reverse(ans.begin(), ans.end());


        // Return bottom-up level order
        return ans;
    }
};


/*
    Function to Build Binary Tree

    We use -1 to represent NULL.

    Example:

        Input:
        1 2 3 4 5 -1 6

        Tree:

                1
               / \
              2   3
             / \   \
            4   5   6
*/
TreeNode* buildTree(vector<int>& values) {

    // Empty input or NULL root
    if (values.empty() || values[0] == -1)
        return nullptr;


    // Create root node
    TreeNode* root = new TreeNode(values[0]);


    /*
        Queue is used to attach children
        level by level.
    */
    queue<TreeNode*> q;

    // Start with root
    q.push(root);


    // Start reading from second value
    int i = 1;


    /*
        Process every node and attach
        its left and right children.
    */
    while (!q.empty() && i < values.size()) {

        // Get current parent node
        TreeNode* current = q.front();
        q.pop();


        /*
            Create LEFT child.

            -1 means there is no left child.
        */
        if (values[i] != -1) {

            current->left = new TreeNode(values[i]);

            // Add child to queue
            q.push(current->left);
        }

        // Move to next value
        i++;


        /*
            Create RIGHT child.

            -1 means there is no right child.
        */
        if (i < values.size() && values[i] != -1) {

            current->right = new TreeNode(values[i]);

            // Add child to queue
            q.push(current->right);
        }

        // Move to next value
        i++;
    }


    // Return constructed tree
    return root;
}


/*
    Main Function
*/
int main() {

    /*
        Example:

                1
               / \
              2   3
             / \
            4   5

        Level Order Input:

        1 2 3 4 5 -1 -1

        -1 represents NULL.
    */
    vector<int> values = {
        1, 2, 3, 4, 5, -1, -1
    };


    // Build the binary tree
    TreeNode* root = buildTree(values);


    // Create Solution object
    Solution obj;


    /*
        Call bottom-up level order traversal.
    */
    vector<vector<int>> ans =
        obj.levelOrderBottom(root);


    /*
        Print the result.
    */
    cout << "Bottom-Up Level Order Traversal:" << endl;

    for (int i = 0; i < ans.size(); i++) {

        cout << "[";

        for (int j = 0; j < ans[i].size(); j++) {

            cout << ans[i][j];

            // Print comma between elements
            if (j != ans[i].size() - 1)
                cout << ", ";
        }

        cout << "]" << endl;
    }


    return 0;
}