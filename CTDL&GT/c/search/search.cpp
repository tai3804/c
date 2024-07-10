 #include <stdio.h>
 
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

