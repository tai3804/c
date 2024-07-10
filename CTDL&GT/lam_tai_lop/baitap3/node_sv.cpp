#include <stdio.h>

typedef struct SINHVIEN{
	char maSV[10];
	char hoSV[20];
	char tenSV[20];
	int diem;
} SV;

sypedef struct Node{
	SV sv;
	Node *next;
} struct;

int main(){
	return 1;
}
