
#include <bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    int minTime(Node* root, int target) {

        // STEP 1: Create a parent mapping for every node.
        // Since a normal binary tree has child pointers but no parent pointer,
        // we store each node's parent using an unordered_map.

        unordered_map<Node*, Node*> parent;

        // BFS queue to traverse the entire binary tree.
        queue<Node*> q;

        q.push(root);

        // Store the address of the node where the fire starts.
        Node* targetNode = NULL;

        // Root has no parent.
        parent[root] = NULL;

        // Traverse the tree and build the parent mapping.
        while (!q.empty()) {

            Node* curr = q.front();
            q.pop();

            // Check whether the current node is the target node.
            if (curr->data == target) {
                targetNode = curr;
            }

            // Process the left child.
            if (curr->left != NULL) {

                // Store the parent of the left child.
                parent[curr->left] = curr;

                q.push(curr->left);
            }

            // Process the right child.
            if (curr->right != NULL) {

                // Store the parent of the right child.
                parent[curr->right] = curr;

                q.push(curr->right);
            }
        }

        // STEP 2: Start BFS from the target node.
        // Fire can spread in three directions:
        // 1. Left child
        // 2. Right child
        // 3. Parent

        // Visited prevents burning the same node multiple times.
        unordered_set<Node*> visited;

        // Queue stores nodes that are currently burning.
        queue<Node*> burn;

        burn.push(targetNode);

        // Mark the starting node as visited.
        visited.insert(targetNode);

        // Stores the total time required to burn the tree.
        int time = 0;

        // STEP 3: Spread fire level by level.
        while (!burn.empty()) {

            // Number of nodes burning at the current second.
            int size = burn.size();

            // Checks whether fire spreads to any new node.
            bool burned = false;

            // Process all nodes burning at the current level.
            for (int i = 0; i < size; i++) {

                Node* curr = burn.front();
                burn.pop();

                // CASE 1: Burn the left child.
                if (curr->left != NULL &&
                    visited.find(curr->left) == visited.end()) {

                    burn.push(curr->left);

                    visited.insert(curr->left);

                    burned = true;
                }

                // CASE 2: Burn the right child.
                if (curr->right != NULL &&
                    visited.find(curr->right) == visited.end()) {

                    burn.push(curr->right);

                    visited.insert(curr->right);

                    burned = true;
                }

                // CASE 3: Burn the parent.
                if (parent[curr] != NULL &&
                    visited.find(parent[curr]) == visited.end()) {

                    burn.push(parent[curr]);

                    visited.insert(parent[curr]);

                    burned = true;
                }
            }

            // If at least one new node caught fire,
            // one second has passed.
            if (burned) {
                time++;
            }
        }

        // All nodes are burned.
        return time;
    }
};


// MAIN FUNCTION
int main() {

    // Construct the following binary tree:
    //
    //             1
    //           /   \
    //          2     3
    //         /     / \
    //        4     5   6
    //             /
    //            7

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    root->right->left = new Node(5);
    root->right->right = new Node(6);

    root->right->left->left = new Node(7);

    // Fire starts from node 5.
    int target = 5;

    Solution obj;

    int ans = obj.minTime(root, target);

    cout << "Minimum time to burn the entire tree: " << ans << endl;

    return 0;
}
