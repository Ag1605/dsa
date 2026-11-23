
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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // STEP 1: Create a parent mapping.
        // A binary tree allows us to move only towards left and right.
        // But for distance K, we must also move towards the parent.
        // So, store the parent of every node.

        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;

        q.push(root);

        // Root does not have any parent.
        parent[root] = NULL;

        // Traverse the entire tree using BFS.
        while (!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            // Store parent of the left child.
            if (curr->left != NULL) {

                parent[curr->left] = curr;

                q.push(curr->left);
            }

            // Store parent of the right child.
            if (curr->right != NULL) {

                parent[curr->right] = curr;

                q.push(curr->right);
            }
        }

        // STEP 2: Start BFS from the target node.
        // We will explore nodes in all three directions:
        // 1. Left child
        // 2. Right child
        // 3. Parent

        // Visited set prevents visiting the same node again.
        unordered_set<TreeNode*> visited;

        // Queue stores nodes at the current and upcoming distances.
        queue<TreeNode*> burn;

        // Start BFS from the target node.
        burn.push(target);

        // Mark target as visited.
        visited.insert(target);

        // Distance of target from itself is 0.
        int distance = 0;

        // STEP 3: Perform BFS until we reach distance K.
        while (!burn.empty() && distance < k) {

            // Number of nodes at the current distance.
            int size = burn.size();

            // Process all nodes at this distance.
            for (int i = 0; i < size; i++) {

                TreeNode* curr = burn.front();
                burn.pop();

                // CASE 1: Visit the left child.
                if (curr->left != NULL &&
                    visited.find(curr->left) == visited.end()) {

                    burn.push(curr->left);

                    visited.insert(curr->left);
                }

                // CASE 2: Visit the right child.
                if (curr->right != NULL &&
                    visited.find(curr->right) == visited.end()) {

                    burn.push(curr->right);

                    visited.insert(curr->right);
                }

                // CASE 3: Visit the parent.
                if (parent[curr] != NULL &&
                    visited.find(parent[curr]) == visited.end()) {

                    burn.push(parent[curr]);

                    visited.insert(parent[curr]);
                }
            }

            // After processing one complete BFS level,
            // we have moved one unit farther from the target.
            distance++;
        }

        // STEP 4: Collect all nodes at distance K.
        // At this point, the queue contains only nodes
        // whose distance from the target is exactly K.

        vector<int> ans;

        while (!burn.empty()) {

            ans.push_back(burn.front()->val);

            burn.pop();
        }

        return ans;
    }
};


// MAIN FUNCTION
int main() {

    // Construct the following binary tree:
    //
    //             3
    //           /   \
    //          5     1
    //         / \   / \
    //        6   2 0   8
    //           / \
    //          7   4

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Target node is 5.
    TreeNode* target = root->left;

    // Find all nodes at distance K = 2.
    int k = 2;

    Solution obj;

    vector<int> ans = obj.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target "
         << target->val << " are: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
