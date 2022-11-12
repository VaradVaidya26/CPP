#include <iostream>

using namespace std;

class Node {
    public:
        int data;
    Node * next;
};

void insert(Node ** head, int data) {

    Node * newNode = new Node();

    newNode -> data = data;
    newNode -> next = * head;

    //changing the new head to this freshly entered node
    * head = newNode;

}
void deletenode(Node ** head, int delVal) {
    Node * temp = new Node();
    temp = * head;
    Node * previous = new Node();

    //Case when there is only 1 node in the list
    if (temp -> next == NULL) {
        * head = NULL;
        free(temp);
        cout << "Value deleted: " << delVal << endl;
        return;
    }
    //if the head node itself needs to be deleted
    if (temp != NULL && temp -> data == delVal) {
        //Case 1 head becomes 30
        * head = temp -> next; //changing head to next in the list

        cout << "Value deleted: " << delVal << endl;
        //case 1: 22 deleted and freed
        free(temp);
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
        printf("Value not found\n");
        return;
    }

    // Case 2: (24)->next = 16 (as 20->next = 16) 
    // Case 3: (16)->next = NULL (as 12->next = NULL)
    previous -> next = temp -> next;
    free(temp);

    //case 2: 20 deleted and freed
    //case 3: 12 deleted and freed
    cout << "Value, deleted: " << delVal << endl;
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
    insert( & head, 12);
    insert( & head, 16);
    insert( & head, 20);
    insert( & head, 24);
    insert( & head, 30);
    insert( & head, 22);

    /*No need for & i.e. address as we do not
    need to change head address
    */
    printf("Linked List Before Operations : ");
    display(head);

    //deleting first occurance of a value in linked list
    deletenode( & head, 22);
    deletenode( & head, 20);
    deletenode( & head, 12);

    printf("Linked List After Operations : ");

    display(head);
    return 0;
}