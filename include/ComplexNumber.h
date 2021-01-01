#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>

class ComplexNumber
{
private:
   double mRealPart;
   double mImaginaryPart;
public:
   ComplexNumber(); // Constructor that sets both real and imaginary part to 0;
   ComplexNumber(double x, double y); // Constructor that sets one double x and a double y to whatever is inside the arugment
   ComplexNumber(const ComplexNumber& x); // Copy Constructor
   ComplexNumber(double x); // Accepts one argument and stores it inside the real paart
   double CalculateModulus() const;
   double CalculateArgument() const;

   double GetRealPart();//Gets the real part of the complex number
   double GetImaginaryPart();//Gets the imaginary part of the complex number
   void SetToConjuate(); // Sets the conjuate
   ComplexNumber CalculateConjugate() const; // Calculates the conjuate
   friend double RealPart(const ComplexNumber& z); // friend method to get real part
   friend double ImaginaryPart(const ComplexNumber& z); // Friend to get imaginary part
   ComplexNumber CalculatePower(double n) const;
   ComplexNumber& operator=(const ComplexNumber& z);
   ComplexNumber operator-() const;
   friend ComplexNumber operator+(const ComplexNumber& z1, const ComplexNumber& z2);
   friend ComplexNumber operator-(const ComplexNumber& z1, const ComplexNumber& z2);
   friend std::ostream& operator<<(std::ostream& output,
                                   const ComplexNumber& z);
};

#endif
