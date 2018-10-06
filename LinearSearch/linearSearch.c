#include <stdio.h>
#include "../Utility/Utility.h"

int main(int argv,char** argc){

    int * list = generateRandomArray(1,9);

    int toSearch = getARandomNumberFromTheList(list);
    // Linear Search
    for(int i = 0; i < 5;i++){
        if(list[i] == toSearch){
            printf("Found %d at %d",list[i],i);
            break;
        }
    }
    return 0;
}