#include <iostream>
using namespace std;

// Definition of Linked List Node
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to reverse a linked list
    ListNode *reverse(ListNode *head)
    {

        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr)
        {

            // Store next node
            ListNode *next = curr->next;

            // Reverse current link
            curr->next = prev;

            // Move prev and curr one step forward
            prev = curr;
            curr = next;
        }

        // prev becomes new head
        return prev;
    }

    ListNode *removeNodes(ListNode *head)
    {

        // Step 1 : Reverse the list
        head = reverse(head);

        // Maximum node seen so far
        ListNode *maxNode = head;

        // Current pointer
        ListNode *curr = head;

        // Traverse reversed list
        while (curr && curr->next)
        {

            // If next node is smaller than maximum,
            // remove it
            if (curr->next->val < maxNode->val)
            {

                curr->next = curr->next->next;
            }
            else
            {

                // New maximum found
                curr = curr->next;
                maxNode = curr;
            }
        }

        // Reverse again to restore original order
        return reverse(head);
    }
};

// Insert node at end
void insert(ListNode *&head, int value)
{

    if (head == NULL)
    {
        head = new ListNode(value);
        return;
    }

    ListNode *temp = head;

    while (temp->next)
        temp = temp->next;

    temp->next = new ListNode(value);
}

// Print linked list
void printList(ListNode *head)
{

    while (head)
    {

        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main()
{

    ListNode *head = NULL;

    // Example:
    // 5 -> 2 -> 13 -> 3 -> 8
    insert(head, 5);
    insert(head, 2);
    insert(head, 13);
    insert(head, 3);
    insert(head, 8);

    cout << "Original List : ";
    printList(head);

    Solution obj;

    head = obj.removeNodes(head);

    cout << "Final List    : ";
    printList(head);

    return 0;
}