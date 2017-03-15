//
// Created by joseph on 2/19/17.
//

#include <cmath>
#include "PagedArray.h"


const int PAGESIZE = 256;

int p1[PAGESIZE] = {-1};
int p2[PAGESIZE] = {-1};
int p3[PAGESIZE] = {-1};
int p4[PAGESIZE] = {-1};
int p5[PAGESIZE] = {-1};
int p6[PAGESIZE] = {-1};

int pages[6][PAGESIZE] = {-1};

void PagedArray::getPage() {

}


int PagedArray::getValue(int index) {
    int page = (int) floor(index / PAGESIZE);
    int position = index % PAGESIZE;

    if (!isPageLoaded(page)) {
        loadPage(page);
    }

    return page;

}


int PagedArray::operator[](int index) {
    return getValue(index);
}

bool PagedArray::isPageLoaded(int page) {
    if (p1[0] == page) {
        return true;
    } else if (p2[0] == page) {
        return true;
    } else if (p3[0] == page) {
        return true;
    } else if (p4[0] == page) {
        return true;
    } else if (p5[0] == page) {
        return true;
    } else return p6[0] == page;
}

void PagedArray::loadPage(int page) {

}
