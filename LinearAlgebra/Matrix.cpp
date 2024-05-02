#include "Matrix.h"

/**
 * Default Constructor
 * Generate Matrix with default size of 3 rows, 4 cols
 */
Matrix::Matrix() {
    generate();
}

/**
 * Arg Constructor
 * Generate matrix with custom size
 * @param rows number of rows in matrix
 * @param cols number of columns in matrix
*/
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    generate();
}

/**
 * generate Function
 *!Currently fills matrix with fixed values
*/
void Matrix::generate() {
    data[0][0] = Fraction(2);   //2,-1,1,5,1,1,-1,-2,-1,2,2,1
    data[0][1] = Fraction(3);
    data[0][2] = Fraction(-4);
    data[0][3] = Fraction(5);
    data[1][0] = Fraction(3);   
    data[1][1] = Fraction(-2);
    data[1][2] = Fraction(1);
    data[1][3] = Fraction(4);
    data[2][0] = Fraction(1);
    data[2][1] = Fraction(1);
    data[2][2] = Fraction(2);
    data[2][3] = Fraction(3);
}

/**
 * setElement Function
 * Sets an element to the passed value
 * @param row The row to modify
 * @param col The column to modify
 * @param val The value to enter in element
*/
void Matrix::setElement(int row, int col, Fraction val) {
    data[row][col] = val;
}

/**
 * getElement Function
 * Returns the value in specified element
 * @param row The row to get value from
 * @param col The column to get value from
 * @return The value in specified element
*/
Fraction Matrix::getElement(int row, int col) {
    return data[row][col];
}

/**
 * getRows Function
 * Returns the number of rows in the matrix
 * @return The number of rows
*/
int Matrix::getRows() {
    return rows;
}

/**
 * getCols Function
 * Returns the number of cols in the matrix
 * @return The number of cols
*/
int Matrix::getCols() {
    return cols;
}

/**
 * print Function
 * Prints the array
*/
void Matrix::print() {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << data[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

/**
 * reset Function
 * Resets all values in matrix to 0
*/
void Matrix::reset() {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] = 0;
        }
    }
}

/**
 * reduceRow Function
 * 
*/
void Matrix::reduceRow(int reduceRow, int reduceByRow, Fraction multiple) {
    if(multiple != 0) {
        for (size_t i = 0; i < cols; ++i) {
            data[reduceRow][i] = data[reduceRow][i] - (data[reduceByRow][i] * multiple);
        }
        std::cout << "Reduce R" << reduceRow+1 << " By R" << reduceByRow+1 << " * " << multiple << ":\n";
    }
}

// /**
//  * checkRowSolved Function
// */
// void Matrix::checkRowSolved() {

// }

// bool Matrix::isLeadingElement1(int row) {
//     int one = 0;
//     int greater = 0;
//     for (size_t i = 0; i < cols; ++i) {
//         if(data[row][i] == 1)
//             ++one;
//         if(data[row][i] > 1)
//             ++greater;
//         if(one == 1) { return true; }
//         if(greater == 1) { return false; }
//     }
//     return false;
// }

// int Matrix::getLeading1Element(int row) {
//     for (size_t i = 0; i < cols; ++i) {
//         if(data[row][i] == 1)
//             return i;
//     }
//     return -1;
// }

// int Matrix::getLeadingElement(int row) {
//     for (size_t i = 0; i < cols; ++i) {
//         if(data[row][i] != 0)
//             return i;
//     }
//     return -1;
// }

/**
 * checkX1 Function
 * Checks to see if data[0][0] is a 1. If it is not a 1 the function will
 * either swap the row with a row that has a 1 in first element, or will
 * reduce the row if required
*/
void Matrix::checkX1() {
    Fraction &x1 = data[0][0];
    //If x1 is already 1, no changes
    if(x1 == 1)
        return;
    //if x1 is 0, change with another row
    else if(x1 == 0) {
        //Loop through matrix to see if swap possible
        for(size_t i = 1; i < rows; ++i) {
            //If data[i][0] == 1 swap row 0 with row i
            if(data[i][0] == 1) {
                swapRows(0, i);
                print();
                return;
            }
        }
        //No row begins with 1, Loop through matrix to swap with any row starting != 0
        for(size_t i = 1; i < rows; ++i) {
            if(data[i][0] != 0) {
                swapRows(0, i);
                print();
                return;
            }
        }
    }
    //Else x1 is not 0, or 1 -> divide row by x1
    else {
        for(size_t i = 1; i < rows; ++i) {
            //If data[i][0] == 1 swap row 0 with row i
            if(data[i][0] == 1) {
                swapRows(0, i);
                print();
                return;
            }  
        }
        //If no other rows begin with 1, divide row by itself
        divideRow(0, data[0][0]);
        print();
    }
}

