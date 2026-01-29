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
    /* first we iterate through the list to find the position then new node will point to the temp next
    then temp->next=newNode; */
    void insertAtPosition(int val, int position) {
        if (position < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 0) {
            insertAtBeginning(val);
            return;
        }
        Node* temp=head;
        for(int i=1;i<position;i++){
            if(temp==NULL){
                cout<<"Position out of bounds"<<endl;
                return;
            }
            temp=temp->next;
            Node* newNode=new Node(val);
            newNode->next=temp->next;   
            temp->next=newNode;


        }
    }












    
};
int main() {
    List ll;
    ll.insertAtBeginning(10);
    ll.insertAtBeginning(20);
    ll.insertAtBeginning(30);
    ll.insertAtEnd(40);
    ll.display(); 
    ll.insertAtPosition(25, 2);
    ll.display();
   
    return 0;
}