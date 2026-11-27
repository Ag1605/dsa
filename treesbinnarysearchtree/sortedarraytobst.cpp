
#include <iostream>
#include <vector>
using namespace std;

// Definition of a Binary Tree Node
struct TreeNode {
    int val;

    // Pointer to the left child
    TreeNode* left;

    // Pointer to the right child
    TreeNode* right;

    // Default constructor
    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with a value
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with value and child nodes
    TreeNode(int x, TreeNode* left, TreeNode* right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public:

    // Helper function to build a balanced BST.
    //
    // nums  = sorted array
    // left  = starting index of current range
    // right = ending index of current range
    TreeNode* buildBST(vector<int>& nums,
                       int left,
                       int right) {

        // BASE CASE:
        // If the current range is empty,
        // there is no node to create.
        if (left > right) {
            return nullptr;
        }

        // STEP 1:
        // Find the middle index of the current range.
        //
        // This formula avoids possible integer overflow
        // compared to (left + right) / 2.
        int mid = left + (right - left) / 2;

        // STEP 2:
        // Create a new node using the middle element.
        //
        // Since the array is sorted,
        // the middle element is a suitable root.
        TreeNode* root = new TreeNode(nums[mid]);

        // STEP 3:
        // Build the left subtree.
        //
        // All elements before mid are smaller
        // than nums[mid], so they belong to the left.
        root->left = buildBST(nums, left, mid - 1);

        // STEP 4:
        // Build the right subtree.
        //
        // All elements after mid are greater
        // than nums[mid], so they belong to the right.
        root->right = buildBST(nums, mid + 1, right);

        // STEP 5:
        // Return the root of the current subtree.
        return root;
    }

    // Main function to convert sorted array into BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        // Handle an empty array.
        if (nums.empty()) {
            return nullptr;
        }

        // Start with the complete array.
        int left = 0;
        int right = nums.size() - 1;

        // Build and return the balanced BST.
        return buildBST(nums, left, right);
    }
};

// Function to print the tree using inorder traversal.
// Inorder traversal of a BST prints sorted values.
void inorder(TreeNode* root) {

    // Stop if the current node is NULL.
    if (root == nullptr) {
        return;
    }

    // Visit left subtree.
    inorder(root->left);

    // Print current node.
    cout << root->val << " ";

    // Visit right subtree.
    inorder(root->right);
}

// Function to print the tree level by level
// using a simple recursive approach.
void printTree(TreeNode* root, int level) {

    // If node is NULL, stop.
    if (root == nullptr) {
        return;
    }

    // Print the current node with indentation.
    for (int i = 0; i < level; i++) {
        cout << "    ";
    }

    cout << root->val << endl;

    // Print the left subtree.
    printTree(root->left, level + 1);

    // Print the right subtree.
    printTree(root->right, level + 1);
}

int main() {

    // Sorted array in ascending order.
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution solution;

    // Convert the sorted array into a balanced BST.
    TreeNode* root = solution.sortedArrayToBST(nums);

    // Print the BST structure.
    cout << "Balanced BST:" << endl;

    printTree(root, 0);

    // Print inorder traversal.
    // It should match the original sorted array.
    cout << endl;
    cout << "Inorder Traversal: ";

    inorder(root);

    cout << endl;

    return 0;
}
