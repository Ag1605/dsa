#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {

    Node* head;
    Node* tail;
public:
    List() {
        head = NULL;
        tail = NULL;
    }

   void insertAtBeginning(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
  } 


  void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    List ll;
    ll.insertAtBeginning(10);
    ll.insertAtBeginning(20);
    ll.insertAtBeginning(30);
    ll.insertAtEnd(40);
    ll.display(); // Output: 30 20 10
   /* myList.insertAtEnd(10);
    myList.insertAtBeginning(5);
    myList.insertAtEnd(15);
    myList.display(); // Output: 5 10 15 */
    return 0;
}