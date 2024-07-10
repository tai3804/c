#include <stdio.h>

struct  Node
{
    double data;
    Node* link;
};

struct Stack
{
    Node* top;
};


void Init(Stack &s){
	s.top = NULL;
}

Node *GetNode(double data){
	Node *node = new Node;
	node->data = data;
	node->link = NULL;
	
	return node;
}

void Push(Stack &s, double num){
	Node *newNode = GetNode(num);
	if (s.top == NULL) {
		s.top = newNode;
		
		return;
	}
	newNode->link = s.top;
	s.top = newNode;
}

void Pushes(Stack &s, double data[], int n){
    for (int i=0; i<n; i++){
        Push(s, data[i]);
    }
}

int Capacity(Stack s){
    int cnt=0;
    while (s.top != NULL){
        cnt++;
        s.top = s.top->link;
    }
    return cnt;
}
void Base10To2(Stack &s, int num){
	if (num == 0) return;
	Push(s, num%2);
	return Base10To2(s, num/2);
}

void PrintBase(Stack s){
	while (s.top != NULL){
		printf("%.0lf", s.top->data);
		s.top = s.top->link;
	}
}

void ShowStackLinkedList(Stack s){
    while(s.top != NULL){
        if (s.top->data - (int)s.top->data == 0) printf("%.0lf ", s.top->data);
        else printf("%.1lf ", s.top->data);
        s.top = s.top->link;
    }
}

int main(){
	Stack s;
	Init(s);
	Base10To2(s, 10);
	PrintBase(s);
	return 0;
}
