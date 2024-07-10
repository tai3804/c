#include <stdio.h>

void input(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("Nhap a[%d]:", i);
        scanf("%d", &a[i]);
    }
}

void output(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%4d", a[i]);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void interchangSort(int a[], int n){
    // so sánh phần tử thứ j và i
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]) swap(&a[i], &a[j]);
        }
    }
}

void bubbleSort(int a[], int n){
    // so sánh 2 phần tử liền kề và swap
    for (int i=0; i< n-1; i++){
        for (int j=i+1; j<n; j++){
            if (a[j-1] > a[j]) swap(&a[j-1], &a[j]);
        }
    }
}

void insectionSort(int a[], int n){
    // chọn phần tử đầu đã sắp xếp và chèn phần tử tiếp theo ở vị trí thích hợp
    int pos, x;
    for (int i=0; i<n; i++){
        pos = i;
        x = a[i+1];
        while (pos >=0 && a[pos] > x){
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = x;
    }
}

void selectionSort(int a[], int n){
    // tìm phần tử nhỏ nhất và đổi chỗ
    int min;
    for (int i=0; i<n-1; i++){
        min = i;
        for (int j=i+1; j<n; j++){
            if (a[j] < min) min = j;
        }
        swap(&min, &i);
    }
}

void quickSort(int a[], int left, int right){
    // sắp xếp phân hạch
    int i=left, j = right, x = a[(left+right)/2];
   do {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) quickSort(a, left, j);
    if (i < right) quickSort(a, i, right);
}

int main(){
}
