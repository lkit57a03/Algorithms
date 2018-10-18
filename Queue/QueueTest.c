#include"Queue.h"
int main(){
    Queue * queue = init(5);
    Enqueue(queue,20);
    Enqueue(queue,30);
    Enqueue(queue,50);
    Enqueue(queue,80);
    Enqueue(queue,90);
    printf("%d",Dequeue(queue));
    printf("%d",Dequeue(queue));
    printf("%d",Dequeue(queue));
}