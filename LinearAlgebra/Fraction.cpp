#include "Fraction.h"
#include <cstdlib>

/**
 * Constructor
 * Takes in a numerator and denominator to make a valid fraction.
 * If the fraction entered is not valid, a valid fraction will be made.
*/
Fraction::Fraction(int numerator, int denominator) {
    if(isValid(numerator, denominator)) {
        reduce();
    }
    else {
        this->numerator = numerator;
        this->denominator = 1;
    }
}

/**
 * isValid Function
 * Checks to ensure the fraction is valid
 * @param numerator The fraction's numerator
 * @param denominator The fractions denominator
 * @return If the fraction is valid
*/
bool Fraction::isValid(int numerator, int denominator) {
    if(denominator == 0) {
        return false;
    }
    else if(numerator == 0) {
        this->numerator = 0;
        this->denominator = 1;
        return true;
    }
    else if(numerator > 0 && denominator < 0) {
        this->numerator = -(numerator);
        this->denominator = -(denominator);
        return true;
    }
    else if(numerator < 0 && denominator < 0) {
        this->numerator = abs(numerator);
        this->denominator = abs(denominator);
        return true;
    }
    else {
        this->numerator = numerator;
        this->denominator = denominator;
        return true;
    }
}

/**
 * reduce Function
 * Reduce the fraction to the smallest fraction possible
 * @param numerator The fraction's numerator
 * @param denominator The fraction's denominator
*/
void Fraction::reduce() {
    if(denominator == 1) {
        return;
    }
    else {
        int a = abs(numerator);
        int b = abs(denominator);
        
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        this->numerator = (numerator / a);
        this->denominator = (denominator / a);
        return;
    }
}

/**
 * getNumerator Function
 * Returns the fraction's numerator
 * @return The fraction's numerator
*/
int Fraction::getNumerator() const {
    return numerator;
}

/**
 * getDenominator Function
 * Returns the fraction's denominator
 * @return The fraction's denominator
*/
int Fraction::getDenominator() const {
    return denominator;
}

/**
 * Less-Than Operator Overload
*/
bool Fraction::operator <(Fraction f) {
    return getNumerator() * f.getDenominator() < getDenominator() * f.getNumerator();
}

/**
 * Greater-Than Operator Overload
*/
bool Fraction::operator >(Fraction f) {
    return getNumerator() * f.getDenominator() > getDenominator() * f.getNumerator();
}

/**
 * Less-Than/Equal-To Operator Overload
*/
bool Fraction::operator <=(Fraction f) {
    return !(*this > f);
}

/**
 * Greater-Than/Equal-To Operator Overload
*/
bool Fraction::operator >=(Fraction f) {
    return !(*this < f);
}

/**
 * Equality Operator Overload
*/
bool Fraction::operator ==(Fraction f) {
    return numerator == f.numerator && denominator == f.denominator;
}

/**
 * Inequality Operator Overload
*/
bool Fraction::operator !=(Fraction f) {
    return !(*this == f);
}

/**
 * Addition Overload - Add Fraction
*/
const Fraction Fraction::operator +(const Fraction& f) {
    if(getDenominator() == f.getDenominator())
        return Fraction(getNumerator() + f.getNumerator(), getDenominator());
    
    else {
        if(f.getDenominator() != 1) {
            return Fraction(getNumerator() * f.getDenominator() + f.getNumerator() * getDenominator(), getDenominator() * f.getDenominator());
        }
        else {
            return Fraction (f.getNumerator() * getDenominator() + getNumerator() * f.getDenominator(), f.getDenominator() * getDenominator());
        }
    }
}

/**
 * Addition Overload - Add Integer
*/
const Fraction Fraction::operator +(int i) {
    if(getDenominator() == 1) {
        return Fraction(getNumerator() + i);
    }
    else {
        return Fraction(getNumerator() + i * getDenominator(), getDenominator());
    }
}

/**
 * Subtraction Overload - Subtract Fraction
*/
const Fraction Fraction::operator -(const Fraction& f) {
    if(getDenominator() == f.getDenominator())
        return Fraction(getNumerator() - f.getNumerator(), getDenominator());
    
    else {
        if(f.getDenominator() != 1) {
            return Fraction(getNumerator() * f.getDenominator() - f.getNumerator() * getDenominator(), getDenominator() * f.getDenominator());
        }
        else {
            return Fraction (f.getNumerator() * getDenominator() - getNumerator() * f.getDenominator(), f.getDenominator() * getDenominator());
        }
    }
}

/**
 * Subtraction Overload - Subtract Integer
*/
const Fraction Fraction::operator -(int i) {
    if(getDenominator() == 1) {
        return Fraction(getNumerator() - i);
    }
    else {
        return Fraction(getNumerator() - i * getDenominator(), getDenominator());
    }
}

/**
 * Multiplication Overload - Multiply Fraction
*/
const Fraction Fraction::operator *(const Fraction& f) {
    return Fraction(getNumerator() * f.getNumerator(), getDenominator() * f.getDenominator());
}

/**
 * Multiplication Overload - Multiply Integer
*/
const Fraction Fraction::operator *(int i) {
    return Fraction(getNumerator() * i, getDenominator());
}

/**
 * Division Overload - Divide Fraction
*/
const Fraction Fraction::operator /(const Fraction& f) {
    return Fraction (getNumerator() * f.getDenominator(), getDenominator() * f.getNumerator());
}

/**
 * Division Overload - Divide Integer
*/
const Fraction Fraction::operator /(int i) {
    return Fraction(getNumerator(), getDenominator() * i);
}

/**
 * Equality Operator Overload - Copy Fraction
*/
const Fraction& Fraction::operator =(const Fraction& f) {
    if(this != &f) {
        numerator = f.numerator;
        denominator = f.denominator;
    }
    return *this;
}

/**
 * Equality Operator Overload - Copy Integer
*/
const Fraction& Fraction::operator =(int i) {
    // if(this == i) {
    //     numerator = f.numerator;
    //     denominator = f.denominator;
    // }
    return *this;
}

/**
 * OutStream Operator Overload
*/
std::ostream& operator <<(std::ostream& os, const Fraction& f) {
    if(f.getDenominator() == 1) { os << f.getNumerator(); }
    else { os << f.getNumerator() << "/" << f.getDenominator(); }
    return os;
}

/**
 * InStream Operator Overload
*/
std::istream& operator >>(std::istream& is, Fraction& f) {
    //Incomplete
    return is;
}

