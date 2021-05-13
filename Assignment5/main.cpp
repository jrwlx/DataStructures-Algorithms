
#include <iostream>
#include <fstream>

#include "HugeInt.h"

using namespace std;

int main(int argc, const char * argv[]) {

    HugeInt one, two, three, four, five, six, seven, eight, nine;
    HugeInt quotient, product, sum, difference;

    //inserting different number of digits
    one.insertDigits(2);
    one.insertDigits(488);
    two.insertDigits(5);
    two.insertDigits(1);

    quotient = one / two; //dividing

    four.insertDigits(-93);
    five.insertDigits(-67);

    product = four * five; //multiplying

    six.insertDigits(123124);
    six.insertDigits(5);
    seven.insertDigits(321);

    sum = six + seven; //adding

    eight.insertDigits(9991);
    nine.insertDigits(-1231);

    difference = eight - nine; //subtracting

    if ((quotient < product) == true) {
        cout << "HugeInt quotient is less than HugeInt product" << endl;
    }
    else {
        cout << "HugeInt quotient is not less than HugeInt quotient" << endl;
    }

    if ((sum == difference) == true) {
        cout << "Equal" << endl;
    }
    else {
        cout << "Not equal" << endl;
    }

    ofstream outFile;
    string outfileName = "File1.txt";
    outFile.open(outfileName.c_str());

    quotient.write(outFile);
    outFile << endl;
    product.write(outFile);
    outFile << endl;
    sum.write(outFile);
    outFile << endl;
    difference.write(outFile);

    outFile.close();

    return 0;
}




