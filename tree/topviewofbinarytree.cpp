
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition of Binary Tree Node.
struct Node {

    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> topView(Node* root) {

        vector<int> ans;

        // If tree is empty, return an empty vector.
        if (root == NULL) {
            return ans;
        }

        // Map stores:
        // Horizontal Distance -> First visible node value.
        // Map automatically sorts horizontal distances.
        map<int, int> mp;

        // Queue stores:
        // {Node pointer, Horizontal Distance}.
        // We use BFS to traverse level by level.
        queue<pair<Node*, int>> q;

        // Root is at horizontal distance 0.
        q.push({root, 0});

        // Perform Level Order Traversal.
        while (!q.empty()) {

            // Get the front element from the queue.
            auto it = q.front();
            q.pop();

            // Extract node and its horizontal distance.
            Node* node = it.first;
            int hd = it.second;

            // If this horizontal distance is not present,
            // store the current node.
            // BFS ensures the first node encountered is
            // the topmost node at this horizontal distance.
            if (mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }

            // Left child moves one position left.
            // Therefore, horizontal distance decreases by 1.
            if (node->left != NULL) {
                q.push({node->left, hd - 1});
            }

            // Right child moves one position right.
            // Therefore, horizontal distance increases by 1.
            if (node->right != NULL) {
                q.push({node->right, hd + 1});
            }
        }

        // Extract node values from the map.
        // Map automatically gives horizontal distances
        // in ascending order.
        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {

    /*
                  1
                /   \
               2     3
                \   /
                 4 5
    */

    // Create binary tree.
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);
    root->right->left = new Node(5);

    Solution obj;

    // Find the top view.
    vector<int> result = obj.topView(root);

    cout << "Top View: ";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
