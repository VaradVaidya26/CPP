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

void insert(Node ** head, int data) {

    Node * newNode = new Node();

    newNode -> data = data;
    newNode -> next = * head;

    //changing the new head to this freshly entered node
    * head = newNode;

}
void deletenode(Node ** head, int pos) {
    Node * temp = * head;
    Node * previous;

    //if the head node itself needs to be deleted
    int size = calcSize( * head);

    if (pos < 1 || pos > size) {
        cout << "Enter valid position\n";

        return;
    }
    if (pos == 1) {
        //Case 1 head becomes 30
        * head = temp -> next; //changing head to next in the list
        cout << "Value deleted: " << temp -> data << endl;

        //case 1: 22 deleted and freed
        free(temp);
        return;
    }

    //run until we find the value to be deleted in the list
    while (--pos) {
        //store previous link node as we need to change its next val
        previous = temp;
        temp = temp -> next;
    }

    // Case 2: (24)->next = 16 (as 20->next = 16) 
    // Case 3: (16)->next = NULL (as 12->next = NULL)
    previous -> next = temp -> next;
    cout << "Value deleted: " << temp -> data << endl;

    free(temp);
    //case 2: 20 deleted and freed
    //case 3: 12 deleted and freed
}

void display(Node * node) {
    cout << endl;

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
    insert( & head, 12);
    insert( & head, 16);
    insert( & head, 20);
    insert( & head, 24);
    insert( & head, 30);
    insert( & head, 22);

    /*No need for & i.e. address as we do not
    need to change head address
    */
    display(head);

    //deleting first occurance of a value in linked list
    deletenode( & head, 1);
    display(head);

    deletenode( & head, 3);
    display(head);

    deletenode( & head, 4);
    display(head);

    deletenode( & head, -2);
    deletenode( & head, 10);
    return 0;
}