#include <stdio.h>
#include "../Utility/Utility.h"
#define SIZE 100

int BinarySearch(int start,int end,int toFind,int* list){
    int middle = start + (end - start) / 2;
    if(end >= start){
        if(list[middle] == toFind){
            return middle;
        }else if(list[middle] > toFind){
            return BinarySearch(start, middle - 1,toFind,list);
        }else if(list[middle] < toFind){
            return BinarySearch(middle + 1, end,toFind,list);
        }
    }else {
        return -1;
    }
}

int comparator(const void * a,const void * b){
    return ( *(int *)a - *(int * )b);
}

int main(int argv,char** argc){
// Linear Search
    int flag = 1;
    int * list = generateRandomArray(1,SIZE);
    int randomNumberInTheList = getARandomNumberFromTheList(list);
    //Remember to sort it;
    qsort(list,SIZE,sizeof(int),comparator);
    printf("\n To find : %d \n It is in place : %d\n",randomNumberInTheList,BinarySearch(0,SIZE,randomNumberInTheList,list));
    printAllElem(list);
    return 0;
}