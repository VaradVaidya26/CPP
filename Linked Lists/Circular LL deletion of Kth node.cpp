C++(Via Double Pointer addressing to another function)
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

void deleteHead(Node ** head) {
    if ( * head == NULL)
        return;
    if (( * head) -> next == ( * head)) {
        * head = NULL;
        return;
    }
    ( * head) -> data = ( * head) -> next -> data;
    Node * temp = ( * head) -> next;
    ( * head) -> next = ( * head) -> next -> next;
    delete temp;
}

void deleteNode(Node ** head, int k) {
    // When LL is empty
    if ( * head == NULL) {
        cout << "LL empty, nothing to delete" << endl;
        return;
    }
    // if head node is to be deleted
    if (k == 1) {
        deleteHead(head);
        return;
    }
    Node * curr = * head;
    // k - 2 because :
    // Need to stop at previous node, to the node that needs to be deleted
    // Since loops runs from 0 and if we need to delete first node we say k = 1
    for (int i = 0; i < k - 2; i++)
        curr = curr -> next;

    Node * temp = curr -> next;
    curr -> next = curr -> next -> next;
    delete temp;
}

void insert(Node ** head, int data) {
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
}

void display(Node * head) {
    if (head == NULL) {
        cout << "The LL is empty" << endl;
        return;
    }

    Node * temp = head;
    //need to take care of circular structure of LL
    do {
        cout << temp -> data << " ";
        temp = temp -> next;

    } while (temp != head);
    cout << "\n" << endl;
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

    //3rd node
    deleteNode( & head, 3);
    display(head);

    //last node
    deleteNode( & head, 5);
    display(head);

    //first node
    deleteNode( & head, 1);
    display(head);

    //second node
    deleteNode( & head, 2);
    display(head);

    //first node
    deleteNode( & head, 1);
    display(head);

    //first node
    deleteNode( & head, 1);
    display(head);
    display(head);

    return 0;
}
C++(Via Single pointer value passing to another function)
    
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

Node * deleteHead(Node * head) {
    if (head == NULL)
        return head;
    if (head -> next == head) {
        head = NULL;
        return head;
    }
    head -> data = head -> next -> data;
    Node * temp = head -> next;
    head -> next = head -> next -> next;
    delete temp;
    return head;
}

void deleteNode(Node ** head, int k) {
    // When LL is empty
    if ( * head == NULL) {
        cout << "LL empty, nothing to delete" << endl;
        return;
    }
    // if head node is to be deleted
    if (k == 1) {
        * head = deleteHead( * head);
        return;
    }
    Node * curr = * head;
    for (int i = 0; i < k - 2; i++)
        curr = curr -> next;

    Node * temp = curr -> next;
    curr -> next = curr -> next -> next;
    delete temp;
}

void insert(Node ** head, int data) {
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
}

void display(Node * head) {
    if (head == NULL) {
        cout << "The LL is empty" << endl;
        return;
    }

    Node * temp = head;
    //need to take care of circular structure of LL
    do {
        cout << temp -> data << " ";
        temp = temp -> next;

    } while (temp != head);
    cout << "\n" << endl;
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

    //3rd node
    deleteNode( & head, 3);
    display(head);

    //last node
    deleteNode( & head, 5);
    display(head);

    //first node
    deleteNode( & head, 1);
    display(head);

    //second node
    deleteNode( & head, 2);
    display(head);

    //first node
    deleteNode( & head, 1);
    display(head);

    //first node
    deleteNode( & head, 1);
    display(head);
    display(head);

    return 0;
}