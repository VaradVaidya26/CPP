#include <stdio.h>

#include <stdlib.h>

class Node {
    public:
        int data;
    Node * next;
    Node * prev;
};

void insertStart(Node ** head, int data) {

    Node * newNode = new Node();

    newNode -> data = data;
    newNode -> next = * head;
    newNode -> prev = NULL;

    //If the linked list already had at least 1 node
    if ( * head != NULL)
        ( * head) -> prev = newNode;
    // *head->prev = newNode; would not work it has (*head) must be used

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
        newNode -> prev = NULL;
        return;
    }

    struct Node * temp = * head;

    while (temp -> next != NULL)
        temp = temp -> next;

    temp -> next = newNode;
    newNode -> prev = temp;
}

//function to print the doubly linked list
void display(Node * node) {
    Node * end;
    printf("List in Forward direction: ");
    while (node != NULL) {
        printf(" %d ", node -> data);
        end = node;
        node = node -> next;
    }

    printf("\nList in backward direction: ");

    while (end != NULL) {
        printf(" %d ", end -> data);
        end = end -> prev;
    }
}

int main() {
    struct Node * head = NULL;

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

    /*No need for & i.e. address as we do not
    need to change head address
    */
    display(head);
    return 0;
}