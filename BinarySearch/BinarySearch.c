#include "BinarySearch.h"

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