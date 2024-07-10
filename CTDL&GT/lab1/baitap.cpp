#include <stdio.h>
#include <string.h>
 
typedef struct WORD{
 	char name[256];
 	char meaning[512];
 } WORD;

//nhap xuat
void nhap(WORD words[], int n){
	for (int i=0; i<n; i++){
		printf("Nhap tu: ");
		scanf("%s", words[i].name);
	
		printf("Nhap nghia cua tu %s: ", words[i].name);
		fflush(stdin);
		gets(words[i].meaning);
	}
}

void xuat(WORD words[], int n){
	for (int i=0; i<n; i++){
		printf("%d. %s : %s\n", i+1, words[i].name, words[i].meaning);
	}
}
//

// swap
void swap(WORD *a, WORD *b){
	WORD temp = *a;
	*a = *b;
	*b = temp;	
}
//

// sort
void interchangeSort(WORD words[], int n){
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			if (strcmp(words[i].name, words[j].name) > 0) swap(&words[i], &words[j]);
		}
	}
}

void bubbleSort(WORD words[], int n){
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			if (strcmp(words[j-1].name, words[j].name) > 0) swap(&words[j-1], &words[j]);
		}
	}
}

void insertionSort(WORD words[], int n){
	int pos;
	WORD x;
	for (int i=1; i<n; i++){
		pos = i-1;
		x = words[i];
		while (pos >= 0 && strcmp(words[pos].name, x.name) > 0){
			words[pos+1] = words[pos];
			pos--;
		}
		words[pos+1] = x;
		}
}

void selectionSort(WORD words[], int n){
	for (int i=0; i<n-1; i++){
		int min = i;
		for (int j=i+1; j<n; j++){
			if (strcmp(words[min].name, words[j].name) > 0) min =j;
		}
		swap(&words[i], &words[min]);
	}
}

void quickSort(WORD words[], int left, int right){
	int i=left, j=right;
	WORD x = words[(left + right) / 2];
	while (i <= j) {
		while (strcmp(words[i].name, x.name) < 0) i++;
		while (strcmp(words[j].name, x.name) > 0) j--;
		if (i <= j){
			swap(&words[i], &words[j]);
			i++;
			j--;
		}
		if (left < j) quickSort(words, left, j);
		if (i < right) quickSort(words, i, right);
	}
}
//

//search
int linearSearch(WORD words[], int n, char key[]){
 	for (int i=0; i<n; i++){
 		if (strcmp(words[i].name, key) == 0) return i+1; 
	}
	
 	return -1;
}

int binarySearch(WORD words[], int left, int right,char key[]){
	if (left > right) return -1;
	int mid = (left+right) /2;
	if (strcmp(key, words[mid].name) == 0) return mid+1;
	if (strcmp(key, words[mid].name) < 0) return binarySearch(words, left, mid-1, key);
	if (strcmp(key, words[mid].name) > 0) return binarySearch(words, mid+1, right, key);
}
//


int main(){
	int n;
	printf("Nhap n: "); scanf("%d", &n);	
	WORD words[n];

	nhap(words, n);
//	interchangeSort(words, n);
//	bubbleSort(words, n);
//	interchangeSort(words, n);
//	selectionSort(words, n);
	quickSort(words, 0, n-1);
	xuat(words, n);
	
	char key[256];
	printf("Nhap tu can tim: "); scanf("%s", &key);
//	int kq = linearSearch(words, 0, n-1, key);
	int kq = binarySearch(words, 0, n-1, key);
	printf("Tim thay %s o vi tri %d.\n", key, kq);
	return 0;
}
