#include <stdio.h>

#define N 1000

struct Stack {
    int list[N];
    int top;
};

void init(struct Stack &s) {
    s.top = -1;
}

int empty(struct Stack s) {
    return s.top == -1 ? 1 : 0;
}

int isFull(struct Stack s) {
    return s.top >= N - 1 ? 1 : 0;
}

void push(struct Stack &s, int x) {
    if (!isFull(s)) {
        s.list[++s.top] = x;
    }
}

int pop(struct Stack &s) {
    return empty(s) ? -1 : s.list[s.top--];
}

int main() {
    Stack s;
    init(s);

    push(s, 42);
    push(s, 17);

    return 0;
}

