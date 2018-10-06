#include <stdio.h>
#include "../Utility/Utility.h"
#define SIZE 100

int main(int argv,char** argc){
// Linear Search
    int j;
    int * list = generateRandomArray(1,SIZE);
    printAllElem(list);
    for(int i = SIZE;i > 0; i--){
        j = i - 1;
        while(j > 0){
            if(list[i] < list[j]){
                swap(list,i,j);
            }
            j--;
        }
    }

    printAllElem(list);
    return 0;
}