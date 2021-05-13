
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "Word.h"

class HashTable {
private:
    struct node {
        Word value;
        node *next;
    };
    node *array;
    int hashSize;

public:
    HashTable(int);
    int hashFunction(Word);
    void insertWord(Word);
    int searchWord(Word);
};

#endif /* HASHTABLE_H_ */