/**
 * checkX2 Function
 * Checks to see if data[1][1] is a 1. If it is not a 1 the function will
 * either reduce the row with row data[2][i] or will divide by itself.
*/
void Matrix::checkX2() {
    if(data[1][1] != 1) {
        if(static_cast<Fraction>(data[1][1] - data[2][1] * data[1][1]) == 1) {
            reduceRow(1,2,data[1][1]); //!Not sure if this should be here
            print();
        }
        else {
            divideRow(1, data[1][1]);
            print();
        }
    }

}

/**
 * checkX3 Function
 * Checks to see if data[2][2] is a 1. If it is not a 1 the function will
 * divide the element by itself.
*/
void Matrix::checkX3() {
    if(data[2][2] != 1) {
        divideRow(2, data[2][2]);
        print();
    }
}

/**
 * checkSolved Function
*/
bool Matrix::checkSolved() {
    if(data[2][0] == 0 && data[2][1] == 0 && data[2][2] == 0 && data[2][3] != 0) {
        std::cout << "0 != " << data[2][3] << " - No Solutions\n";
        return true;
    }
    else if(data[2][0] == 0 && data[2][1] == 0 && data[2][2] == 0 && data[2][3] == 0) {
        std::cout << "Many Solutions\n";
        return true;
    }
    if(data[0][0] != 1)
        return false;
    else if(data[1][1] != 1)
        return false;
    else if(data[2][2] != 1)
        return false;
    else if(data[0][1] != 0 || data[0][2] != 0)
        return false;
    else if(data[1][0] != 0 || data[1][2] != 0)
        return false;
    else if(data[2][0] != 0 || data[2][1] != 0)
        return false;
    else
        return true;
}

// void Matrix::checkColZeros() { 
//     for (size_t i = 0; i < rows; ++i) {
//         if(i == 0) {
//             checkCol1Zeros();
//         }
//         if(i == 2) {
//             checkCol2Zeros();
//         }
//         if(i == 3) {
//             checkCol3Zeros();
//         }
//     }
// }

/**
 * checkCol1Zeros Function
 * Reduces elements in column 1 to zero below x1
*/
void Matrix::checkCol1Zeros() {
    for (size_t i = 1; i < rows; i++) {
        if(data[i][0] != 0) {
            reduceRow(i, 0, data[i][0]);
            print();
        }
    }
}

/**
 * checkCol2Zeros Function
 * Reduces elements in column 2 to zero above and below x2
*/
void Matrix::checkCol2Zeros() {
    if(static_cast<Fraction>(data[0][1] - data[1][1] * data[0][1]) == 0) {
        reduceRow(0, 1, data[0][1]);
        print();
    }
    if(static_cast<Fraction>(data[2][1] - data[1][1] * data[2][1]) == 0) {
        reduceRow(2, 1, data[2][1]);
        print();
    }
}

/**
 * checkCol3Zeros Function
 * Reduces elements in column 3 to zero above x3
*/
void Matrix::checkCol3Zeros() {
    if(static_cast<Fraction>(data[0][2] - data[2][2] * data[0][2]) == 0) {
            reduceRow(0, 2, data[0][2]);
            print();
    }
    if(static_cast<Fraction>(data[1][2] - data[2][2] * data[1][2]) == 0) {
            reduceRow(1, 2, data[1][2]);
            print();
    }
}

/**
 * swapFraction Function
 * Swaps two fractions
 * @param f1 The first Fraction
 * @param f2 The second Fraction
*/
void Matrix::swapFraction(Fraction &f1, Fraction &f2) {
    Fraction temp = f1;
    f1 = f2;
    f2 = temp;
}

/**
 * swapRows Function
 * Swaps two rows
 * @param r1 The first row
 * @param r2 The second row
*/
void Matrix::swapRows(int r1, int r2) {
    for(int i = 0; i < cols; ++i) {
        swapFraction(data[r1][i], data[r2][i]);
    }  
    std::cout << "Swap R" << r1+1 << " With R" << r2+1 << ":\n";
}

/**
 * multiplyRow Function
 * Multiplies a row by a constant
 * @param row The row to multiply
 * @param f The constant to multiply the row by
*/
// void Matrix::multiplyRow(int row, Fraction f) {
//     for(int i = 0; i < cols; ++i) {
//         data[row][i] = data[row][i] * f;
//         std::cout << "Multiply R" << i+1 << " By " << data[i][i] << ":\n";
//     } 
// }

/**
 * divideRow Function
 * Divides a row by a constant
 * @param row The row to divide
 * @param f The constant to divide the row by
*/
void Matrix::divideRow(int row, Fraction f) {
    for(int i = 0; i < cols; ++i) {
        data[row][i] = data[row][i] / f;
    } 
    std::cout << "Divide R" << row+1 << " By " << f << ":\n";
}

/**
 * addRows Function
 * Adds a multiple of one row to another row
 * @param r1 The row to be modified
 * @param r2 The row to be multiplied and added
 * @param multiple The constant to multiply by
 * 
*/
// void Matrix::addRows(int r1, int r2, Fraction multiple) {
//     for(int i = 0; i < cols; ++i) {
//         data[r1][i] = data[r1][i] + multiple * data[r2][i];
//     } 
// }
