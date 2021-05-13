
#ifndef WORDSTACK_CPP_
#define WORDSTACK_CPP_

#include <stdio.h>
#include <iostream>

#include "WordStack.h"

//Implement as Linked List

WordStack::WordStack() {
    top = NULL;
}

WordStack::~WordStack() {
    StackNode *traverse, *previous;
    traverse = top;
    while (traverse != NULL) {
        previous = traverse->next;
        delete traverse;
        traverse = previous;
    }
}

// push accepts a Word object, then inserts it into the stack of Words
void WordStack::push(Word a) {
    //top of stack is the front
    StackNode *node = new StackNode;
    node->word = a;
    if (!top) { //if stack is empty
        top = node;
        node->next = NULL;
    }
    else {
        node->next = top;
        top = node;
    }
}

Word WordStack::pop() {
    Word a;
    try {
        if (!top) { //if stack is empty
            throw 99; //throw an exception
        }
        else {
            a = top->word; //saves Word object being popped
            StackNode *traverse;
            traverse = top->next;
            delete top; //deletes top of stack
            top = traverse; //makes top point to next Word object
            return a; //returns Word object that was popped
        }
    } catch (int error) {
        std::cerr << "Cannot pop an empty stack\n";
        return a; //returns empty top
    }
}

bool WordStack::isEmpty() const {
    if (!top) {
        return true;
    }
    else {
        return false;
    }
}

#endif /* WORDSTACK_CPP_ */
