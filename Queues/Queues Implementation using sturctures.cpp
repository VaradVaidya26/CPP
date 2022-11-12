#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

// creating a structure to hold the queue 
struct myQueue 
{ 
    int front, rear;
    unsigned size; 
    //here we have created a pointer which will point to memory of array
    //created later in createQueue function 
    int* array; 
}; 

// initialise the queue 
struct myQueue* createQueue(unsigned size) 
{ 
    struct myQueue* queue = (struct myQueue*) malloc(sizeof(struct myQueue)); 
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    
    //Memory is created for the array
    queue->array = (int*) malloc(queue->size * sizeof(int)); 
    return queue; 
} 

// Will return true if queue size has reached capacity 
int isFull(struct myQueue* queue)
{
    if(queue->rear == queue->size -1)
        printf("Overflow condition\n");
        
    return (queue->rear == queue->size -1);
} 

// Will return true if the queue is empty
int isEmpty(struct myQueue* queue) 
{
    if(queue->front == -1)
        printf("Underflow Condition\n");
        
    return (queue->front == -1); 
} 

// function to Enqueue in the queue and change relevant values 
void enqueue(struct myQueue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
        
    if(queue->front == -1)
        queue->front = 0;
    
    queue->rear++;
    queue->array[queue->rear] = item;
    printf("%d added to the queue\n", item); 
} 

// Function is deuque from queue and change relevant values
void dequeue(struct myQueue* queue) 
{ 
    if (isEmpty(queue)) 
        return;
        
    int item = queue->array[queue->front]; 
    queue->front++;
    
    //resetting the queue when last item is Dequeued 
    if(queue->front > queue->rear)
	   queue->front = queue->rear = -1;

    printf("%d dequeued from queue\n", item);
}

//function to display the queue
void display(struct myQueue* queue)
{
    if(queue->rear == -1)
        printf("\nQueue was Empty!!!");
   else{
        int i;
        printf("\nQueue :\n");
      
        for(i=queue->front; i<=queue->rear; i++)
	        printf("%d ",queue->array[i]);
   }
}

// Main function
int main() 
{ 
    struct myQueue* queue = createQueue(5); 

    enqueue(queue, 10);
    enqueue(queue, 20); 
    enqueue(queue, 30); 
    enqueue(queue, 40);

    dequeue(queue);
    dequeue(queue);

    
    display(queue);

    return 0; 
}