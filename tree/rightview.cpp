
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

    vector<int> rightView(Node* root) {

        // Store nodes visible from the right side
        vector<int> ans;

        // If tree is empty, return empty answer
        if (root == NULL) {
            return ans;
        }


        // Queue is used for BFS traversal
        queue<Node*> q;


        // Insert root into queue
        q.push(root);


        // Continue until queue becomes empty
        while (!q.empty()) {

            /*
                Store the number of nodes at the current level.

                We process only these nodes in the current iteration.
                Newly inserted children belong to the next level.
            */

            int size = q.size();


            // Process all nodes of the current level
            for (int i = 0; i < size; i++) {

                // Get the front node
                Node* curr = q.front();

                // Remove front node
                q.pop();


                /*
                    Last node of every level is visible
                    from the right side.

                    i == size - 1 means we are processing
                    the last node of the current level.
                */

                if (i == size - 1) {
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


        // Return right view
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

    // Call right view function
    vector<int> ans = obj.rightView(root);


    // Print result
    cout << "Right View: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
