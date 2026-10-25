#include <bits/stdc++.h>
using namespace std;

// Definition of a linked list node
class ListNode {
public:
    int val;         // Stores the value of the node
    ListNode* next;  // Pointer to the next node

    // Constructor to initialize a node
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    string gameResult(ListNode* head) {

        // Count the number of points won by Even and Odd
        int even = 0;
        int odd = 0;

        // Process two nodes at a time
        // head must exist, and head->next must also exist
        while (head != nullptr && head->next != nullptr) {

            // Compare the values of the current pair
            if (head->val > head->next->val) {

                // First value is greater, so Even wins
                even++;
            }
            else if (head->val < head->next->val) {

                // Second value is greater, so Odd wins
                odd++;
            }

            // If both values are equal, nobody gets a point

            // Skip both nodes and move to the next pair
            head = head->next->next;
        }

        // Decide the winner by comparing the scores
        if (even > odd) {
            return "Even";
        }
        else if (odd > even) {
            return "Odd";
        }

        // If both scores are equal, the result is a tie
        return "Tie";
    }
};

// Main function to test the solution
int main() {

    // Create the linked list:
    // 5 -> 3 -> 2 -> 8 -> 7 -> 1

    ListNode* head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next = new ListNode(1);

    // Create a Solution object
    Solution sol;

    // Call the function and store the result
    string result = sol.gameResult(head);

    // Print the winner
    cout << result << endl;

    // Free the dynamically allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}