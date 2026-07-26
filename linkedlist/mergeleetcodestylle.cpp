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
    // Find the middle node and split the linked list
    ListNode *splitAtMid(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Break the list into two halves
        if (prev != nullptr)
            prev->next = nullptr;

        return slow;
    }

    // Merge two sorted linked lists
    ListNode *merge(ListNode *left, ListNode *right)
    {

        ListNode dummy(-1);
        ListNode *tail = &dummy;

        while (left != nullptr && right != nullptr)
        {

            if (left->val <= right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        // Attach remaining nodes
        while (left != nullptr)
        {
            tail->next = left;
            left = left->next;
            tail = tail->next;
        }

        while (right != nullptr)
        {
            tail->next = right;
            right = right->next;
            tail = tail->next;
        }

        return dummy.next;
    }

    // Merge Sort
    ListNode *mergeSort(ListNode *head)
    {

        // Base Case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Divide
        ListNode *right = splitAtMid(head);
        ListNode *left = head;

        // Sort both halves
        left = mergeSort(left);
        right = mergeSort(right);

        // Merge
        return merge(left, right);
    }

    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
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

    head = obj.sortList(head);

    print(head);

    return 0;
}