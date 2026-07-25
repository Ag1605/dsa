#include <bits/stdc++.h>
using namespace std;

// Definition of Linked List Node
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        // Find the length of the linked list
        int length = 0;
        ListNode *temp = head;

        while (temp)
        {
            length++;
            temp = temp->next;
        }

        // If the first node has to be removed
        if (length == n)
            return head->next;

        temp = head;

        // Move to the node before the one to be deleted
        for (int i = 1; i < length - n; i++)
            temp = temp->next;

        // Remove the nth node from the end
        temp->next = temp->next->next;

        return head;
    }
};

int main()
{

    int n;
    cin >> n;

    // Create Linked List
    ListNode *head = NULL;
    ListNode *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        ListNode *newNode = new ListNode(x);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int removePos;
    cin >> removePos;

    Solution obj;
    head = obj.removeNthFromEnd(head, removePos);

    // Print Updated List
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}