
#ifndef HUGEINT_CPP_
#define HUGEINT_CPP_


#include <stdio.h>

#include <fstream>
#include <cmath>
#include <iostream>
#include <string>
#include "HugeInt.h"

using namespace std;

HugeInt::HugeInt() {
    least = nullptr;
    most = nullptr;
    sign = PLUS;
    numDigits = 0;
}

void HugeInt::makeEmpty() {
    Node *traverse = nullptr;
    while (traverse != nullptr) {
        traverse = least;
        least = least->next;
        delete traverse;
    }
    numDigits = 0;
    least = nullptr;
    most = nullptr;
}

HugeInt::~HugeInt() {
    makeEmpty();
}

void HugeInt::write(ofstream &outF) {
    Node *current = most;
    while (current != nullptr) {
        outF << current->digit << " ";
        current = current->previous;
    }
}

//Helper function for adding and subtracting
//Important because creates a more readable and cleaner code
//Private because only want user to insert digits through 'insertDigits' function
//Inserts digits at most significant end (tail)
void HugeInt::appendDigit(int number) {

    Node *node = nullptr;

    if (least == nullptr && most == nullptr) { //list is initially empty
        node = new Node;
        node->digit = number;
        least = node;
        most = node;
        node->next = nullptr;
        node->previous = nullptr;
        numDigits++;
    }
    else {
        node = new Node;
        node->digit = number;
        most->next = node;
        node->previous = most;
        node->next = nullptr;
        most = node;
        numDigits++;
    }

} //end of function

//Helper function to remove insignificant zeroes gained from adding or subtracting
//Achieves this by simply manipulating 'most' to point to correct most significant digit
//Important because these zeroes could throw of adding or subtracting
void HugeInt::removeZero() {

    if (least == most) { //if only one digit or list is empty
        return;
    }
    else {
        Node *traverse = most;
        while (most->digit == 0) { //removing zeros
            most = most->previous;
            traverse->previous = nullptr;
            most->next = nullptr;
            traverse = most;

        }
    }

} //end of function

void HugeInt::insertDigits(int number) {

    //Checking signs of HugeInt
    bool isNegative = false;
    if (number < 0 && sign == PLUS) { //inserting negative number
        number = number * - 1;
        sign = MINUS; //updates HugeInt sign
        isNegative = true; //reupdate most significant digit to negative
    }
    else if (number < 0 && sign == MINUS) { //inserting negative when Hugeint is already negative
        number = number * -1;
    }

    //Inserting number into HugeInt
    Node *node = nullptr;

    if (number <= 9) { //number is a single digit
        node = new Node;
        node->digit = number;

        if (least == nullptr && most == nullptr) { //list is initially empty
            least = node;
            most = node;
            node->next = nullptr;
            node->previous = nullptr;
            numDigits++; //updating
        }
        else {
            //insert at front
            least->previous = node;
            node->next = least;
            least = node;
            node->previous = nullptr;
            numDigits++; //updating
        }
    }
    else if (number >= 10) { //number is more than one digit

        //find number of digits in 'number'
        int numberOfDigits = 0;
        int nCopy = number;
        while (nCopy) {
            nCopy = nCopy / 10;
            numberOfDigits++;
        }
        int exponent = numberOfDigits - 1; //help figure out place value of digit

        //Retrieving each digit in number
        for (int i = 0; i < numberOfDigits; i++) {

            int placeValue = pow(10, exponent); //10^X to get place value
            exponent--; //place values decrease at powers of 10
            int result = number / placeValue; //to obtain most signicant digit of 'a'

            if (least == nullptr && most == nullptr) { //list is initally empty
                node = new Node;
                node->digit = result;
                least = node;
                most = node;
                node->next = nullptr;
                node->previous = nullptr;
                numDigits++; //updating
            }
            else {
                //inserting at front
                node = new Node;
                node->digit = result;
                least->previous = node;
                node->next  = least;
                least = node;
                node->previous = nullptr;
                numDigits++; //updating
            }

            number = number % placeValue; //removes most significant digit just inserted from 'a'

        } //end of for loop
    } //end of else if

    if (isNegative == true) { //if HugeInt is not already negative
        most->digit = most->digit * -1; //most significant digit negative for driver to see
    }

} //end of function


