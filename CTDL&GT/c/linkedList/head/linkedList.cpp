#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    node *next;
} node;

node *makeNode(int value){
    node *head = (node*)malloc(sizeof(node));
    head->value = value;
    head->next = NULL;
    return head;
} 

void output(node *head){
    while(head != NULL){
        printf("%4d", head->value);
        head  = head->next;
    }
}

int size(node *head){
    int cnt=0;
    while (head != NULL) {
        head = head->next;
        cnt++;
    }
    return cnt;
}

void pushFront(node **head, int value){
    node *newNode = makeNode(value);
    newNode->next = *head;
    *head = newNode;
}

void pushBack(node **head, int value){
    node *newNode = makeNode(value);
	node *temp = *head;
        
        if (*head == NULL){
        *head = newNode;
        return;
		}

    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void push(node **head, int value, int pos){
    node *newNode = makeNode(value);
    node *temp = *head;

    if (pos <= 1) pushFront(head, value);
	else if (pos >= size(*head)) pushBack(head, value);
    else{
        for (int i=2; i<pos; i++){
            temp = temp->next;
		}
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void popFront(node **head){
	node *temp = *head;
	temp = temp->next;
	free(head);
	*head = temp;
}

int main(){
    int chon;
    while (true) {
        printf("=====menu=====");
        printf("0. Thoat");
        printf("1. Tao list.\n");
        printf("2. Them node vao dau ds.\n");
        printf("3. Them node vao cuoi ds.\n");
        printf("4. Them node vao ds vi tri bat ki.\n");
        printf("5. Xoa node dau ds.\n");
        printf("6. Xoa node cuoi ds.\n");
        printf("7. Xoa node o vi tri bat ki.\n");
        printf("Moi chon: "); scanf("%d", &chon);
        if (chon == 1) break;
        switch(chon)
        	case 1:
//        		int value;
//        		printf("Nhap gia tri: "); scanf("%d", &value);
//        		node *head = makeNode(value);
        		break;
        	case 2:
        		int value;
        		printf("Nhap gia tri: "); scanf("%d", &value);
        		pushFront(&head, value);
        		break;
        	case 3:
        		printf("Nhap gia tri: "); scanf("%d", &value);
        		pushBack(&head, value);
        		break;
        	case 4:
        		int i;
        		printf("Nhap gia tri: "); scanf("%d", &value);
        		printf("Nhap vi tri can chen: "); scanf("%d", &i);
        		push(&head, value, i);
        		break;
        	case 5:
        		popF
	}
}
