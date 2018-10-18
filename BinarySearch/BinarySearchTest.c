#include "BinarySearch.h"

int main(int argv,char** argc){
    int * list = generateRandomArray(1,SIZE);
    int randomNumberInTheList = getARandomNumberFromTheList(list);
    //Remember to sort it;
    qsort(list,SIZE,sizeof(int),comparator);
    printf("\n To find : %d \n It is in place : %d\n",randomNumberInTheList,BinarySearch(0,SIZE,randomNumberInTheList,list));
    printAllElem(list,SIZE);
    return 0;
}