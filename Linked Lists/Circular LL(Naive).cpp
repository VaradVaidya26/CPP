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

void insert(Node ** head, int data) {
    Node * newNode = new Node(data);

    if ( * head == NULL) {
        * head = newNode;
        ( * head) -> next = * head;
        return;
    }
    Node * curr = * head;
    // traverse till last node in LL
    while (curr -> next != * head) {
        curr = curr -> next;
    }
    curr -> next = newNode;
    newNode -> next = * head;
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

    insert( & head, 12);
    insert( & head, 16);
    insert( & head, 20);
    insert( & head, 24);
    insert( & head, 30);
    insert( & head, 22);

    display(head);

    return 0;
}