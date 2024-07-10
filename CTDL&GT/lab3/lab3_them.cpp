#include <bits/stdc++.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    Node *next;
} Node;

typedef struct List{
	Node *head;
	Node *tail;
} List;

void makeEmptyList(List &l){
	l.head = NULL;
	l.tail = NULL;
}

int size(List l){
    int cnt=0;
    while (l.head != NULL) {
    	cnt++;
        l.head = l.head->next;        
    }
    return cnt;
}

Node *getNode(int value){
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
} 

void duyet(List l){
    while (l.head != NULL) {
    	printf("%d ", l.head->value);
        l.head = l.head->next;       
    }
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

void createListLast(List &l){
	int i;
	while (true){
		printf("Nhap gia tri can them vao cuoi (nhap -1 de thoat): "); scanf("%d", &i);
		if (i==-1) return;
		insertLast(l, i);
	}
}

void sort (List &l){
	for (Node *i = l.head; i!=NULL; i=i->next){
		for (Node *j = i->next; j != NULL; j=j->next){
			if (i->value > j->value){
				int temp = i->value;
				i->value = j->value;
				j->value = temp;
			}
		}
	}
}

void Separating_List(List &l, List &l1, int x){
	sort(l);
	Node *temp = l.head;
	
	if (l.head == NULL) return;
	if (x > l.tail->value){
		return;
	}
	while (temp->next->value < x) {
		temp = temp->next;
	}
	while(temp->next != NULL){
		insertLast(l1, temp->next->value);
		Node *nextNode = temp->next;
		temp->next = nextNode->next;
		free(nextNode);
	}
}


int main(){
	List l, l1;
	makeEmptyList(l);
	makeEmptyList(l1);
	createListLast(l);
	
	int x;
	printf("Nhap gia tri cua x: "); scanf("%d", &x);
	
	Separating_List(l, l1, x);
	printf("l:", l.head->value);
	duyet(l);
	printf("\nl1: ");
	duyet(l1);
	return 0;
}
