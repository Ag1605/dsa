#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void push_back(int val)
    {

        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

// Insert at End
void insertAtEnd(Node *&head, int val)
{

    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Print Linked List
void printList(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

// Split the list into two halves
Node *splitAtMid(Node *head)
{

    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {

        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL)
        prev->next = NULL;

    return slow;
}

// Merge two sorted linked lists
Node *merge(Node *left, Node *right)
{

    List ans;

    Node *i = left;
    Node *j = right;

    while (i != NULL && j != NULL)
    {

        if (i->data <= j->data)
        {
            ans.push_back(i->data);
            i = i->next;
        }
        else
        {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while (i != NULL)
    {
        ans.push_back(i->data);
        i = i->next;
    }

    while (j != NULL)
    {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

// Merge Sort
Node *mergeSort(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *right = splitAtMid(head);
    Node *left = head;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main()
{

    Node *head = NULL;

    insertAtEnd(head, 4);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 3);
    insertAtEnd(head, 5);

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}