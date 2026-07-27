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
    // Function to swap every two adjacent nodes
    ListNode *swapPairs(ListNode *head)
    {

        // Dummy node before head
        ListNode dummy(0);
        dummy.next = head;

        // prev always points to the node before the pair
        ListNode *prev = &dummy;

        while (prev->next != nullptr && prev->next->next != nullptr)
        {

            // First node of the pair
            ListNode *first = prev->next;

            // Second node of the pair
            ListNode *second = first->next;

            // Node after the pair
            ListNode *temp = second->next;

            // Swap the two nodes
            second->next = first;
            prev->next = second;
            first->next = temp;

            // Move prev to the end of the swapped pair
            prev = first;
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

    cout << "Original List: ";
    print(head);

    head = obj.swapPairs(head);

    cout << "After Swapping: ";
    print(head);

    return 0;
}