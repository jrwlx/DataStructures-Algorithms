//Homework 2, Jarren Jose

#ifndef people_h
#define people_h

#include "human.h"
#include <string>

class people {

public:
    people();
    bool search(std::string a);
    void insert(human obj);

private:
    human list[5]; //each people object needs a statically allocated array of humans
    int size; //represents size of array
    int position; //represents next free position in array
};

#endif /* people_h */

