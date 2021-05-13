
#ifndef WORDSTACK_H_
#define WORDSTACK_H_

#include "Word.h"

class WordStack {
private:
    struct StackNode {
        Word word;
        StackNode *next;
    };

    StackNode *top;

public:
    WordStack();
    ~WordStack();
    void push(Word a);
    Word pop();
    bool isEmpty() const;
};



#endif /* WORDSTACK_H_ */
