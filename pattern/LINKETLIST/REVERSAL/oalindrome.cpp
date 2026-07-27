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
    // Reverse a linked list
    ListNode *rev(ListNode *head)
    {

        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;

        while (curr != nullptr)
        {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode *head)
    {

        // Empty list or single node is always palindrome
        if (head == nullptr || head->next == nullptr)
            return true;

        // Find the middle node
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode *second = rev(slow);

        // First half pointer
        ListNode *first = head;

        // Compare both halves
        while (second != nullptr)
        {

            if (first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
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

    if (obj.isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}