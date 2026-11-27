
#include <iostream>
#include <vector>
using namespace std;

// Definition of a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    // Step 1:
    // Store all BST values in sorted order.
    void inorder(TreeNode* root, vector<int>& nums) {

        // Base case:
        // If the node is NULL, stop.
        if (root == nullptr) {
            return;
        }

        // First visit the left subtree.
        inorder(root->left, nums);

        // Store the current node's value.
        nums.push_back(root->val);

        // Finally visit the right subtree.
        inorder(root->right, nums);
    }

    // Step 2:
    // Construct a balanced BST from sorted values.
    TreeNode* buildBST(vector<int>& nums, int left, int right) {

        // If the range is empty,
        // there is no node to create.
        if (left > right) {
            return nullptr;
        }

        // Find the middle index of the range.
        int mid = left + (right - left) / 2;

        // Create the middle element as the root.
        TreeNode* root = new TreeNode(nums[mid]);

        // Build the left subtree using
        // elements before the middle.
        root->left = buildBST(nums, left, mid - 1);

        // Build the right subtree using
        // elements after the middle.
        root->right = buildBST(nums, mid + 1, right);

        // Return the root of this subtree.
        return root;
    }

    // Main function required by LeetCode.
    TreeNode* balanceBST(TreeNode* root) {

        // Vector to store sorted BST values.
        vector<int> nums;

        // Step 1:
        // Inorder traversal gives sorted values.
        inorder(root, nums);

        // Step 2:
        // Build and return a balanced BST.
        return buildBST(nums, 0, (int)nums.size() - 1);
    }
};

// Print the tree using inorder traversal.
void printInorder(TreeNode* root) {

    if (root == nullptr) {
        return;
    }

    printInorder(root->left);

    cout << root->val << " ";

    printInorder(root->right);
}

// Print the tree level by level.
void printLevelOrder(TreeNode* root) {

    if (root == nullptr) {
        return;
    }

    vector<TreeNode*> queue;
    queue.push_back(root);

    int index = 0;

    while (index < (int)queue.size()) {

        TreeNode* current = queue[index];
        index++;

        cout << current->val << " ";

        if (current->left != nullptr) {
            queue.push_back(current->left);
        }

        if (current->right != nullptr) {
            queue.push_back(current->right);
        }
    }
}

int main() {

    // Create an unbalanced BST:
    //
    //       1
    //        \
    //         2
    //          \
    //           3
    //            \
    //             4
    //              \
    //               5

    TreeNode* root = new TreeNode(1);

    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);

    Solution solution;

    // Balance the BST.
    TreeNode* balancedRoot = solution.balanceBST(root);

    cout << "Inorder of balanced BST: ";
    printInorder(balancedRoot);

    cout << "\nLevel order of balanced BST: ";
    printLevelOrder(balancedRoot);

    return 0;
}
