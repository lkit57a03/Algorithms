#include"../Utility/Utility.h"
#include"../BinarySearch/BinarySearch.h"
void removeElem(int pos,int* arr,int size){
    
    for(int i = pos; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    
}
int main(){
    int size = 100;
    int * arr = generateRandomArray(0, size);
    int randomVar = getARandomNumberFromTheList(arr);
    qsort(arr,size,sizeof(int),comparator);
    int pos = BinarySearch(0,size,randomVar,arr);
}
