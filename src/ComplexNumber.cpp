#include "ComplexNumber.h"
#include <cmath>

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber()
{
   mRealPart = 0.0;
   mImaginaryPart = 0.0;
}

ComplexNumber::ComplexNumber(double x, double y)
{
   mRealPart = x;
   mImaginaryPart = y;
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
   return sqrt(mRealPart*mRealPart+
               mImaginaryPart*mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
   return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to the power n
// using De Moivre's theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
   double modulus = CalculateModulus();
   double argument = CalculateArgument();
   double mod_of_result = pow(modulus, n);
   double arg_of_result = argument*n;
   double real_part = mod_of_result*cos(arg_of_result);
   double imag_part = mod_of_result*sin(arg_of_result);
   ComplexNumber z(real_part, imag_part);
   return z;
}

/* ----------------------------------------------------------------------- */
/*                            ADDED METHODS                                */
/* ----------------------------------------------------------------------- */

/* Constructor which accepts the real part and sets the imaginary part to 0 */
ComplexNumber::ComplexNumber(double x)
{
   mRealPart = x;
   mImaginaryPart = 0;
}

/* Getter Method to return the real part */
double ComplexNumber::GetRealPart()
{
  return mRealPart;
}

/* Getter Method to return the imaginary part */
double ComplexNumber::GetImaginaryPart()
{
  return mImaginaryPart;
}

/* Friend Method to return the real part by accessing the class */
double RealPart(const ComplexNumber& z)
{
    return z.mRealPart;
}

/* Friend Method to return the imaginary part by accessing the class */
double ImaginaryPart(const ComplexNumber& z)
{
  return z.mImaginaryPart;
}

/* Copy Constructor */
ComplexNumber::ComplexNumber(const ComplexNumber& z)
{
  mRealPart = z.mRealPart;
  mImaginaryPart = z.mImaginaryPart;
}

ComplexNumber ComplexNumber::CalculateConjugate() const
{
  return ComplexNumber(mRealPart,-mImaginaryPart);
}

void ComplexNumber::SetToConjuate()
{
    mImaginaryPart = (-mImaginaryPart);
}
// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::
               operator=(const ComplexNumber& z)
{
   mRealPart = z.mRealPart;
   mImaginaryPart = z.mImaginaryPart;
   return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
  ComplexNumber w;
  w.mRealPart = -mRealPart;
  w.mImaginaryPart = -mImaginaryPart;
  return w;
}

// Overloading the binary + operator
ComplexNumber operator+(const ComplexNumber& z1, const ComplexNumber& z2)
{
  ComplexNumber w;
  w.mRealPart = z1.mRealPart + z2.mRealPart;
  w.mImaginaryPart = z1.mImaginaryPart + z2.mImaginaryPart;
  return w;
}

// Overloading the binary - operator
ComplexNumber operator-(const ComplexNumber& z1, const ComplexNumber& z2)
{
  ComplexNumber w;
  w.mRealPart = z1.mRealPart - z2.mRealPart;
  w.mImaginaryPart = z1.mImaginaryPart - z2.mImaginaryPart;
  return w;
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output,
                         const ComplexNumber& z)
{
   // Format as "(a + bi)" or as "(a - bi)"
   output << "(" << z.mRealPart << " ";
   if (z.mImaginaryPart >= 0.0)
   {
      output << "+ " << z.mImaginaryPart << "i)";
   }
   else
   {
      // z.mImaginaryPart < 0.0
      // Replace + with minus sign
      output << "- " << -z.mImaginaryPart << "i)";
   }
   return output;
}
