#include <bits/stdc++.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    Node *next;
} Node;

typedef struct List{
	Node *head, *tail;
} List;

Node *getNode(int value){
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
} 

void makeEmptyList(List &l){
	l.head = NULL;
	l.tail = NULL;
}

void duyet(List l){
    while (l.head != NULL) {
    	printf("%d ", l.head->value);
        l.head = l.head->next;       
    }
}



int size(List l){
    int cnt=0;
    while (l.head != NULL) {
    	cnt++;
        l.head = l.head->next;        
    }
    return cnt;
}

void addFirst(List &l, Node *node){
	if (l.head == NULL ){
		l.head = l.tail = node;
		return;
	}
	node->next = l.head;
	l.head = node;
}

void insertFirst(List &l, int value){
	Node *newNode = getNode(value);
	Node *temp = l.head;
	while (temp != NULL){
		if (temp->value == newNode->value){
			printf("Khong the them gia tri trung lap!\n"); 
			return;
		}
		temp = temp->next;
	}
	if (newNode == NULL) return;
	
	addFirst(l, newNode);
}

void addLast(List &l, Node *node){
	if (l.head == NULL ){
		l.head = l.tail = node;
		return;
	}
	l.tail->next = node;
	l.tail = node;
}

void insertLast(List &l, int value){
	Node *newNode = getNode(value);
	Node *temp = l.head;
	while (temp != NULL){
		if (temp->value == newNode->value){
			printf("Khong the them gia tri trung lap!\n"); 
			return;
		}
		temp = temp->next;
	}
	if (newNode == NULL) return;
	
	addLast(l, newNode);
}

void insert(List &l, int value, int pos){
	Node *newNode = getNode(value);
	if (pos == 0) insertFirst(l, value);
	else if(pos >= size(l)) insertLast(l, value);
	else {
		Node *temp = l.head;
		while (--pos > 0){
			temp = temp->next;
		}	
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void createListFirst(List &l){
	int i;
	while (true){
		printf("Nhap gia tri can them vao dau (nhap -1 de thoat): "); scanf("%d", &i);
		if (i==-1) return;
		insertFirst(l, i);
	}
}

void createListLast(List &l){
	int i;
	while (true){
		printf("Nhap gia tri can them vao cuoi (nhap -1 de thoat): "); scanf("%d", &i);
		if (i==-1) return;
		insertLast(l, i);
	}
}

void xoaDau(List &l){
	if (l.head == NULL) return;
	if (l.head->next == NULL) {
		free(l.tail);
		return;
	}
	Node *temp = l.head;
	l.head = l.head->next;
	free(temp);
}

void xoaCuoi(List &l){
	if (l.head == NULL) return;
	Node *temp = l.head;
	while (temp->next != l.tail){
		temp=temp->next;
	}
	temp->next=  NULL;
	free(l.tail);
	l.tail = temp;
}

int main(){
	List l;
	createListLast(l);
	duyet(l);
	return 0;
}
