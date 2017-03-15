//
// Created by joseph on 2/19/17.
//

#ifndef TAREAARREGLOSPAGINADOS_PAGEDARRAY_H
#define TAREAARREGLOSPAGINADOS_PAGEDARRAY_H


class PagedArray {

    void getPage();

public:
    int getValue(int index);

    int operator[](int index);

    bool isPageLoaded(int page);

    static void loadPage(int page);
};


#endif //TAREAARREGLOSPAGINADOS_PAGEDARRAY_H
