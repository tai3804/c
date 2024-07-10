#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	Node* left;
	Node* right;
};

typedef struct Node* Tree;

void init(Tree &t){
	t = NULL;
}

Node* getNode(int data){
	Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

void add(Tree &t, Node* newNode){
	if (t == NULL) {
		t= newNode;
		return;
	}
	if (newNode->data < t->data) add(t->left, newNode);
	else add(t->right, newNode);
}

void insert(Tree &t, int data){
	if (t==NULL){
		t = getNode(data);
		return;
	}
	if (data < t->data) insert(t->left, data);
	else insert(t->right, data);
}

int demNutLa(Tree t){
	if (t==NULL) return 0;
	if (t->left == NULL && t->right == NULL) return 1;
	return demNutLa(t->left) + demNutLa(t->right);
}

int demNut(Tree t){
	if (t==NULL) return 0;
	return demNut(t->left) + demNut(t->right) + 1;
}

int Max (int a, int b){
	if (a > b) return a;
	return b;
}

int TinhDoCao(Tree c){
	if (c == NULL) {
		return 0;
	}
	return Max(TinhDoCao(c->left), TinhDoCao(c->right))+1;
}

void duyetLRN(Tree t){
	if (t== NULL) return;
	if (t->left != NULL) duyetLRN(t->left);
	printf("%d ", t->data);
	if (t->right != NULL) duyetLRN(t->right); 
}

void xoaNode(Tree &t, int x) {
	if (t== NULL) return;
	if (x < t->data) xoaNode(t->left, x); //duuyet qua trai
	else if (x > t->data) xoaNode(t->right, x); // duyet qua phai
	else { // tim thay node can xoa 
		Node *temp = t;
		if (t->left == NULL) t = t->right; // node co 1 con ben phai
		else if (t->right == NULL) t=t->left; // node co 1 con ben trai
		else { // node co 2 con
			temp = t->left; //re nhanh trai
			while (temp->right != NULL){
				temp=temp->right; // tim phan tu cuoi phari cua nhanh trai
			}
			t = temp; // gan gia tri the mang cho t
			temp = temp->left; // gan nhanh con lai cho temp
		}
		free(temp);
	}
}

int main(){
	Tree t;
	init(t);
	insert(t, 5);
	insert(t, 3);
	insert(t, 4);
	insert(t, 6);
	insert(t, 7);
	insert(t, 8);
	insert(t, 9);
	insert(t, 10);
	insert(t, 32);
	xoaNode(t, 5);
	duyetLRN(t);
	return 0;
}
