//
// Created by joseph on 2/19/17.
//

#ifndef TAREAARREGLOSPAGINADOS_PAGEDARRAY_H
#define TAREAARREGLOSPAGINADOS_PAGEDARRAY_H


class PagedArray {

    int * getPage();

public:
    int getValue(int index);

    int& operator[](int index);

    bool isPageLoaded(int page);

    static int * loadPage(int page);

    int *getPage(int page);

    int freePage();

    PagedArray(FILE *File);

    int *loadPage(int where, int which);

    void cleanup();
};


#endif //TAREAARREGLOSPAGINADOS_PAGEDARRAY_H
