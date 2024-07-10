#include <bits/stdc++.h>

typedef struct Node
{
	int data;
	Node *next;
	Node *prev;
} Node;

typedef struct List
{
	Node *head;
	Node *tail;
} List;

void makeEmptyList(List &l){
	l.head = l.tail = NULL;
}

void printList(List l){
	while(l.head != NULL){
		printf("%d ", l.head->data);
		l.head = l.head->next;
	}
}

int size(List l){
	int cnt = 0;
	while(l.head != NULL){
		l.head = l.head->next;
		cnt++;
	}
	return cnt;
}

Node *getNode(int data){
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = node->prev = NULL;
}

void insertFirst(List &l, Node *node){
	if (l.head == NULL){
		l.head = l.tail = node;
		return;
	}
	node->next = l.head;
	l.head->prev = node;
	l.head = node;
}

void insertLast(List &l, Node *node){
	if (l.head == NULL){
		l.head = l.tail = node;
		return;
	}
	l.tail->next = node;
	node->prev = l.tail;
	l.tail = node;
}

void insertAfterq(List &l, Node *q,  Node *newNode){
	if (l.head == NULL){
		l.head=l.tail=newNode;
		return;
	}
	if (l.tail->data == q->data){
		insertLast(l, newNode);
		return;
	}
	Node *temp = l.head;
	while (temp->data != q->data){
		if (temp->data == l.tail->data){
			printf("khong the tim thay q trong list!\n");
			return;
		} 
		temp=temp->next;
	}
	temp->next->prev = newNode;
	newNode->next = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
}

void insertBeforeq(List &l, Node *q,  Node *newNode){
	if (l.head == NULL){
		l.head=l.tail=newNode;
		return;
	}
	if (l.head->data == q->data){
		insertFirst(l, newNode);
		return;
	}
	Node *temp = l.head;
	while (temp->data != q->data){
		if (temp->data == l.tail->data){
			printf("khong the tim thay q trong list!\n");
			return;
		} 
		temp=temp->next;
	}
	temp->prev->next = newNode;
	newNode->prev = temp->prev;
	newNode->next = temp;
	temp->prev = newNode;
}

void delFirst(List &l){
	if (l.head == NULL) return;
	if (l.head->next == NULL){
		free(l.head);
		l.head = l.tail = NULL;
		return;
	}
	Node *temp = l.head;
	temp = temp->next;
	temp->prev = NULL;
	free(l.head);
	l.head = temp;
}

void delLast(List &l){
	if (l.head == NULL) return;
	if (l.head->next == NULL){
		free(l.head);
		l.head = l.tail = NULL;
		return;
	}
	Node *temp = l.tail->prev;
	temp->next = NULL;
	free(l.tail);
	l.tail = temp;
}

void del(List &l, int pos){
	if (l.head == NULL) return;
	if (l.head->next == NULL){
		free(l.head);
		l.head = l.tail = NULL;
		return;
	}
	
	if (pos <= 0){
		delFirst(l);
		return;
	}
	
	if(pos >= size(l)){
		delLast(l);
		return;
	}
	
	Node *temp =l.head;
	while (pos-- > 0){
		temp = temp->next;
	}
	
	Node *prevNode = temp->prev;
	Node *nextNode = temp->next;
	prevNode->next = nextNode; 
	nextNode->prev = prevNode;
	free(temp);
}

int main(){
	List l;
	makeEmptyList(l);
	for(int i=1; i<5; i++){
		Node *node = getNode(i);
		insertFirst(l, node);
	}
	
	Node *node2 = getNode(10);
	
	insertBeforeq(l, getNode(1), node2);
	printList(l);
	return 0;
}
