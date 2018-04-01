/*******************************************************************************

      Tyler Hull
      p622s636
   
      Program 3
      
      This program implements the Fraction class to represent a ratio of two
      integers.  It contains member values for the numerator and denominator.
      Default constructor will set fraction to 1/1. Additional constructor to
      allow user to set numerator and denominator. Member functions to return
      double value of fraction and to return the fraction reduced to lowest
      terms.  Overloaded operators for +,-,*, and / to operate on fractions
      
   Pseudo Code:
    Class Name: Fraction
    Data:       numer - holds fraction numerator
                denom - holds fraction denominator
    Constructor Functions:
                default - sets numer and denom to 1/1
                user based to set numer and denom at declaration
    Mutator Functions:
                No mutator functions
    Accessor Functions:
                Double_value - Returns the value of the fraction as a double
                Print_string - Returns a string representation of the fraction
                  Renamed function to Print. Adjusted this to directly print
                  the value of the fraction to the screen via cout due to
                  difficulties getting it to convert to a string.
                Lowest_term - Returns fraction reduced to lowest terms
    Operator Overload Functions:
                operator+ - overloads + for Fraction
                operator- - overloads - for Fraction
                operator* - overloads * for Fraction
                operator/ - overloads / for Fraction
                                
*/

class Fraction
{
      // Numerator and Denominator member values
      int numer, denom;
      
public:
        // Constructors
        Fraction (void);
        Fraction (int num, int den);
        
        // Mutator Functions
        // No mutator functions
        
        // Accessor Functions:
        double Double_value(void);
        void Print(void); // Renamed, see comments above
        Fraction Lowest_term (void);
        
        // Operator Overload Functions
        Fraction operator+ (Fraction addend);
        Fraction operator- (Fraction subtrahend);
        Fraction operator* (Fraction factor);
        Fraction operator/ (Fraction divisor);
};