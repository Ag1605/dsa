
#include <bits/stdc++.h>
using namespace std;

// Structure of Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    vector<int> leftView(Node* root) {

        // Store the left view nodes
        vector<int> ans;

        // If tree is empty, return empty answer
        if (root == NULL) {
            return ans;
        }


        // Queue is used for level order traversal (BFS)
        queue<Node*> q;


        // Initially, insert root into queue
        q.push(root);


        // Continue until queue becomes empty
        while (!q.empty()) {

            /*
                Store the number of nodes at the current level.

                IMPORTANT:
                This size represents only the current level.
                Nodes added during this iteration belong to
                the next level.
            */

            int size = q.size();


            // Process all nodes of the current level
            for (int i = 0; i < size; i++) {

                // Get the front node
                Node* curr = q.front();

                // Remove it from queue
                q.pop();


                /*
                    First node of every level is visible
                    from the left side.

                    i == 0 means this is the first node
                    of the current level.
                */

                if (i == 0) {
                    ans.push_back(curr->data);
                }


                // Add left child to queue
                if (curr->left != NULL) {
                    q.push(curr->left);
                }


                // Add right child to queue
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }


        // Return all left view nodes
        return ans;
    }
};


// MAIN FUNCTION
int main() {

    /*
                1
               / \
              2   3
             / \   \
            4   5   6
               /
              7
    */

    // Create root node
    Node* root = new Node(1);

    // Second level
    root->left = new Node(2);
    root->right = new Node(3);

    // Third level
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Fourth level
    root->left->right->left = new Node(7);


    // Create Solution object
    Solution obj;

    // Call left view function
    vector<int> ans = obj.leftView(root);


    // Print result
    cout << "Left View: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
