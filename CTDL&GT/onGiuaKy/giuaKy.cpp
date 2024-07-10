#include <bits/stdc++.h>

struct WORD {
	char Name[256];
	char Meaning[512];
};

void writeWord(WORD w);
void printWord(WORD w);
void printWords(WORD ws[], int n);
void writePrimaryData_WORD(char fn[]);
void readPrimaryData_WORD(char fn[], WORD w[], int &n);
void writeBinaryData_WORD(char fn[]);
void readBinaryData_WORD(char fn[], WORD w[], int &n);

int main(){
	char fn[20] = "binaryData.txt";
	WORD ws[1000];
	int n=0;
	
	writeBinaryData_WORD(fn);
	readBinaryData_WORD(fn, ws, n);
	printWords(ws, n);
	return 0;
}

void writeWord(WORD &w){
	printf("Enter Name: "); scanf("%s", w.Name);
	printf("Enter Meaning: "); fflush(stdin); gets(w.Meaning);
}

void printWord(WORD w){
	printf("%s : %s", w.Name, w.Meaning);
}

void printWords(WORD ws[], int n){
	for (int i=0; i<n; i++){
		printf("%d. ", i+1);
		printWord(ws[i]);
	}
}

void writePrimaryData_WORD(char fn[]){
	FILE *f = fopen(fn, "w");
	if (!f){
		printf("can't open file'!");
		return;
	}
	
	WORD w;
	char option;
	while (true){
		printf("Enter Name: "); scanf("%s", w.Name);
		printf("Enter Meaning: "); fflush(stdin); gets(w.Meaning);
		printf("Nhap tiep khong (y/n)? "); scanf("%c", &option);
		fprintf(f, "%s,%s\n", w.Name, w.Meaning);
		if (option == 'n') break;
	}
	fclose(f);
}

void readPrimaryData_WORD(char fn[], WORD w[], int &n){
	FILE *f = fopen(fn, "r");
	if (!f){
		printf("can't open file!");
		return;
	}
	
	char line[768];
	n=0;
	while (fgets(line, 768, f) != NULL){
		char *tok = strtok(line, ",");
		strcpy(w[n].Name, tok);
		tok = strtok(NULL, ",");
		if (tok != NULL){
			strcpy(w[n++].Meaning, tok);
		}
	}
	fclose(f);
}

void writeBinaryData_WORD(char fn[]) {
    FILE *f = fopen(fn, "wb");
    if (!f) {
        printf("Can't open file!");
        return;
    }

    WORD w;
    char option;
    while (true) {
        printf("Enter Name: ");
        scanf("%s", w.Name);
        getchar();
        
        printf("Enter Meaning: ");
        scanf("%s", w.Meaning);
        getchar();
        
        fwrite(&w, sizeof(w), 1, f);
        
        printf("Continue (y/n)? ");
        scanf("%c", &option);
        if (option != 'y')
            break;
    }
    fclose(f);
}


void readBinaryData_WORD(char fn[], WORD w[], int &n){
	FILE *f = fopen(fn, "rb");
	if(!f){
		printf("can't open file!");
	}	
	
	char line[768];
	n=0;
	while(fread(line, 768, 1, f) == 1){
		char *tok = strtok(line, ",");
		strcpy(w[n].Name, tok);
		tok = strtok(NULL, ",");
		if (tok != NULL){
			strcpy(w[n++].Meaning,tok);
		}
	}
	fclose(f);
}
