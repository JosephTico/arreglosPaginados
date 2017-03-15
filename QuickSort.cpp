//
// Created by joseph on 2/19/17.
//

#include <iostream>
#include "QuickSort.h"

void QuickSort::sort() {

    int SIZE = 10;
    int myInts[SIZE] = { 1,4,0,2,1,4,6,9,7,3};

    int pivot = myInts[SIZE - 1];

    std::cout << std::to_string(pivot) << std::endl;

}
