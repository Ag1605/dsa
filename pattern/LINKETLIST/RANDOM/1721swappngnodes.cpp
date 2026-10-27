#include <bits/stdc++.h>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;

    // Default constructor
    ListNode() : val(0), next(nullptr) {}

    // Constructor with value
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor with value and next pointer
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        // STEP 1: Find the kth node from the beginning
        ListNode* first = head;

        // Move first forward k - 1 times
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // STEP 2: Find the kth node from the end
        // fast starts at the kth node from the beginning
        ListNode* fast = first;

        // slow starts at the head
        ListNode* slow = head;

        // Move both pointers together until fast reaches
        // the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Now:
        // first points to the kth node from the beginning
        // slow points to the kth node from the end

        // STEP 3: Swap the values of these two nodes
        swap(first->val, slow->val);

        // Return the original head of the list
        return head;
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

// Free dynamically allocated memory
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {

    // Create the linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Position counted from the beginning
    int k = 2;

    cout << "Original list: ";
    printList(head);

    // Create Solution object
    Solution sol;

    // Swap the kth node from the beginning
    // with the kth node from the end
    head = sol.swapNodes(head, k);

    cout << "Updated list: ";
    printList(head);

    // Free memory
    deleteList(head);

    return 0;
}