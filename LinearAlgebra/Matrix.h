#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Fraction.h"

class Matrix {
    public:
        Matrix();
        Matrix(int height, int width);
        void setElement(int row, int col, Fraction val);
        Fraction getElement(int row, int col);
        int getRows();
        int getCols();
        void reset();
        void print();
        void reduceRow(int reduceRow, int reduceByRow, Fraction multiple);
        void checkRowSolved();
        bool isLeadingElement1(int row);
        int getLeading1Element(int row);
        int getLeadingElement(int row);
        void checkX1();
        void checkX2();
        void checkX3();
        bool checkSolved();
        void checkColZeros();
        void checkCol1Zeros();
        void checkCol2Zeros();
        void checkCol3Zeros();
        void swapFraction(Fraction&, Fraction&);
        void swapRows(int r1, int r2);
        void multiplyRow(int row, Fraction f);
        void divideRow(int row, Fraction f);
        void addRows(int r1, int r2, Fraction multiple);
    private:
        void generate();
        Fraction data[10][10];
        int rows = 3;
        int cols = 4;

};

#endif 