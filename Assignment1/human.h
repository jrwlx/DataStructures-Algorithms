//Homework 1, Jarren Jose

#ifndef human_h
#define human_h

#include <string>

class human {
public:
    human(); //constructor with no arguments
    human(std::string, int, std::string); //constructor with name, age, phrase as parameters
    
    std::string getName();
    void setName(std::string n);

    int getAge();

    std::string getPhrase();
    void setPhrase(std::string p);

private:
    std::string name;
    int age;
    std::string phrase;
};

#endif /* human_h */
