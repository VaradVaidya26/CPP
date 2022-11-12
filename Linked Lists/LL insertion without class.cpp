#include <iostream>

using namespace std;

class Node {
    public:
        int data;
    Node * next;
};

int calcSize(Node * node) {
    int size = 0;

    while (node != NULL) {
        node = node -> next;
        size++;
    }
    return size;
}

void insertStart(Node ** head, int data) {

    Node * newNode = new Node();

    newNode -> data = data;
    newNode -> next = * head;

    //changing the new head to this freshly entered node
    * head = newNode;

}

void insertLast(Node ** head, int data) {

    Node * newNode = new Node();

    newNode -> data = data;
    newNode -> next = NULL;

    //need this if there is no node present in linked list at all
    if ( * head == NULL) {
        * head = newNode;
        return;
    }

    struct Node * temp = * head;

    while (temp -> next != NULL)
        temp = temp -> next;

    temp -> next = newNode;
}

void insertPosition(int pos, int data, Node ** head) {
    int size = calcSize( * head);

    //If pos is 1 then should use insertStart method
    //If pos is less than or equal to 0 then can't enter at all
    //If pos is greater than size then bufferbound issue
    if (pos < 1 || size < pos) {
        printf("Can't insert, %d is not a valid position\n", pos);

    } else {
        Node * temp = * head;
        Node * newNode = new Node();

        newNode -> data = data;
        newNode -> next = NULL;

        while (--pos) {
            temp = temp -> next;
        }
        //(25)->next = 10 as 12->next is 10 
        newNode -> next = temp -> next;
        // (12)->next = 25
        temp -> next = newNode;
        //new node added in b/w 12 and 10
    }
}

void display(Node * node) {

    //as linked list will end when Node is Null
    while (node != NULL) {
        cout << node -> data << " ";
        node = node -> next;
    }
    cout << endl;
}

int main() {

    Node * head = NULL;

    /*Need & i.e. address as we
    need to change head address only needs to traverse
    and access items temporarily
    */
    insertStart( & head, 12);
    insertStart( & head, 16);
    insertStart( & head, 20);

    insertLast( & head, 10);
    insertLast( & head, 14);
    insertLast( & head, 18);
    insertLast( & head, 11);

    //Inserts after 3rd position
    insertPosition(3, 25, & head);

    /*No need for & i.e. address as we do not
    need to change head address
    */
    display(head);
    return 0;
}