#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
    Definition of a Binary Tree Node
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
        Zigzag Level Order Traversal

        Example:

                1
               / \
              2   3
             / \   \
            4   5   6

        Normal Level Order:
        1
        2 3
        4 5 6

        Zigzag Level Order:
        1
        3 2
        4 5 6
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // Stores the final answer
        vector<vector<int>> ans;

        // If tree is empty, return empty answer
        if (root == nullptr)
            return ans;

        /*
            Queue is used for BFS (Level Order Traversal).

            Initially:
                q = [1]
        */
        queue<TreeNode*> q;

        // Start BFS from root
        q.push(root);

        /*
            This variable tells us the direction
            in which we should store the current level.

            true  -> left to right
            false -> right to left
        */
        bool leftToRight = true;


        /*
            Continue until there are no nodes left
            in the queue.
        */
        while (!q.empty()) {

            /*
                q.size() tells us how many nodes
                belong to the CURRENT level.

                We store it because while processing
                this level, we will add children
                for the NEXT level.
            */
            int size = q.size();

            // Stores values of the current level
            vector<int> level;


            /*
                Process every node of the current level.
            */
            for (int i = 0; i < size; i++) {

                // Get the first node from queue
                TreeNode* node = q.front();

                // Remove it from queue
                q.pop();


                /*
                    Store the node's value.

                    Initially we always collect values
                    from left to right because BFS gives
                    us nodes in that order.
                */
                level.push_back(node->val);


                /*
                    Add left child to queue.

                    These children will be processed
                    in the NEXT level.
                */
                if (node->left != nullptr)
                    q.push(node->left);


                /*
                    Add right child to queue.

                    These children will also be processed
                    in the NEXT level.
                */
                if (node->right != nullptr)
                    q.push(node->right);
            }


            /*
                If the direction is right to left,
                reverse the current level.

                Example:

                Before reverse:
                    [2, 3]

                After reverse:
                    [3, 2]
            */
            if (!leftToRight)
                reverse(level.begin(), level.end());


            // Add the completed level to the answer
            ans.push_back(level);


            /*
                Change direction for the next level.

                true  -> false
                false -> true

                So the traversal becomes:

                Left -> Right
                Right -> Left
                Left -> Right
                Right -> Left
                ...
            */
            leftToRight = !leftToRight;
        }


        // Return the complete zigzag traversal
        return ans;
    }
};


/*
    Build Binary Tree from Level Order Input

    We use -1 to represent NULL.

    Example input:

        1 2 3 4 5 -1 6

    Represents:

             1
            / \
           2   3
          / \   \
         4   5   6
*/
TreeNode* buildTree(vector<int>& values) {

    // If input is empty or first value is -1,
    // there is no tree.
    if (values.empty() || values[0] == -1)
        return nullptr;


    // Create root node
    TreeNode* root = new TreeNode(values[0]);

    // Queue helps us attach children level by level
    queue<TreeNode*> q;

    // Start with root
    q.push(root);

    // Index for traversing input array
    int i = 1;


    /*
        Continue until:
        1. Queue becomes empty
        2. We process all input values
    */
    while (!q.empty() && i < values.size()) {

        // Get current parent node
        TreeNode* current = q.front();
        q.pop();


        /*
            First value is the LEFT child.
        */
        if (values[i] != -1) {

            current->left = new TreeNode(values[i]);

            // Add left child to queue
            q.push(current->left);
        }

        // Move to next value
        i++;


        /*
            Second value is the RIGHT child.
        */
        if (i < values.size() && values[i] != -1) {

            current->right = new TreeNode(values[i]);

            // Add right child to queue
            q.push(current->right);
        }

        // Move to next value
        i++;
    }


    return root;
}


/*
    Main Function
*/
int main() {

    /*
        Example Tree:

                1
               / \
              2   3
             / \   \
            4   5   6

        Level order input:

        1 2 3 4 5 -1 6

        -1 means NULL.
    */
    vector<int> values = {
        1, 2, 3, 4, 5, -1, 6
    };


    // Build the binary tree
    TreeNode* root = buildTree(values);


    // Create Solution object
    Solution obj;


    // Call zigzag traversal
    vector<vector<int>> ans =
        obj.zigzagLevelOrder(root);


    /*
        Print the answer
    */
    cout << "Zigzag Level Order Traversal:" << endl;

    for (int i = 0; i < ans.size(); i++) {

        cout << "[";

        for (int j = 0; j < ans[i].size(); j++) {

            cout << ans[i][j];

            // Avoid printing comma after last element
            if (j != ans[i].size() - 1)
                cout << ", ";
        }

        cout << "]" << endl;
    }


    return 0;
}