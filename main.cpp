#include <iostream>
#include "QuickSort.h"
#include "PagedArray.h"
#include "FileHandler.h"

int main() {

    //std::cout << std::to_string(PagedArray::getValue(9000)) << std::endl;

   // QuickSort::sort();

    std::FILE* file = FileHandler::openByFilename("numeros.txt", "rb");

    std::FILE* binFile =  FileHandler::txtToBinary(file);

    PagedArray par = PagedArray(binFile);

    std::cout << par[0] << std::endl;

    std::cout << par[1] << std::endl;

    std::cout << par[2] << std::endl;

    std::cout << par[3] << std::endl;



    //std::cout << result[2560] << std::endl;


    //FileHandler::writeNumbers("file.bin");
//    int *result = FileHandler::readNumbers("file.bin", 0, 2559);
//
//    std::cout << sizeof(&result) / sizeof(int) << std::endl;
//
//    std::cout << result[3] << std::endl;
//
//    PagedArray par;
//
//    int res = par[511];
//
//    //std::cout << res <<  std::endl;
//
//    free(result);

    return 0;
}