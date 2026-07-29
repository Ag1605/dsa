#include <iostream>
using namespace std;

// Definition of Linked List Node
struct ListNode
{
    int val;
    ListNode *next;

    // Constructor
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

// Solution class
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        // Dummy node is a temporary starting node.
        // It makes it easy to build the answer list.
        ListNode dummy(0);

        // tail always points to the last node of answer list.
        ListNode *tail = &dummy;

        // Initially there is no carry.
        int carry = 0;

        // Continue while:
        // 1. l1 has nodes
        // 2. OR l2 has nodes
        // 3. OR carry is still remaining
        while (l1 != NULL || l2 != NULL || carry != 0)
        {

            // Start sum with previous carry.
            int sum = carry;

            // Add value from first list if available.
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next; // Move to next node
            }

            // Add value from second list if available.
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next; // Move to next node
            }

            // Calculate new carry.
            carry = sum / 10;

            // Create new node containing current digit.
            tail->next = new ListNode(sum % 10);

            // Move tail to newly created node.
            tail = tail->next;
        }

        // Return actual answer.
        // dummy itself is not part of answer.
        return dummy.next;
    }
};

// Function to insert node at end
void insert(ListNode *&head, int value)
{

    // If list is empty
    if (head == NULL)
    {
        head = new ListNode(value);
        return;
    }

    ListNode *temp = head;

    // Reach last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Add new node
    temp->next = new ListNode(value);
}

// Function to print linked list
void printList(ListNode *head)
{

    while (head != NULL)
    {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main()
{

    ListNode *l1 = NULL;
    ListNode *l2 = NULL;

    // Number 342
    // Stored as 2 -> 4 -> 3
    insert(l1, 2);
    insert(l1, 4);
    insert(l1, 3);

    // Number 465
    // Stored as 5 -> 6 -> 4
    insert(l2, 5);
    insert(l2, 6);
    insert(l2, 4);

    cout << "First Number : ";
    printList(l1);

    cout << "Second Number: ";
    printList(l2);

    Solution obj;

    ListNode *result = obj.addTwoNumbers(l1, l2);

    cout << "Result       : ";
    printList(result);

    return 0;
}