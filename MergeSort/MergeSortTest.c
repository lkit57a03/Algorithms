#include "../Utility/Utility.h"
#include "MergeSort.h"
#define SIZE 100

int main(int argv,char** argc){
    int * list = generateRandomArray(1,SIZE);
    checkIfSorted(list,SIZE);
    merge_sort(list,0,SIZE);
    checkIfSorted(list,SIZE);
}