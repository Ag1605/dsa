#include <bits/stdc++.h>
using namespace std;

// Definition of ListNode
class ListNode
{
public:
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
    void removeCycle(ListNode *head)
    {

        // If list is empty
        if (!head)
            return;

        ListNode *slow = head;
        ListNode *fast = head;

        // ---------------- Step 1: Detect Cycle ----------------
        while (fast && fast->next)
        {

            slow = slow->next;
            fast = fast->next->next;

            // Cycle Found
            if (slow == fast)
            {

                // ---------------- Step 2: Find Start of Cycle ----------------
                ListNode *start = head;

                while (start != slow)
                {
                    start = start->next;
                    slow = slow->next;
                }

                // ---------------- Step 3: Find Last Node of Cycle ----------------
                ListNode *temp = start;

                while (temp->next != start)
                    temp = temp->next;

                // ---------------- Step 4: Break the Cycle ----------------
                temp->next = NULL;

                return;
            }
        }
    }
};

// Print Linked List
void printList(ListNode *head)
{

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{

    /*
          1 -> 2 -> 3 -> 4 -> 5
                  ^         |
                  |_________|
    */

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create Cycle
    head->next->next->next->next->next = head->next->next;

    Solution obj;

    obj.removeCycle(head);

    cout << "Linked List After Removing Cycle:\n";

    printList(head);

    return 0;
}