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
    // Function to remove duplicate nodes
    ListNode *deleteDuplicates(ListNode *head)
    {

        // Pointer to traverse the list
        ListNode *temp = head;

        // Traverse until last node
        while (temp != nullptr && temp->next != nullptr)
        {

            // Duplicate found
            if (temp->val == temp->next->val)
            {

                // Skip the duplicate node
                temp->next = temp->next->next;
            }
            else
            {

                // Move to next node
                temp = temp->next;
            }
        }

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

    cout << "Original List : ";
    print(head);

    head = obj.deleteDuplicates(head);

    cout << "After Removing Duplicates : ";
    print(head);

    return 0;
}