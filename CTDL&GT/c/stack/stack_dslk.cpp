#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Math.h>

struct Node
{
	int data;
	Node *pNext;
};

struct Stack
{
	Node *top;
};


void init(Stack &S)
{
	S.top = NULL;
}

int  isEmpty (Stack S)
{ 
	return  S.top == NULL ? 1 : 0; 
}

Node *getNode(int x){
	Node *p = new Node;
	if (p==NULL)  { 
		printf("Khong du bo nho"); 
		return NULL; 
	}
	p->data = x;
	p->pNext= NULL;	
	return p;
}

void  Push (Stack &S,  int  x)
{
	Node *p = getNode(x);
	if (S.top==NULL)  
		S.top = p;
	else{	
		p->pNext = S.top; 
		S.top = p;	
	}
}

int Pop (Stack &S)
{	
	if (S.top==NULL){
		printf("Stack rong!");
		return -1;
	}
	Node *p = getNode(S.top->data);
	int x = p->data;
	S.top = S.top->pNext;
	free(p);	
	return x;		
}

void DocTu(char s[], char tu[], int &vt){
	for (int i=0; i<strlen(tu); i++){
		tu[i] = ' ';
	}
	int i=0;
	while ( s[vt] != ' ') {
		tu[i] = s[vt];
		vt++;
		i++;
	}
}



int LaToanTu(char s[]) {
	char c= s[0];
	if ((c== '+') || (c =='-') || (c == '*') || (c == '/') || (c == '^'))
		return 1;
	return 0; 
}

float TinhToan(float toanHang1, float toanHang2, char toanTu){
	float kq;
	switch (toanTu){
		case '+':
			kq = toanHang1 + toanHang2;
			break;
		case '-':
			kq = toanHang1 - toanHang2;
			break;
		case '*':
			kq = toanHang1 * toanHang2;
			break;
		case '/':
			kq = toanHang1 / toanHang2;
			break;
		case '^':
			kq = pow(toanHang1,toanHang2);
			break;
	}
	
	return kq;
}

float TinhBieuThuc(Stack &s, char bieuThuc[]){
	float kq;
	char t[10];
	int i=0;
	do {
		DocTu (bieuThuc, t, i);
		if (LaToanTu(t)){
			char toanTu = t[0];
			float toanHang1 = Pop(s);
			float toanHang2 = Pop(s);
			kq = TinhToan(toanHang2, toanHang1, toanTu);
			Push(s, kq);
		}
		else {
			float toanHang = atof(t);
			Push(s, toanHang);
		}
		i++;
	} while (bieuThuc[i] != '#');
	return Pop(s);
}

int main (){
	
	return 0;
}
