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
    // Remove all duplicate values
    ListNode *deleteDuplicates(ListNode *head)
    {

        // Dummy node handles deletion at the head
        ListNode dummy(0);
        dummy.next = head;

        // prev points to the last confirmed unique node
        ListNode *prev = &dummy;

        // curr traverses the list
        ListNode *curr = head;

        while (curr != nullptr)
        {

            // Duplicate sequence found
            if (curr->next != nullptr &&
                curr->val == curr->next->val)
            {

                // Store duplicate value
                int value = curr->val;

                // Skip every node having this value
                while (curr != nullptr &&
                       curr->val == value)
                {

                    curr = curr->next;
                }

                // Connect previous unique node
                // to next different value
                prev->next = curr;
            }
            else
            {

                // Current node is unique
                prev = curr;
                curr = curr->next;
            }
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

    cout << "Original List : ";
    print(head);

    head = obj.deleteDuplicates(head);

    cout << "After Removing All Duplicates : ";
    print(head);

    return 0;
}