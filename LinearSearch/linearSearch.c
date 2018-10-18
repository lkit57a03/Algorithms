#include "../Utility/Utility.h"

int main(int argv,char** argc){
    int SIZE = 100;
    int * list = generateRandomArray(0,SIZE);

    int toSearch = getARandomNumberFromTheList(list);
    // Linear Search
    for(int i = 0; i < SIZE;i++){
        if(list[i] == toSearch){
            printf("Found %d at %d",list[i],i);
            break;
        }
    }
    return 0;
}