#include "../Utility/Utility.h"
#include "../MergeSort/MergeSort.h"
int main(){
    int size = 100;
    int * OddArray = generateOddEvenValues(size,true);
    int * EvenArray= generateOddEvenValues(size,false);
    int * OddAndEvenArray = malloc(sizeof(int) * size * 2);
    
    for(int i = 0; i <= size; i++)
    {
        OddAndEvenArray[i] = OddArray[i];
    }
    
    for(int i = size + 1, k = 0; i <= size * 2; i++, k++)
    {
        OddAndEvenArray[i] = EvenArray[k];
    }
    checkIfSorted(OddAndEvenArray,size * 2);
    merge(OddAndEvenArray,0,size,size *   2);
    checkIfSorted(OddAndEvenArray,size * 2);
}

/*#include "../Utility/Utility.h"
#include "../MergeSort/MergeSort.h"

int main(){
    int size = 100;
    int * OddArray = generateOddEvenValues(size,true);
    int * EvenArray= generateOddEvenValues(size,false);
    int * OddAndEvenArray = malloc(sizeof(int) * size * 2);
    
    for(int i = 0; i <= size; i++)
    {
        OddAndEvenArray[i] = OddArray[i];
    }
    
    for(int i = size + 1, k = 0; i <= size * 2; i++, k++)
    {
        OddAndEvenArray[i] = EvenArray[k];
    }
    
    
    
    printf("\nODD And Even ARRAY\n");
    printAllElem(OddAndEvenArray,size * 2);
    merge(OddAndEvenArray,0,size - 1,size * 2);
    printAllElem(OddAndEvenArray,size * 2);
    
}*/