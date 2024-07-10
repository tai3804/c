#include <stdio.h>

void test(int **ptr){
    printf("%d\n", ptr);
    printf("%d\n", *ptr);
    printf("%d\n", **ptr);
    printf("\n");
}

int main(){
    int i=0, *ptr = &i;
     
    printf("&i = %d\n", &i);
    printf("&ptr = %d\n", &ptr);
    test(&ptr);
}