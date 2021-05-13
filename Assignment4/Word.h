
#ifndef WORD_H_
#define WORD_H_

#include <string>

class Word {
private:
    std::string word;

public:
    Word();
    std::string getWord() const;
    void setWord(std::string a);
};

#endif /* WORD_H_ */
