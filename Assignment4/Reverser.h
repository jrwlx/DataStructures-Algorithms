
#ifndef REVERSER_H_
#define REVERSER_H_

#include "WordStack.h"
#include <string>

class Reverser {
private:
    WordStack reverseStack;
    std::string original_string;

public:
    Reverser();
    std::string reverse(std::string);
};

#endif /* REVERSER_H_ */
