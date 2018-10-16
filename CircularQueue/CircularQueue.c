#include "CircularQueue.h"

CircularQueue * init(int capacity){
    CircularQueue * circularQueue = (CircularQueue *)malloc(sizeof(CircularQueue));
    circularQueue->stackArr = malloc(capacity*sizeof(int));
    circularQueue->capacity = capacity;
    circularQueue->first = circularQueue->last = -1;
    return circularQueue;
}

bool isFull(CircularQueue * circularQueue){
    if(circularQueue->first == 0 && circularQueue->last == circularQueue->capacity -1){
        return true;
    }else if(circularQueue->first == circularQueue->last + 1){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(CircularQueue * circularQueue){
    return circularQueue->first == -1;
}

bool EnCircularQueue(CircularQueue * circularQueue,int val){
    if(isFull(circularQueue)){
        printf("CircularQueue is Full");
        return false;
    }else{
        if(circularQueue->first == -1) circularQueue->first = 0;
        circularQueue->last = (circularQueue->last + 1)%circularQueue->capacity;
        circularQueue->stackArr[circularQueue->last] = val;
    }
}
int DeCircularQueue(CircularQueue * circularQueue){
    int temp;
    if(isEmpty(circularQueue)){
        printf("CircularQueue is Empty");
        return 0;
    }else {
        temp = circularQueue->stackArr[circularQueue->first]; 
        if (circularQueue->first == circularQueue->last){
            circularQueue->first = circularQueue->last = -1;
        }else{
        circularQueue->stackArr[circularQueue->first] = 0;
        circularQueue->first  = (circularQueue->first + 1)% circularQueue->capacity;
        }
    }
    return temp;
}
int Front(CircularQueue * circularQueue){
    return circularQueue->stackArr[circularQueue->first];
}
int Rare(CircularQueue * circularQueue){
    return circularQueue->stackArr[circularQueue->last];
}

void reset(CircularQueue * circularQueue){
    circularQueue->first = circularQueue->last = -1;
}
