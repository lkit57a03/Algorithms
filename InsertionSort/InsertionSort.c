#include "../Utility/Utility.h"
#define SIZE 100

int main(int argv,char** argc){
// Linear Search
int j , elem;
    int * list = generateRandomArray(1,SIZE);
    
    for (int i = 0; i <= SIZE;i++){
        elem = list[i];
        j = i - 1;
        while(j >= 0 && list[j] > elem){
            list[j + 1] = list[j];
            j = j-1;
        }
    list[j + 1] = elem;
    }    
    printAllElem(list,SIZE);
    return 0;
}