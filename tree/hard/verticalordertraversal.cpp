
#include <bits/stdc++.h>
using namespace std;

// Structure of Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // If tree is empty, return empty answer
        if (root == NULL) {
            return {};
        }

        /*
            Store nodes using three levels:

            map<int, map<int, multiset<int>>>

            First map:
            Column -> Stores columns from left to right

            Second map:
            Row -> Stores rows from top to bottom

            Multiset:
            Stores node values in sorted order
            when multiple nodes have the same row and column.
        */

        map<int, map<int, multiset<int>>> nodes;


        /*
            Queue stores:

            TreeNode*
            Row
            Column

            Format:
            {node, {row, column}}
        */

        queue<pair<TreeNode*, pair<int, int>>> q;


        // Root starts at row 0 and column 0
        q.push({root, {0, 0}});


        // STEP 1: Perform BFS traversal
        while (!q.empty()) {

            // Get the front element from queue
            auto p = q.front();

            // Remove front element
            q.pop();


            // Extract current tree node
            TreeNode* node = p.first;

            // Extract row and column
            int row = p.second.first;
            int col = p.second.second;


            // Store node value at its row and column
            // Multiset automatically maintains sorted order
            nodes[col][row].insert(node->val);


            // STEP 2: Process left child

            if (node->left != NULL) {

                // Left child:
                // Row increases by 1
                // Column decreases by 1

                q.push({
                    node->left,
                    {row + 1, col - 1}
                });
            }


            // STEP 3: Process right child

            if (node->right != NULL) {

                // Right child:
                // Row increases by 1
                // Column increases by 1

                q.push({
                    node->right,
                    {row + 1, col + 1}
                });
            }
        }


        // STEP 4: Build final answer

        vector<vector<int>> ans;


        // Traverse columns from left to right
        // Map automatically sorts column numbers

        for (auto p : nodes) {

            // Store one complete vertical column
            vector<int> col;


            // Traverse rows from top to bottom
            // Inner map automatically sorts row numbers

            for (auto q : p.second) {

                // Traverse all values at the same row and column
                // Multiset automatically gives sorted values

                for (auto val : q.second) {

                    col.push_back(val);
                }
            }

            // Add completed vertical column to answer
            ans.push_back(col);
        }


        // Return final vertical traversal
        return ans;
    }
};


// MAIN FUNCTION
int main() {

    /*
                1
               / \
              2   3
             / \ / \
            4  5 6  7
    */

    // Create root
    TreeNode* root = new TreeNode(1);

    // Second level
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Third level
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    // Create Solution object
    Solution obj;

    // Call vertical traversal
    vector<vector<int>> ans = obj.verticalTraversal(root);


    // Print answer
    cout << "Vertical Traversal:" << endl;

    for (int i = 0; i < ans.size(); i++) {

        for (int j = 0; j < ans[i].size(); j++) {

            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
