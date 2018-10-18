#include"CircularQueue.h"
int main(){
    CircularQueue * CircularQueue = init(5);
    EnCircularQueue(CircularQueue,20);
    EnCircularQueue(CircularQueue,30);
    EnCircularQueue(CircularQueue,50);
    printf("%d",DeCircularQueue(CircularQueue));
    printf("%d",DeCircularQueue(CircularQueue));
    printf("%d",DeCircularQueue(CircularQueue));
}