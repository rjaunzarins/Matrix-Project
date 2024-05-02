#include "Matrix.h"
#include "Fraction.h"

#include <iostream>

int main() {

    Matrix m;
    m.print();

    bool solved = false;
    while(!solved) {    
        m.checkX1();
        solved = m.checkSolved();
        if(solved) { break; }

        m.checkCol1Zeros();
        m.checkX2();
        m.checkCol2Zeros();
        m.checkX3();
        m.checkCol3Zeros();
        solved = true;
    }


}