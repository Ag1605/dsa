#include <bits/stdc++.h>
using namespace std;

// Definition of Node
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    // Function to sort a linked list containing only 0s, 1s and 2s
    Node *segregate(Node *head)
    {

        // Count the number of 0s, 1s and 2s
        int zero = 0;
        int one = 0;
        int two = 0;

        Node *temp = head;

        // ---------------- First Traversal ----------------
        // Count frequencies
        while (temp != nullptr)
        {

            if (temp->data == 0)
                zero++;

            else if (temp->data == 1)
                one++;

            else
                two++;

            temp = temp->next;
        }

        // Again start from head
        temp = head;

        // ---------------- Second Traversal ----------------
        // Rewrite node values according to frequencies
        while (temp != nullptr)
        {

            if (zero > 0)
            {

                temp->data = 0;
                zero--;
            }

            else if (one > 0)
            {

                temp->data = 1;
                one--;
            }

            else
            {

                temp->data = 2;
                two--;
            }

            temp = temp->next;
        }

        return head;
    }
};

// Insert node at end
void pushBack(Node *&head, int x)
{

    Node *newNode = new Node(x);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Print linked list
void print(Node *head)
{

    while (head != nullptr)
    {

        cout << head->data << " ";

        head = head->next;
    }

    cout << endl;
}

int main()
{

    Solution obj;

    int n;
    cin >> n;

    Node *head = nullptr;

    // Input linked list
    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;

        pushBack(head, x);
    }

    cout << "Original List : ";
    print(head);

    head = obj.segregate(head);

    cout << "Sorted List   : ";
    print(head);

    return 0;
}