
#include <stdio.h>

#include "Reverser.h"
#include <string>

Reverser::Reverser() {
    original_string = "";
}

//takes a string
//reverses order of words
//returns reversed string
std::string Reverser::reverse(std::string a) {
    Word object;
    std::string word = "";

    //loops through each character in string a
    //when there is a whitespace, it is the end of a word
    //adds this word onto reverseStack
    for (auto x : a) {
        if (x == ' ') {
            object.setWord(word); //assigns string word to Word object
            reverseStack.push(object); //adds this Word object onto top of stack
            word = ""; //resets word for next word
        }
        else {
            word = word + x;
        }
    }

    //removes word object from top stack
    //adds the string associated with word object just removed into orginal_string
    //repeats until reverseStack is empty
    while (reverseStack.isEmpty() != 1) {
        original_string = original_string + reverseStack.pop().getWord() + " ";
    }

    return original_string; //reversed string
}





