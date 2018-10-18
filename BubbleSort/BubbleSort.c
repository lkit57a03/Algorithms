#include "../Utility/Utility.h"
#define SIZE 100

int main(int argv,char** argc){
// Linear Search
    int flag = 1;
    int * list = generateRandomArray(1,SIZE);
    printAllElem(list,SIZE);

    while(flag == 1){
        flag = -1;
        for(int i = 0;i < SIZE;i++){
            if(list[i] > list[i + 1]){
                swap(list,i,i+1);
                flag = 1;
            }
        }
    }

    printAllElem(list,SIZE);
    return 0;
}