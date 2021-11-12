void DeQueue(Queue *Q){ 
if (!Empty_Queue(Q)){ 
Position T; 
T=Q->Front; 
Q->Front=Q->Front->Next; 
free(T); 
} 
else printf(”Error: Queue is empty.”); 
}

void enq(int *rear, element item)
{
/* add an item to the queue */
if (*rear == MAX_QUEUE_SIZE_1) {
queue_full( );
return;
}
queue [++*rear] = item;
}

 element deq(int *front, int rear)
{
if ( *front == rear)
return queue_empty( ); 
/* return an error key */
return queue [++ *front];
} 

void addq(int front, int *rear, element item)
{
*rear = (*rear +1) % MAX_QUEUE_SIZE;
if (front == *rear) /* reset rear and print 
error */
return;
}
queue[*rear] = item; 
}

element deleteq(int* front, int rear)
{
element item;
if (*front == rear)
return queue_empty( ); 
/* queue_empty returns an error key */
*front = (*front+1) % MAX_QUEUE_SIZE;
return queue[*front];
}