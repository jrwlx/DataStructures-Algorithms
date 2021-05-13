
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <sstream>

#include "Word.h"
#include "WordStack.h"
#include "Reverser.h"

using namespace std;

int main(int argc, const char * argv[]) {

    ifstream inFile;
    ofstream outFile;
    string inFileName = "File1.txt";
    string outFileName = "File1Output.txt";
    string stringWord = "";
    string total = "";

    inFile.open(inFileName.c_str());

    if (!inFile) {
        cout << "file in not found\n";
        exit(2);
    }

    //putting all words with spaces from "File1.txt" into a single string called total
    while (inFile >> stringWord) {
        total = total + stringWord + " ";
    }

    cout << "\nReversing order of words in File1.txt\n";
    Reverser object;
    //calling Reverser to reverse order of words inside total
    string a = object.reverse(total);


    outFile.open(outFileName.c_str());
    //writing the reverse of total to "File1Output.txt"
    outFile << a;

    inFile.close();
    outFile.close();

    return 0;
}


