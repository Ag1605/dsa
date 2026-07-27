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

    int pairSum(ListNode *head)
    {

        // Find middle of linked list
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

        int ans = 0;

        // Find maximum twin sum
        while (second != nullptr)
        {

            ans = max(ans, first->val + second->val);

            first = first->next;
            second = second->next;
        }

        return ans;
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

    cout << "Linked List: ";
    print(head);

    cout << "Maximum Twin Sum = " << obj.pairSum(head);

    return 0;
}