#include <stdio.h>
#include <string.h>

typedef struct WORD {
	char name[256];
	char meaning[512];
} WORD;

void readData(char fn[], WORD w[], int &n){
	FILE *f = fopen(fn, "r");
	if (!f){
		printf("khong the mo file!");
		return;
	}
	
	char line[512];
	n=0;
	while (fgets(line, 512, f) != NULL){
		char *tokken = strtok(line, ",");
		strcpy(w[n].name, tokken);
		tokken = strtok(NULL, ",");
		if (tokken != NULL)
			strcpy(w[n].meaning, tokken);
		n++;
	}
}

int main(){
	int n=10;
	char fn[10] = "test.txt";
	WORD w[n];
	readData(fn, w, n);
	for (int i=0; i<n; i++){
		printf("%s %-s", w[i].name, w[i].meaning);
	}
	
	return 0;
}
