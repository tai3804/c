//tran thanh tai
//thai viet phat
// vu van ha duong
//phan nhat quang
//nguyen van huy
// do thanh nhan
// dang the bao
//ngo tran van diem

#include <stdio.h>
#include <string.h>

typedef struct sv {
    char ten[30];
    char maSV[10];
} sv;

void layTen(char ten[]){
    int size = strlen(ten);

}

void LinearSearch (sv sv[],char key[10], int n){
    int j=0;
    for (int i=0; i<n; i++){
        if (strcmp(sv[i].ten, key) == 0){
            printf("tim thay sinh vien %s tai vi tri %d\n", key, i);
        }
    }
}

void nhap(sv *sv){
    printf("Nhap ma sinh vien: ");
    fflush(stdin);
    gets(sv->maSV);
    
    printf("Nhap ten sinh vien: ");
    fflush(stdin);
    gets(sv->ten);
}

void xuat(sv sv[], int n){
    for (int i=0; i<n; i++){
        printf("Sinh vien %s co ma %s\n", sv[i].ten, sv[i].maSV);
    }
}

int main(){
    int n;
    char key[10];
    printf("Nhap so luong sinh vien: "); scanf("%d", &n);
    printf("Nhap sinh vien can tim: "); scanf("%s", key);

    sv sv[n];
    for (int i = 0; i < n; i++){
        nhap(&sv[i]);
    }

    xuat(sv, n);
    return 0;
}