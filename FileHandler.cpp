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
    // It checks if the file exists first and THEN tries to open the file. The other way around would create the file.

    if (!is_file_exist(filename.c_str()) || (pFile = std::fopen(filename.c_str(), mode.c_str())) == NULL)  {
        cout << "Couldn't open file: " + filename << endl;
        exit(101);
    };


    return pFile;
}


std::FILE* FileHandler::txtToBinary(std::FILE* file) {

    int charCode;
    std::fseek(file, 0, SEEK_SET);

    string tmpNum;

    std::FILE *binFile = FileHandler::createTempFile();

    while ((charCode = std::fgetc(file)) != EOF) {

        char charData = (char) charCode;

        if (charCode == 44 || charCode == 32) { // Check if it's a comma (ascii code 44) or space (code 32)

            try {

                FileHandler::writeNumtoBin(binFile, std::stoi(tmpNum));

            } catch(std::invalid_argument&) {
                std::cout << "The input file contains invalid data" << std::endl;
                exit(102);
            }


            tmpNum = "";
            continue;
        }

        tmpNum += charData;

    }

    if (tmpNum != "") {
        FileHandler::writeNumtoBin(binFile, std::stoi(tmpNum));
    }


    return binFile;

}


void FileHandler::writeNumtoBin(std::FILE* file, int num) {

    std::fseek(file, 0, SEEK_END);

    fwrite(&num, sizeof(int), 1, file);
}


void FileHandler::writeNumbers(std::FILE* file, int* arr, int page) {

    int arrSize = sizeof(arr) / sizeof(int);


    std::fseek(file, sizeof(int) * page * arrSize, SEEK_SET);


    for (int i = 0; i < arrSize; ++i) {
        fwrite(&arr[i], sizeof(int), 1, file);
    }

}

void FileHandler::createFinalFile(std::FILE* binFile) {
    std::FILE* pFile = std::fopen("resultado.txt", "wb");



}


int *FileHandler::readNumbers(std::FILE *pFile, int start, int length) {

    // Must be in heap because of the non-constant array size.
    static int* result;
    result = (int*) malloc(length * sizeof(int));
    std::fill_n(result, length, -1);



    std::fseek(pFile, sizeof(int) * start, SEEK_SET);



    for (int i = 0; i < length; i++){
        std::fread(&result[i], sizeof(int), 1, pFile);
    }


    return result;
}