bool HugeInt::operator<(HugeInt second) {

    bool lessThan = false;

    if (sign != second.sign) { //signs not the same
        if (sign == MINUS && second.sign == PLUS) { //first is negative and second is positive, return true
            lessThan = true;
            return lessThan;
        }
        else if (second.sign == MINUS && sign == PLUS) { //first is positive and second is negative, return false
            return lessThan;
        }
    }
    else if (numDigits != second.numDigits && sign == MINUS && sign == PLUS) { //numDigits not equal and both negative, digits with more is smaller
        if (numDigits > second.numDigits) {
            lessThan = true;
            return lessThan;
        }
        else {
            return lessThan;
        }

    }
    else if (numDigits != second.numDigits) { //numDigits are not equal, number with less digits is smaller
        if (numDigits < second.numDigits) {
            lessThan = true;
            return lessThan;
        }
        else {
            return lessThan;
        }
    }
    else if (numDigits == second.numDigits) { //same number of digits

        Node *traverseOne = most, *traverseTwo = second.most;

        //comparing each digit in HugeInt
        for (int i = 0; i < numDigits && i < second.numDigits; i++) {

            if (traverseOne->digit < traverseTwo->digit) { //first less than second, return true
                lessThan = true;
                return lessThan;
            }
            else if (traverseOne->digit == traverseTwo->digit) { //digits are equal, set traverseOne and traverseTwo equal to next most significant digit
                traverseOne = traverseOne->previous;
                traverseTwo = traverseTwo->previous;
            }
            else if (i == numDigits - 1 && traverseOne->digit == traverseTwo->digit) { //digits are all equal, return false
                return lessThan;
            }

        }//end of for loop
    }//end of else if

    return lessThan;

}//end of function

bool HugeInt::operator==(HugeInt second) {
    bool equal = false;

    if(sign != second.sign) { //signs are not equal
        return equal;
    }
    else if (numDigits != second.numDigits) { //digits are not equal
        return equal;
    }
    else if (numDigits == second.numDigits) {

        Node *traverseOne = most, *traverseTwo = second.most;

        //loops through HugeInt comparing each digit
        for (int i = 0; i < numDigits && i < second.numDigits; i++) {

            if (traverseOne->digit != traverseTwo->digit) { //breaks if any digit isn't equal
                return equal;
            }

            traverseOne = traverseOne->previous;
            traverseTwo = traverseTwo->previous;

        }//end of for loop

        equal = true;

    } //end of else if

    return equal;

} //end of function

HugeInt HugeInt::operator+(HugeInt second) {

    HugeInt third; //stores sum
    HugeInt negative;
    negative.insertDigits(-1);

    //Checking signs of Huge Int
    bool twoNegatives = false;

    if (most->digit < 0 && second.most->digit < 0) { //two negative numbers same as adding, then making it negative
        //makes most significant positive so calculations are correct
        operator*(negative);
        second.operator*(negative);
        twoNegatives = true; //to attach negative at the end of addition
    }
    else if (second.most->digit < 0 && most->digit > 0) { //second HugeInt is negative
        second.most->digit = second.most->digit * -1; //make most significant to positive so calculations don't get messed up
        if (operator<(second) == true) { //first HugeInt is less than second, then second - first
            third = operator-(second);
            HugeInt temp;
            temp = operator+(second) - second; //stores first
            third = second - temp; //second - first

            third = third * negative; //allows driver to see negative number
            third.sign = MINUS;
            return third;
        }
        else if (operator<(second) == false) { //first Huge is greater than second, first - second
            third = operator-(second);
            third.sign = PLUS;
            return third;
        }
    }
    else if (second.most->digit > 0 && most->digit < 0) { //first HugeInt is negative
        most->digit = most->digit * -1;

        if (operator<(second) == true) { //second HugeInt is less than second, then second - first
            third = operator-(second);
            HugeInt temp;
            temp = operator+(second) - second; //stores first
            third = second - temp; //second - first
            third.sign = PLUS;
            return third;
        }
        else if (operator<(second) == false) { //second Huge is greater than second, first - second
            third = operator-(second);
            third = third * negative; //allows driver to see negative number
            third.sign = MINUS;
            return third;
        }
    }
    //end of checking signs of HugeInt

    //fills zeros to make addition easier if digits aren't equal
    while (numDigits < second.numDigits) {
        appendDigit(0);
    }
    //fills zeros to make addition easier if digits aren't equal
    while (second.numDigits < numDigits) {
        second.appendDigit(0);
    }

    //pointer to traverse each HugeInt starting at least significant
    Node *traverseOne = least, *traverseTwo = second.least;

    int carry = 0; //if number has a carry

    //loops through each digit in HugeInts
    for (int i = 0; i < numDigits; i++) {

        int sum = traverseOne->digit + traverseTwo->digit + carry;

        if (sum <= 9) { //no carry needed
            third.appendDigit(sum);
            carry = 0;
        }
        else if (sum >= 10) { //carry needed
            third.appendDigit(sum % 10);

            if (most == traverseOne) { //if adding increases number of digits
                third.appendDigit(sum / 10);
            }

            carry = 1; //update carry to reflect next summation

        } //end of else if

        traverseOne = traverseOne->next;
        traverseTwo = traverseTwo->next;
        //traverseThree = traverseThree->next;

    } //end of for loop

    if (twoNegatives == true) { //third is negative
        third.most->digit = third.most->digit * -1;
        third.sign = PLUS;
        return third;
    }

    return third;

} //end of function

