#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	Node *left;
	Node *right;
};

typedef struct Node* Tree;

//khoi tao
void init(Tree &r){
	r = NULL;
}

//tao node
Node* getNode(int data){
	Node *node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//them node
void add(Tree &r, int data){
	Node *newNode = getNode(data);
	if (r == NULL) {
		r = newNode;
		return;
	}
	
	if (data < r->data) add(r->left, data);
	if (data > r->data) add(r->right, data);
}

int countLeaft(Tree r){
	if (r == NULL) return 0;
	if (r->left == NULL && r->right == NULL) return 1;
	return countLeaft(r->left) + countLeaft(r->right);
}

int countNode(Tree r){
	if (r == NULL) return 0;
	return countNode(r->left) + countNode(r->right) + 1;
}

int max(int a, int b){
	return a>b ? a : b;
}

int getHeight(Tree r){
	if (r == NULL)  return 0;
	return max(getHeight(r->left), getHeight(r->right)) + 1;
}

//xoa node
//void deleteNode(Tree &r, int data){
//	if (r == NULL) return;
//	if (data < r->data) deleteNode(r->left, data);
//	else if (data > r->data) deleteNode(r->right, data);
//	else {
//		Node *temp = r;
//		if (r->left == NULL) r = r->right;
//		else if (r->right == NULL) r = r->left;
//		else {
//			temp = r->left;
//			Node *p = r;
//			if (temp->right != NULL){
//				while (temp->right != NULL) {
//					p = temp;
//					temp = temp->right;
//				}
//				r->data = temp->data;
//				p->right = temp->left;
//			}
//			else {
//				r->data = temp->data;
//				p->left = temp->left;
//			}
//		}
//		free(temp);
//	}
//}

void findDelNode(Tree &x, Tree &y){
	if (y->right != NULL) findDelNode(x, y->right);
	else {
		x->data = y->data;
		x=y;
		y=y->left;
	}
}

void deleteNode(Tree &r, int data){
	if (r == NULL) return;
	if (data < r->data) deleteNode(r->left, data);
	else if (data > r->data) deleteNode(r->right, data);
	else {
		Node *temp = r;
		if (r->left == NULL) r = r->right;
		else if (r->right == NULL) r = r->left;
		else {
			findDelNode(temp, r->left);
		}
		free(temp);
	}
}

// duyet cay
void LRNTree(Tree r){
	if (r == NULL) return;
	if (r->left != NULL) LRNTree(r->left);
	printf("%d ", r->data);
	if (r->right != NULL) LRNTree(r->right);
}

int main(){
	Tree r;
	init(r);
	add(r, 10);
	add(r, 5);
	add(r, 7);
	add(r, 6);
	add(r, 99);
	add(r, -1);
	add(r, 100);
	deleteNode(r, 10);
	LRNTree(r);
	printf("\nso nut la: %d", countLeaft(r));
	printf("\nso nut la: %d", countNode(r));
	printf("\ndo cao cua cay la: %d", getHeight(r));
	return 0;
}
