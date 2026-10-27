#include <bits/stdc++.h>
using namespace std;

// Definition of a linked list node
class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor to initialize a node
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Create a dummy node before the actual head
        // This helps us remove the first node easily
        ListNode dummy(0);
        dummy.next = head;

        // Start curr at the dummy node
        ListNode* curr = &dummy;

        // Continue while a next node exists
        while (curr->next != nullptr) {

            // Check whether the next node contains the target value
            if (curr->next->val == val) {

                // Skip the node that must be removed
                curr->next = curr->next->next;

                // Do not move curr here!
                // The new next node must also be checked
            }
            else {

                // If the next node is not the target,
                // move curr forward by one node
                curr = curr->next;
            }
        }

        // Return the updated head, not the dummy node
        return dummy.next;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr) {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

// Function to free allocated memory
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {

    // Create the linked list:
    // 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    int val = 6;

    cout << "Original list: ";
    printList(head);

    // Create the Solution object
    Solution sol;

    // Remove every node whose value equals val
    head = sol.removeElements(head, val);

    cout << "Updated list: ";
    printList(head);

    // Free the remaining nodes
    deleteList(head);

    return 0;
}