HugeInt HugeInt::operator*(HugeInt second) {

    //checking signs of HugeInts
    bool isNegative = false;
    if (sign == MINUS && second.sign == PLUS) { //-1 * +1 = -1
        most->digit = most->digit * -1;
        isNegative = true;
    }
    else if (second.sign == MINUS && sign == PLUS) { //+1 * -1 = -1
        second.most->digit = second.most->digit * -1;
        isNegative = true;
    }
    else if (sign == MINUS && second.sign == MINUS) { //-1 * -1 = 1
        most->digit = most->digit * -1;
        second.most->digit = second.most->digit * -1;

    }

    //takes HugeInt number and
    //translates to an integer for the amount of repeated addition
    //by turning numbers into string, reversing string, converting to int
    std::string single;
    std::string number;
    int digit = 0;

    //stores least to most significant digits of HugeInt into 'number'
    Node *traverse = least;
    while (traverse != nullptr) {
        digit = traverse->digit;
        single = std::to_string(digit);
        number = number + single;
        traverse = traverse->next;
    }

    std::reverse(number.begin(), number.end()); //now stores most to least after reverse

    int loop = std::stoi(number); //keep track of repeated addition

    HugeInt product; //stores product
    product = second;
    int i = 0;
    while (i < loop - 1) {
        //continually sums second
        product = product.operator+(second);

        i++;
    }

    if (isNegative == true) { //product is negative
        product.most->digit = product.most->digit * -1;
        product.sign = MINUS;
    }

    return product;

} //end of function

