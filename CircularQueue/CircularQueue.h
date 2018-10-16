#include "../Utility/Utility.h"

typedef struct CircularQueue {
    int * stackArr;
    int first,last;
    int capacity;
}CircularQueue;

CircularQueue * init(int capacity);
bool EnCircularQueue(CircularQueue * circularQueue,int val);
int DeCircularQueue(CircularQueue * circularQueue);
int Front(CircularQueue * circularQueue);
int Rare(CircularQueue * circularQueue);
bool isFull(CircularQueue * circularQueue);
bool isEmpty(CircularQueue * circularQueue);