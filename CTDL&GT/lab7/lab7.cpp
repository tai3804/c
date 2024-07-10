#include <stdio.h>
#include <string.h>

#define MAXQUEUE 100

typedef struct mathang {
    int mamh;
    char tenmh[12];
} mathang;

struct queue {
    int front, rear;
    mathang nodes[MAXQUEUE];
};

void Initialize(struct queue* pq) {
    pq->front = pq->rear = MAXQUEUE - 1;
}

int empty(struct queue* pq) {
    return (pq->front == pq->rear);
}

void Insert(struct queue* pq, mathang x) {
    if (pq->rear == MAXQUEUE - 1) pq->rear = 0;
    else (pq->rear)++;
    if (pq->rear == pq->front) 
        printf("Kho hang bi day");
    else 
        pq->nodes[pq->rear] = x;
}

mathang Remove(struct queue* pq) {
    mathang emptyMathang = { -1, "" };
    if (empty(pq))
        printf("Kho khong con hang");
    else {
        if (pq->front == MAXQUEUE - 1) 
            pq->front = 0;
        else 
            (pq->front)++;
    }
    return pq->nodes[pq->front];
}

void traverse(struct queue* pq) {
    int i = pq->front;
    if (pq->front <= pq->rear) {
        while (i <= pq->rear) {
            printf("\n%11d%15s", pq->nodes[i].mamh, pq->nodes[i].tenmh);
            i++;
        }
    } else {
        while (i < MAXQUEUE) {
            printf("\n%11d%15s", pq->nodes[i].mamh, pq->nodes[i].tenmh);
            i++;
        }
        i = 0;
        while (i <= pq->rear) {
            printf("\n%11d%15s", pq->nodes[i].mamh, pq->nodes[i].tenmh);
            i++;
        }
    }
}

int main() {
    struct queue q;
    Initialize(&q);
    char c;
    int chucnang, front1;
    mathang mh;
    
    do {
        printf("\n\n\t\t\tCHUONG TRINH QUAN LY KHO");
        printf("\n\t\t\t(NHAP TRUOC - XUAT TRUOC)");
        printf("\n\nCac chuc nang cua chuong trinh:\n");
        printf("1: Nhap mot mat hang\n");
        printf("2: Xuat mot mat hang\n");
        printf("3: Xem mat hang chuan bi xuat\n");
        printf("4: Xem mat hang moi nhap\n");
        printf("5: Xem cac mat hang co trong kho\n");
        printf("6: Xuat toan bo kho hang\n");
        printf("0: Ket thuc chuong trinh\n");
        printf("Chuc nang ban chon: ");
        scanf("%d", &chucnang);

        switch (chucnang) {
            case 1:
                printf("\nMa mat hang: ");
                scanf("%d", &mh.mamh);
                printf("Ten mat hang: ");
                scanf("%s", mh.tenmh);
                Insert(&q, mh);
                break;
            case 2:
                if (!empty(&q)) {
                    mh = Remove(&q);
                    printf("\nMat hang xuat: Ma:%d, Ten:%s", mh.mamh, mh.tenmh);
                } else {
                    printf("\nKho khong con hang.\n");
                }
                break;
            case 3:
                if (!empty(&q)) {
                    front1 = (q.front == MAXQUEUE - 1) ? 0 : q.front + 1;
                    printf("\nMat hang chuan bi xuat: Ma:%d, Ten:%s", q.nodes[front1].mamh, q.nodes[front1].tenmh);
                } else {
                    printf("\nKho khong con hang.\n");
                }
                break;
            case 4:
                if (!empty(&q)) {
                    printf("\nMat hang moi nhap: Ma:%d, Ten:%s", q.nodes[q.rear].mamh, q.nodes[q.rear].tenmh);
                } else {
                    printf("\nKho khong con hang.\n");
                }
                break;
            case 5:
                printf("\nCac mat hang co trong kho:");
                printf("\n%11s%15s", "MA MAT HANG", "TEN MAT HANG");
                traverse(&q);
                break;
            case 6:
                printf("\nBan co chac khong (c/k): ");
                scanf(" %c", &c);
                if (c == 'c' || c == 'C') {
                    Initialize(&q);
                    printf("Da xuat toan bo kho hang.\n");
                }
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (chucnang != 0);

    return 0;
}
