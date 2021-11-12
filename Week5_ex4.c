int Full_Queue(Queue Q){
return (Q.Rear-Q.Front+1) % 
MaxLength==0;
}

void DeQueue(Queue *Q){ 
	if (!Empty_Queue(*Q)){ 
	//if queue contain only one element 
	if (Q->Front==Q->Rear) MakeNull_Queue(Q); 
	else Q->Front=(Q->Front+1) % MaxLength; 
} 
	else printf("Queue is empty!"); 
}

	void EnQueue(ElementType X,Queue *Q){ 
	if (!Full_Queue(*Q)){
	if (Empty_Queue(*Q)) Q->Front=0;
		Q->Rear=(Q->Rear+1) % MaxLength; 
		Q->Elements[Q->Rear]=X;
} else printf("Queue is full!"); 
}

typedef ... ElementType; 
typedef struct Node{ 
	ElementType Element;
	Node* Next; //pointer to next element
};

typedef Node* Position; 
typedef struct{ 
	Position Front, Rear;
} Queue;

void MakeNullQueue(Queue *Q){ 
	Position Header; 
	Header=(Node*)malloc(sizeof(Node)); 
	//Allocation Header 
	Header->Next=NULL; 
	Q->Front=Header; 
	Q->Rear=Header;
}

int EmptyQueue(Queue Q){ 
return (Q.Front==Q.Rear); 
}

void EnQueue(ElementType X, Queue *Q){ 
	Q->Rear->Next=
	(Node*)malloc(sizeof(Node));
	Q->Rear=Q->Rear->Next; 
	Q->Rear->Element=X; 
	Q->Rear->Next=NULL;
}

void DeQueue(Queue *Q){ 
	if (!Empty_Queue(Q)){ 
	Position T; 
	T=Q->Front; 
	Q->Front=Q->Front->Next; 
	free(T); 
} 
	else printf(”Error: Queue is empty.”); 
}