#include <iostream>
#define MAX_SIZE 1000

typedef int DataType;

struct Stack {
    double  list[MAX_SIZE];
    int   top;
};

void Init(Stack &s){
	s.top = -1;
}

int isFull(Stack s){
    return s.top == MAX_SIZE-1 ? 1 : 0;
}

void Push(Stack &s, double x){
    if (isFull(s)) return;
    s.list[++s.top] = x;
}

void Pop(Stack &s){
    if (s.top == -1){
        return;
    }
    else
        s.list[s.top--];
}

void StackFile(string fn, Stack &s){
    ifstream f;
    f.open(fn.c_str(), ios::in);
    double x;
    while(f >> x){
        Push(s, x);
    }
    f.close();
}

void Capacity(Stack s){
    Stack tmp;
    Init(tmp);
    for (int i=0; i<=s.top; i++){
        if (s.list[i] >= 0){
            Push(tmp, s.list[i]);
        }
        else {
            Pop(tmp);
        }
    }

    printf("%d", ++tmp.top);
}
