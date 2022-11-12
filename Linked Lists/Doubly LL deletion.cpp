#include <iostream>

using namespace std;

class Node {
    public:
        int data;
    Node * next;
    Node * prev;
};

void insert(Node ** head, int data) {

    Node * newNode = new Node();

    newNode -> data = data;
    newNode -> next = * head;
    newNode -> prev = NULL;

    //If the linked list already had atleast 1 node
    if ( * head != NULL)
        ( * head) -> prev = newNode;
    // *head->prev = newNode; would not work it has (*head) must be used

    //changing the new head to this freshly entered node
    * head = newNode;
}

void deletenode(Node ** head, int delVal) {
    Node * temp = * head;
    Node * previous = new Node();

    //Case when there is only 1 node in the list

    if (temp -> next == NULL) {
        * head = NULL;
        free(temp);
        cout << "Value deleted: " << delVal << "\n" << endl;
        return;

    }
    //if the head node itself needs to be deleted
    if (temp != NULL && temp -> data == delVal) {
        //Case 1 head becomes 30
        * head = temp -> next; //changing head to next in the list
        ( * head) -> prev = NULL; //assing new head's previous value to NULL

        //case 1: 22 deleted and freed
        free(temp);
        cout << "Value deleted: " << delVal << "\n" << endl;

        return;
    }

    //run until we find the value to be deleted in the list
    while (temp != NULL && temp -> data != delVal) {
        //store previous link node as we need to change its next val
        previous = temp;
        temp = temp -> next;
    }

    //if value is not present then
    //temp will have traversed to last node NULL
    if (temp == NULL) {
        cout << "Value not found" << endl;
        return;
    }

    // Case 2: (24)->next = 16 (as 20->next = 16) 
    // Case 3: (16)->next = NULL (as 12->next = NULL)
    previous -> next = temp -> next;

    //If the last node is to be deleted
    if (temp -> next == NULL) {
        // Case 3: Just need to free the memory 
        cout << "Value deleted: " << delVal << "\n" << endl;
        free(temp);
        return;
    }

    Node * temp2 = new Node();

    // Case 2 : temp2 = 20->next = 16
    temp2 = temp -> next;
    temp2 -> prev = previous;

    free(temp);
    //case 2: 20 deleted and freed
    cout << "Value deleted: " << delVal << "\n" << endl;
}

//function to print the doubly linked list

//function to print the doubly linked list
void display(Node * node) {
    struct Node * end;
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
    cout << endl;
}

int main() {
    Node * head = NULL;

    /*Need & i.e. address as we
    need to change head address only needs to traverse
    and access items temporarily*/

    insert( & head, 12);
    insert( & head, 16);
    insert( & head, 20);
    insert( & head, 24);
    insert( & head, 30);
    insert( & head, 22);

    /*No need for & i.e. address as we do not
    need to change head address*/
    display(head);

    //deleting first occurance of a value in linked list
    deletenode( & head, 22);
    display(head);

    deletenode( & head, 20);
    display(head);

    deletenode( & head, 12);
    display(head);

    deletenode( & head, 30);
    display(head);

    deletenode( & head, 16);
    display(head);

    deletenode( & head, 24);
    display(head);

    return 0;
}