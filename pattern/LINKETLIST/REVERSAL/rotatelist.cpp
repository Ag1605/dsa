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
        next = nullptr;
    }
};

class Solution
{
public:
    // Function to rotate the linked list by k positions
    ListNode *rotateRight(ListNode *head, int k)
    {

        // If list is empty, has one node, or k is 0
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // ---------------- Find Length ----------------
        int length = 1;
        ListNode *tail = head;

        while (tail->next != nullptr)
        {
            tail = tail->next;
            length++;
        }

        // If k is greater than length, reduce it
        k = k % length;

        if (k == 0)
            return head;

        // ---------------- Make Circular List ----------------
        tail->next = head;

        // ---------------- Find New Tail ----------------
        ListNode *newTail = head;

        // Move to (length-k)th node
        for (int i = 1; i < length - k; i++)
        {
            newTail = newTail->next;
        }

        // New head is next of newTail
        ListNode *newHead = newTail->next;

        // Break the circle
        newTail->next = nullptr;

        return newHead;
    }
};

// Insert node at end
void pushBack(ListNode *&head, int x)
{

    ListNode *newNode = new ListNode(x);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    ListNode *temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Print linked list
void print(ListNode *head)
{

    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{

    Solution obj;

    int n;
    cin >> n;

    ListNode *head = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pushBack(head, x);
    }

    int k;
    cin >> k;

    cout << "Original List: ";
    print(head);

    head = obj.rotateRight(head, k);

    cout << "Rotated List: ";
    print(head);

    return 0;
}