#include <stdio.h>
#include <stdlib.h>

using namespace std;
typedef int DataType;

struct DNode
{
    DataType data;     
    DNode* pPrev;     // tr? d?n ph?n t? d?ng tru?c
    DNode* pNext;    // tr? d?n ph?n t? d?ng sau
};

struct DList
{
    DNode* pHead;     // tr? d?n ph?n t? d?u ds
    DNode* pTail;        // tr? d?n ph?n t? cu?i ds
};

//khoi tao
void Init(DList &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

//tao node
DNode* getDNode(int data){
    DNode* dNode = new DNode;
    dNode->data = data;
    dNode->pNext=NULL;
    dNode->pPrev=NULL;
    
    return dNode;
}

// them
void insertLast(DList &dl, int data){
    DNode *dNode = getDNode(data);
    if (dl.pHead == NULL){
        dl.pHead = dl.pTail = dNode;
        return;
    }
    dl.pTail->pNext = dNode;
    dNode->pPrev = dl.pTail;
    dl.pTail = dNode;
}
 
void DListAppend(DList &dl, int a[], int n){
	for (int i=0; i<n; i++){
		insertLast(dl, a[i]);
	}
}

void insertFirst(DList &dl, int data){
    DNode *dNode = getDNode(data);
    if (dl.pHead == NULL){
        dl.pHead = dl.pTail = dNode;
        return;
    }
    dNode->pNext = dl.pHead;
    dl.pHead->pPrev = dNode;
    dl.pHead = dNode;
}

int DListInsertAfterKey(DList &dl, int k, int value){
    DNode* newDNode = getDNode(value);
    DNode* temp = dl.pHead;
	if (dl.pHead == NULL){
		dl.pHead = dl.pTail = newDNode;
		return -1;
	}
    if (dl.pTail->data == k){
        insertLast(dl, value);
        return 1;
    }
    while (temp->pNext != NULL){
    	if (temp->data == k){
    		newDNode->pNext = temp->pNext;
    		newDNode->pPrev = temp;
    		temp->pNext->pPrev = newDNode;
    		temp->pNext = newDNode;
    		return 1;
		}
    	temp = temp->pNext;
	}
	
	insertFirst(dl, value);
    return -1;
}

int DListInsertBeforeKey(DList &dl, int k, int value){
	DNode* newDNode = getDNode(value);
	if (dl.pHead == NULL){
		dl.pHead = dl.pTail = newDNode;
		return -1;
	}
    if (dl.pHead->data == k){
        insertFirst(dl, value);
        return 1;
    }
    DNode* temp = dl.pHead;
    while (temp != NULL){
    	if (temp->data == k){
    		newDNode->pNext = temp;
    		newDNode->pPrev = temp->pPrev;
    		temp->pPrev->pNext = newDNode;
    		temp->pPrev = newDNode;
    		return 1;
		}
    	temp = temp->pNext;
	}
	
	insertFirst(dl, value);
    return -1;
}

DNode* InsertHead(DList &dl, int data){
	insertFirst(dl, data);
	return dl.pHead;
}

// xoá
int RemoveHead(DList &dl){
    if (dl.pHead == NULL) return -1;
    
    DNode* dNode = dl.pHead;
    dl.pHead = dl.pHead->pNext;
    free(dNode);
    
    return 1;
}

int RemoveTail(DList &dl){
    if(dl.pHead == NULL) return -1;
    if (dl.pHead == dl.pTail){
        free(dl.pTail);
        dl.pHead = dl.pTail = NULL;
        
        return 1;
    }
    
    DNode* tmp = dl.pTail;
    dl.pTail = dl.pTail->pPrev;
    dl.pTail->pNext = NULL;
    free(tmp);
    
    return 1;
}
// show
void DListShow(DList dl){
    while(dl.pHead != NULL){
    	printf("%d ",dl.pHead->data);
    	dl.pHead = dl.pHead->pNext; 
	}
}

void DListShowHeads(DList dl, int h){
    while (h-- && dl.pHead != NULL){
        printf("%d ", dl.pHead->data);
        dl.pHead = dl.pHead->pNext;
    }
}

void DListShowTails(DList dl, int h){
    while(h-- && dl.pTail != NULL){
        printf("%d ", dl.pTail->data);
        dl.pTail = dl.pTail->pPrev; 
    }
}

int main(){
	DList DL;    
	Init(DL);
	int n = 3, h = 5;
	DataType Arr[] = {1, 2, 3, 4, 5};
	DListAppend(DL,Arr,n);
	int res = RemoveHead(DL);
	DListShowHeads(DL,h);
	return 0;
}
