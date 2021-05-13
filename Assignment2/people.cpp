//Homework 2, Jarren Jose

#include "people.h"
#include <iostream>
#include <string>

//constructor with no arguments
people::people() {
    size = 5;
    position = 0;
}

//search takes string and returns bool
//if found, return true
//if not found, return false
bool people::search(std::string a) {
    bool found = false;

    for (int i = 0; i < size; i++) {
        std::string key =  list[i].getName();
        if (key == a) {
            found = true;
        }
    }
    return found;
}

//takes human object
//if array is not full, adds object to the array and position is incremented
//print error if array is full
void people::insert(human obj) {
    try {
        if (size == position) {
            throw 66;
        } else {
            list[position] = obj;
            position++;
        }
    } catch (int error) {
        std::cout << "ERROR: Unable to insert previous human as people object is full.\n";
    }
}

