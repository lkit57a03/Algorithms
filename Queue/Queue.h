#include "../Utility/Utility.h"

typedef struct Queue {
    int * stackArr;
    int first,last;
    int capacity;
}Queue;

Queue * init(int capacity);
bool Enqueue(Queue * queue,int val);
int Dequeue(Queue * queue);
int Front(Queue * queue);
int Rare(Queue * queue);
void reset(Queue * queue);