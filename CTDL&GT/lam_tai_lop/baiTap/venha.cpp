#include <stdio.h>
#include <string.h>

typedef struct NgaySinh {
    int ngay;
    int thang;
    int nam;
} NgaySinh;

struct SinhVien {
    char maSV[10];
    char hoTen[50];
    NgaySinh ngaySinh;
    char maLop[10];
};

void swap(SinhVien &a, SinhVien &b){
    SinhVien temp = a;
    a = b;
    b = temp;
}

void quickSort(SinhVien a[], int left, int right){
    // sắp xếp phân hạch
    int i=left, j = right;
    SinhVien x = a[(left + right)/2];

    while (i <= j){
        while(strcmp(a[i].maSV, x.maSV) < 0) i++;
        while(strcmp(a[j].maSV, x.maSV) > 0) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        if (i < right) quickSort(a, i, right);
        if (left < j) quickSort(a, left, j);
    }
}

void interchangeSort(SinhVien a[], int n){
    for (int i=0; i < n-1; i++){
        for (int j=i+1; j<n; j++){
            if (strcmp(a[i].maSV, a[j].maSV) > 0) swap(a[i], a[j]);
        }
    }
}

void bubbleSort(SinhVien a[], int n){
    for (int i=0; i < n-1; i++){
        for (int j=i+1; j<n; j++){
            if (strcmp(a[j].maSV, a[j-1].maSV) < 0) swap(a[j], a[j-1]);
        }
    }
}

void insetionSort(SinhVien a[], int n){
    int pos;
    SinhVien x;
    for (int i=1; i<n; i++){
        x = a[i];
        pos = i-1;
        while (pos >=0 && strcmp(a[pos].maSV, x.maSV) > 0) {
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = x;
    }
}

void selectionSort(SinhVien a[], int n){
    int min;
    for (int i=0; i<n-1; i++){
        min = i;
        for (int j=i+1; j < n; j++){
            if (strcmp(a[min].maSV, a[j].maSV) > 0) min = j;
        }
        swap(a[min], a[i]);
    }
}

int main(){
    int n=2;
    SinhVien sv[n];
    for (int i=0; i<n; i++){
        printf("Nhap sinh vien %d.\n ", i+1);
        printf("Nhap ma sv: ");     scanf("%s", sv[i].maSV);
        printf("nhap ho ten: ");     scanf("%s", sv[i].hoTen);
        printf("nhap ngay sinh: ");     scanf("%d", &sv[i].ngaySinh.ngay);
        printf("Nhap thang sinh: ");     scanf("%d", &sv[i].ngaySinh.thang);
        printf("Nhap nam sinh: ");     scanf("%d", &sv[i].ngaySinh.nam);
        printf("Nhap ma lop: ");     scanf("%s", sv[i].maLop);
        printf("\n");
    }

    selectionSort(sv, n);

    for (int i=0; i<n; i++){
        printf("%10s%10s", sv[i].maSV, sv[i].hoTen);
    }
    
    return 0;
}