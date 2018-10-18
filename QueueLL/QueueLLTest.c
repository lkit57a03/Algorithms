#include"QueueLL.h"
int main(){
    Queue * Queue = initQueue(5);
    EnQueue(8);
    EnQueue(18);
    printf("\n%d\n",DeQueue());
    printf("\n%d\n",DeQueue());
}