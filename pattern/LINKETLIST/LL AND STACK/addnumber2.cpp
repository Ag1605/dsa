#include <iostream>
#include <stack>
using namespace std;

// Definition of Linked List Node
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        // Two stacks to store digits of both numbers
        stack<int> s1, s2;

        // Push all digits of first number into stack
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Push all digits of second number into stack
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;

        // Head of the answer linked list
        ListNode *head = NULL;

        // Continue while either stack has digits or carry exists
        while (!s1.empty() || !s2.empty() || carry)
        {

            // Start sum with previous carry
            int sum = carry;

            // Add top digit from first stack
            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }

            // Add top digit from second stack
            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }

            // Calculate carry for next iteration
            carry = sum / 10;

            // Create node containing current digit
            ListNode *newNode = new ListNode(sum % 10);

            // Insert node at the beginning of answer list
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};

// Insert node at end
void insert(ListNode *&head, int value)
{

    if (head == NULL)
    {
        head = new ListNode(value);
        return;
    }

    ListNode *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new ListNode(value);
}

// Print linked list
void printList(ListNode *head)
{

    while (head != NULL)
    {
        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main()
{

    ListNode *l1 = NULL;
    ListNode *l2 = NULL;

    // Number = 7243
    insert(l1, 7);
    insert(l1, 2);
    insert(l1, 4);
    insert(l1, 3);

    // Number = 564
    insert(l2, 5);
    insert(l2, 6);
    insert(l2, 4);

    cout << "First Number : ";
    printList(l1);

    cout << "Second Number: ";
    printList(l2);

    Solution obj;

    ListNode *result = obj.addTwoNumbers(l1, l2);

    cout << "Result       : ";
    printList(result);

    return 0;
}