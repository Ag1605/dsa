
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <functional>

using namespace std;

// Structure of a Binary Tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Codec {
public:

    // Converts the binary tree into a string
    string serialize(TreeNode* root) {

        // Stores the serialized tree
        string result = "";

        // Helper function for preorder traversal
        function<void(TreeNode*)> preorder =
        [&](TreeNode* node) {

            // If the node is NULL,
            // store N to preserve the tree structure
            if (node == nullptr) {
                result += "N,";
                return;
            }

            // Store the current node's value
            result += to_string(node->val) + ",";

            // Serialize the left subtree
            preorder(node->left);

            // Serialize the right subtree
            preorder(node->right);
        };

        // Start preorder traversal from the root
        preorder(root);

        // Return the complete serialized string
        return result;
    }


    // Converts the serialized string back into a tree
    TreeNode* deserialize(string data) {

        // If the string is empty,
        // return an empty tree
        if (data.empty()) {
            return nullptr;
        }

        // Stores all values separated by commas
        vector<string> values;

        // String stream helps split the string
        stringstream ss(data);

        string value;

        // Extract values one by one
        while (getline(ss, value, ',')) {
            values.push_back(value);
        }

        // Tracks the current position in values
        int index = 0;

        // Helper function to rebuild the tree
        function<TreeNode*()> build =
        [&]() -> TreeNode* {

            // Read the current value
            string current = values[index];

            // Move to the next value
            index++;

            // N represents a NULL node
            if (current == "N") {
                return nullptr;
            }

            // Convert string value into integer
            int nodeValue = stoi(current);

            // Create the current tree node
            TreeNode* node = new TreeNode(nodeValue);

            // Rebuild the left subtree
            node->left = build();

            // Rebuild the right subtree
            node->right = build();

            // Return the constructed node
            return node;
        };

        // Start rebuilding from the first value
        return build();
    }
};


// Prints the tree using preorder traversal
void printPreorder(TreeNode* root) {

    // Base case
    if (root == nullptr) {
        cout << "N ";
        return;
    }

    // Print root
    cout << root->val << " ";

    // Print left subtree
    printPreorder(root->left);

    // Print right subtree
    printPreorder(root->right);
}


int main() {

    // Create the original binary tree
    //
    //          1
    //         / \
    //        2   3
    //           /
    //          4

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);

    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);

    // Create Codec object
    Codec codec;

    // Serialize the tree
    string serialized = codec.serialize(root);

    cout << "Serialized Tree: " << serialized << endl;

    // Deserialize the string
    TreeNode* newRoot = codec.deserialize(serialized);

    // Print the reconstructed tree
    cout << "Reconstructed Tree: ";

    printPreorder(newRoot);

    cout << endl;

    return 0;
}
