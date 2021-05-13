
#ifndef HUGEINT_H_
#define HUGEINT_H_

enum SignType {PLUS, MINUS};

class HugeInt {

private:
    struct Node {
        int digit; //holds single digit
        Node *next; //points to most significant digit
        Node *previous; //points to least significant digit
    };

    Node *least; //head, least significant digit
    Node *most; //tail, holds most significant digit
    SignType sign; //enum of the sign of the HugeInt
    int numDigits; //number of digits in the HugeInt
    void makeEmpty(); //clear the linked list of digits
    void appendDigit(int); //helper for operator overload functions
    void removeZero(); //helper for operator overload functions

public:
    HugeInt();
    ~HugeInt();
    bool operator<(HugeInt second);
    bool operator==(HugeInt second);
    HugeInt operator+(HugeInt second);
    HugeInt operator-(HugeInt second);
    HugeInt operator*(HugeInt second);
    HugeInt operator/(HugeInt second);
    void insertDigits(int);
    void write(std::ofstream&);

};

#endif /* HUGEINT_H_ */
