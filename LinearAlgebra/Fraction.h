#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction {
    public:
        Fraction(int numerator = 1, int denominator = 1);
        int getNumerator() const;
        int getDenominator() const;
        bool operator <(Fraction f);
        bool operator >(Fraction f);
        bool operator <=(Fraction f);
        bool operator >=(Fraction f);
        bool operator ==(Fraction f);
        bool operator !=(Fraction f);
        const Fraction operator +(const Fraction&);
        const Fraction operator +(int);
        const Fraction operator -(const Fraction&);
        const Fraction operator -(int);
        const Fraction operator *(const Fraction&);
        const Fraction operator *(int);
        const Fraction operator /(const Fraction&);
        const Fraction operator /(int);
        const Fraction& operator =(const Fraction&);
        const Fraction& operator =(int);
        friend std::ostream& operator <<(std::ostream&, const Fraction&);
        friend std::istream& operator >>(std::istream&, Fraction&);
    private:
        bool isValid(int numerator, int denominator);
        void reduce();
        int numerator;
        int denominator;
};

#endif