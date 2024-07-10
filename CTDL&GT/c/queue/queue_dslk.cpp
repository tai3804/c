#include <stdio.h>
#define MAXQUEUE 1000

struct Node
{
	int data;
	Node *Next;
};
struct Queue
{
	Node *front, *rear;
};


void Init(Queue &q)
{
	q.front = q.rear = NULL; 
}

int  isEmpty(Queue &q)
{ 
	return q.front == NULL ? 1 : -1;
}

void EnQueue (Queue &q, Node *new_ele)
{
	if(q.front == NULL)
	{
		q.front = new_ele;
		q.rear = new_ele;
	}	
	else
	{
		q.rear->Next = new_ele;
		q.rear = new_ele;
	}
}

Node *getNode(int x){
	Node *p = new Node;
	if (p==NULL)  { 
		printf("Khong du bo nho"); 
		return NULL; 
	}
	p->data = x;
	p->Next= NULL;	
	return p;
}

int EnQueueX (Queue &q, int x)
{
	Node *p = getNode(x);
	EnQueue(q,p);
	return 1;
}

int DeQueue(Queue &q)
{	
	if (!isEmpty(q))
	{
		Node *p = q.front;
		int x = p->data;
		q.front = p->Next;
		delete p;
		
		return x;
	}
	
	return 0;
}


int main(){
	return 0;
}
