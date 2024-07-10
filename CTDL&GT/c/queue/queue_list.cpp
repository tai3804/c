#include <stdio.h>

#define MAX 1000

struct Queue
{ 
	int n;
	int	front, rear;
	int list[MAX];
};

void   Init(Queue &q)
{
	q.front = 0; q.rear= MAX - 1; 
	q.n = 0;
}

int isEmpty(Queue q)
{
	if (q.n == 0) 
		return 1;
	return 0;
}

int isFull(Queue q)
{	
  if (q.n == MAX) 	return 1;
  return 0;
}

int  EnQueue(Queue &q, int x){
	if (isFull(q)) return 0;
	q.rear =(q.rear + 1) % MAX;
	q.list[q.rear] = x;
	q.n++;
	return 1;	
}

int DeQueue(Queue &q)
{	
	if (!isEmpty(q)) {
		int x = q.list[q.front];
		q.front = (q.front + 1) % MAX; 
		q.n--;
		return x;
	}
	return -1;
}

int main(){
	return 0;
}
