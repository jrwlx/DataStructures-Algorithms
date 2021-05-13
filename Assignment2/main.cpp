//Homework 2, Jarren Jose

#include "human.h"
#include "people.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int a;
    string name, phrase;
    people obj; //people object created

    cout << "Number of humans people can hold: ";
    cin >> a;

    cout << "Number of humans to create: ";
    cin >> a;
    cin.ignore();

    for (int i = 0; i < a; i++) {
        cout << "Enter name: ";
        getline(cin, name);
        human *p = new human(name, 0, phrase); //human object created
        obj.insert(*p); //human object inserted
    }

    cout << "\n\nSearching: ";
    getline(cin, name);

    if (obj.search(name) == true) {
        cout << "Word found\n\n";
    } else {
        cout << "Word not found\n\n";
    }

    return 0;
}

