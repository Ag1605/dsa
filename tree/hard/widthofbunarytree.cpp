
#include <bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    int widthOfBinaryTree(TreeNode* root) {

        // If the tree is empty, width is 0.
        if (root == NULL) {
            return 0;
        }

        // STEP 1: Create a queue that stores:
        // 1. TreeNode*       -> Address of the node.
        // 2. unsigned long long -> Index of the node.
        //
        // We assign indexes as if the binary tree were a complete
        // binary tree, including positions of missing nodes.

        queue<pair<TreeNode*, unsigned long long>> q;

        // Root is assigned index 0.
        q.push({root, 0});

        // Stores the maximum width found so far.
        unsigned long long maxWidth = 0;

        // STEP 2: Perform BFS (level-order traversal).
        while (!q.empty()) {

            // Number of nodes present at the current level.
            int size = q.size();

            // Get the index of the first node at this level.
            unsigned long long minIndex = q.front().second;

            // Stores the index of the first and last node
            // at the current level.
            unsigned long long firstIndex = 0;
            unsigned long long lastIndex = 0;

            // Process all nodes at the current level.
            for (int i = 0; i < size; i++) {

                // Get the front node and its index.
                auto curr = q.front();
                q.pop();

                TreeNode* node = curr.first;

                // STEP 3: Normalize the index.
                //
                // Subtract the first index of the current level
                // from the current node's index.
                //
                // This keeps indexes smaller and helps prevent
                // integer overflow in large trees.

                unsigned long long index = curr.second - minIndex;

                // First node at the current level.
                if (i == 0) {
                    firstIndex = index;
                }

                // Last node at the current level.
                if (i == size - 1) {
                    lastIndex = index;
                }

                // STEP 4: Calculate indexes of child nodes.
                //
                // For a node at index i:
                //
                // Left child  = 2 * i + 1
                // Right child = 2 * i + 2

                // Process left child.
                if (node->left != NULL) {

                    q.push({
                        node->left,
                        2 * index + 1
                    });
                }

                // Process right child.
                if (node->right != NULL) {

                    q.push({
                        node->right,
                        2 * index + 2
                    });
                }
            }

            // STEP 5: Calculate width of the current level.
            //
            // Width = Last index - First index + 1
            //
            // We add 1 because indexes are zero-based.

            unsigned long long width =
                lastIndex - firstIndex + 1;

            // Update maximum width.
            maxWidth = max(maxWidth, width);
        }

        // Return the maximum width of the binary tree.
        return (int)maxWidth;
    }
};


// MAIN FUNCTION
int main() {

    // Construct the following binary tree:
    //
    //              1
    //            /   \
    //           3     2
    //          / \     \
    //         5   3     9
    //
    // Indexes:
    //
    //              0
    //            /   \
    //           1     2
    //          / \     \
    //         3   4     6

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(9);

    Solution obj;

    int ans = obj.widthOfBinaryTree(root);

    cout << "Maximum width of binary tree: " << ans << endl;

    return 0;
}
