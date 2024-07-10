#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//van de 1
void nhap(int a[], int n){
	for (int i=0; i<n; i++){
		printf("Nhap phan tu thu %d: ", i+1);
		scanf("%d", a[i]);
	}
}

void phatSinhMang(int a[], int n){
	srand(time(NULL));
	for (int i=0; i<n; i++){
		a[i] = rand();
	}	
}

void xuat(int a[], int n){
	for (int i=0; i<n; i++){
		printf("%10d", a[i]);
	}
	printf("\n");
}

 int ghiFile(char *fileName, int a[], int n){
 	FILE *f = fopen(fileName, "w");
 	if (!f)
 		return 0;
		
 	for (int i=0; i<n; i++){
 		fprintf(f, "%d\t", a[i]);
		
 	fclose(f);
 	return 1;
 	}
 }

 int docFile(char *fileName, int a[], int &n){
 	FILE *f = fopen(fileName, "r");
 	if (!f)
 		return 0;
 	int i=0;
 	while(!feof(f)){
 		fscanf(f, "%d", a[i]);
 		i++;
 	}
 	n=i;
 	fclose(f);
 }

 //van de 2
 int linearSearch(int a[], int n, int x){
 	int i=0;
 	while (i<n && a[i] != x) i++;
	
 	return i<n ?i :-1;
 }

 int linearSearchCaiTien(int a[], int n, int x){
 	int i=0;
 	a[n] = x;
 	while (a[i] != x) i++;
	
 	return i<n ?i :-1;
 }

 //van de 3
 int binarySearch(int a[], int left, int right, int x){
 	if (left > right) return -1;
 	int mid = (left + right) /2;
 	if (x == a[mid]) return mid;
 	if (x < a[mid]) return binarySearch(a, left, mid-1, x);
 	if (x > a[mid]) return binarySearch(a, mid+1, right, x);
 }

void phatSinhMangTang(int a[], int n){
	srand(time(NULL));
	a[0] = rand()%50;
	for (int i=0; i<n; i++){
		a[i] = a[i-1] + rand()%10;
	}
}

 //bt ve nha
 int binarySearchKDQ(int a[], int left, int right, int x){
 	while (left <= right) {
 		int mid = left + (right - left) / 2;
 		if (a[mid] == x){
 			return mid;
 		}
 		if (x < a[mid]){
 			right = mid - 1;
 		} else {
 			left = mid + 1;
 		}
 	}
 	return -1;
 }

int main(){
	int a[100000], n, x;
	printf("Nhap so phan tu cua mang: "); scanf("%d", &n);
	phatSinhMangTang(a, n);
	xuat(a, n);
	printf("Nhap khoa can tim: "); scanf("%d", &x);
		
	//van de 4
	clock_t start, end;
	
	start = clock();
	linearSearch(a, n, x);
	end = clock();
	double t = end - start;
	printf("Thoi gian tim kiem tuyen tinh la: %f\n", t);
	
	start = clock();
	binarySearch(a, 0, n, x);
	end = clock();
	t = end - start;
	printf("Thoi gian tim kiem nhi phan la: %f\n", t);
	
	int kq = binarySearch(a, 0, n, x);
	if (kq == -1) printf("Khong tim thay!");
	else {
		printf("Tim thay tai vi tri %d de quy.\n", kq);
		printf("Tim thay tai vi tri %d khong de quy.\n", binarySearchKDQ(a, 0, n, x));
	}
	
	return 0;
}
