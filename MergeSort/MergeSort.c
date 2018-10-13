#include "../Utility/Utility.h"
#define SIZE 100

//Define Merge Subroutine
void merge(int A[ ] , int start, int mid, int end) {
 //stores the starting position of both parts in temporary variables.
    int p = start ,q = mid+1;

    int Arr[end-start+1] , k=0;

    for(int i = start ;i <= end ;i++) {
        if(p > mid)      //checks if first part comes to an end or not .
            Arr[ k++ ] = A[ q++] ;
        else if ( q > end)   //checks if second part comes to an end or not
            Arr[ k++ ] = A[ p++ ];
        else if( A[ p ] < A[ q ])     //checks which part has smaller element.
            Arr[ k++ ] = A[ p++ ];
        else
            Arr[ k++ ] = A[ q++];
 }
  for (int p=0 ; p< k ;p ++) {
   /* Now the real array has elements in sorted manner including both 
        parts.*/
     A[ start++ ] = Arr[ p ] ;                          
  }
}

void merge_sort(int * list,int start,int end){
    if(start < end){
        int middle = (start + end)/2;
        merge_sort(list,start,middle);
        merge_sort(list,middle + 1,end);
        merge(list,start,middle,end);
    }
}
int main(int argv,char** argc){
    int * list = generateRandomArray(1,SIZE);
    printAllElem(list);
    printf("\nSorted Array\n");
    merge_sort(list,1,SIZE);
    printAllElem(list);
}