HugeInt HugeInt::operator-(HugeInt second) {

    if (most->digit == 0)
        removeZero();

    if (second.most->digit == 0)
        second.removeZero();

    HugeInt third; //stores difference

    //pointer to traverse each HugeInt starting at least significant
    Node *traverseOne = least, *traverseTwo = second.least;

    int difference = 0;
    bool borrow = false;

    //first HugeInt is only negative
    if (second.most->digit >= 0 && most->digit < 0) {
        most->digit = most->digit * -1;
        third = operator+(second);
        third.sign = MINUS;
        third.most->digit = third.most->digit * -1;
        return third;
    }

    //if second HugeInt is negative
    else if (second.most->digit <= 0 && most->digit > 0) {
        second.most->digit = second.most->digit * -1;
        third = operator+(second);
        third.sign = PLUS;
        return third;
    }

    //both HugeInts are negative or trying to subtract larger from smaller, second - first
    else if ((most->digit <= 0 && second.most->digit <= 0) || operator<(second) == true) {

        bool firstIsSmallerThanSecond = false;
        if (operator<(second) == true) {
            firstIsSmallerThanSecond = true;
        }

        most->digit = most->digit * -1;
        second.most->digit = second.most->digit * -1;

        //fills zeros to make subtraction easier if digits aren't equal
        while (numDigits < second.numDigits) {
            appendDigit(0);
        }
        //fills zeros to make subtraction easier if digits aren't equal
        while (second.numDigits < numDigits) {
            second.appendDigit(0);
        }

        //second HugeInt is less than first
        if (operator<(second) == false) {

            while (traverseOne != nullptr && traverseTwo != nullptr) {

                if (traverseTwo->digit <= traverseOne->digit) { //no current borrow

                    if (borrow == false) { //no current borrow and no previous borrow
                        difference = traverseOne->digit - traverseTwo->digit;
                        third.appendDigit(difference);
                    }
                    else if (borrow == true) { //no current borrow and previous borrow
                        difference = (traverseOne->digit - 1) - traverseTwo->digit;
                        third.appendDigit(difference);
                        borrow = false;
                    }
                }
                else if (traverseTwo->digit >= traverseOne->digit) { //current borrow

                    if (borrow == true){ //current borrow and previous borrow
                        difference = ((traverseOne->digit + 10) - 1) - traverseTwo->digit;
                        third.appendDigit(difference);
                        if (traverseTwo->next->digit <= traverseOne->next->digit) {
                            borrow = true;
                        }
                    }
                    else if (borrow == false) { //current borrow and no previous borrow
                        difference = (traverseOne->digit + 10) - traverseTwo->digit;
                        third.appendDigit(difference);
                        borrow = true;
                    }
                } //end of else if

                //move on to next digit
                traverseOne = traverseOne->next;
                traverseTwo = traverseTwo->next;

            } //end of while

            //third.most->digit = third.most->digit * -1;
            //allows driver to see number is negative
            HugeInt temp2;
            temp2.insertDigits(-1);
            third = third * temp2; //makes third visibly negative
            third.sign = MINUS;
            return third;

        } //end of if

        //second HugeInt is greater than first
        else if (operator<(second) == true) {


            while (traverseOne != nullptr && traverseTwo != nullptr) {

                if (traverseOne->digit <= traverseTwo->digit) { //no current borrow

                    if (borrow == false) { //no current borrow and no previous borrow
                        difference = traverseTwo->digit - traverseOne->digit;
                        third.appendDigit(difference);
                    }
                    else if (borrow == true) { //no current borrow and previous borrow
                        difference = (traverseTwo->digit - 1) - traverseOne->digit;
                        third.appendDigit(difference);
                        borrow = false;
                    }
                }
                else if (traverseOne->digit >= traverseTwo->digit) { //current borrow

                    if (borrow == true){ //current borrow and previous borrow
                        difference = ((traverseTwo->digit + 10) - 1) - traverseOne->digit;
                        third.appendDigit(difference);
                        if (traverseOne->next->digit <= traverseTwo->next->digit) {
                            borrow = true;
                        }
                    }
                    else if (borrow == false) { //current borrow and no previous borrow
                        difference = (traverseTwo->digit + 10) - traverseOne->digit;
                        third.appendDigit(difference);
                        borrow = true;
                    }
                } //end of else if

                //move on to next digit
                traverseOne = traverseOne->next;
                traverseTwo = traverseTwo->next;

            } //end of while

            if (firstIsSmallerThanSecond == true) {
                cout << "HELLO";
                HugeInt temp2;
                temp2.insertDigits(-1);
                third = third * temp2; //makes third visibly negative
                third.sign = MINUS;
                return third;
            }

            third.sign = PLUS;
            return third;

        } //end of else if

    } //end of else if

    //regular subtraction
    else {

        //fills zeros to make subtraction easier if digits aren't equal
        while (numDigits < second.numDigits) {
            appendDigit(0);
        }
        //fills zeros to make subtraction easier if digits aren't equal
        while (second.numDigits < numDigits) {
            second.appendDigit(0);
        }

        while (traverseOne != nullptr && traverseTwo != nullptr) {

            if (traverseTwo->digit <= traverseOne->digit) { //no current borrow

                if (borrow == false) { //no current borrow and no previous borrow
                    difference = traverseOne->digit - traverseTwo->digit;
                    third.appendDigit(difference);
                }
                else if (borrow == true) { //no current borrow and previous borrow
                    difference = (traverseOne->digit - 1) - traverseTwo->digit;
                    third.appendDigit(difference);
                    borrow = false;
                }
            }
            else if (traverseTwo->digit >= traverseOne->digit) { //current borrow

                if (borrow == true){ //current borrow and previous borrow
                    difference = ((traverseOne->digit + 10) - 1) - traverseTwo->digit;
                    third.appendDigit(difference);
                    if (traverseTwo->next->digit <= traverseOne->next->digit) {
                        borrow = true;
                    }
                }
                else if (borrow == false) { //current borrow and no previous borrow
                    difference = (traverseOne->digit + 10) - traverseTwo->digit;
                    third.appendDigit(difference);
                    borrow = true;
                }
            } //end of else if

            //move on to next digit
            traverseOne = traverseOne->next;
            traverseTwo = traverseTwo->next;

        } //end of while

        return third;
    }

    return third;

} //end of function

HugeInt HugeInt::operator/(HugeInt second) {

    HugeInt quotient;

    //attempting to divide by larger number
    if (operator<(second) == true) {
        cerr << "Cannot divide by larger number" << endl;
        return quotient;
    }

    //checking signs of HugeInts
    bool isNegative = false;
    if (sign == MINUS && second.sign == PLUS) { //-1 / +1 = -1
    	most->digit = most->digit * -1;
        isNegative = true;
    }
    else if (second.sign == MINUS && sign == PLUS) { //+1 / -1 = -1
        second.most->digit = second.most->digit * -1;
        isNegative = true;
    }
    else if (sign == MINUS && second.sign == MINUS) { //-1 / -1 = 1
        most->digit = most->digit * -1;
        second.most->digit = second.most->digit * -1;
    }


    quotient = operator+(second);
    quotient = quotient.operator-(second); //quotient is equal to value of second

    int count = 0; //keep track of how many subtractions

    while (quotient.sign != MINUS) {
        count++;
        quotient = quotient.operator-(second); //continually subtracts
    }

    quotient.makeEmpty();

    quotient.insertDigits(count - 1); //inserts count into quotient

    if (isNegative == true) {
    	quotient.most->digit = quotient.most->digit * -1;
    	quotient.sign = MINUS;
    }

    return quotient;

} //end of function


#endif /* HUGEINT_CPP_ */
