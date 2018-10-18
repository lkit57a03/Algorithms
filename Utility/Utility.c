#include "Utility.h"

int numOfElement = 0;

int * generateRandomArray(int startFrom,int endTo){
    numOfElement = endTo - startFrom + 1;
    int * randomArray = malloc(sizeof(int) * numOfElement);
    srand(time(NULL));
    for(int i = 0;i < numOfElement;i++){
        randomArray[i] = random()%endTo + startFrom + 1;
    }

//    printf(" -- \n%d , %ld\n",numOfElement,sizeof(randomArray));

    return randomArray;
}

void printAllElem(int * list,int numOfElement){
    if(numOfElement  == 0){
        printf("Please Enter the Size of the Element.");
        return;
    }
    for(int i = 0; i <= numOfElement;i++){
        printf("\n%d,%d",i,list[i]);
    }   
}


int getARandomNumberFromTheList(int * list){
    srand(time(NULL));
    int randomInt = random()%numOfElement;

    // printf("Taking Random Number from Place %d which is %d",randomInt,list[randomInt]);

    return list[randomInt];
}
int getARandomNumber(int size){
    srand(time(NULL));
    int randomInt = random()%size;
    return randomInt;
}

void swap(int * list,int i, int j){
    int temp = list[i];
    list[i]  = list[j];
    list[j]  = temp;
}


int * generateOddEvenValues(int numberOfElem,bool Odd){
    int * arr = malloc(numberOfElem * sizeof(int));
    if(Odd == true){
        int k = 1;
        for(int i = 0;i <= numberOfElem;i++){
            arr[i] = k;
            k += 2;
        }
    }else {
        int k = 0;
        for(int i = 0;i <= numberOfElem;i++){
            arr[i] = k;
            k += 2;
        }
    }
    return arr;
}


bool checkIfSorted(int * list,int size){
    for(int i = 0;i < size;i++){
        if(list[i] > list[i + 1]){
            printf("The Array is not Sorted.");
            return false;
        }
    }
    printf("The Array is Sorted.");
    return true;
}