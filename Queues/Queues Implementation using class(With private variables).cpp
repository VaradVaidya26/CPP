#include <bits/stdc++.h>
using namespace std;

// Basic struct for queue
class Queue 
{
    private: 
        int front, rear, currSize; 
        unsigned maxCapacity; 
        int* array;
    public:
    
    Queue(int size){
        maxCapacity = size;
        front = 0;
        currSize = 0;
        rear = maxCapacity - 1;
        array = new int [maxCapacity];
    }
    void enqueue(int x);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void display();

}; 

// Will return true if queue Current size has reached maxCapacity 
bool Queue::isFull() 
{
    if(currSize == maxCapacity)
        cout << "Can't insert as queue is full\n";
        
    return (currSize == maxCapacity);  
} 

// Will return true if queue Current size is 0
bool Queue::isEmpty() 
{  
    if(currSize == 0)
        cout << "Can't deque as queue is empty\n";
    return (currSize == 0); 
} 

// Here we add new item to queue and change rear and Current size  
void Queue::enqueue(int item) 
{ 
    if (isFull()) 
        return; 

    //Bcz, rear is set up to maxCapacity adding + 1 
    //and % maxCapacity will set rear to start of queue
    //enqueue happens at the rear value always so to maintain First in first out 
    rear = (rear + 1)%maxCapacity; 
    array[rear] = item; 
    currSize = currSize + 1; 
    cout << item << " added to the queue at array pos:" << rear << endl; 
} 

// Here we remove or dequeue from queue and 
//also change the front value and Current size of queue  
void Queue::dequeue() 
{ 
    if (isEmpty())
        return; 
    int item = array[front]; 
    front = (front + 1)%maxCapacity; 
    currSize = currSize - 1;
    cout << item << " dequeued from queue, new front is at pos:" << front << endl;
}

void Queue::display()
{
    if(currSize == 0)
        cout << "\nQueue was Empty!!!";
   else{
        int i,j;
        cout <<"\nQueue :\n";
      
        for(i=front,j=0; j<currSize; j++)
	        cout << array[(i+j) % maxCapacity] << " ";
   }
}
// Main function to run queue program
int main() 
{ 
    Queue queue = Queue(5); 

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
   
    cout << endl;
   
    queue.dequeue();
    queue.dequeue();
    
    cout << endl;

    queue.enqueue(50);
    queue.enqueue(60);
    
    queue.display();

    return 0; 
}