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
   void displaylength() {
        Node* temp = head;
        int length = 0;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        cout << "Length of the list: " << length << endl;
    }


 void popfront() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;  
        delete temp;
    }

    void popback() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = tail = NULL;
            return;
        }
        /*if we dont have a tail pointer,  then temp->next->next != NULL */
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
       
    }                 
    void iterativesearch(int key) {
        Node* temp = head;
        int index=0;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element " << key << " found in the list at index " << index << endl;

                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "Element " << key << " not found in the list." << endl;
    }

 void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        tail = head;  
        while (current != NULL) {
            next = current->next;  
            current->next = prev;  
            prev = current;        
            current = next;       
        }
        head = prev;  
    }
int getsize() {
        int sz = 0;
        Node* temp = head;
        while (temp != NULL) {
            sz++;
            temp = temp->next;
        }
        return sz       ;
    }

void removeNthFromEnd(int n) {
    if (head == nullptr) return;

    int size = getsize();

    // If head needs to be removed
    if (n == size) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = head;
    for (int i = 1; i < size - n; i++) {
        prev = prev->next;
    }

    Node* todel = prev->next;
    prev->next = todel->next;
    delete todel;
}


    void removeNthFromFront(int n) {
    if (head == nullptr) return;

    int size = getsize();

    // Invalid position
    if (n > size || n <= 0) return;

    // If head needs to be removed
    if (n == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = head;

    // Move to (n-1)th node
    for (int i = 1; i < n - 1; i++) {
        prev = prev->next;
    }

    Node* todel = prev->next;
    prev->next = todel->next;
    delete todel;
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
   ll.popback();
    ll.displaylength();
    ll.iterativesearch(25);
    return 0;
}