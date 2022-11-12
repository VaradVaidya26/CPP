#include <bits/stdc++.h>
using namespace std;

// Basic class for queue
class Queue 
{
    private: 
        int front, rear, currSize; 
        unsigned maxCapacity; 
        int* a;
    public:
    
    Queue(int size){
        maxCapacity = size;
        front = -1;
        currSize = 0;
        rear = -1;
        a = new int [maxCapacity];
    }
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    bool isFull();
    void display();

}; 

// Will return true if queue Current size has reached maxCapacity 
bool Queue::isFull() 
{
    if ((front == rear + 1) || 
    (front == 0 && rear == maxCapacity - 1)){
        return true;
    }
    return false; 
} 

// Will return true if queue Current size is 0
bool Queue::isEmpty() 
{  
    if (front == -1) 
    {
        return true;
    }
  return false;
} 

// Here we add new item to queue and change rear and Current size  
void Queue::enqueue(int item) 
{ 
    if (isFull())
        printf("Can't add the queue is full \n");
    
    else
    {
        if (front == -1) 
            front = 0;
        
        rear = (rear + 1) % maxCapacity;
        a[rear] = item;
        printf("%d was added\n", item);
  }
} 

// Here we remove or dequeue from queue and 
//also change the front value and Current size of queue  
int Queue::dequeue() 
{ 
int item;
    if (isEmpty()) 
    {
        printf("Can't add the queue is empty \n");
        return (INT_MIN);
    }
    else
    {
        item = a[front];
        if (front == rear) 
        {
            front = rear = -1 ;
        } 
        else 
        {
            front = (front + 1) % maxCapacity;
        }
        printf("%d dequeued\n", item);
        return item;
    }
}

void Queue::display()
{
  int i;
  if (isEmpty())
    printf("Empty Queue\n");
  else {

    printf("\nQueue: ");
    for (i = front; i != rear; i = (i + 1) % maxCapacity) {
      printf("%d ", a[i]);
    }
    printf("%d \n\n", a[i]);

  }
}
// Main function to run queue program
int main() 
{ 
    Queue queue = Queue(6); 

    queue.dequeue();//Underflow condition

    queue.enqueue(12);
    queue.enqueue(14);
    queue.enqueue(16);
    queue.enqueue(18);
    queue.enqueue(20);

    queue.display();
    queue.dequeue();
    queue.dequeue();

    queue.display();

    queue.enqueue(22);
    queue.enqueue(24);
    queue.enqueue(26);
    queue.enqueue(28);//Overflow condition
    queue.display();

    return 0; 
}