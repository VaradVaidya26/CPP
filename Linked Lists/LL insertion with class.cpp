#include <iostream>

using namespace std;

class Node {
    public:
        int data;
    Node * next;
};

class LinkedList {
    private:
        Node * head;
    public:
        LinkedList() { // constructor
            head = NULL;
        }
    int calcSize();
    void insertStart(int data);
    void insertLast(int data);
    void insertPosition(int pos, int data);
    void display();
};

int LinkedList::calcSize() {

    Node * node = new Node();
    node = head;

    int size = 0;

    while (node != NULL) {
        node = node -> next;
        size++;
    }
    return size;
}

void LinkedList::insertStart(int data) {

    Node * newNode = new Node();

    newNode -> data = data;
    newNode -> next = head;

    //changing the new head to this freshly entered node
    head = newNode;

}

void LinkedList::insertLast(int data) {

    Node * newNode = new Node();

    newNode -> data = data;
    newNode -> next = NULL;

    //need this if there is no node present in linked list at all
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node * temp = head;

    while (temp -> next != NULL)
        temp = temp -> next;

    temp -> next = newNode;
}

void LinkedList::insertPosition(int pos, int data) {
    int size = calcSize();

    //If pos is 1 then should use insertStart method
    //If pos is less than or equal to 0 then can't enter at all
    //If pos is greater than size then bufferbound issue
    if (pos < 1 || size < pos) {
        printf("Can't insert, %d is not a valid position\n", pos);

    } else {
        Node * temp = head;
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

void LinkedList::display() {

    Node * node = new Node();
    node = head;

    //as linked list will end when Node is Null
    while (node != NULL) {
        cout << node -> data << " ";
        node = node -> next;
    }
    cout << endl;
}

int main() {

    LinkedList * list = new LinkedList();

    /*Need & i.e. address as we
    need to change head address only needs to traverse
    and access items temporarily
    */
    list -> insertStart(12);
    list -> insertStart(16);
    list -> insertStart(20);

    list -> insertLast(10);
    list -> insertLast(14);
    list -> insertLast(18);
    list -> insertLast(11);

    //Inserts after 3rd position
    list -> insertPosition(3, 25);

    /*No need for & i.e. address as we do not
    need to change head address
    */
    list -> display();
    return 0;
}