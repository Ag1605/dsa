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
    ListNode *partition(ListNode *head, int x)
    {

        // Dummy node for values less than x
        ListNode smallDummy(0);

        // Dummy node for values greater than or equal to x
        ListNode largeDummy(0);

        // Tail pointer of smaller list
        ListNode *small = &smallDummy;

        // Tail pointer of larger list
        ListNode *large = &largeDummy;

        // Traverse original linked list
        while (head != nullptr)
        {

            // Current node belongs to small list
            if (head->val < x)
            {

                small->next = head;
                small = small->next;
            }

            // Current node belongs to large list
            else
            {

                large->next = head;
                large = large->next;
            }

            // Move to next node
            head = head->next;
        }

        // End the large list
        large->next = nullptr;

        // Connect both lists
        small->next = largeDummy.next;

        // Return head of new list
        return smallDummy.next;
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

    int n;
    cin >> n;

    ListNode *head = nullptr;

    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;

        pushBack(head, x);
    }

    int pivot;
    cin >> pivot;

    cout << "Original List : ";
    print(head);

    Solution obj;

    head = obj.partition(head, pivot);

    cout << "Partitioned List : ";
    print(head);

    return 0;
}