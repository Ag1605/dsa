
#include <bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
struct Node
{
    int data;       // Stores the value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor: Creates a new node
    Node(int val)
    {
        data = val;

        // Initially, both children are NULL
        left = NULL;
        right = NULL;
    }
};

// Function to print all nodes present at Kth level
void printKthLevel(Node* root, int k, int level)
{
    // BASE CASE 1:
    // If the current node is NULL, there is nothing to process
    if (root == NULL)
    {
        return;
    }

    // BASE CASE 2:
    // If the current level becomes equal to K,
    // we have reached the required level.
    // Print the current node's data.
    if (level == k)
    {
        cout << root->data << " ";

        // No need to visit children because
        // we only want nodes at level K.
        return;
    }

    // RECURSIVE CALL 1:
    // Move to the left child.
    // Since we move one level down, increase level by 1.
    printKthLevel(root->left, k, level + 1);

    // RECURSIVE CALL 2:
    // Move to the right child.
    // Again, increase level by 1.
    printKthLevel(root->right, k, level + 1);
}

int main()
{
    // STEP 1: Create the root node
    Node* root = new Node(1);

    // STEP 2: Create the left and right children
    root->left = new Node(2);
    root->right = new Node(3);

    // STEP 3: Create children of node 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // STEP 4: Create children of node 3
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // STEP 5: Specify which level we want to print
    int k = 2;

    cout << "Nodes at level " << k << ": ";

    // STEP 6: Call the function
    // Root node starts at level 0
    printKthLevel(root, k, 0);

    cout << endl;

    return 0;
}
