#include <stdio.h>
#include <stdlib.h>

struct Node {
	float heSo;
	int soMu;
	Node *link;
};

struct List {
	Node *first, *last;
};

void init(List &l){
	l.first = l.last = NULL;
}

Node *GetNode(float heSo,int soMu) {
	Node *p;
	p = new Node;
	if (p == NULL)
		return NULL;
	p->heSo = heSo;
	p->soMu = soMu;
	p->link = NULL;
	return p;
}

void AddLast (List &l,Node *new_ele) {
	if (l.first == NULL) {
		l.first = l.last = new_ele;
	}
	else {
		l.last->link = new_ele;
		l.last = new_ele;
	}
}

void InsertLast (List &l,float heSo,int soMu) {
	Node *new_ele=GetNode(heSo, soMu);
	if (new_ele==NULL)
		return;
	AddLast(l,new_ele);
}

void NhapDaThuc(List&l){
	float heSo;
	int soMu;
	do {
		printf("\nNhap he so: "); scanf("%f", &heSo);
		if (heSo == -0){
			break;
		}
		printf("\nNhap so mu: "); scanf("%d", &soMu);
		InsertLast(l, heSo, soMu);
	} while(heSo != 0);
	printf("\nDa nhap da thuc xong:\n");
}

void XuatDanhSach(List l){
	Node *p;
	p = l.first->link;
	printf("\n%.0fx^%d", l.first->heSo, l.first->soMu);
	while (p != NULL){
		if (p->heSo > 0) printf(" + ");
		printf("%.0fx^%d", p->heSo, p->soMu);
		p = p->link;
	}
}

void swap(Node *a, Node *b) {
    float tempHeSo = a->heSo;
    int tempSoMu = a->soMu;

    a->heSo = b->heSo;
    a->soMu = b->soMu;

    b->heSo = tempHeSo;
    b->soMu = tempSoMu;
}

void sapXepDaThucTheoMu(List &d) {
    if (d.first == NULL) {
        return;
    }

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = d.first;

        while (ptr1->link != lptr) {
            if (ptr1->soMu > ptr1->link->soMu) {
                swap(ptr1, ptr1->link);
                swapped = 1;
            }
            ptr1 = ptr1->link;
        }
        lptr = ptr1;
    } while (swapped);
}

void CongDaThuc(List d1, List d2, List &d3){
	sapXepDaThucTheoMu(d1);
	sapXepDaThucTheoMu(d2);
	init(d3);
	Node *p = d1.first, *q = d2.first;
	float tongHeSo;
	while (p&&q){
		if (p->soMu == q->soMu){
			tongHeSo = p->heSo + q->heSo;
			if (tongHeSo != 0)
				InsertLast(d3, tongHeSo, p->soMu);
			p = p->link;
			q = q->link;
		}
		else {
			if (p->soMu > q->soMu){
				InsertLast(d3, p->heSo, p->soMu);
				p = p->link;
			}
			else {
				if (p->soMu < q->soMu){
				InsertLast(d3, q->heSo, q->soMu);
				q = q->link;
				}
			}
		}
	}
	while (q){
		InsertLast(d3, q->heSo, q->soMu);
		q = q->link;
	}
	while (p){
		InsertLast(d3, p->heSo, p->soMu);
		p = p->link;
	}
}

void TruDaThuc(List d1, List d2, List &d3){
	init(d3);
	Node *p = d1.first, *q = d2.first;
	float tongHeSo;
	while (p && q){
		if (p->soMu == q->soMu){
			tongHeSo = p->heSo - q->heSo;
			if (tongHeSo != 0){
				InsertLast(d3, tongHeSo,q->soMu);
			}
			p=p->link;
			q=q->link;
		}
		else {
			if (p->soMu > q->soMu){
				InsertLast(d3, p->heSo, p->soMu);
				p=p->link;
			}
			else {
				InsertLast(d3, q->heSo, q->soMu);
				q=q->link;
			}
		}
	}
	while (p){
		InsertLast(d3, p->heSo, p->soMu);
		p=p->link;
	}
	while (q){
		InsertLast(d3, q->heSo, q->soMu);
		q = q->link;
	}
}


void xoaCuoi(List &l){
	if (l.first == NULL) return;
	Node *temp = l.first;
	while (temp->link != l.last){
		temp=temp->link;
	}
	temp->link=  NULL;
	free(l.last);
	l.last = temp;
}

void RutGonDaThuc(List& d) {
	if (d.first == NULL){
		return;
	}
	Node *p = d.first;
	while(p->link != NULL){
		Node *q = p->link;
		while(q!=NULL){
			if (p->soMu == q->soMu){
				p->heSo += q->heSo;
				q->heSo = 0;
			}
			q=q->link;
		}
		p=p->link;
	}
	p=d.first;
	while(d.last->heSo == 0){
		xoaCuoi(d);
	}
	while (p->link != NULL){
		if (p->link->heSo == 0){
			Node *node = p->link;
			p->link = node->link;
			free(node);
		}
		p=p->link;
	}
}

void nhanDaThuc(List d1, List d2, List &d3){
	Node *p=d1.first;
	float tichHeSo;
	int tongSoMu;
	while (p){
		if (p->heSo !=0){
			Node *q=d2.first;
			while(q){
				tichHeSo = p->heSo;
				tongSoMu = p->soMu;
				if (q->heSo != 0){
					tichHeSo *= q->heSo;
					tongSoMu += q->soMu;
					q=q->link;
					InsertLast(d3, tichHeSo, tongSoMu);
				}	
			}
		}
		RutGonDaThuc(d3);
		sapXepDaThucTheoMu(d3);
		p=p->link;
	}

}

int main(){
	List d1, d2, d3;
	init(d1);
	init(d2);
	init(d3);
	NhapDaThuc(d1);
	printf("\nDanh sach bieu dien da thuc d1: ");
	XuatDanhSach(d1);
	NhapDaThuc(d2);
	printf("\nDanh sach bieu dien da thuc d2: ");
	XuatDanhSach(d2);
	nhanDaThuc(d1, d2, d3);
	printf("\nDanh sach bieu dien da thuc tong: ");
	XuatDanhSach(d3);
	return 0;
}
