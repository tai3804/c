#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* cau truc file (moi hang 1 so)
* 1
* 3
* 98
*	100
 * -9999
*/
struct Node	{
	int data;
	Node *next;
};

struct List {
	Node *head;
	Node *tail;
};

void init(List &l);
void writeData(char fn[]);
void readData(char fn[], List &l);
void printList(List l);
Node *getNode(int data);
void addLast(List l);
int linearSearch(List l, int key);
void swap(Node *a, Node *b);
void interchangeSort(List &l);
void bubbleSort(List &l);
void selectionSort(List &l);

int main(){
	List l;
	init(l);
	char fn[20] = "linked.txt";
	readData(fn, l);
	selectionSort(l);
	printList(l);
	return 0;
}

int linearSearch(List l, int key){
	for (Node *p=l.head; p!=NULL; p=p->next){
		if (p->data == key){
			return key;
		}
	}
	return -1;
}

void swap(Node *a, Node *b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void interchangeSort(List &l){
	for (Node *p=l.head; p->next!=NULL; p=p->next){
		for(Node *q=p->next; q!=NULL; q=q->next){
			if (p->data > q->data) 
				swap(p, q);
		}
	}
}

void bubbleSort(List &l){
	for(Node *p=l.head; p!=NULL; p=p->next){
		for (Node *q=l.head; q->next!=NULL; q=q->next){
			if (q->data > q->next->data) 
				swap(q, q->next);
		}
	}
}

void selectionSort(List &l){
	for (Node *p=l.head; p->next!=NULL; p=p->next){
		Node *min = p;
		for (Node *q=p->next; q!=NULL; q=q->next){
			if (min->data > q->data) min=q;
		}
		if(p!=min) swap(min, p);
	}
}


void init(List &l){
	l.head = l.tail = NULL;
}

Node *getNode(int data){
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	
	return node;
}

void addLast(List &l, int data){
	Node *node = getNode(data);
	if (l.head == NULL){
		l.head = l.tail = node;
		return;
	}
	
	l.tail->next = node;
	l.tail = node;
}

void printList(List l){
	Node *temp =l.head;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void writeData(char fn[]){
	FILE *f = fopen(fn, "w");
	if (!f) {
		printf("can not open file!");
		return;
	}
	
	int num;
	char chon;
	while (1){
		printf("Nhap so can ghi vao file!: "); scanf("%d", &num);
		fprintf(f, "%d\n", num);
		printf("Nhap tiep khong (y/n)? "); getchar(); scanf("%c", &chon);
		if (chon == 'n') break;
	}
	fclose(f);
}

void readData(char fn[], List &l){
	FILE *f = fopen(fn, "r");
	if (!f) {
		printf("can not open file!");
		return;
	}
	
	char line[100];
	Node *temp = l.head;
	while (fgets(line, 100, f) != NULL){
		addLast(l, atoi(line));
	}
	fclose(f);
}

