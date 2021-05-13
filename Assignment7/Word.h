
#ifndef WORD_H_
#define WORD_H_

#include <string>

class Word {
private:
    std::string word;

public:
    Word();
    void setWord(std::string);
    std::string getWord() const;
};

#endif /* WORD_H_ */
