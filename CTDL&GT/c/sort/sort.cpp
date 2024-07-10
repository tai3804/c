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
    // so s�nh 2 ph?n t? li?n k? v� swap
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) { // S?a di?u ki?n c?a v�ng l?p trong n�y
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}


void insectionSort(int a[], int n){
    // chọn phần tử đầu đã sắp xếp và chèn phần tử tiếp theo ở vị trí thích hợp
    int pos, x;
    for (int i=0; i<n-1; i++){
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
            if (a[j] < a[min]) min = j;
        }
        if(min != i) swap(&a[min], &a[i]);
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

void quickSortKDQ(int a[], int left, int right){
	int i=left, j = right;
	while (i<=j){
		int mid = (i+j)/2;
		int x = a[mid];
		while (a[i]< x) i++;
		while (a[j] > x) j--;
		if (i <= j){
			swap(&a[i], &a[j]);
            i++;
            j--;
		} 
        if (i <= mid) {
            i = mid +1;
        }
        if (j >= mid) {
        	j = mid-1;
		}
	}
}

int main(){
    int a[100], n;
    printf("Nhap so phan tu:"); scanf("%d", &n);
    input(a, n);
    selectionSort(a, n);
    output(a, n);
}
