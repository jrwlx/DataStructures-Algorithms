//Homework 1, Jarren Jose

#include "human.h"
#include <string>

//constructor
human::human() {
    name = "";
    age = 0;
    phrase = "";
}

//constructor with name, age, phrase as parameters
human::human(std::string n, int a, std::string p) {
    name = n;
    age = a;
    phrase = p;
}

/*
 each time these functions are called, age will increase by 1
 */
std::string human::getName() {
    age++;
    return name;
}

void human::setName(std::string n) {
    age++;
    name = n;
}

int human::getAge() {
    age++;
    return age;
}

std::string human::getPhrase() {
    age++;
    return phrase;
}

void human::setPhrase(std::string p) {
    age++;
    phrase = p;
}

