
#include <iostream>
using namespace std;

// Definition of Binary Tree Node.
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
        // Therefore, they are identical here.
        if (p == NULL && q == NULL) {
            return true;
        }

        // Case 2: Only one node is NULL.
        // The structures of the trees are different.
        if (p == NULL || q == NULL) {
            return false;
        }

        // Case 3: Compare the current node values.
        // If values are different, trees are not identical.
        if (p->val != q->val) {
            return false;
        }

        // Case 4: Recursively compare both subtrees.
        // Left of P must match left of Q.
        // Right of P must match right of Q.
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main() {

    /*
            Tree 1:          Tree 2:

                1                1
               / \              / \
              2   3            2   3
    */

    // Create first tree.
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Create second tree.
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;

    // Check whether both trees are identical.
    bool result = obj.isSameTree(p, q);

    if (result) {
        cout << "Both trees are identical." << endl;
    }
    else {
        cout << "Both trees are NOT identical." << endl;
    }

    return 0;
}
