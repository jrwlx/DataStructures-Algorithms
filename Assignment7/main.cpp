
#include <iostream>
#include <fstream>
#include "HashTable.h"

using namespace std;

int main(int argc, const char * argv[]) {

    Word word;
    HashTable hash(200000);

    ifstream inFile;
    string inFileName = "words.txt";
    string readWord = " ";
    inFile.open(inFileName.c_str());

    if (!inFile) {
        cout << "File not found\n";
        exit(2);
    }
    else {

        while (inFile >> readWord) { //reading text file
            word.setWord(readWord); //creating Word object
            hash.insertWord(word); //insert into HashTable
        }

        //Looping menu for user to perform searches
        string searchHash = " ";
        for (int i = 0; i < 200000; i++) {
            cout << "Word to search: ";
            cin >> searchHash;
            if (searchHash == "-1")
            	break;
            Word search;
            search.setWord(searchHash);
            int index = hash.searchWord(search); //Searching HashTable
            if (index == -1)
                cout << "Word not found" << endl << endl;
            else
                cout << "Found, Key: " << index << endl << endl;

            }

    }


    return 0;
}



