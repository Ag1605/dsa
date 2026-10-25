#include <bits/stdc++.h>
using namespace std;

// Definition of a linked list node
class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* frequenciesOfElements(ListNode* head) {

        // Stores each value and its frequency
        unordered_map<int, int> freq;

        ListNode* curr = head;

        // STEP 1: Count the frequency of every value
        while (curr != nullptr) {

            // Increase the count of the current value by 1
            freq[curr->val]++;

            // Move to the next node
            curr = curr->next;
        }

        // STEP 2: Create a new linked list
        // Dummy node simplifies insertion into the new list
        ListNode dummy(0);

        // tail always points to the last node of the new list
        ListNode* tail = &dummy;

        // Visit every value-frequency pair in the map
        for (auto it = freq.begin(); it != freq.end(); it++) {

            // Create a new node containing the frequency
            tail->next = new ListNode(it->second);

            // Move tail to the newly created node
            tail = tail->next;
        }

        // Return the actual head of the new linked list
        // Do not return dummy, because it is only a helper node
        return dummy.next;
    }
};

// Function to print a linked list
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

// Function to free dynamically allocated nodes
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {

    // Input linked list:
    // 1 -> 2 -> 2 -> 1 -> 1 -> 3

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(3);

    cout << "Original list: ";
    printList(head);

    // Call the solution
    Solution sol;
    ListNode* result = sol.frequenciesOfElements(head);

    cout << "Frequency list: ";
    printList(result);

    // Free the memory used by both lists
    deleteList(head);
    deleteList(result);

    return 0;
}