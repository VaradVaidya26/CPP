#include <bits/stdc++.h>
using namespace std;
 
// A structure to represent a queue
class Queue {
public:
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
Queue* createQueue(unsigned capacity)
{
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    queue->rear = capacity - 1;
    queue->array = new int[queue->capacity];
    return queue;
}


bool isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}
 
bool isEmpty(Queue* queue)
{
    return (queue->size == 0);
}
 
void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    cout << item << " is enqueued to Queue\n";
}
 
int dequeue(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
int front(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 
int rear(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}
 
// Driver code
int main()
{
    Queue* queue = createQueue(5);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    cout << "\n" << dequeue(queue)
         << " dequeued from Queue\n"<< endl;
 
    cout << "Front: "
         << front(queue) << endl;
    cout << "Rear: "
         << rear(queue) << endl;
 
    return 0;
}