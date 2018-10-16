#include "../Utility/Utility.h"
#define SIZE 100

int main(int argv,char** argc){
    int * list = generateRandomArray(1,SIZE);
    printAllElem(list,SIZE);
    printf("\nSorted Array\n");
    merge_sort(list,1,SIZE);
    printAllElem(list,SIZE);
}