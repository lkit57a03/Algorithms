#include "../../Utility/Utility.h"
#define SIZE 100
#include <stdbool.h>
struct maxPQ{
    int * maxPQArray;
    int size;
    int pointer;
};

void swim(int k,struct maxPQ PQ){
    while(k > 1 && PQ.maxPQArray[k/2] < PQ.maxPQArray[k]){
        swap(PQ.maxPQArray,k , k/2);
        k = k / 2;
    }
}
void sink(int k,struct maxPQ PQ){
    while(2*k <= PQ.size){
        int j = 2 * k;
        if (j < PQ.size && PQ.maxPQArray[j] < PQ.maxPQArray[j + 1]) j++;
        if (!(PQ.maxPQArray[k] < PQ.maxPQArray[j])) break;
        swap(PQ.maxPQArray,k,j);
        k = j;
    }
}

struct maxPQ generateRandomPQ(struct maxPQ PQ){
    PQ.size = SIZE;

    PQ.maxPQArray = generateRandomArray(0,SIZE);

    for(int k = PQ.size / 2; k >= 1;k++){
        sink(k,PQ);
    }
    PQ.pointer = PQ.size;
}
int * resize(struct maxPQ PQ,int capacity){
    if(capacity > PQ.size){
        PQ.maxPQArray = (int *)realloc(PQ.maxPQArray,capacity * sizeof(int));
    }
    PQ.size = capacity;
    return PQ.maxPQArray;
}

bool isMaxHeap(int k,struct maxPQ PQ){
    if(k > PQ.size) return true;
    int left = 2 * k;
    int right= 2 * k + 1;
    if(left < PQ.size && PQ.maxPQArray[k] < PQ.maxPQArray[left]) return false;
    if(right < PQ.size && PQ.maxPQArray[k] < PQ.maxPQArray[right]) return false;
    return isMaxHeap(right,PQ) && isMaxHeap(left,PQ);
}
void insert(int k,struct maxPQ PQ){
    if(PQ.size ==  SIZE - 1) resize(PQ,2 * PQ.size);
    PQ.maxPQArray[++PQ.pointer] = k;
    swim(PQ.pointer,PQ);
    //static_assert(isMaxHeap(PQ.pointer,PQ));
}
int deleteMax(struct maxPQ PQ){
    int max = PQ.maxPQArray[0];
    swap(PQ.maxPQArray,0,PQ.pointer--);
    sink(0,PQ);
    PQ.maxPQArray[PQ.pointer + 1] = 0;
    if((PQ.pointer > 0) && (PQ.pointer == (PQ.size - 1)/4)) resize(PQ,PQ.size/2);
    //static_assert(isMaxHeap(0,PQ));
    return max;
}
int main(int argv,char * argc){
    struct maxPQ PQ;
    generateRandomPQ(PQ);
    printf("Hello World");
    return 0;
}