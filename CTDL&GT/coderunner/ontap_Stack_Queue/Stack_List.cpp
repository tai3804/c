#include <stdio.h>
#define MAX_SIZE 1000

typedef int DataType;

struct Stack {
    DataType  list[MAX_SIZE];
    int   top;
};

#define MAX_SIZE 1000

typedef int DataType;

struct Stack {
    DataType  list[MAX_SIZE];
    int   top;
};

void Init(Stack &s){
	s.top = -1;
}

int isFull(Stack s){
    return s.top == MAX_SIZE-1 ? 1 : 0;
}

void Push(Stack &s, int x){
    if (isFull(s)) return;
    s.list[++s.top] = x;
}

void Pushes(Stack &s, int a[], int n){
    for (int i=0; i<n; i++){
        Push(s, a[i]);
    }
}

void Pop(Stack &s){
    if (s.top == -1){
        printf("Emptied Stack\n");
    }
    else
        printf("%d\n", s.list[s.top--]);
}

void Popes(Stack &s, int outs){
    while (outs-- != 0){
        Pop(s);
    }
}

void Capacity(Stack s){
    printf("%d", ++s.top);
}

void PrintStack(Stack s){
	for (int i=0; i<=s.top; i++){
		printf("%d", s.list[i]);
	}
}

int main(){
	Stack s;
	Init(s);
	Push(s, 10);
	PrintStack(s);
	return 0;
}
