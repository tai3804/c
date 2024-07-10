#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct NGAY {
	int ngay, thang, nam;
};

struct SINHVIEN {
	char maSV[8];
	char hoTen[50];
	int gioiTinh;
	NGAY ngaySinh;
	char diaChi[100];
	char lop[12];
	char khoa[7];
};


struct Node {
	SINHVIEN data;
	Node* next;
};

struct List {
	Node* first;
	Node* last;
};

Node* GetNode(SINHVIEN sv){
	Node* p = new Node;
	p->data = sv;
	p->next = NULL;
	return p;
}

void Init(List &l){
	l.first = l.last = NULL;
}

//them node
void AddFirst(List &l, Node *newNode){
	if (l.first == NULL) {
		l.first = l.last = newNode;
		return;
	}
	
	newNode->next = l.first;
	l.first = newNode;
}

void InsertFirst(List &l, SINHVIEN sv){
	Node *newNode = GetNode(sv);
	AddFirst(l, newNode);
}

int Search(List l, char ma[]){
	while (l.first != NULL){
		if (strcmp(l.first->data.maSV, ma) == 0) return 1;
		l.first = l.first->next;
	}
	return 0;
}

int InsertFirst_khongTrung(List &l, SINHVIEN sv){
	if (Search(l, sv.maSV)) {
		printf("Ma sinh vien trung!");
		return 0;
	}
	InsertFirst(l, sv);
	return 1;
}
void AddLast(List &l, Node* newNode){
	if (l.first == NULL) {
		l.first=l.last=newNode;
		return;
	}
	l.last->next = newNode;
	l.last = newNode;
}

void InsertLast(List &l, SINHVIEN sv){
	Node* newNode = GetNode(sv);
	AddLast(l, newNode); 
}

void InsertAfter (List &l, Node* p, SINHVIEN sv){
	if (strcmp(l.last->data.maSV, sv.maSV) == 0) {
		InsertLast(l, sv);
		return;
	}
	Node *temp = l.first;
	while(temp != NULL){
		if (strcmp(temp->data.maSV,sv.maSV) == 0) {
			Node *newNode = temp->next;
			if (l.first == NULL) l.first = l.last = newNode;
			
			newNode->next = temp ->next;
			temp->next = newNode;
			return;
		}
		temp =temp->next;
	}
	InsertFirst(l, sv);
}

Node* TimThem(List l, SINHVIEN x){
	Node *p = l.first;
	while (p!= l.last && strcmp(p->next->data.maSV, x.maSV) < 0){
		p = p->next;
	}
	return p;
}

void ThemCoThuTu (List &l, SINHVIEN sv){
	if (strcmp(sv.maSV, l.first->data.maSV) < 0)
		InsertFirst(l, sv);
	else {
		Node *p = TimThem(l, sv);
		InsertAfter(l, p, sv);
	}
}

//xoa 
void RemoveFirst(List &l){
	Node *temp = l.first;
	l.first = l.first->next;
	free(temp);
}

void RemoveLast(List &l){
	Node *temp = l.first;
	while (temp->next != l.last) {
		temp = temp->next;
	}
	temp->next = NULL;
	free(l.last);
	l.last = temp;
}

//Node* TimXoa(List l, int x){
//	Node *p= l.first;
//	while (p != l.last && p->next->data != x) p = p->next;
//	if (p != l.last) return p;
//	
//	return NULL;
//}


//sap xep
void swapSV(SINHVIEN &a, SINHVIEN &b){
	SINHVIEN temp = a;
	a=b;
	b=temp;
}

void ListAppend(List &l, List &l2){
	if (l2.first == NULL) return ;
	if (l.first == NULL) l=l2;
	else {
		l.last->next = l2.first;
		l.last = l2.last;
	}
	Init(l2);
}

//void ListQSort(List &l) {
//	Node *x, *p;
//	List l1, l2;
//	if (l.first == l.last) return;
//	Init(l1);
//	Init(l2);
//	x = l.first;
//	l.first = x->next;
//	while (l.first != NULL){
//		p = l.first;
//		if (p->data <= x->data) AddFirst(l1, p);
//		else AddFirst(l2, p);
//	}
//	ListQSort(l1);
//	ListQSort(l2);
//	AddLast(l, x);
//	ListAppend(l, l2);
//}

// xuat List ra man hinh
void InterchangeSortList(List &l){
	for (Node *i = l.first; i!= l.last; i=i->next){
		for (Node *j=i->next; j!=NULL; j=j->next){
			if (strcmp(i->data.hoTen, j->data.hoTen) > 0) 
				swapSV(i->data, j->data);
		}
	}
}
void xoa(List &l, char ma[]){
	if (strcmp(l.first->data.maSV, ma) == 0) RemoveFirst(l);
	if (strcmp(l.first->data.maSV, ma) == 0) RemoveLast(l);
	
	Node *temp = l.first;
	while (temp->next != NULL){
		if (strcmp(temp->next->data.maSV, ma) == 0){
			Node *nodeXoa = temp->next;
			temp->next = nodeXoa->next;
			free(nodeXoa);
			return;
		}
		temp = temp->next;
	}
}

int NhapSinhVien(SINHVIEN &x){	
	printf("Ma so sinh vien: ");
	fflush(stdin); gets(x.maSV);
	if (strcmp(x.maSV, "0") == 0)
		return 0; //Nhap MASV = 0 de dung
	printf("Ho va ten: ");
	fflush(stdin);
	gets (x.hoTen);
	printf("Gioi tinh: ");
	fflush (stdin);
	scanf("%d", &x.gioiTinh); printf("Ngay thang nam sinh: ");
	fflush(stdin);
	scanf("%d %d %d", &x.ngaySinh.ngay,&x.ngaySinh.thang, &x.ngaySinh.nam);
	printf("Dia chi: "); fflush(stdin);
	gets (x.diaChi);
	printf("Lop: ");
	fflush(stdin);
	gets (x.lop);
	printf("Khoa: ");
	fflush(stdin);
	gets(x.khoa);
	
	return 1;
}

void NhapDSSV(List &l){
	printf("\nbat dau nhap dssv. Nhap masv = 0 de dung\n");
	SINHVIEN sv;
	while(NhapSinhVien(sv)){
		InsertFirst_khongTrung(l, sv);
	}
	printf("ket thuc nhap sinh vien\n");
}

void XuatSinhVien(SINHVIEN s){
	char gt[4];
	if (s.gioiTinh == 0)
		strcpy(gt, "Nam");
	else 
		strcpy(gt, "Nu");
	printf("\n%10s %20s %5d/%d/%d %5s %40s %8s %8s", s.maSV, s.hoTen, s.ngaySinh.ngay, s.ngaySinh.thang, s.ngaySinh.nam, gt, s.diaChi, s.khoa, s.lop);
}

void XuatDSSV(List l){
	Node* p = l.first;
	while(p!=NULL){
		XuatSinhVien(p->data);
		p = p->next;
	}
}

int main(){
	List l;
	Init(l);
	NhapDSSV(l);
	XuatDSSV(l);
	return 0;
}
