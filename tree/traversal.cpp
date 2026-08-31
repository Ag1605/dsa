#include <iostream>
#include <vector>
#include <queue>
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

// Build Binary Tree from Preorder
Node* buildTree(vector<int>& preorder, int& index) {

    // -1 means there is no node
    if (preorder[index] == -1) {
        index++;
        return NULL;
    }

    // Create current node
    Node* root = new Node(preorder[index]);
    index++;

    // Build left subtree
    root->left = buildTree(preorder, index);

    // Build right subtree
    root->right = buildTree(preorder, index);

    return root;
}

// Preorder: Root -> Left -> Right
void preorder(Node* root) {

    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left -> Root -> Right
void inorder(Node* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {

    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}

// Level Order: Level by Level
void levelorder(Node* root) {

    if (root == NULL) {
        return;
    }

    // Queue is used for level order traversal
    queue<Node*> q;

    // Start with root
    q.push(root);

    while (!q.empty()) {

        // Take the front node
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        // Add left child to queue
        if (current->left != NULL) {
            q.push(current->left);
        }

        // Add right child to queue
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {

    // Preorder representation of tree
    // -1 means NULL
    vector<int> values = {
        1,
        2, 4, -1, -1, 5, -1, -1,
        3, -1, -1
    };

    // Start from index 0
    int index = 0;

    // Build the tree
    Node* root = buildTree(values, index);

    // Preorder
    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    // Inorder
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    // Postorder
    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    // Level Order
    cout << "Level Order: ";
    levelorder(root);
    cout << endl;

    return 0;
}