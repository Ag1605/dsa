
#include <iostream>
using namespace std;

// Definition of a Binary Tree Node.
struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    // Function to check whether two trees are identical.
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Case 1: Both nodes are NULL.
        // Both trees have ended at this position.
        // Therefore, they match.
        if (p == NULL && q == NULL) {
            return true;
        }

        // Case 2: Only one node is NULL.
        // Tree structures are different.
        if (p == NULL || q == NULL) {
            return false;
        }

        // Case 3: Both nodes exist.
        // Their values must be equal.
        if (p->val != q->val) {
            return false;
        }

        // Case 4: Check both subtrees.
        // Left subtree must match AND right subtree must match.
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    // Function to check whether subRoot exists inside root.
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // If the main tree is empty,
        // it cannot contain a non-empty subtree.
        if (root == NULL) {
            return false;
        }

        // Check whether the current tree matches subRoot.
        if (isSameTree(root, subRoot)) {
            return true;
        }

        // If not matched, search inside the left subtree
        // OR search inside the right subtree.
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

int main() {

    /*
                Main Tree

                    3
                   / \
                  4   5
                 / \
                1   2
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(4);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    /*
              Subtree

                  4
                 / \
                1   2
    */

    TreeNode* subRoot = new TreeNode(4);

    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution obj;

    bool result = obj.isSubtree(root, subRoot);

    if (result) {
        cout << "subRoot is a subtree of root." << endl;
    }
    else {
        cout << "subRoot is NOT a subtree of root." << endl;
    }

    return 0;
}
