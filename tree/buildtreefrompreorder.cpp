#include <iostream>
#include <vector>
using namespace std;

// Node of Binary Tree
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

// Build tree from preorder
Node* buildTree(vector<int>& preorder, int& index) {

    // If value is -1, there is no node
    if (preorder[index] == -1) {
        index++;
        return NULL;
    }

    // Create current node
    Node* root = new Node(preorder[index]);
    index++;

    // First build left subtree
    root->left = buildTree(preorder, index);

    // Then build right subtree
    root->right = buildTree(preorder, index);

    return root;
}

int main() {

    // Preorder traversal
    // -1 means NULL
    vector<int> preorder = {
        1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1
    };

    // Start from index 0
    int index = 0;

    // Build the binary tree
    Node* root = buildTree(preorder, index);

    return 0;
}