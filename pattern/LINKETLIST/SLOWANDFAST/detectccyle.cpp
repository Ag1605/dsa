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
    bool hasCycle(ListNode *head)
    {

        // Both pointers start from head
        ListNode *slow = head;
        ListNode *fast = head;

        // Traverse until fast reaches the end
        while (fast != NULL && fast->next != NULL)
        {

            // Slow moves one step
            slow = slow->next;

            // Fast moves two steps
            fast = fast->next->next;

            // If both meet, cycle exists
            if (slow == fast)
                return true;
        }

        // Fast reached NULL
        // No cycle exists
        return false;
    }
};

int main()
{

    /*
       Create Linked List

       1 -> 2 -> 3 -> 4 -> 5
                 ^         |
                 |_________|
    */

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create a cycle
    head->next->next->next->next->next = head->next->next;

    Solution obj;

    if (obj.hasCycle(head))
        cout << "Cycle Found";
    else
        cout << "No Cycle";

    return 0;
}