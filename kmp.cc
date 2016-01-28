#include <iostream>
#include "kmpStringMatch.h"

kmpStringMatch::kmpStringMatch(string ptrn, string *src) {
    this->ptrn = ptrn;
    this->src = src;
    next = new int[ptrn.length()];
    fileptr = NULL;
}

kmpStringMatch::kmpStringMatch(string ptrn, ifstream *fileptr) {
    this->ptrn = ptrn;
    this->fileptr = fileptr;
    next = new int[ptrn.length()];
    src = NULL;
}

kmpStringMatch::~kmpStringMatch() {
    delete next;
}

//----------------------------------------------
//----------------------------------------------

// last above zero
/**void kmpStringMatch::matchAux(int last) {
    int i = next[last-1];
    int j = last;
    //int matchNum = 0;
    next[last] = next[last-1];
    if (ptrn[last] == ptrn[next[last-1]]) {
        next[last] = next[last-1] + 1;
    } else {
        if (next[last-1] > 0) {
            while (i > 0) {
                if (ptrn[i-1] == ptrn[j]) {
                    --i;
                    --j;
                } else {
                    j = last;
                    --(next[last]);
                    i = next[last] - 1;
                }
            }
        } else {
            next[last] = 0;
        }
    }
}
**/
void kmpStringMatch::buildNextArray() {
    int last = 0;
    int length = 0;
    int i = 0;
    int j = 0;
    if (!ptrn.empty()) {
        length = ptrn.length();
        next[0] = 0;
        for (last = 1; last < length; last++) {
            next[last] = next[last-1];
            i = next[last-1];
            j = last;
            while (i >= 0) {
                if (ptrn[i] != ptrn[j]) {
                    --(next[last]);
                    i = next[last];
                    j = last;
                } else {
                    --i;
                    --j;
                }
            }
            next[last] = next[last] + 1;
        }
    }
}

vector<int> kmpStringMatch::search() {
    vector<int> array;
    int src_i = 0;
    int ptrn_i = 0;
    int ptrnlen = ptrn.length();
    int srclen = src->length();
    if (ptrnlen <= srclen && ptrnlen > 0) { 
        buildNextArray();
        while (src_i < srclen) {
            //match keyword
            if (ptrn_i == ptrnlen) {
                array.push_back(src_i-ptrnlen);
                src_i = src_i - next[ptrn_i-1];
                ptrn_i = 0;
            } else {
                if (ptrn[ptrn_i] == (*src)[src_i]) {
                    ++src_i;
                    ++ptrn_i;
                } else {
                    if (ptrn_i > 0) {
                        src_i = src_i - next[ptrn_i-1];
                    } else { 
                        ++src_i;
                    }
                    ptrn_i = 0;
                }
            }
        }
        if (src_i == srclen and ptrn_i == ptrnlen) {
            array.push_back(src_i-ptrnlen);
        }
    }
    return array;
}


void kmpStringMatch::getNext() {
    buildNextArray();
    int length = ptrn.length();
    for (int i = 0; i < length; i++) {
        cout << next[i] << ' ';
    } 
}
