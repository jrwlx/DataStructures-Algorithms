
#include <stdio.h>

#include "Word.h"

Word::Word() {
    word = " ";
}

std::string Word::getWord() const {
    return word;
}

void Word::setWord(std::string a) {
    word = a;
}



