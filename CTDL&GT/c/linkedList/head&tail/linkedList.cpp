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
	Node *temp = l.head;
    while (temp != NULL) {
    	printf("%d ", temp->value); 
        temp = temp->next;       
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

void insertFirst(List &l, int value){
	Node *newNode = getNode(value);
	if (l.head == NULL ){
		l.head = l.tail = newNode;
		return;
	}
	newNode->next = l.head;
	l.head=newNode;
}

void insertLast(List &l, int value){
	Node *newNode = getNode(value);
	if (l.head == NULL){
		l.head = l.tail = newNode;
		return;
	}
	l.tail->next = newNode;
	l.tail = newNode; 
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

void xoa_truoc_x(List l, int x){
	if (l.head == NULL){
		return;
	}
	
	if (l.head->next==NULL){
		free(l.head);
		l.head=l.tail=NULL;
		return;
	}
	
	if (x <= 2){
		xoaDau(l);
		return;
	}
	
	if (x >= size(l)){
		xoaCuoi(l);
		return;
	}
	
	Node *temp = l.head;
	while (x-- > 2){
		temp=temp->next;
	}
	Node *node = temp->next;
	temp->next=node->next;
	node->next = NULL;
	free(node);
}

void list_to_array(List l, int a[], int n){
	if (l.head == NULL){
		return;
	}
	
	int s = size(l);
	if (n < s) s=n;
	
	Node *temp = l.head;
	for (int i=0; i<s; i++){
		a[i] = temp->value;
		temp = temp->next;
	}
}

void delete_x(List &l, int x){
	while (l.head->value == x){
		Node *node = l.head;
		l.head = l.head->next;
		free(node);
	}
	
	while (l.tail->value == x){
		Node *temp = l.head;
		while (temp->next != l.tail){
			temp = temp->next;
		}
		free(l.tail);
		temp->next = NULL;
		l.tail = temp;
	}
	
	Node *temp = l.head;
	while(temp->next != NULL){
		if(temp->next->value == x){
			Node *node = temp->next;
			temp->next=node->next;
			free(node);
		}
		temp = temp->next;
	}
}

int main(){
	List l;
	int n=5;
	int a[n];
	l.head = l.tail = NULL;
	insertLast(l, 4);
	insertLast(l, 1);
	insertLast(l, 4);
	insertLast(l, 2);
	insertLast(l, 3);
	insertLast(l, 5);
	insertLast(l, 4);
	insertLast(l, 7);
	insertLast(l, 8);
	delete_x(l, 4);
	duyet(l);
	return 0;
}
