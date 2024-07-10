#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SINHVIEN{
	char MSSV[10];
	char ho[20];
	char ten[10];
	char gioiTinh[4];
	char diaChi[50];
	double dtb;
	
} SV;

void nhap(SV &sv){
	printf("Nhap MSSV:"); scanf("%s", sv.MSSV);
	printf("Nhap ho:"); fflush(stdin); gets(sv.ho);
	printf("Nhap ten:"); scanf("%s", sv.ten);
	printf("Nhap gioi tinh (nam/nu/khac):"); scanf("%s", sv.gioiTinh);
	printf("Nhap dia chi:"); fflush(stdin); gets(sv.diaChi);
	printf("Nhap dtb:"); scanf("%lf", &sv.dtb);
}

void xuat(SV sv){
	printf("%-10s %s %-10s %-4s %10s %10.2lf\n", sv.MSSV, sv.ho, sv.ten, sv.gioiTinh, sv.diaChi, sv.dtb);
}

int timSVMa(SV sv[],int n, char mssv[]){
	for (int i=0; i<n; i++){
		if (strcmp(sv[i].MSSV, mssv) == 0) return i;
	}
	
	return -1;
}

void swap(SV &a, SV &b){
	SV temp = a;
	a=b;
	b=temp;
}

void sortByDTB(SV sv[], int n){
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			if (sv[i].dtb > sv[j].dtb) swap(sv[i],sv[j]);
		}
	}
}

void sortByTen(SV sv[], int n){
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			if (strcmp(sv[i].ten, sv[j].ten) > 0 ) swap(sv[i],sv[j]);
		}
	}
}

int main(){
	int chon, n;
	SV sv[1000];
	while(true){
		printf("\n=====menu=====\n");
		printf("0. Thoat.\n");
		printf("1. Nhap sinh vien.\n");
		printf("2. Xuat sinh vien.\n");
		printf("3. Xuat thong tin cua sinh vien co ma so x.\n");
		printf("4. Sap xep danh sach sinh vien theo thu tu tang dan diem trung binh.\n");
		printf("5. Sap xep danh sach sinh vien theo thu tu tang dan cua ho va ten.\n");
		printf("Moi chon: "); scanf("%d", &chon);
		if (chon == 0) break;
		
		switch (chon) {
		case 1:
			printf("Nhap so luong sinh vien: "); scanf("%d", &n);
			for (int i=0; i<n; i++){
				printf("Nhap sinh vien %d\n", i+1);
				nhap(sv[i]);
			}
			break;
		case 2:
			for(int i=0; i<n; i++){
				xuat(sv[i]);
			}
			break;
		case 3:
			char mssv[10]; 
			printf("Nhap ma so sinh vien can xuat: "); scanf("%s", mssv);
			if (timSVMa(sv, n, mssv) == -1) {
				printf("khong tim thay!\n");
			}else {
				xuat(sv[timSVMa(sv, n, mssv)]);
			}
			break;
			
		case 4:
			sortByDTB(sv, n);
			break;
			
		case 5:
			sortByTen(sv, n);
			break;
			
		}
	}
	
	
	return 0;
}
