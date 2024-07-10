#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef int DataType;

struct Node {
    int data;
    Node *pNext;
};

struct List {
    Node *pHead;
    Node *pTail;
};

void Init(List &l){
    l.pHead =l.pTail =NULL;
}

Node *getNode(int data){
    Node *node = new Node;
    node->data = data;
    node->pNext = NULL;
    return node;
}

void InsertFirst(List &l, int data){
    Node *newNode = getNode(data);
    if (l.pHead == NULL) {
        l.pHead =l.pTail = newNode;
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

void AppendList (List &dl, int a[], int n){
	for (int i=0; i<n; i++){
		InsertLast(dl, a[i]);
	}
}

void FindAndInsert(List &l, int key, int value){
    Node *newNode = getNode(value);
    if (l.pHead->data == key){
        newNode->pNext = l.pHead->pNext;
        l.pHead->pNext = newNode;
        return;
    }
    if (l.pTail->data == key){
        InsertLast(l, value);
        return;
    }
    Node *tmp = l.pHead;
    while (tmp->pNext != NULL){
        if (tmp->data == key){
            newNode->pNext = tmp->pNext;
            tmp->pNext = newNode;
            return;
        }
        tmp=tmp->pNext;
    }
    InsertFirst(l, value);
}

//sum list
int SumLinkedList(const List& sll)
{
    int sum = 0;
    Node* current = sll.pHead;

    while (current != NULL)
    {
        sum += current->data;
        current = current->pNext;
    }

    return sum;
}

//search
int SearchKey(List l, int key){
    while (l.pHead != NULL){
        if (l.pHead->data == key) return 1;
        l.pHead = l.pHead->pNext;
    }
    return -1;
}

//show
void ShowList(List l){
    while(l.pHead != NULL){
        printf("%d ", l.pHead->data);
        l.pHead=l.pHead->pNext;
    }
}

//tao list tu file
List CreateLinkedListFromFile(string fileName)
{
    List linkedList = {NULL, NULL};

    ifstream file(fileName.c_str(), ios::in);
    if (!file.is_open())
    {
        cerr << "Error: Could not open the file." << endl;
        return linkedList;
    }

    string line;
    while (getline(file, line))
    {
        int value, option;
        if (sscanf(line.c_str(), "%d,%d", &value, &option) == 2)
        {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->pNext = NULL;

            if (option == 0) // Insert at the beginning
            {
                newNode->pNext = linkedList.pHead;
                linkedList.pHead = newNode;
                if (linkedList.pTail == NULL)
                    linkedList.pTail = newNode;
            }
            else if (option == -1) // Insert at the end
            {
                if (linkedList.pTail == NULL)
                {
                    linkedList.pHead = newNode;
                    linkedList.pTail = newNode;
                }
                else
                {
                    linkedList.pTail->pNext = newNode;
                    linkedList.pTail = newNode;
                }
            }
        }
    }

    file.close();
    return linkedList;
}

int main(){
	List sll;
	Init(sll);
	int n = 5;
	int V[] = {1,2,3,4,5};
	AppendList(sll,V,n);
	ShowList(sll);
	return 0;
}
