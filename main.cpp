#include <iostream>
#include <vector>
#include "Sorting.h"
#include "cmdline.h"
#include "FileHandler.h"

int main(int argc, char* argv[]) {

    cmdline::parser a;

    a.add<std::string>("input", 'i', "input file", true, "");

    a.add<std::string>("algorithm", 'o', "sort algorithm to use", true, "");

    a.add<std::string>("output", 'o', "output file", true, "resultado.txt");

    a.parse_check(argc, argv);

    std::cout << a.get<std::string>("input") << ", "
         << a.get<std::string>("algorithm") << ", "
         << a.get<std::string>("output") << std::endl;


    exit(0);


    std::FILE* file = FileHandler::openByFilename("numeros.txt", "rb");

    std::FILE* binFile =  FileHandler::txtToBinary(file);

    long length = FileHandler::getSize(binFile) / sizeof(int);

    PagedArray par = PagedArray(binFile);

    Sorting::quickSort(&par, 0, (int) (length - 1));

    Sorting::selectionSort(&par, (int) (length));

    Sorting::insertionSort(&par, (int) (length));


    par.cleanup();

    return 0;
}