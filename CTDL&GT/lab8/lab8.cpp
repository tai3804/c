#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien {
	char maSV[20];
	char name[20];
	double diem;
};

struct Node {
	SinhVien data;
	Node *left;
	Node *right;
};

typedef struct Node* Tree;

void Init(Tree &r){
	r = NULL;
}

Node *GetNode(SinhVien sv){
	Node *node = new Node;
	node->data = sv;
	node->left = node->right = NULL;
	
	return node;
}

void add(Tree &r, SinhVien sv){
	if (r == NULL) {
		Node *newNode = GetNode(sv);
		r = newNode;
		
		return;
	}
	else if (strcmp(sv.maSV, r->data.maSV) == 0){
		printf("Khong the them do trung ma!");
		
		return;
	}
	else if (strcmp(sv.maSV, r->data.maSV) < 0) add(r->left, sv);
	else add(r->right, sv);
}

void NhapSV(SinhVien &sv){
	printf("Nhap ma sv: "); scanf("%s", &sv.maSV);
	printf("Nhap ten sv: "); fflush(stdin); gets(sv.name);
	printf("Nhap diem: "); scanf("%lf", &sv.diem);
}

void ThemSVVaoCay(Tree &r){
	int chon = -1;
	SinhVien sv;
	while (chon != 0){
		printf("Moi nhap sv\n");
		NhapSV(sv);
		add(r, sv);
		printf("Nhap nua khong? 1: tiep, 0: dung "); scanf("%d", &chon);
	}
}

void PrintSV(SinhVien sv){
	printf("%-20s %-20s %-5.2lf", sv.maSV, sv.name, sv.diem);
	printf("\n");
}

void LNR(Tree r){
	if (r == NULL) return;
	if (r->left != NULL) LNR(r->left);
	PrintSV(r->data);
	if (r->right != NULL) LNR(r->right);
}

void LRN(Tree r){
	if (r == NULL) return;
	if (r->left != NULL) LRN(r->left);
	if (r->right != NULL) LRN(r->right);
	PrintSV(r->data);
}

int DemNutLa(Tree r){
	if (r==NULL) return 0;
	else if(r->left == NULL && r->right == NULL) return 1;
	return DemNutLa(r->left) + DemNutLa(r->right);
}

int max(int a, int b){
	return a>b ? a : b;
}

int TinhChieuCao(Tree r){
	if (r == NULL) return 0;
	return max(TinhChieuCao(r->left), TinhChieuCao(r->right)) + 1;
}

SinhVien TimNode(Tree r, char ma[]){
	if (r==NULL) {
		SinhVien sv;
		strcpy(sv.maSV, "null");
		return sv;
	}
	else if (strcmp(ma, r->data.maSV) == 0) return r->data;
	else if (strcmp(ma, r->data.maSV) < 0) return TimNode(r->left, ma);
	else return TimNode(r->right, ma);
}

void TimNodeTheMang(Tree &x, Tree &y){
	if (y->right != NULL) {
		TimNodeTheMang(x, y->right);
	} 
	else {
		x->data = y->data;
		x = y;
		y=y->left;
	}
}

int XoaNode(Tree &r, char ma[]){
	if (r == NULL) return 0;
	else if (strcmp(ma, r->data.maSV) < 0) return XoaNode(r->left, ma);
	else if (strcmp(ma, r->data.maSV) < 0) return XoaNode(r->right, ma);
	else if (strcmp(ma, r->data.maSV) == 0) {
		Node *temp = r;
		if (r->left == NULL) r=r->right;
		else if (r->right == NULL) r = r->left;
		else {
			TimNodeTheMang(temp, r->left);
			free(temp);
		}
	}
	else {
		printf("khong tim thay sinh vien!");
		
		return 0;
	}
}

int main(){
	Tree r;
	Init(r);
	int chon =-1;
	while (chon != 0){
		printf("\n===menu===\n");
		printf("0. Thoat\n");
		printf("1. Nhap sinh vien\n");
		printf("2. In ra theo thu tu LNR\n");
		printf("3. Sap xep theo truong du lieu\n");
		printf("4. Dem so nut la\n");
		printf("5. Tinh chieu cao\n");
		printf("6. Chen them sinh vien\n");
		printf("7. Tim kiem sinh vien\n");
		printf("8. Xoa sinh vien\n");
		printf("moi chon: "); scanf("%d", &chon);
		switch (chon) {
			case 1: {
				ThemSVVaoCay(r);
				break;
			}
			case 2: {
				LNR(r);
				break;
			}
			case 3: {
				//
				break;
			}
			case 4: {
				printf("so nut la la: %d", DemNutLa(r));
				break;
			}
			case 5: {
				printf("Chieu cao cua cay la: %d", TinhChieuCao(r));
				break;
			}
			case 6: {
				ThemSVVaoCay(r);
				break;
			}
			case 7: {
				char ma[20];
				printf("Nhap ma sv: "); scanf("%s", ma);
				SinhVien sv = TimNode(r, ma);
				if (strcmp(sv.maSV, "null") == 0) printf("Khong tim thay sv!");
				else PrintSV(sv);
				break;
			}
			case 8:{
				char ma[20];
				printf("Nhap ma sv: "); scanf("%s", ma);
				XoaNode(r, ma);
				break;
			}
			default: {
				printf("Lua chon khong hop le!");
				break;
			}
		}
	}
	return 0;
}
