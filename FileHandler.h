//
// Created by joseph on 2/20/17.
//

#ifndef TAREAARREGLOSPAGINADOS_FILEWRITER_H
#define TAREAARREGLOSPAGINADOS_FILEWRITER_H


#include <string>

class FileHandler {

public:


    static void writeNumbers(std::string filename);

    static int *
    readNumbers(std::string filename, int start, int finish);

    FILE *createTempFile();

    static FILE *openByFilename(std::string filename, std::string mode);

    static void txtToBinary(FILE *file);

    static void writeNumtoBin(FILE *file, int num);
};


#endif //TAREAARREGLOSPAGINADOS_FILEWRITER_H
