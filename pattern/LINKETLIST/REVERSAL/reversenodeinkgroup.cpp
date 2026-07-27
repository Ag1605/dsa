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
    // Function to find the kth node from the current position
    ListNode *getKth(ListNode *curr, int k)
    {

        while (curr != nullptr && k > 0)
        {
            curr = curr->next;
            k--;
        }

        return curr;
    }

    // Reverse nodes in groups of size k
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        // Dummy node before head
        ListNode dummy(0);
        dummy.next = head;

        // Points to node before current group
        ListNode *groupPrev = &dummy;

        while (true)
        {

            // Find kth node
            ListNode *kth = getKth(groupPrev, k);

            // If fewer than k nodes remain, stop
            if (kth == nullptr)
                break;

            // First node of next group
            ListNode *nextGroup = kth->next;

            // Reverse current group
            ListNode *prev = nextGroup;
            ListNode *curr = groupPrev->next;

            while (curr != nextGroup)
            {

                ListNode *next = curr->next;

                curr->next = prev;

                prev = curr;

                curr = next;
            }

            // Connect reversed group
            ListNode *temp = groupPrev->next;

            groupPrev->next = kth;

            // Move groupPrev to end of reversed group
            groupPrev = temp;
        }

        return dummy.next;
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

    head = obj.reverseKGroup(head, k);

    cout << "After Reversing in Groups: ";
    print(head);

    return 0;
}