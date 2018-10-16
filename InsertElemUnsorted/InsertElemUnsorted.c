#include"../Utility/Utility.h"

int * removeElem(int * arr,int index,int elem,int * SIZE){
    int * tempArr = realloc(arr,(*SIZE + *SIZE/4) * sizeof(int));
    for(int i = 0; i < *SIZE; i++)
    {
        if(i == index){
            tempArr[i] = elem;
        }else{
            tempArr[i] = arr[i];
        }
    }
    free(arr);
    return(tempArr);
}
int main(){
    int SIZE = 100;
    int *arr = generateRandomArray(0,SIZE);
    int index = getARandomNumber(SIZE);
    int elem = getARandomNumber(time(NULL));
    arr = removeElem(arr,index,elem,&SIZE);   
}