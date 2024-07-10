#include <bits/stdc++.h>
#include <stdlib.h>

struct Node {
    int data;
    Node* pNext;
};

struct List {
    struct Node* pHead;
    struct Node* pTail;
};

Node *getNode(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->pNext = NULL;
    return node;
} 
void Init(struct List &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

void InsertFirst(List &l, int data){
    Node *newNode = getNode(data);
    if (l.pHead == NULL){
        l.pHead = l.pTail = newNode;
        return;
    }
    newNode->pNext = l.pHead;
    l.pHead = newNode;
}

void InsertLast(List &l, int data){
    Node *newNode = getNode(data);
    if (l.pHead == NULL){
        l.pHead = l.pTail = newNode;
        return;
    }
    l.pTail->pNext = newNode;
    l.pTail = newNode;
}

void FindAndInsert(List &l,int key, int data){
    Node *newNode = getNode(data);
    if (l.pHead == NULL){
        return;
    }
    if (l.pHead->data == key){
        InsertFirst(l,data);
        return;
    }
    if (l.pTail->data == key) {
        InsertLast(l, data);
        return;
    }
    Node *temp = l.pHead;
    
    while (temp->pNext != NULL || temp->pNext->data != key){
        temp = temp->pNext;
    }
    newNode->pNext = temp->pNext;
    temp->pNext = newNode;
}

void ShowList(List l){
    while (l.pHead != NULL){
        printf("%d ", l.pHead->data);
        l.pHead = l.pHead->pNext;
    }
}

int main(){
	List l;
	Init(l);
	InsertLast(l, 7);
	ShowList(l);
	return 1;
}
