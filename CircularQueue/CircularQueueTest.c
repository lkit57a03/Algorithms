#include"CircularQueue.h"
int main(){
    CircularQueue * CircularQueue = init(50);
    EnCircularQueue(CircularQueue,20);
    EnCircularQueue(CircularQueue,30);
    EnCircularQueue(CircularQueue,50);
    EnCircularQueue(CircularQueue,80);
    EnCircularQueue(CircularQueue,90);
    printf("%d",DeCircularQueue(CircularQueue));
    printf("%d",DeCircularQueue(CircularQueue));
    printf("%d",DeCircularQueue(CircularQueue));
}