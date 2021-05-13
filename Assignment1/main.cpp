//Homework 1, Jarren Jose

#include "human.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::getline;

int main(int argc, const char * argv[]) {

    std::string name, phrase;
    int size = 0;
    cout << "Number of humans to create: ";
    cin >> size;
    cin.ignore();

    //array of human objects of a user defined size
    human obj[size];

    //setting values of each human by iterating through the array of humans
    for (int i = 0; i < size; i++) {

        if (i == size - 1) {

            cout << "Setting values: \n";
            cout << "Human #" << i << endl;

            cout << "Name: ";
            std::getline(cin, name);

            cout << "Phrase: ";
            std::getline(cin,phrase);

            int age = 0;
            //using constructor with name, age, and phrase as parameters
            human obj1(name, age, phrase);
            
            obj[size -1] = obj1;

        } else {
            //using default constructor
            
            cout << "Setting values: \n";
            cout << "Human #" << i << endl;

            cout << "Name: ";
            std::getline(cin, name);
            obj[i].setName(name);

            cout << "Phrase: ";
            std::getline(cin,phrase);
            obj[i].setPhrase(phrase);

        }

        cout << endl;
    }

    //getting values of each human by iterating through the array of humans
    for (int j = 0; j < size; j++) {
        cout << "Getting values of Human: #" << j << endl;;
        cout << "Name: " << obj[j].getName() << endl;
        cout << "Age: " << obj[j].getAge() << endl;
        cout << "Phrase: " << obj[j].getPhrase() << endl;
        cout << "Age: " << obj[j].getAge() << endl << endl;
    }

    return 0;
}


