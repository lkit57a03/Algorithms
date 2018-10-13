#include "../Utility/Utility.h"
#define SIZE 100

int partition(int* list,int start,int end){
    int i = start + 1;
    int piv = list[start];

    for(int j = start + 1;j < end;j++){
        if(list[j] < piv){
            swap(list,i,j);
            i += 1;
        }
    } 
    swap(list,start,i-1);
    return i-1;
}

void QuickSort(int * list, int start,int end){
    if(start < end){
        int piv_pos = partition(list,start,end);
        QuickSort(list,start,piv_pos - 1);
        QuickSort(list,piv_pos + 1, end);
    }
}

int main(int argv,char** argc){
// Linear Search
    int flag = 1;
    int * list = generateRandomArray(1,SIZE);
    printAllElem(list);
    printf("\nSorted:\n");
    QuickSort(list,0,SIZE);
    printAllElem(list);
    return 0;
}





// int partition(int * list,int start,int end){
//     int i = start + 1;
//     int piv = list[start];
//     for(int j = start + 1;j < end;j++){
//     printf("\n i - %d \n piv - %d\n list[start] - %d",i,piv,list[start]);
//         printf("\n Cheacking that \n list[j] < piv\n %d  <  %d \n Where j = %d\n\n ",list[j],piv,j);
//         if(list[j] < piv){
//             printf("True");
//             swap(list,i,j);
//             i += 1;
//         }
//         printf("\n i = %d\n",i);
//         printAllElem(list);
//     }
//     swap(list,start,i-1);
//     return i - 1;
// }