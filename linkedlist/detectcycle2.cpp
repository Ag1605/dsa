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
    ListNode *detectCycle(ListNode *head)
    {

        // Initialize slow and fast pointers
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect whether a cycle exists
        while (fast && fast->next)
        {

            // Slow moves one step
            slow = slow->next;

            // Fast moves two steps
            fast = fast->next->next;

            // Cycle detected
            if (slow == fast)
            {

                // Step 2:
                // Move one pointer to the head
                ListNode *temp = head;

                // Move both one step at a time
                while (temp != slow)
                {
                    temp = temp->next;
                    slow = slow->next;
                }

                // Starting node of the cycle
                return temp;
            }
        }

        // No cycle
        return nullptr;
    }
};

int main()
{

    /*
          1 → 2 → 3 → 4 → 5
                  ↑       |
                  |_______|
    */

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create cycle
    head->next->next->next->next->next = head->next->next;

    Solution obj;

    ListNode *ans = obj.detectCycle(head);

    if (ans)
        cout << "Cycle starts at node: " << ans->val;
    else
        cout << "No Cycle";

    return 0;
}