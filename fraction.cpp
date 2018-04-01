/*******************************************************************************

   Tyler Hull
   p622s636
   
      Program 3
      
   .cpp file for member functions of Fraction class
*/

#include <cstdlib> // for abs
#include <utility> // for swap
#include <iostream> // for cout
#include "fraction.hpp"


// Constructors

// default constructor initializes numerator and denominator to 1 
Fraction::Fraction (void)
{
   numer = 1;
   denom = 1;
}

// Allows user set numerator and denominator at decleration
Fraction::Fraction (int num, int den)
{
   numer = num;
   denom = den;
}


// Mutator Functions
// No mutator functions


// Accessor Functions

// Will return the double value of the Fraction
double Fraction::Double_value(void)
{
   return double(numer) / double(denom);
}

// Returns a string value equivalent to the value of the fraction to be used
// as needed where a string would be applicable. This function changed to just
// print to screen a representation of the fraction as numer/denom.
void Fraction::Print(void)
{
   std::cout << numer << "/" << denom;
   return;
}

Fraction Fraction::Lowest_term (void)
{
   int gcd; // holds greatest common denominator
   int x, y, z; // will be used to compute gcd
   
   // Compute gcd of numerator and denominator
   // set x to greater of numerator and denominator
   if (abs(numer) > abs(denom))
   {
      x = abs(numer);
      y = abs(denom);
   }
   else
   {
      x = abs(denom);
      y = abs(numer);
   }
   
   while (y > 0)
   {
      z = x % y;
      x = y;
      y = z;
   }
   gcd = x;
   
   // adjust numerator and denominator based on gcd and assign
   Fraction reduced((numer / gcd),(denom / gcd));
   return reduced;
}

// Operator Overload Functions
// Overload + to add two Fraction type. Will multiply the denominators
// to create a definite multiple of both fractions then call Lowest_term
// to reduce the result before returning
Fraction Fraction::operator+ (Fraction addend)
{
   Fraction sum; // holds sum
   
   // create numerator
   sum.numer = (numer * addend.denom) + (denom * addend.numer);
   
   // create denominator
   sum.denom = denom * addend.denom;
   
   // return reduced fraction
   return sum.Lowest_term();
}

// Overload - to subtract two Fraction type. Will multiply the denominators
// to create a definite multiple of both fractions the call Lowest_term
// to reduce the result before returning
Fraction Fraction::operator- (Fraction subtrahend)
{
   Fraction dif; // holds difference
   
   // create numerator
   dif.numer = (numer * subtrahend.denom) - (denom * subtrahend.numer);
   
   // create denominator
   dif.denom = denom * subtrahend.denom;
   
   // reduce reduced fraction
   return dif.Lowest_term();
}

// Overload * to multiply two fractions. Will reduce using Lowest_term after
// multiplication
Fraction Fraction::operator* (Fraction factor)
{
   Fraction product; // holds product
   
   // create numerator
   product.numer = numer * factor.numer;
   
   // create denominator
   product.denom = denom * factor.denom;
   
   // reduce fraction
   return product.Lowest_term();
}

// Overload / to divide two Fraction type. Will utilise property that division
// by a fraction is multiplication by its inverse to compute. Will reduce using
// Lowest_term after division. This function will also check if the denominator
// has become negative due to the inverse and change signs if necessary
Fraction Fraction::operator/ (Fraction divisor)
{
   Fraction quotient; // holds quotient
   
   // create numerator
   quotient.numer = numer * divisor.denom;
   
   // create denominator
   quotient.denom = denom * divisor.numer;
   
   if (quotient.denom < 0)
   {
      quotient.numer = quotient.numer * -1;
      quotient.denom = quotient.denom * -1;
   }
   
   // reduce fraction
   return quotient.Lowest_term();
}