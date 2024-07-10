#include <stdio.h>
#include <string.h>

struct NgaySinh {
    int ngay;
    int thang;
    int nam;
};

struct SinhVien {
    char maSV[10];
    char hoTen[50];
    struct NgaySinh ngaySinh;
    char maLop[10];
};

void swap(struct SinhVien* a, struct SinhVien* b) {
    struct SinhVien temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct SinhVien arr[], int low, int high) {
    char pivot[10];
    strcpy(pivot, arr[high].maSV);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j].maSV, pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct SinhVien arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    struct SinhVien dsSV[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cho sinh vien %d:\n", i + 1);
        printf("Ma SV: ");
        scanf("%s", dsSV[i].maSV);
        printf("Ho ten: ");
        scanf("%s", dsSV[i].hoTen);
        printf("Ngay sinh (ngay thang nam): ");
        scanf("%d %d %d", &dsSV[i].ngaySinh.ngay, &dsSV[i].ngaySinh.thang, &dsSV[i].ngaySinh.nam);
        printf("Ma lop: ");
        scanf("%s", dsSV[i].maLop);
    }

    quickSort(dsSV, 0, n - 1);

    printf("\nDanh sach sinh vien sau khi sap xep theo ma SV:\n");
    for (int i = 0; i < n; i++) {
        printf("Ma SV: %s, Ho ten: %s, Ngay sinh: %d/%d/%d, Ma lop: %s\n",
               dsSV[i].maSV, dsSV[i].hoTen, dsSV[i].ngaySinh.ngay, dsSV[i].ngaySinh.thang, dsSV[i].ngaySinh.nam, dsSV[i].maLop);
    }

    return 0;
}
