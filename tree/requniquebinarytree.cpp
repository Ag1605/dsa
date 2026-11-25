
#include <iostream>
using namespace std;

class Solution {
public:
    bool uniqueBinaryTree(int a, int b) {

        // Case 1:
        // Preorder + Inorder
        // Preorder tells us the root first.
        // Inorder tells us the left and right subtrees.
        // Therefore, a unique binary tree can be constructed.
        if ((a == 1 && b == 2) ||
            (a == 2 && b == 1)) {
            return true;
        }

        // Case 2:
        // Inorder + Postorder
        // Postorder tells us the root last.
        // Inorder helps us divide the left and right subtrees.
        // Therefore, a unique binary tree can be constructed.
        if ((a == 2 && b == 3) ||
            (a == 3 && b == 2)) {
            return true;
        }

        // Case 3:
        // Preorder + Postorder
        // These two traversals alone cannot uniquely
        // construct every binary tree.
        return false;
    }
};

int main() {

    Solution obj;

    // Example 1:
    // Preorder (1) + Inorder (2)
    int a = 1;
    int b = 2;

    bool result = obj.uniqueBinaryTree(a, b);

    if (result == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}
