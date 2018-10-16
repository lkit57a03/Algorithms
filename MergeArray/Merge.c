#include "../Utility/Utility.h"
#include "../MergeSort/MergeSort.h"
int main(){
    int size = 100;
    int * OddArr = generateOddEvenValues(size,true);
    int * EvenArr= generateOddEvenValues(size,false);
    int * OddEvenArr = malloc(2 * SIZE * sizeof(int));
    printAllElem(OddArr,SIZE);
    printAllElem(EvenArr,SIZE);

    for(int i = 0; i < size * 2; i++)
    {
        if(i < size){
            OddEvenArr[i] = OddArr[i];
        }else {
            OddEvenArr[i] = EvenArr[i % size]; 
        }
    }
    printAllElem(OddEvenArr,SIZE * 2);
    merge(OddEvenArr,0,size-1,size *   2);
    printAllElem(OddEvenArr,size * 2);
}