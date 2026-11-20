
#include <bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:

    // STEP 1: Find Lowest Common Ancestor (LCA)
    Node* findLCA(Node* root, int a, int b)
    {
        // Base case: If tree is empty
        if (root == NULL)
        {
            return NULL;
        }

        // If current node is either a or b,
        // return the current node
        if (root->data == a || root->data == b)
        {
            return root;
        }

        // Search for node a or b in left subtree
        Node* left = findLCA(root->left, a, b);

        // Search for node a or b in right subtree
        Node* right = findLCA(root->right, a, b);

        // If both left and right return non-NULL,
        // it means a and b are present in different subtrees.
        // Therefore, current node is their LCA.
        if (left != NULL && right != NULL)
        {
            return root;
        }

        // If only left subtree has a result,
        // return that result.
        if (left != NULL)
        {
            return left;
        }

        // Otherwise, return the right subtree result.
        return right;
    }


    // STEP 2: Find distance from a given root to target node
    int findDistance(Node* root, int target, int level)
    {
        // If node does not exist
        if (root == NULL)
        {
            return -1;
        }

        // If target node is found,
        // return the current distance.
        if (root->data == target)
        {
            return level;
        }

        // Search in left subtree.
        // Moving one level down, so increase level by 1.
        int left = findDistance(root->left, target, level + 1);

        // If target is found in left subtree,
        // return its distance.
        if (left != -1)
        {
            return left;
        }

        // Otherwise, search in right subtree.
        int right = findDistance(root->right, target, level + 1);

        // Return the result from right subtree.
        return right;
    }


    // STEP 3: Main function to calculate distance between a and b
    int findDist(Node* root, int a, int b)
    {
        // First, find the Lowest Common Ancestor of a and b.
        Node* lca = findLCA(root, a, b);

        // If LCA does not exist
        if (lca == NULL)
        {
            return -1;
        }

        // Find distance from LCA to node a.
        // Start level from 0 because LCA is the starting node.
        int d1 = findDistance(lca, a, 0);

        // Find distance from LCA to node b.
        int d2 = findDistance(lca, b, 0);

        // If either node is not present in the tree
        if (d1 == -1 || d2 == -1)
        {
            return -1;
        }

        // Total distance = distance from LCA to a
        //                 + distance from LCA to b
        return d1 + d2;
    }
};


int main()
{
    // STEP 1: Create the binary tree

    //              1
    //            /   \
    //           2     3
    //          / \   / \
    //         4   5 6   7

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // STEP 2: Select two target nodes
    int a = 4;
    int b = 7;

    // STEP 3: Create Solution object
    Solution obj;

    // STEP 4: Calculate distance
    int ans = obj.findDist(root, a, b);

    // STEP 5: Print answer
    cout << "Distance between " << a << " and " << b
         << " is: " << ans << endl;

    return 0;
}
