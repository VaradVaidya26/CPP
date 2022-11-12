#include <iostream>

using namespace std;

class Node {
    public:
        int data;
    Node * next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertLast(Node ** head, int data) {
    Node * newNode = new Node(data);

    // if this the first node being entered
    if ( * head == NULL) {
        * head = newNode;
        ( * head) -> next = * head;
        return;
    }
    // add element just after the head node
    // swap data values of new_node and head node
    newNode -> next = ( * head) -> next;
    ( * head) -> next = newNode;

    int temp = ( * head) -> data;
    ( * head) -> data = newNode -> data;
    newNode -> data = temp;

    * head = newNode;
}

void display(Node * head) {
    cout << endl;
    if (head == NULL)
        return;

    Node * temp = head;
    //need to take care of circular structure of LL
    do {
        cout << temp -> data << " ";
        temp = temp -> next;

    } while (temp != head);
    cout << endl;
}

int main() {
    Node * head = NULL;

    insertLast( & head, 12);
    insertLast( & head, 16);
    insertLast( & head, 20);
    insertLast( & head, 24);
    insertLast( & head, 30);
    insertLast( & head, 22);

    display(head);

    return 0;
}