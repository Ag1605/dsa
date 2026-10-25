
#include <bits/stdc++.h>
using namespace std;

// Structure of a linked list node
struct ListNode {
    int val;
    ListNode* next;

    // Constructor: creates a node with a value
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // Step 1: Create a dummy node before the head.
        // This makes handling left = 1 easier.
        ListNode dummy(0);
        dummy.next = head;

        // Step 2: prev points to the node just before
        // the section that we want to reverse.
        ListNode* prev = &dummy;

        // Move prev to position left - 1.
        // Positions in this problem start from 1.
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        // Step 3: curr is the first node of the section
        // that we want to reverse.
        ListNode* curr = prev->next;

        // Step 4: Reverse the section using pointer changes.
        // Each iteration moves the next node after curr
        // to the beginning of the section.
        for (int i = 0; i < right - left; i++) {

            // Store the node immediately after curr.
            ListNode* nextnode = curr->next;

            // Remove nextnode from its current position.
            curr->next = nextnode->next;

            // Insert nextnode at the beginning of the section.
            nextnode->next = prev->next;

            // Connect prev to the newly moved node.
            prev->next = nextnode;
        }

        // Step 5: Return the actual head, not the dummy node.
        return dummy.next;
    }
};

// Print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val;

        if (temp->next != nullptr) {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

int main() {

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    // Reverse nodes from position 2 to position 4
    int left = 2;
    int right = 4;

    Solution obj;
    head = obj.reverseBetween(head, left, right);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
