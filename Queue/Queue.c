#include "Queue.h"

Queue * init(int capacity){
    Queue * queue = (Queue *)malloc(sizeof(Queue));
    queue->stackArr = malloc(capacity*sizeof(int));
    queue->capacity = capacity;
    queue->first = queue->last = 0;
    return queue;
}
bool Enqueue(Queue * queue,int val){
    if(queue->last == queue->capacity){
        printf("Queue is Full");
        return false;
    }else{
        queue->stackArr[queue->last] = val;
        queue->last++;
    }
}
int Dequeue(Queue * queue){
    int temp;
    if(queue->first == queue->last){
        printf("Queue is Empty");
        return 0;
    }else {
        temp = queue->stackArr[queue->first]; 
        queue->stackArr[queue->first] = 0;
        queue->first++;
    }
    return temp;
}
int Front(Queue * queue){
    return queue->stackArr[queue->first];
}
int Rare(Queue * queue){
    return queue->stackArr[queue->last];
}

void reset(Queue * queue){
    queue->first = queue->last = 0;
}