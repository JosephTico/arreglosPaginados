//
// Created by joseph on 2/20/17.
//

#include "FileHandler.h"
#include <iostream>
#include <fstream>
using namespace std;




bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}


std::FILE* FileHandler::createTempFile() {
    std::FILE* tmpf = std::tmpfile();
    return tmpf;
}


std::FILE* FileHandler::openByFilename(string filename, string mode) {

    std::FILE *pFile;

    if (!is_file_exist(filename.c_str()) || (pFile = std::fopen(filename.c_str(), mode.c_str())) == NULL)  {
        cout << "Couldn't open file: " + filename << endl;
        exit(101);
    };


    return pFile;
}


void FileHandler::txtToBinary(std::FILE* file) {

    int charCode;
    std::fseek(file, 0, SEEK_SET);

    string tmpNum;

    std::FILE *binFile = FileHandler::openByFilename("file.bin", "wb");

    while ((charCode = std::fgetc(file)) != EOF) {

        char charData = (char) charCode;

        if (charCode == 44 || charCode == 32) { // Check if it's a comma (ascii code 44) or space (code 32)
            std::cout << tmpNum << std::endl;

            std::cout << std::stoi(tmpNum) << std::endl;
            FileHandler::writeNumtoBin(binFile, std::stoi(tmpNum));
            tmpNum = "";
            continue;
        }

        tmpNum += charData;

    }

    if (tmpNum != "") {
        std::cout << std::stoi(tmpNum) << std::endl;
        FileHandler::writeNumtoBin(binFile, std::stoi(tmpNum));
    }


}


void FileHandler::writeNumtoBin(std::FILE* file, int num) {

    std::fseek(file, 0, SEEK_END);

    fwrite(&num, sizeof(int), 1, file);
}


void FileHandler::writeNumbers(string filename) {

    std::FILE *pFile = FileHandler::openByFilename(filename, "wb");

    // It checks if the file exists first and THEN tries to open the file. The other way around would create the file.



    int arr[] = {1,2,3,44,5,6,7,999,99999,9999999,99999999};

    int arrSize = sizeof(arr) / sizeof(int);

    for (int i = 0; i < arrSize; ++i) {
        //Some calculations to fill a[]
        //cout << &arr[i] << endl;
        fwrite(&arr[i], sizeof(int), 1, pFile);
    }


    fclose(pFile);
}


int *FileHandler::readNumbers(string filename, int start, int length) {

    std::FILE *pFile = FileHandler::openByFilename(filename, "rb");

    // Must be in heap because of the non-constant array size.
    static int* result;
    result = (int*) malloc(length * sizeof(int));


    std::fseek(pFile, sizeof(int) * start, SEEK_SET);



    for (int i = 0; i < length; i++){
        std::fread(&result[i], sizeof(int), 1, pFile);
    }


    std::fclose(pFile);

    return result;
}