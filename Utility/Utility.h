#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include<stdbool.h>
int * generateRandomArray(int startFrom,int endTo);

int getARandomNumberFromTheList(int * list);

void printAllElem(int * list,int numberOfElement);

void swap(int * list,int i, int j);

int getARandomNumber(int size);


int * generateOddEvenValues(int numberOfElem,bool Odd);

bool checkIfSorted(int * list,int size);
