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
    // Function to arrange odd indexed nodes first
    // followed by even indexed nodes
    ListNode *oddEvenList(ListNode *head)
    {

        // If list is empty or has only one node
        if (head == nullptr || head->next == nullptr)
            return head;

        // Odd pointer starts from first node
        ListNode *odd = head;

        // Even pointer starts from second node
        ListNode *even = head->next;

        // Store head of even list
        ListNode *evenHead = even;

        while (even != nullptr && even->next != nullptr)
        {

            // Connect current odd node to next odd node
            odd->next = even->next;
            odd = odd->next;

            // Connect current even node to next even node
            even->next = odd->next;
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;

        return head;
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

    head = obj.oddEvenList(head);

    cout << "Odd Even List: ";
    print(head);

    return 0;
}
