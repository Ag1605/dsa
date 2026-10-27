#include <bits/stdc++.h>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        // Create a dummy node before the head
        // This helps us handle cases where the beginning
        // of the linked list must be removed
        ListNode dummy(0);
        dummy.next = head;

        // Maps each prefix sum to its LAST node
        unordered_map<int, ListNode*> mp;

        // Running prefix sum
        int sum = 0;

        // Start from the dummy node
        ListNode* curr = &dummy;

        // STEP 1: Store the last node for each prefix sum
        while (curr != nullptr) {

            // Add the current node's value to the prefix sum
            sum += curr->val;

            // Store or update the node for this prefix sum
            // If the sum already exists, the later node replaces
            // the earlier node in the map
            mp[sum] = curr;

            // Move to the next node
            curr = curr->next;
        }

        // STEP 2: Traverse the list again
        // Reset the prefix sum and current pointer
        sum = 0;
        curr = &dummy;

        while (curr != nullptr) {

            // Calculate the prefix sum again
            sum += curr->val;

            // Find the last node with this same prefix sum
            // Skip all nodes between curr and that last node
            curr->next = mp[sum]->next;

            // Continue from the next node that remains
            curr = curr->next;
        }

        // Return the head of the modified linked list
        return dummy.next;
    }
};

// Print the linked list
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

// Free dynamically allocated nodes
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {

    // Input linked list:
    // 1 -> 2 -> -3 -> 3 -> 1

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    cout << "Original list: ";
    printList(head);

    // Create Solution object
    Solution sol;

    // Remove consecutive sequences whose sum is zero
    head = sol.removeZeroSumSublists(head);

    cout << "Updated list: ";
    printList(head);

    // Free the remaining dynamically allocated nodes
    deleteList(head);

    return 0;
}