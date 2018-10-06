#include <stdio.h>
#include "../Utility/Utility.h"
#define SIZE 100

int main(int argv,char** argc){
// Linear Search
int j , elem;
    int * list = generateRandomArray(1,SIZE);
    for (int i = 0; i < SIZE;i++){
        //Sorted
        j = i - 1;

        while(list[i] < list[j]){
            swap(list,i,j);
            i = j;
            j--;
        }
    }
    printAllElem(list);
    return 0;
}